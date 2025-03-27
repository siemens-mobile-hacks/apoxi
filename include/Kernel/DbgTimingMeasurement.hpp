#if defined(APOXI_ENABLE_TIMING_MEASUREMENTS)

class DbgTimingMeasurement {
    public:
        DbgTimingMeasurement(const CHAR *context) {
            m_context = context;
            ticks = Os::GetTicks();
            // TODO: DBG_OUT has to be replaced with Apoxi trace classes
            DBG_OUT((10110, "TimingMeasurement start: %s\n", m_context));       
        }

        ~DbgTimingMeasurement() {
            Stop();
        }

        void Stop() {
            if (m_context != 0) {
                // TODO: DBG_OUT has to be replaced with Apoxi trace classes
                DBG_OUT((10110, "TimingMeasurement stop: %s\n. Expired time: %d ms", m_context, ticks.GetExpiredTime()));
                m_context = 0;
            }
        }

    protected:
        const CHAR *m_context;
        Ticks ticks; 
};

#else

class DbgTimingMeasurement {
    public:
        DbgTimingMeasurement(const CHAR *) { }
        void Stop() { }
};

#endif

