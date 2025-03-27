/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DwdPlayer_hpp)
#define Apoxi_DwdPlayer_hpp

#include <Audio/AudioPlayer.hpp>
#include <Audio/DwdDevice.hpp>
#include <Apc/SignalHandler/SignalMapTableEntry.hpp>    // For ProcessPtr

const UINT8 c_max_slots = 5;//The maximum number of suspend slot for each player

class DwdPlayer : public AudioPlayer, public DwdDevice
{
    public:
        DwdPlayer();
        virtual ~DwdPlayer();
        
        virtual BOOLEAN CanPlay(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanSuspend(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanResume(const AudioActiveReference& active_reference) const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
        // from AudioDeviceBase
        virtual BOOLEAN ApplyDeviceVolume();
        virtual BOOLEAN ApplyMasterVolume();
        virtual BOOLEAN UpdateReferenceVolume(const AudioActiveReference& active_reference, VolumeLevel volume);
        
        virtual BOOLEAN SetMute(BOOLEAN enable = TRUE, MuteDirection direction = UpDownlinkDirection);
        
        static void OnSdlSignal_Audio(const ProcessPtr &process_ptr);
                    
#endif //DOXYGEN_SHOULD_SKIP_THIS

    protected:
        
        virtual BOOLEAN OnSdlSignal(UINT16 func_id, UINT8 handle, UINT16 drv_id, INT8 return_code, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);
                
        typedef UINT8 SuspendSlotType;

        void AllocateSuspendSlot(SuspendSlotType suspendSlot, AudioActiveReference* ref_ptr);

        void ReleaseSuspendSlot(AudioActiveReference* ref_ptr); 

        void AllocateSuspendSlot(SuspendSlotType suspend_slot);
        void ReleaseSuspendSlot(DwdPlayer::SuspendSlotType suspend_slot);
            
        BOOLEAN GetAvailableSuspendSlot(SuspendSlotType &suspend_slot);
        BOOLEAN GetAllocatedSuspendSlot(AudioActiveReference* ref_ptr, SuspendSlotType &suspend_slot);
            
        virtual BOOLEAN SetVolume_Implementation(VolumeLevel volume);           

    private:
        AudioActiveReference* m_suspend_slot_info[c_max_slots];
        
};

#endif  // Apoxi_DwdPlayer_hpp

