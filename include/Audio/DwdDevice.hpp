/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DwdDevice_hpp)
#define Apoxi_DwdDevice_hpp

#include <Audio/AudioDeviceBase.hpp>
#include <Audio/AudioError.hpp>

#include <Auxiliary/SimpleMap.hpp>

class DwdDevice
{
    public:
        DwdDevice();
        virtual ~DwdDevice();

    protected:
                    
        BOOLEAN HandleAudReturnCode(const AudioReference& audio_reference, const AudioError::AudReturnCode return_code);
            
        typedef UINT16 DwdIDType;
        typedef UINT8 DwdHandleType; //TODO: Avoid duplication in AudioDeviceBase.          
            
        //These are allocated, refcount, reused and released when no longer used:
        //DwdIDType m_dwd_handle_id; //The ID has a 1-to-1 relationship with the handle.
        DwdHandleType m_dwd_handle;
        //UINT m_dwd_handle_refcount, m_dwd_handle_id_refcount; //The ID lives longer than the handle, so we refcount it separately.
        
        typedef INT AudResource; //It's really an enum, but this allows us to hide the aud header.          
            
        void GenerateHandleId(AudioActiveReference &active_reference);
            
        BOOLEAN Play_Allocate_DWD(AudioActiveReference &active_reference, AudResource aud_resource);            
        
        //Accessed by active reference that is why it is public.
        void DeAllocateDwd(AudioActiveReference &audio_ref);

        //Accessed by active reference that is why it is public.
        void DeAllocateDwdID(AudioActiveReference &audio_ref);
        
        static void AddReferenceMapping(AudioActiveReference &active_reference, INT32 handle_id);
        static void RemoveReferenceMapping(UINT32 handle_id);
        static SharedPtr<AudioActiveReference> FindReference(INT32 handle_id);  
        
        //Accessed by active reference that is why it is public.
        virtual BOOLEAN Play_Allocate(AudioActiveReference &audio_ref) = 0;

                //void SetVolume_Implementation(AudioDeviceBase::VolumeLevel volume);
    private:
        
        static INT32 m_ref_count;
        static SimpleMap<INT32, AudioActiveReference*> m_id_to_ref_map;

};

#endif  // Apoxi_DwdPlayer_hpp

