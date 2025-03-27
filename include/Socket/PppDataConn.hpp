/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PppDataConn_hpp)
#define Apoxi_PppDataConn_hpp

#include <Socket/DataConn.hpp>

struct PppCallBackData;
struct PppSetupCallBackData;

class PppDataConn : public DataConn
{
    typedef DataConn Base;

    protected:
        PppDataConn(const DataConnProfilePtr &profile);

        virtual ~PppDataConn();

    protected:
        virtual void DoSetup()
            { OnBeforePppSetup(); }

        virtual void OnBeforePppSetup()
            { DoStartPppSetup(); }

        void DoStartPppSetup();

        virtual void DoRelease()
            { DoStartPppRelease(); }

        virtual BOOLEAN CancelSetup();

        void DoStartPppRelease();

        virtual void OnAfterPppRelease()
            { ReleasedEvent(); }

        void OnPppSetup(INT error, const PppSetupCallBackData* data);

        void OnPppStop(INT error);

        void ReleasePPP();

        virtual void Cleanup();

        virtual BOOLEAN GetIpAddress(IpAddr &addr) const;

    private:
        IpAddr m_ip_address;

    private:
        static void PppSetupCallbackHandler(INT error, PppDataConn &dc,
            const PppCallBackData *data);
        static void PppStopCallbackHandler(INT error, PppDataConn &dc,
            const PppCallBackData *data);
};

#endif  // Apoxi_PppDataConn_hpp

