/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbRecord_hpp)
#define Mmi_PbRecord_hpp
#include <AddOns/AdcExtensions/Record.hpp>
#include <AdvPhonebook/PbTypes.hpp>
#include <AdvPhonebook/PbConfig.hpp>

class PbRecord : public Record {
    typedef Record Base;
    
    public:
        PbRecord();
        
        void SetName(const WString &name) { WStrCpy(m_data.m_name, name); }

        const WCHAR * GetName() const { return m_data.m_name; }

        void SetEmail(const String &email) { strcpy(m_data.m_email, email.c_str()); }

        const CHAR * GetEmail() const { return m_data.m_email; }

        void SetGroupId(UINT grp_id) { m_data.m_bits.group_id = grp_id; }

        const UINT GetGroupId() const { return m_data.m_bits.group_id; }

        void SetIccId(INT icc_id) { m_data.m_bits.icc_id = icc_id; }

        const INT GetIccId() { return m_data.m_bits.icc_id; } 

        void SetValid(BOOLEAN valid) { m_data.m_bits.valid = valid; }

        BOOLEAN IsValid() { return m_data.m_bits.valid; }

        virtual const UINT8* GetData();

        virtual void SetData(const UINT8* data);

        virtual INT GetPersistentSize();

        virtual void MarkDeleted();

        virtual BOOLEAN IsRecordDeleted(); 

        struct Persist {
            UINT8       type;
            WCHAR       m_name[c_max_name_len + 1];
            CHAR        m_email[c_max_email_len + 1];
            struct {
                UINT    group_id    : 4;
                INT     icc_id      : 2;    
                BOOLEAN valid       : 1;
                BOOLEAN deleted     : 1;
            } m_bits;
        }m_data;
};

class PbNumberRecord : public Record {
    typedef Record Base;
    
    public:
        PbNumberRecord();
        
        void SetNameRecNo(UINT16 name_recno) { m_data.m_name_recno = name_recno; }

        const UINT16 GetNameRecNo() const { return m_data.m_name_recno; }

        void SetNoId(UINT no_id) { m_data.m_bits.no_id = no_id; }

        const UINT GetNoId() const { return m_data.m_bits.no_id; }

        void SetPhoneNumber(const PhoneNumber &phoneno) { phoneno >> m_data.m_phoneno_persist; }

        const PhoneNumber GetPhoneNumber() const; 

        void SetPhoneNoType(PhoneNoType no_type) { m_data.m_bits.phoneno_type = no_type; }

        const PhoneNoType GetPhoneNoType() const { return m_data.m_bits.phoneno_type; }

        void SetSimRecNo(UINT16 sim_recno) { m_data.m_sim_recno = sim_recno; }

        const UINT GetSimRecNo() const { return m_data.m_sim_recno; }

        void SetIsOnSim(BOOLEAN on_sim) { m_data.m_bits.is_on_sim = on_sim; }

        const BOOLEAN IsOnSim() const { return m_data.m_bits.is_on_sim; }

        void SetValid(BOOLEAN valid) { m_data.m_bits.valid = valid; }

        BOOLEAN IsValid() { return m_data.m_bits.valid; }

        virtual const UINT8* GetData();

        virtual void SetData(const UINT8* data);

        virtual INT GetPersistentSize();

        virtual void MarkDeleted();

        virtual BOOLEAN IsRecordDeleted();

//CN200013749 
        void SetUniqueId(UINT32 unique_id) { m_data.m_unique_id = unique_id; }

        const UINT32 GetUniqueId() const { return m_data.m_unique_id; }
//END CN200013749 
        //  Phone numbers data field definition
        struct Persist {
            PhoneNumber::Persist    m_phoneno_persist;      
            UINT16      m_name_recno;
            UINT16      m_sim_recno;
            UINT8       type;
//CN200013749 
            UINT32          m_unique_id;
//END CN200013749 
            struct {
                UINT        no_id           : 4;
                PhoneNoType phoneno_type    : 4;// CN200007163 old 3 bit
                BOOLEAN     is_on_sim       : 1;
                BOOLEAN     valid           : 1;
                BOOLEAN     deleted         : 1;
            } m_bits;
        }m_data;        
};

#endif  // Mmi_PbRecord_hpp
