/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetLinkedAttachmentRsp_hpp)
#define BtBipGetLinkedAttachmentRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Auxiliary/DataSink.hpp>
#include <Bluetooth/BIP/BtBipGetRsp.hpp>

class BtBipGetLinkedAttachmentRsp : BtBipGetRsp
{
    private:
        typedef BtBipGetRsp Base;

    public:
        BtBipGetLinkedAttachmentRsp();
        virtual ~BtBipGetLinkedAttachmentRsp();

        virtual BtRequestType GetRequestType() const { return BtRqtBipGetLinkedAttachment; }

        void GetLinkedAttachmentInd();

    protected:
        virtual BOOLEAN ExecuteRsp();
        
    private:
        friend class BtBipController;
        friend class BtBipServerService;
};
#endif

#endif  // BtBipGetLinkedAttachmentRsp_hpp

