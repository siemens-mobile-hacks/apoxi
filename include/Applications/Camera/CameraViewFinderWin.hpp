#if !defined(Mmi_CameraViewFinderWin_hpp)
#define Mmi_CameraViewFinderWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/MmiAlert.hpp>
#include <Common/CommonMsgTypes.hpp>
#include "CameraSettings.hpp"

class CameraApp;

//class CameraViewFinderWin : public CameraLayoutSettingsWin
class CameraViewFinderWin : public MmiWindow
{
    //typedef CameraLayoutSettingsWin Base;
    typedef MmiWindow Base;



public:
    void Init(CameraApp *pcamera_app);
    void SetViewFinderRectToNewFormat(Rect& vf_rect, Camera::ImageSizeType size_type);

    void SetSettingModeTextline(const WString &);
    void RefreshViewFinder();

protected:
    void OnOpen();
    void OnClose();

    virtual void OnLayoutClient(); //copied from CameraLayoutSettingsWin.hpp
    virtual void OnLoseFocus();
    virtual void OnGetFocus();
    virtual void OnPaint(const Rect& repaint_rect);

    void RedrawStatusLine();    //copied from CameraLayoutSettingsWin.hpp

    //copied from CameraLayoutSettingsWin.hpp
    WString                 m_wstr_settingmode;
    TextLine                m_textline_settingmode;
    ImageBox                m_arrow_prev;
    ImageBox                m_arrow_next;

private:
    

    StillCamera*                m_camera_ref;   //HaJo
    UINT                    m_current_camera_idx;
    
    CameraApp               *m_pcamera_app;
    
    BOOLEAN                 m_init;
};

#endif //Mmi_CameraViewFinderWin_hpp
