/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SimDataTypes_hpp)
#define Apc_SimDataTypes_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/ElementList.hpp>
#include <Auxiliary/BitField.hpp>

#include <Apc/DataCodingScheme.hpp>
#include <Apc/Tlv.hpp>

#include <Apc/SignalTypes.hpp>
#include <Apc/UserData.hpp>


/*  ========================================================================
    SimAtom
    ========================================================================*/
template <class T> class SimAtom {
    public:
        SimAtom(const T &elem = 0) : m_elem(elem) {}
        BOOLEAN operator ==(const SimAtom<T> &sim_elem) const {
            return (m_elem == sim_elem.m_elem);
        }
        BOOLEAN operator ==(const T &elem) const {
            return (m_elem == elem);
        }
        BOOLEAN operator <(const SimAtom<T> &sim_elem) const {
            return (m_elem < sim_elem.m_elem);
        }
        BOOLEAN operator <(const T &elem) const {
            return (m_elem < elem);
        }

        const T& Get() const { return (m_elem); }
        void Clear(UINT8 set = 0x00) { memset(&m_elem, set, sizeof(T)); }
        BOOLEAN IsInvalid() const { return (m_elem == 0); }

    private:
        T m_elem;
};

/*  ========================================================================
    SimDummy
    ========================================================================*/
typedef SimAtom<UINT8> SimDummy;

/*  ========================================================================
    SimReferenceNumber
    ========================================================================*/
typedef SimAtom<UINT8> SimReferenceNumber;

/*  ========================================================================
    SmsReferenceNumber
    ========================================================================*/
typedef UINT8 SmsReferenceNumber;

/*  ========================================================================
    SimIconId
    ========================================================================*/
typedef SimAtom<TlvAtom> SimIconId;

/*  ========================================================================
    SimItemId
    ========================================================================*/
class SimItemId : public SimAtom<TlvAtom> {
    public:
        typedef SimAtom<TlvAtom> Base;
        enum { InvalidId };
        SimItemId();
        SimItemId(const TlvAtom &id);
        ~SimItemId();

        BOOLEAN operator < (const SimItemId &id) const { return Get() < id.Get();}
        BOOLEAN IsInvalid() const { return (Get() == (TlvAtom) InvalidId); }
};

/*  ========================================================================
    SimIconQualifier
    ========================================================================*/
class SimIconQualifier {
    public:
        SimIconQualifier();
        SimIconQualifier(TlvAtom bit_field);
        ~SimIconQualifier();

        BOOLEAN IsSelfExplanatory() const { return (!m_bit_field.GetBit(0)); }

        UINT8 Get() const { return (m_bit_field.Get()); }
        void Clear() { m_bit_field.Clear(); }

    private:
        BitField<TlvAtom> m_bit_field;
};


/*  ========================================================================
    SimAlphaIdentifier
    ======================================================================== */
class SimAlphaIdentifier {
    public:
        SimAlphaIdentifier();
        SimAlphaIdentifier(const TlvAtom *data_ptr, const INT len);
        SimAlphaIdentifier(const Tlv &tlv);
        SimAlphaIdentifier(const T_ALPHA_IDENTIFIER &sdl_alpha_id);
        SimAlphaIdentifier(const WString &text);
        ~SimAlphaIdentifier();

        const WString& GetText() const { return (m_text); }

        BOOLEAN IsValid() const { return (m_identifier_valid); }

        void SetValid(BOOLEAN identifier_valid) { m_identifier_valid = identifier_valid; }

        INT Convert2Buffer(UINT8 *buffer, INT &len) const;
        INT Convert2SdlAlpha(T_ALPHA_IDENTIFIER &sdl_alpha) const;
        void Clear() { m_text.Clear(); }    

    private:
        WString m_text;
        BOOLEAN m_identifier_valid;
};

/*  ========================================================================
    SimItemIdentifier
    ======================================================================== */
class SimItemIdentifier : public Linkable<SimItemIdentifier> {
    public:
        SimItemIdentifier();
        SimItemIdentifier(const TlvAtom *data_ptr, const INT len);
        SimItemIdentifier(const Tlv &tlv);
        virtual ~SimItemIdentifier();

