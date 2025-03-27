/*  ------------------------------------------------------------------------
  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
  All rights reserved.
  ------------------------------------------------------------------------
  This document contains proprietary information belonging to COMNEON.
  Passing on and copying of this document, use and communication of its
  contents is not permitted without prior written authorisation.
  ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(AddOns_VoiceRecognition_VrDispatcher_hpp)
#define AddOns_VoiceRecognition_VrDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Message.hpp>
#include <Asc/StackMsgDispatcher.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Auxiliary/Linkable.hpp>

#include "VrTemplateData.hpp"

class VrData;
class VrHandler;

class VrDispatcher : public StackMsgDispatcher 
{
    typedef StackMsgDispatcher Base;
    friend VrHandler;

 public:
    VrDispatcher();

    virtual ~VrDispatcher();

    void SetHandler(VrHandler* vr_handler) {
        m_vr_handler = vr_handler;
    }

    BOOLEAN OnLoadTemplateReq(const StackMsgArgument &arg);
    BOOLEAN OnSayNameInd(const StackMsgArgument &arg);
    BOOLEAN OnErrorInd(const StackMsgArgument &arg);
    BOOLEAN OnWarningInd(const StackMsgArgument &arg);
    BOOLEAN OnVrIntrmRecogResultInd(const StackMsgArgument &arg);
    BOOLEAN OnVrRecogResultInd(const StackMsgArgument &arg);
    BOOLEAN OnVrAbortEngineInd(const StackMsgArgument &arg);
    BOOLEAN OnVrStoreTemplateReq(const StackMsgArgument &arg);
    BOOLEAN OnVrTrainResultInd(const StackMsgArgument &arg);
    BOOLEAN OnVrStopRecogIndArg(const StackMsgArgument &arg);
    BOOLEAN OnVrG2AResultInd(const StackMsgArgument &arg);

    // audio callback for playback end
    static void OnAudioMessageCallback(const Message* message, void* pUserData);

 private:

    static const StackMsgArgMap<VrDispatcher> m_arg_map[];

    StackMsgArgMapContainer<VrDispatcher> m_arg_map_container;

    VrHandler*  m_vr_handler;

    VrData*     m_vr_data;

        
};

#endif // AddOns_VoiceRecognition_VrDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS

