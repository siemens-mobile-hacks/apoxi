/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CsdDataConn_hpp)
#define Apoxi_CsdDataConn_hpp

#include <Socket/PppDataConn.hpp>
#include <Asc/DataCallControl.hpp>
#include <Asc/Types.hpp>

class CsdDataConnProfile;

class CsdDataConn : public PppDataConn, public DataCallControl
{
    typedef PppDataConn Base;

    friend class NiSharedPtr<DataConn>;
    friend class DataConnProfile;

    public:
        virtual void OnSetupCompleted(DcError error);

        virtual void OnReleaseCompleted(DcError error);

    protected:
        CsdDataConn(const DataConnProfilePtr &profile);

        virtual ~CsdDataConn();

    protected:
        virtual void PostInfoMsg(MessageType type) const;

        virtual void OnBeforePppSetup();

        virtual void OnAfterPppRelease();

        void ReleaseDataCall();

        virtual void Cleanup();

    protected:
        const CsdDataConnProfile& MyProfile() const {
            return (const CsdDataConnProfile &)Base::MyProfile();
        }

    protected:
        DcError m_dc_err;       
        CallApiRc m_dch_err;    

    private:
        BOOLEAN m_csd_active;

    private:
        void PostDataConnInfoMsg(DataConnInfoMsgType msg, DcError csd_err,
            CallApiRc csd_dial_err) const;
};

#endif  // Apoxi_CsdDataConn_hpp


