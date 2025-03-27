/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(AddOns_VoiceRecognition_VrHandler_hpp)
#define AddOns_VoiceRecognition_VrHandler_hpp



#include <Kernel/Types.hpp>
#include <Asc/BaseHandler.hpp>
#include <Audio/StreamAudioReference.hpp>
#include <Audio/StreamAudioPlayer.hpp>
#include <Audio/AudioActiveReference.hpp>
#include <stack/extensions.h>

#include "VrTypes.hpp"
#include "VrDispatcher.hpp"
#include "VrWaitDispatcher.hpp"


class VrData;


class VrHandler : public BaseHandler {
    
    typedef BaseHandler Base;
    friend VrDispatcher;
 
 public:
    enum { ID = VrHandlerId };  

    enum VrApiRc {  
        VrSuccess,
        VrFailed
    };

    enum VrCommand {
        // keep order, range operations are done
        Digit0,
        Digit1,
        Digit2,
        Digit3,
        Digit4,
        Digit5,
        Digit6,
        Digit7,
        Digit8,
        Digit9,
        Dial,
        Cancel,
        Clear,
        TrainedCommand,
        InvalidCommand
    };


    enum VrRecognitionMode {
        IsolatedWord,
        ConnectedWord
    };


    enum VrCommandSet {
        Digits,         // only digits 0-9
        DigitDialing,   // digits 0-9, Dial, Cancel, Clear
        Complete        // all known commands

// perhaps coming sometime
//      Characters      // all characters a-z, A-Z
//      LowerCase       // all lowercase characters a-z
//      UpperCase       // all uppercase characters A-Z
    };

    VrHandler();
    
    virtual ~VrHandler();
    
    virtual HandlerId GetHandlerId() const;
        
    static BOOLEAN Startup();

    VrApiRc InitVr();
    
    void StartRecognition(const Vector<UINT16>& id_set, VrRecognitionMode mode = ConnectedWord, UINT16 max_time = 700, UINT32 max_silence = 80);

    void StartRecording();
    
//  void StopRepeatedRecognition();

    VrApiRc StopRecognition();

    VrApiRc Abort();
    
    VrCommand GetCommand(UINT16 template_id);
    
    VrApiRc PlayTemplate(UINT16 template_id);

    VrApiRc GetAppTemplates(const WString& client_name, Vector<UINT16>& template_ids);


    VrApiRc GetCommandTemplates(VrCommandSet set, Vector<UINT16>& template_ids);


    VrApiRc RemoveTemplate(const WString& client_name, UINT16 template_id);


    VrApiRc RemoveAllTemplates(const WString& client_name);


    void StartTraining(const WString& client_name);
    
    void CreateTemplate(const WString& client_name, const WString& text);

    BOOLEAN IsSupported(VrProperty property);
        
 protected:
    void Reset();
    VrApiRc Abort(BOOLEAN send_message);
    void Error(VrErrorCode error_code);

    
 private:

    void StartTraining(const WString& app_name, VrCommand command);

    VrHandler::VrApiRc SetParameters(void* params);


    VrHandler::VrApiRc GetProperties();

    VrDispatcher        m_vr_dispatcher;

    UINT16*             m_template_ids;

    VrData*             m_vr_data;

    SharedPtr<StreamAudioReference> m_audio_ref;

    StreamAudioPlayer* m_audio_player;

    SharedPtr<AudioActiveReference> m_player_ref;
};

#endif // AddOns_VoiceRecognition_VrHandler_hpp


