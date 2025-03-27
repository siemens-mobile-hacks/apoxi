/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioError_hpp)
#define Apoxi_AudioNewAPI_AudioError_hpp

#include <Auxiliary/NonCloneable.hpp>
class AudioReference;

//There is no real implementation in this class,
//but I am waiting (just feeling) new requirements soon, (simonal)
class AudioError : public NonCloneable
{
    public:
        virtual ~AudioError();

        static AudioError& GetInstance();

        enum ErrorType
        {
            ErrorUnknown,
            ErrorResourceInUse,
            ErrorResourceConflict,
            ErrorHandleNotUsed,
            ErrorNoHwSupport,
            ErrorSharingViolation,
            ErrorParameterOutOfRange,
            ErrorFormatNotSupported,
            ErrorAudioDriverDisabled,
            ErrorRingerToneError,
            ErrorVmFFSProblems,
            ErrorVmPerformanceProblems,
            ErrorRingerSuspendresumeError,
            ErrorMissingDspResource,
            ErrorUnknownPosition,
            ErrorNoPlayback,
            ErrorNoPlaytime,
            ErrorPerformanceProblems
        };

        typedef INT8 AudReturnCode;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        static void SendAudioErrorMsg(AudioReference& audio_reference, const AudReturnCode return_code);

        // Map the driver defined error to the APOXI error type
        AudioError::ErrorType DriverError2ApoxiError(AudReturnCode return_code);
protected:
    AudioError();

protected:
    static AudioError m_instance;

#endif // DOXYGEN_SHOULD_SKIP_THIS
};

#endif  // Apoxi_AudioNewAPI_AudioError_hpp


