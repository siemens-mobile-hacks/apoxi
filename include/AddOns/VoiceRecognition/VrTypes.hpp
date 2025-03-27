/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(AddOns_VoiceRecognition_VrTypes_hpp)
#define AddOns_VoiceRecognition_VrTypes_hpp

enum VrErrorCode {

#if defined VR_ENABLED_STACK
    // training errors
    VrTrainMemoryError = VR_ERROR_TRAIN_MEM,            
    VrInvalidTrainParam = VR_ERROR_TRAIN_PARAM,
    VrBufferOvervlow = VR_ERROR_TRAIN_BUF_OVERFLOW,
    VrStoreTimeout = VR_ERROR_TRAIN_STORE_TIMEOUT,
    VrTrainPromptTimeOut = VR_ERROR_TRAIN_PROMPT_TIMEOUT,
    VrTrainAbort = VR_ERROR_TRAIN_ABBORT,
    
    // recognition errors
    VrRecogMemoryError = VR_ERROR_RECOG_MEM,
    VrInvalidRecogParam = VR_ERROR_RECOG_PARAM_RANGE,
    VrRecogPromptTimeout = VR_ERROR_RECOG_PROMPT_TIMEOUT,
    VrNoTemplate = VR_ERROR_RECOG_NO_TEMPLATE,
    VrTemplateResponseTimeout = VR_ERROR_RECOG_TEMP_RESP_TIMEOUT,
    VrUndiffTemplate = VR_ERROR_RECOG_UNDIFF_TEMPLATE,
    VrRecogAbort = VR_ERROR_REC_ABBORT,
    
    VrG2AInitMemoryError = VR_ERROR_G2A_INIT_MEM,       //not enough memory during initialization of G2A
    VrG2AParamRangeError = VR_ERROR_G2A_PARAM_RANGE,    //bad parameter during initialization of G2A
    VrG2AExecutionError = VR_ERROR_G2A_EXEC,        //something went wrong during execution of G2A
    VrG2AEmptyBufferError = VR_ERROR_G2A_EMPTY_BUFF,    //no data from apoxi for G2A
#else
    // training errors
    VrTrainMemoryError,         
    VrInvalidTrainParam,
    VrBufferOvervlow,
    VrStoreTimeout,
    VrTrainPromptTimeOut,
    VrTrainAbort,
    
    // recognition errors
    VrRecogMemoryError,
    VrInvalidRecogParam,
    VrRecogPromptTimeout,
    VrNoTemplate,
    VrTemplateResponseTimeout,
    VrUndiffTemplate,
    VrRecogAbort,
    
    VrG2AInitMemoryError,       //not enough memory during initialization of G2A
    VrG2AParamRangeError,   //bad parameter during initialization of G2A
    VrG2AExecutionError,        //something went wrong during execution of G2A
    VrG2AEmptyBufferError,  //no data from apoxi for G2A
#endif

    // APOXI specific errors
    VrLoadTemplateError = 100,
    VrBusy = 101,
    VrStoreTemplateError = 102,
    VrAudioError = 103,
    VrSequenceError = 104
};

enum VrWarningCode {

#if defined VR_ENABLED_STACK
    VrInitTimeout = VR_WARNING_INIT_TIMEOUT, 
    VrRecogBuffer = VR_WARNING_RECOG_BUFFER,
    VrRefExceed = VR_WARNING_REFERENCES_EXCEED,
    VrInputTruncated = VR_WARNING_INPUT_TEXT_TRUNCATED_TO40
#else
    VrInitTimeout, 
    VrRecogBuffer,
    VrRefExceed,
    VrInputTruncated
#endif  
};

enum VrProperty {
#if defined VR_ENABLED_STACK

    IsolatedWordRecognition = ISOLATED_WORD_RECOGNITION,
    ConnectedWordRecognition = CONNECTED_WORD_RECOGNITION,
    SpeakerDependentTraining = SPEAKER_DEPENDENT_TRAINING,
    G2ATraining = G2A_TRAINING,
    SpeakerAdaption = SPEAKER_ADAPTION,
    InvalidProperty = INVALID_PROPERTY
#else

    IsolatedWordRecognition,
    ConnectedWordRecognition,
    SpeakerDependentTraining,
    G2ATraining,
    SpeakerAdaption,
    InvalidProperty
#endif
};


#endif // AddOns_VoiceRecognition_VrTypes_hpp

