/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\grossau_latest_sv\lnz_apoxi\Apoxi\Adc\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Adc_MsgTypes_hpp)
#define Adc_MsgTypes_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Kernel/Application.hpp>
#include <Adc/Types.hpp>
#include <Adc/DataHandler.hpp>
#include <Apc/UsimPbTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class DataControlModificationMsg
    ====================================================================== */

class DataControlModificationMsg : public Message {
    public:
        DataControlModificationMsg(const DataControlType& dataControlType, Application* application);
        virtual ~DataControlModificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDataControlType(const DataControlType& dataControlType) { m_dataControlType = dataControlType; }
        const DataControlType& GetDataControlType() const { return m_dataControlType; }
        void SetApplication(Application* application) { m_application = application; }
        Application* GetApplication() const { return m_application; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DataControlType m_dataControlType;
        Application* m_application;
        
    };


/*  ======================================================================
    Class DataControlStartBootMsg
    ====================================================================== */

class DataControlStartBootMsg : public Message {
    public:
        DataControlStartBootMsg();
        virtual ~DataControlStartBootMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class DataControlBootProgressMsg
    ====================================================================== */

class DataControlBootProgressMsg : public Message {
    public:
        DataControlBootProgressMsg(INT provider_id, INT progress);
        virtual ~DataControlBootProgressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetProviderId(INT provider_id) { m_provider_id = provider_id; }
        INT GetProviderId() const { return m_provider_id; }
        void SetProgress(INT progress) { m_progress = progress; }
        INT GetProgress() const { return m_progress; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19002
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_provider_id;
        INT m_progress;
        
    };


/*  ======================================================================
    Class DataControlBootMsg
    ====================================================================== */

class DataControlBootMsg : public Message {
    public:
        DataControlBootMsg(const BootState& boot_state);
        virtual ~DataControlBootMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetBootState(const BootState& boot_state) { m_boot_state = boot_state; }
        const BootState& GetBootState() const { return m_boot_state; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19003
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BootState m_boot_state;
        
    };


/*  ======================================================================
    Class DataControlEndBootMsg
    ====================================================================== */

class DataControlEndBootMsg : public Message {
    public:
        DataControlEndBootMsg(const BootState& boot_state);
        virtual ~DataControlEndBootMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetBootState(const BootState& boot_state) { m_boot_state = boot_state; }
        const BootState& GetBootState() const { return m_boot_state; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19004
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BootState m_boot_state;
        
    };


/*  ======================================================================
    Class DataControlPhonebookStateMsg
    ====================================================================== */

class DataControlPhonebookStateMsg : public Message {
    public:
        DataControlPhonebookStateMsg(BOOLEAN fdn_enabled, BOOLEAN bdn_enabled);
        virtual ~DataControlPhonebookStateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetFdnEnabled(BOOLEAN fdn_enabled) { m_fdn_enabled = fdn_enabled; }
        BOOLEAN IsFdnEnabled() const { return m_fdn_enabled; }
        void SetBdnEnabled(BOOLEAN bdn_enabled) { m_bdn_enabled = bdn_enabled; }
        BOOLEAN IsBdnEnabled() const { return m_bdn_enabled; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19005
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_fdn_enabled;
        BOOLEAN m_bdn_enabled;
        
    };


/*  ======================================================================
    Class UsimPbReadyMsg
    ====================================================================== */

class UsimPbReadyMsg : public Message {
    public:
        UsimPbReadyMsg(const UsimPbResult& usim_pb_result);
        virtual ~UsimPbReadyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetUsimPbResult(const UsimPbResult& usim_pb_result) { m_usim_pb_result = usim_pb_result; }
        const UsimPbResult& GetUsimPbResult() const { return m_usim_pb_result; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19010
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UsimPbResult m_usim_pb_result;
        
    };


/*  ======================================================================
    Class UsimPbResetedMsg
    ====================================================================== */

class UsimPbResetedMsg : public Message {
    public:
        UsimPbResetedMsg();
        virtual ~UsimPbResetedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19011
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Adc_MsgTypes_hpp

