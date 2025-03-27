/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined(APOXI_SER_DATACONN_SUPPORT) || defined(APOXI_COMPAT_1_13_0)

#if !defined(Apoxi_SerDataConn_hpp)
#define Apoxi_SerDataConn_hpp

#include <Socket/PppDataConn.hpp>

class SerDataConn : public PppDataConn
{
    typedef PppDataConn Base;

    friend class NiSharedPtr<DataConn>;
    friend class DataConnProfile;

    protected:
        SerDataConn(const DataConnProfilePtr &profile);

        virtual ~SerDataConn();

    protected:
        virtual void PostInfoMsg(MessageType type) const;

    private:
        void PostDataConnInfoMsg(DataConnInfoMsgType msg) const;
};

#endif  // Apoxi_SerDataConn_hpp

#endif  // APOXI_SER_DATACONN_SUPPORT || APOXI_COMPAT_1_13_0


