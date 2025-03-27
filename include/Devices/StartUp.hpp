/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StartUp_hpp)
#define Apoxi_StartUp_hpp

#include <Auxiliary/BitField.hpp>

class StartUp {
    public:
        enum Cause {
            NormalOn = 1,   // value must begin with 1, cause 0 is reserved for SilentReset (see StartUp::Data) 
            AlarmOn,
            ChargerOn,
            ProductionTestOn,
            AirplaneOn
            // INFO: probably must be expanded by currently missing accessories, which are also causing startup (see SignalHandler.cpp -> Apoxi_startup())
        };

        class Data {
            public:
                Data() { }

                Data(Cause startup_cause) { SetCause(startup_cause); }

                void Reset() { m_bits.Clear(); }
                
                BOOLEAN IsValid() const { return (m_bits.Get() != 0); }

                void SetCause(Cause cause, BOOLEAN set = TRUE) { m_bits.SetBit(cause, set); }
                
                BOOLEAN IsCause(Cause cause) const { return m_bits.GetBit(cause); }

                Cause GetMainCause() const;

                void SetSilentReset(BOOLEAN set = TRUE) { m_bits.SetBit(SilentReset, set); }

                BOOLEAN IsSilentReset() const { return m_bits.GetBit(SilentReset); }

            private:
                enum {
                    SilentReset = 0
                };

                BitField8 m_bits;
        };

        struct Table {
            BOOLEAN enabled;    
            Application* app;   
            INT app_cont_idx;   
            UINT stacksize;     
        };

        static void Start(const Data &startup_data);
        
        static void Restart(const Data &startup_data);

        static const Data& GetStartupData() { return m_startup_data; }

        static void Abort();

    private:
        friend class AlarmManager;

        static BOOLEAN m_canceled;
        static Data m_startup_data;

        static void SetStartupData(const Data& startup_data) {  
            m_startup_data = startup_data;
        }
};

#endif  // Apoxi_StartUp_hpp

