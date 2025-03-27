/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "ap_str_BSR_03_14\03.14.02-1_delivery\lnz_apoxi\Apoxi\MediaFramework\BinaryCompatLayer\Network\ApoxiExtensions\NetworkServiceThreadMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Common_NetworkServiceThreadMsgTypes_hpp)
#define Common_NetworkServiceThreadMsgTypes_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include <Kernel/Message.hpp>
#include "EmApoxiInterface.hpp"


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class NetworkServiceThreadMsg
    ====================================================================== */

class NetworkServiceThreadMsg : public ContextMsg {
    public:
        NetworkServiceThreadMsg(ExecutionContext* context, 
            const EmNetworkServiceThreadMsgType& type,
            EmNetworkExecCbFn *cb_fn_ptr, 
            void *cb_fn_param);
        virtual ~NetworkServiceThreadMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetType(const EmNetworkServiceThreadMsgType& type) { m_type = type; }
        const EmNetworkServiceThreadMsgType& GetType() const { return m_type; }
        const EmNetworkExecCbFn *GetCbFunction() const { return mp_cb_fn; }
        const void *GetCbFunctionParam() const { return mp_cb_fn_param; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 54001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        EmNetworkServiceThreadMsgType m_type;
        EmNetworkExecCbFn *mp_cb_fn;
        void *mp_cb_fn_param;
        
    };

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Common_NetworkServiceThreadMsgTypes_hpp