        BOOLEAN operator == (const SimItemIdentifier &id) const { return (m_id == id.m_id); }
        BOOLEAN operator <  (const SimItemIdentifier &id) const { return (m_id <  id.m_id); }

        const SimItemId& GetId() const { return (m_id); }

        const WString& GetText() const { return (m_text); } 

        BOOLEAN IsInvalid() const {  return (m_id.IsInvalid()); }   

        void Clear();

    private:
        SimItemId m_id;
        WString m_text;
};

/*  ========================================================================
    SimItemIdentifierList
    ======================================================================== */
typedef ElementList<SimItemIdentifier>  SimItemIdentifierList;

/*  ========================================================================
    SimTextString
    ======================================================================== */
class SimTextString {
    public:
        enum DataSource { 
            TlvSource,          // used for sim toolkit, ... text transformations
            SmsDataSource,      // used for sms, ... text transformations
            CbsDataSource,      // used for cellbroadcast, ... text transformations
            UssdDataSource      // used for ussd, ... text transformations
        };

        SimTextString();
        SimTextString(const UINT8 *buffer, const INT len, const DataCodingScheme &dcs = DataCodingScheme());
        SimTextString(const UINT8 *buffer, const INT len, const DataCodingScheme &dcs, DataSource datasource);
        SimTextString(const UserData &user_data, const DataCodingScheme &dcs);
        SimTextString(const Tlv &tlv);
        SimTextString(const T_SI_TEXT &sdl_si_text);
        SimTextString(const T_SI_TEXT_PTR &sdl_si_text_ptr);
        SimTextString(const WString &text, const DataCodingScheme &dcs);
        ~SimTextString();

        const DataCodingScheme& GetDataCodingScheme() const { return (m_dcs); } 

        const WString& GetText() const { return (m_text); } 

        INT Convert2SdlText(T_SI_TEXT &sdl_si_text) const;
        INT Convert2UserData(UserData &user_data) const;

        void Clear() { m_text.Clear(); }    

    private:
        DataCodingScheme m_dcs;
        WString m_text;

        void ConvertBuffer2WString(const UINT8 *data_ptr, const INT data_len, const DataSource data_source, UINT8 padding = 0);
};

/*  ========================================================================
    SimNextActionIdentifier
    ======================================================================== */
class SimNextActionIdentifier {
    public:
        SimNextActionIdentifier();
        SimNextActionIdentifier(const TlvAtom *data_ptr, const INT len);
        SimNextActionIdentifier(const Tlv &tlv);
        SimNextActionIdentifier(const SimNextActionIdentifier &sim_items_nai);
        ~SimNextActionIdentifier();
        SimNextActionIdentifier& operator =(const SimNextActionIdentifier &sim_items_nai);

        INT GetNoOfNai() const { return (m_no_of_nai); }

        const Nai& GetNai(INT i) const { 
            ASSERT(i >= 0 && i < m_no_of_nai && m_nai != 0); 
            return (m_nai[i]); 
        }   

        void Clear();

    private:
        Nai *m_nai;
        INT m_no_of_nai;
};

/*  ========================================================================
    SimIconIdentifier
    ======================================================================== */
class  SimIconIdentifier {
    public:
        SimIconIdentifier();
        SimIconIdentifier(const TlvAtom *data_ptr, const INT len);
        SimIconIdentifier(const Tlv &tlv);
        SimIconIdentifier(const T_SI_ICON_ID &sdl_si_icon_id);
        SimIconIdentifier(const SimIconIdentifier &sim_icon);
        ~SimIconIdentifier();
        SimIconIdentifier& operator =(const SimIconIdentifier &sim_icon);

        const SimIconQualifier& GetQualifier() const { return (m_qualifier); }  
        const SimIconId& GetId(INT i = 0) const { 
            ASSERT(i >= 0 && i < m_no_of_icons && m_id != 0); 
            return (m_id[i]); 
        }   

        INT GetNoOfIcons() const { return (m_no_of_icons); }    

        void Clear();

    private:
        SimIconQualifier m_qualifier;
        SimIconId *m_id;
        INT m_no_of_icons;

};


#endif  // Apc_SimDataTypes_hpp


