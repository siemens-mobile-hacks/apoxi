/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetLinkedThumbnailRsp_hpp)
#define BtBipGetLinkedThumbnailRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Auxiliary/DataSink.hpp>
#include <Bluetooth/BIP/BtBipGetRsp.hpp>

class BtBipGetLinkedThumbnailRsp : BtBipGetRsp
{
    private:
        typedef BtBipGetRsp Base;

    public:
        BtBipGetLinkedThumbnailRsp();
        virtual ~BtBipGetLinkedThumbnailRsp();

        virtual BtRequestType GetRequestType() const { return BtRqtBipGetLinkedThumbnail; }

        void GetLinkedThumbnailInd();

    protected:
        virtual BOOLEAN ExecuteRsp();
        
    private:
        friend class BtBipController;
        friend class BtBipServerService;
};
#endif

#endif  // BtBipGetLinkedThumbnailRsp_hpp

