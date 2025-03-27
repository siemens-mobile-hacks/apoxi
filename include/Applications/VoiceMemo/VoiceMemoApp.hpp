/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_VoiceMemoApp_hpp)
#define Mmi_VoiceMemoApp_hpp
#include <AddOns/Services/ServiceBroker.hpp>

#include <Common/MmiServices.hpp>
#include <Common/MmiApplication.hpp>
#include <Common/CommonMsgTypes.hpp>
#include <Audio/Messages/AudioStoppedMsg.hpp>
#include <VoiceMemo/VoiceMemoRecordWin.hpp>

class VoiceMemoApp : public MmiApplication,
                     public VoiceMemoService {
    typedef MmiApplication Base;

    public:
        static VoiceMemoApp *GetInstance();

        virtual ~VoiceMemoApp();

        virtual ServiceResult StartRecording(SharedPtr<AudioActiveReference> &voicememo_ref);

        virtual ServiceResult StopRecording();

        virtual ServiceResult PauseRecording();

        virtual ServiceResult ResumeRecording();
        void OnErrorNotification(const SharedPtr<AudioActiveReference>&);

    protected:
        virtual void OnOpen();
        virtual void OnClose();
        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnStartup();
        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

    private:
        static  VoiceMemoApp                m_voicememo_app;
        //VoiceMemoWin                      m_voicememo_win;
        VoiceMemoRecordWin                  m_voicememo_record_win;
//      MenuAction                          m_voicememo_action;
        

        enum FeatureItemIds{
            VmVoiceMemo,
            VmRecordvm,
            VmStopRecordvm,
            VmFeatureCnt
        };
        
        Feature m_items[VmFeatureCnt];
        
        VoiceMemoApp();
};
#endif  // Mmi_VoiceMemoApp_hpp
