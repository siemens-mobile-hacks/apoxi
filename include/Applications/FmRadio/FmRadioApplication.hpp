#if !defined(Mmi_FmRadioApp_hpp)
#define Mmi_FmRadioApp_hpp

#include <Common/MmiApplication.hpp>
#include "FmRadioWindow.hpp"

#include "FmRadioSettingsProvider.hpp"
#include "FmRadioStationsProvider.hpp"
#include "FmRadioSelectStrongerFreq.hpp"
#include "FmRadioEditWin.hpp"

#include <Common/Properties/Descriptors/SetPropertyDescriptor.hpp>

class FmRadioApplication : public MmiApplication
{
    typedef MmiApplication Base;

public:
        typedef enum 
        {
            RadioFmOff,
            RadioFmOn,  
            RadioFmOnMinimized,
            RadioFmToRestart
        }RadioFmState;

    virtual ~FmRadioApplication();
    static FmRadioApplication* GetInstance();
        RadioFmState GetRadioOn(void){ return m_fmradio_state; }
        void SetRadioOn(RadioFmState State){ m_fmradio_state = State; }
        void CloseMinimizedRadio(void){ m_fmradio_state = RadioFmToRestart; m_fmradio_win.Close(); }
        //RadioAudioDevice* GetRadioDevice(void){ return m_device_radio; }

        FmRadioSettingsProvider * GetFmRadioSettingsProv(void){ return &m_fmradio_settings_prov; }
        FmRadioStationsProvider * GetFmRadioStationsProv(void){ return &m_fmradio_stations_prov; }
        FmRadioWindow * GetFmRadioWin(void) { return &m_fmradio_win; }

protected:
        virtual void OnStartup();
    virtual void OnOpen();
    virtual void OnClose();
    virtual BOOLEAN OnMessage(const Message &msg);
        virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);

        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification, 
                                                const Property* property, 
                                                const DataItem& value);

private:
        enum FeatureItemIds {
                FmRadio,
                FmRadioIdle,
                MinimizeFeature,
                MuteFeature,
                UnmuteFeature,
                SkMuteFeature,
                SkUnmuteFeature,
                MonoFeature,
                StereoFeature,
                ListSavedFeature,
                EditFreqFeature,
                CloseFeature,
                FmRadioFeatureCnt
            };

    FmRadioApplication();

        Feature                     m_items[FmRadioFeatureCnt];

    static FmRadioApplication m_app;
        RadioFmState                m_fmradio_state;
        //RadioAudioDevice *            m_device_radio;
        FmRadioWindow               m_fmradio_win;

        FmRadioSettingsProvider     m_fmradio_settings_prov;
        FmRadioStationsProvider     m_fmradio_stations_prov;
        FmRadioSelectStrongerFreq   m_fmradio_freq_list_win;
        FmRadioEditWin              m_fmradio_edit_win;

        Property                    m_set_level_property;
        Property                    m_set_band_property;
        SetPropertyDescriptor       m_set_level_descriptor;
        SetPropertyDescriptor       m_set_band_descriptor;
        Property                    m_radio_prop;
};

#endif // Mmi_FmRadioApp_hpp

