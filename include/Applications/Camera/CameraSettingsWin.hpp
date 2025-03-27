/*  ------------------------------------------------------------------------
    Copyright (C) Danish Wireless Design A/S. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(CameraSettingsWin_hpp)
#define CameraSettingsWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <Gui/RadioButtonControl.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include "CameraSettings.hpp"
#include "HorizontalListControl.hpp"



class CameraSettingsWin : public MmiWindow
{
    typedef MmiWindow Base;
    
public:

    CameraSettingsWin();
    virtual ~CameraSettingsWin();

    void Init();

protected:
    //this function is called before the window opens
    void OnOpen();
    void OnClose();

    virtual void OnActionExecuted(Action *action);
    virtual void OnLayoutClient();
//  virtual BOOLEAN OnKeyDown(KeyCode key_code);

private:
    Action          m_select_action;
    Action          m_cancel_action;
    

    TextLine        m_label_1;
    TextLine        m_label_2;
    TextLine        m_label_3;
        TextLine        m_label_4;  //HaJo 15.09.2005

    HorizontalListControl   m_select_1;
    HorizontalListControl   m_select_2;
    HorizontalListControl   m_select_3;
        HorizontalListControl   m_select_4; //HaJo 15.09.2005

    WString             m_size_list[MAX_ENTRY_COUNT];
    Camera::ImageSizeType       m_size_map[MAX_ENTRY_COUNT];
    WString             m_color_list[MAX_ENTRY_COUNT];
    //HaJo
    /*
    Camera::ColorFormatType     m_color_map[MAX_ENTRY_COUNT];
    */
    WString             m_jpeg_list[MAX_ENTRY_COUNT];
    INT                         m_jpeg_map[MAX_ENTRY_COUNT]; //HaJo 21.09.2005
    
    WString             m_transformation_list[MAX_ENTRY_COUNT]; //HaJo 15.09.2005
    Camera::TransformationType  m_transformation_map[MAX_ENTRY_COUNT];  //HaJo 15.09.2005
    
};

#endif
