/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsMainApp_hpp)
#define Mmi_LcsMainApp_hpp

#include <Common/MmiApplication.hpp>

#include "LocationResultWin.hpp"
#include "TransferLocationDialogWin.hpp"

struct GpsFixData;

class LcsMainApp : public MmiApplication
{
    typedef MmiApplication Base;
    
    public:

        virtual ~LcsMainApp();

        static LcsMainApp* GetInstance();

        
    protected:

        virtual void OnStartup();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnTimeout(const Timer& timer);

        virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);

        virtual BOOLEAN OnContextFeatureTriggered(const FeatureID& feature_id, const DataItem& context_item);


    private:

        LcsMainApp();

        void ProcessNotificationInvoke(const Message& msg);

        void ProcessLocationResult(const Message& msg);

        void ProcessGpsFixData(const GpsFixData& gps_fix_data, WString& fix_data_text, WString& sv_text);


    private:

        static LcsMainApp m_lcs_app;

        enum LcsFeatureId {
            SelfLocation,
            TransferLocation,
            WhereAmI,
            FriendFinder,
            LcsFeatureCnt
        };

        Feature m_features[LcsFeatureCnt];

        INT m_feature_invoked;

        enum LcsContextFeatureId {
            LcsPrevResult,
            LcsNextResult,
            LcsPauseResultUpdate,
            LcsCloseResultWin,
            LcsAbortPosnFix,
            LcsContextFeatureCnt
        };

        ContextFeature m_context_features[LcsContextFeatureCnt];

        TransferLocationDialog m_transfer_loc_dlg;

}; // LcsMainApp

#endif // Mmi_LcsMainApp_hpp
