/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Devices_Display_hpp)
#define Apoxi_Devices_Display_hpp

#if defined(APOXI_RTOS_WIN32)
    #include <Devices/Win32/VirtualDisplay.hpp>
#elif defined(APOXI_PLATFORM_BP30)
    #include <Devices/BP30/VirtualDisplay.hpp>
#elif defined(APOXI_PLATFORM_MPE)
    #include <Devices/MPE/VirtualDisplay.hpp>
#elif defined(APOXI_PLATFORM_MPEU)
    #include <Devices/MPEU/VirtualDisplay.hpp>
#elif defined(APOXI_PLATFORM_MP1U)
    #include <Devices/SGold/VirtualDisplay.hpp>
#else
    #error Platform not supported!
#endif

class Display : public VirtualDisplay {
    typedef VirtualDisplay Base;

    public:
        enum BacklightMode {
            BacklightModeOff,
            BacklightModeAuto,
            BacklightModeOn
        };
        
        enum PowerMode {
            PowerModeOff,
            PowerModeAuto,
            PowerModeOn
        };

        enum Info {
            PowerTurnedOn,
            PowerTurnedOff,
            BacklightTurnedOn,
            BacklightTurnedOff,
            DisplayTimeout
        };

        class CustomFrameBuffer {
            public:
                CustomFrameBuffer(const Bitmap& bmp, const Rect& blit_rect) :
                  m_bmp(bmp), m_blit_rect(blit_rect) {}
                const Bitmap& GetBitmap() const { return m_bmp; }
                const Rect& GetBlitRect() const { return m_blit_rect; }

            private:
                const Bitmap& m_bmp;
                const Rect& m_blit_rect;
        };

        Display(INT index);

        virtual ~Display();
        
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

        virtual void SetCustomFrameBufferRect(const Rect& rect);

        virtual void Refresh();

        virtual void Refresh(const CustomFrameBuffer* custom_frame_buf);

        virtual VideoChannel* GetVideoChannel();
        
        virtual void IndicateAlphaMaskUpdate();
        
        void SetLocked(BOOLEAN locked) { m_locked = locked; }

        BOOLEAN IsLocked() const { return m_locked; }
        
        virtual void SetCallbackActive(BOOLEAN state);

        virtual BOOLEAN IsCallbackActive() const;

        void Refresh(BOOLEAN block, const CustomFrameBuffer* custom_frame_buf = 0);
        
    private:
        BOOLEAN m_locked;
};

#endif  // Apoxi_Devices_Display_hpp

