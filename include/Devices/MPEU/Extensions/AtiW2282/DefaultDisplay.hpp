/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultDisplay_hpp)
#define Apoxi_DefaultDisplay_hpp

class VideoChannel;
#include <Kernel/Types.hpp>
#include <Kernel/Os/SystemTimer.hpp>
#include <Devices/Display.hpp>

class DefaultDisplay : public Display {
    typedef Display Base;

    public:
        DefaultDisplay(INT index);

        virtual ~DefaultDisplay();

        virtual const WCHAR* GetName() const;

        virtual void OnStart();

        virtual void OnStop();
        
        virtual void SetContrast(INT contrast);

        virtual INT GetContrast() const;

        virtual void SetBrightness(INT brightness);

        virtual INT GetBrightness() const;

        virtual void SetBacklightTimeout(UINT32 timeout);

        virtual void SetPowerTimeout(UINT32 timeout);

        virtual void ReactivateBacklight();

        virtual void ReactivatePower();

        virtual void SetBacklightMode(BacklightMode mode);

        virtual BacklightMode GetBacklightMode() const;

        virtual BOOLEAN IsBacklightOn() const;

        virtual void SetPowerMode(PowerMode mode);

        virtual PowerMode GetPowerMode() const;

        virtual BOOLEAN IsPowerOn() const;

        virtual void Refresh();

        virtual void Refresh(const CustomFrameBuffer* custom_frame_buf);

        virtual VideoChannel* GetVideoChannel();
                
        void OnTimer();
                        
        /*  S-Gold specific interface, which is not part of the common Display interface and hence may
            not be used by any APOXI or MMI interface. */
        static void SynchronizeBuffers();
        
        virtual void SetCallbackActive(BOOLEAN state);

        virtual BOOLEAN IsCallbackActive() const;

    private:
        enum Status {
            DisplayOff,
            BacklightOff,
            BacklightOn
        };

        struct {
            UINT backlight_mode         : 2;
            UINT power_mode             : 2;
            UINT status                 : 2;
            UINT power_on               : 1;
            UINT backlight_on           : 1;
        } m_bits;
        VideoChannel* m_video_channel;
        SystemTimer* m_timer;
        UINT32 m_backlight_timeout;
        UINT32 m_power_timeout;

        UINT8 m_contrast;
        UINT8 m_brightness;

        volatile BOOLEAN m_cb_active;
        BOOLEAN m_synchronize_buffer_skipped;

        Semaphore m_sem;
        BOOLEAN m_gdd_transfer;
        Rect m_updated_blit_rect;
        DDrvAtomPtr m_transfer_buffer;      // buffer which contains a copy of the main frame buffer

        void SetBacklight(BOOLEAN backlight);
        void SetPower(BOOLEAN power);
        
        static void CallbackFn(void* arg);
        
        friend class VideoChannel;
};

#endif  // Apoxi_DefaultDisplay_hpp

