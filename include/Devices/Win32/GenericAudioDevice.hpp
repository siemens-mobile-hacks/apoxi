/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(GenericAudioDevice_hpp)
#define GenericAudioDevice_hpp

#include <Kernel/Types.hpp>
#include <Kernel/UserDispatcher.hpp>
#include <Kernel/Message.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Devices/AbstractDevice.hpp>

class GenericAudioDevice : public AbstractDevice, public UserDispatcher {
    public:
        enum Priority {
            PrioNormal, 
            PrioHigh    
        };

        enum AudioReturnCode {
            AudioRcOk,                          
            AudioRcfunctionalityNotAvailable,   
            AudioRcResourceInUse,               
            AudioRcResourceConflict,            
            AudioRcHandleNotUsed,               
            AudioRcNoHwSupport,                 
            AudioRcSharingViolation,            
            AudioRcParameterOutOfRange,         
            AudioRcFormatNotSupported,          
            AudioRcAudioDriverDisabled,         
            AudioRcRingerToneError,             
            AudioRcMp3Info,                     
            AudioRcRadioInfo,                   
            AudioRcRingerToneFinish,            
            AudioRcToneFinish,                  
            //
            AudioRcDeviceNotInitialized,        
            AudioRcMimeTypeNotSupported,        
            AudioRcDeviceAlreadyInitialized,    
            AudioRcErrorAllocateHW,             
            AudioRcFileNotFound,                
            AudioRcFileCloseError,              
            AudioRcStartParamNotSet,            
            AudioRcError                        
        };

        GenericAudioDevice();
        virtual ~GenericAudioDevice();

        virtual const WCHAR* GetName() const;

        virtual AudioReturnCode Init(Priority prio = PrioNormal);

        virtual AudioReturnCode Stop(UINT8 channel = 0);        

        virtual AudioReturnCode Release();

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        BOOLEAN IsInitialized();

        UINT GetId();

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnToneStopped(AudioReturnCode return_code, INT nParams, UINT32 param_array[]);

        AudioReturnCode Convert2AudioReturnCode(INT error);

        INT ConvertPriority2INT(Priority prio);

        UINT8 m_hw_handle;

        BOOLEAN m_auto_release;

    private:
        UINT m_id;              
}; 

#endif // GenericAudioDevice_hpp


