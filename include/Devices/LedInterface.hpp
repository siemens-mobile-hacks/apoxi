/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class Led {
#endif
#if defined(APOXI_LED_NEW_INTERFACE)
    public:
        /* bit field, internally mapped to led_keyboard, led_service... */
        enum Peripheral {
            Keyboard = 0x01,
            Display = 0x02,
            InService = 0x04,
            All = (Keyboard | Display | InService)
        };

        enum Notification {
            StreamFinished, 
            StreamStopped,  
            StreamError     
        };

        struct Color {
            UINT8 red;      
            UINT8 green;    
            UINT8 blue;     
        };
    
        struct Frame {
            Color color;
            UINT32 on_time;     
            UINT32 total_time;  
            UINT16 iterations;  
        };

        struct StreamField {
            Frame frame;
            Color fading_color;     
        };

        struct Stream {
            const StreamField* stream_field;    
            UINT8 length;                       
            UINT16 iterations;                      
        };

        virtual ~Led();

        virtual const WCHAR* GetName() const;

        static void Reset();

        static BOOLEAN On(Peripheral peripheral, Frame frame);

        static BOOLEAN ChangeColor(Peripheral peripheral, Color color);

        static BOOLEAN Off(Peripheral peripheral, UINT32 fading_time);

        static BOOLEAN ColorStream(Peripheral peripheral, const Stream* stream, INT sequence_id = 0);
 
        static BOOLEAN MusicMode(Peripheral peripheral, BOOLEAN on); 

#else
    public:
        typedef UINT16 Duration;

        class Config {
            public:
                Config(Color color = InvalidColor, BOOLEAN is_changeable = TRUE,
                        Duration on_time = 0, Duration total_time = 0) :
                    m_color(color),
                    m_is_changeable(is_changeable),
                    m_on_time(on_time),
                    m_total_time(total_time) {}
        
                Color GetColor() const { return (m_color); }
                BOOLEAN IsChangeable() const { return (m_is_changeable); }
                Duration GetOnTime() const { return (m_on_time); }
                Duration GetTotalTime() const { return (m_total_time); }
        
                void SetColor(Color color) { m_color = color; }
                void SetOnTime(Duration on_time) { m_on_time = on_time; }
                void SetTotalTime(Duration total_time) { m_total_time = total_time; }
        
            private:
                Color m_color;
                BOOLEAN m_is_changeable;
                Duration m_on_time;
                Duration m_total_time;
        };

        virtual ~Led();

        virtual const WCHAR* GetName() const;

        static ControlArg Control(INT command, ControlArg arg);

        static BOOLEAN Do(Action action, Color color, Duration on_time, Duration total_time);
        static BOOLEAN Do(Action action, Config config);

        static INT GetMaxColorStreamLength() { return (c_max_colorstream_length); }

        static void SetColorStream(Color *color_buffer, INT len);
        static void SetColorStream(Config *config, INT len);

        static Config GetEvent(Event event);

        static BOOLEAN SetEvent(Event event, const Config &config);

        static void ChangeIntensity(Color color, Intensity level);

        static BOOLEAN IsOn(Color color);

        static void Charger(BOOLEAN activate);

        static void MusicMode(BOOLEAN activate);

        static void Reset(); 
#endif

    private:
        static Led m_led;

        Led();

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

