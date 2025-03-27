/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "APOXI_1.10.0\src\Applications\Lcs\LcsAppMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Lcs_LcsAppMsgTypes_hpp)
#define Lcs_LcsAppMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>
#include <Applications/Lcs/LcsFeatTypes.hpp>
#include <Applications/Lcs/ResultWinBase.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class LcsAppTransferLocMsg
    ====================================================================== */

class LcsAppTransferLocMsg : public ApplicationMsg {
    public:
        LcsAppTransferLocMsg(Application* application, const ClientId& client_id, const MlcNumber& mlc_number);
        virtual ~LcsAppTransferLocMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const ClientId& GetClientId() const { return m_client_id; }
        const MlcNumber& GetMlcNumber() const { return m_mlc_number; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 22232
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ClientId m_client_id;
        MlcNumber m_mlc_number;
        
    };


/*  ======================================================================
    Class LcsAppRegisterForMtlrMsg
    ====================================================================== */

class LcsAppRegisterForMtlrMsg : public ApplicationMsg {
    public:
        LcsAppRegisterForMtlrMsg(Application* application);
        virtual ~LcsAppRegisterForMtlrMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 22236
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class LcsAppResWinMsg
    ====================================================================== */

class LcsAppResWinMsg : public ApplicationMsg {
    public:
        LcsAppResWinMsg(Application* application, const ResultWinBase::ResWinAction& event_code);
        virtual ~LcsAppResWinMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const ResultWinBase::ResWinAction& GetEventCode() const { return m_event_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 22237
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ResultWinBase::ResWinAction m_event_code;
        
    };

#endif // Lcs_LcsAppMsgTypes_hpp

