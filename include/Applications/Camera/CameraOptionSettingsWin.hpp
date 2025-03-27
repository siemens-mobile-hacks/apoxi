/*  ------------------------------------------------------------------------
    Copyright (C) Danish Wireless Design A/S. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(CameraOptionSettingsWin_hpp)
#define CameraOptionSettingsWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <Gui/RadioButtonControl.hpp>
#include <Gui/RadioButtonGroup.hpp>

#include "CameraSettings.hpp"

class CameraOptionSettingsWin : public MmiWindow
{
    typedef MmiWindow Base;

public:
    enum 
    {
        MaFlsAuto,
        MaFlsOff,
        MaFlsRedEye,
        MaFlsLast
    }FlsType;
    enum 
    {
        MaFliOff,
        MaFli50Hz,
        MaFli60Hz,
        MaFliLast
    }FliType;
    enum 
    {
        MaWbAuto,
        MaWbOutdoor,
        MaWbIndoor,
        MaWbLast
    }WbType;

    typedef enum 
    {
        FlashType,
        WhiteBalanceType,
        AntiFlickerType,    
    }WindowType;


    CameraOptionSettingsWin();
    virtual ~CameraOptionSettingsWin();

    void Init(WindowType type);

protected:
    //this function is called before the window opens
    void OnOpen();

    virtual void OnActionExecuted(Action *action);
    virtual void OnLayoutClient();

private:
    //Camera handler used to access the camera driver
//  CameraHandler           *m_cam_handler;

    Action          m_select_action;
    Action          m_cancel_action;

//  RadioButtonAction m_rb_action[MaSizeLast];
    RadioButtonControl m_rb_control[MaFlsLast];
    RadioButtonGroup    m_rb_list;
    StillCamera::FlashType m_map_fls[MaFlsLast]; //HaJo
    Camera::AntiFlickerType m_map_fli[MaFliLast];
    CameraSettings::WhiteBalanceType    m_map_wb[MaWbLast];
    //enum type 
    WindowType              m_type;
};

#endif
