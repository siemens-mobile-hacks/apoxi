#ifndef _FMRADIOWINDOW_H
#define _FMRADIOWINDOW_H

#include <Common/MmiWindow.hpp>
#include <Devices/AudioDeviceManager.hpp>

class FmRadioApplication;

class FmRadioWindow : public MmiWindow {
    typedef MmiWindow Base;

    
public:
    FmRadioWindow();
    
    ~FmRadioWindow();

    void Init();
    
    void CloseMinimized(void);

    void SetFrequency(UINT32 edited_freq);

    void HandleRadioAudioNotification(void);

    void UpdateRadioDisplay(void);

protected:
    void SetFrequency(KeyCode key_code);
    void OnLayoutClient();
    void OnOpen();
    void OnClose();
    void SwitchOff();
    BOOLEAN OnMessage(const Message &msg);
    BOOLEAN SaveFrequency(KeyCode key_code);

private:
    #define VOLUME_STEPS 10

    void LoadSavedData();

    TextBox                         m_frequency;
    TextBox                         m_info;
    TextBox                         m_vol_text;

    ProgressBar                     m_volume_bar;

    TextFormat                      m_freq_format;
    TextFormat                      m_vol_format;
    INT                             m_volume;

    WCHAR                           m_freq_str[11];
    WCHAR                           m_mem_str[11];
    UINT32                          m_stored_freq[c_max_fmradio_stations_records];

    ImageBox                        up_down_image;
    ImageBox                        stereo_image;

    BOOLEAN                         m_is_fmradio_running;

    RadioAudioDevice::StationInfo   m_radio_info;

    FmRadioApplication *            m_fmradio_app;
};
#endif
