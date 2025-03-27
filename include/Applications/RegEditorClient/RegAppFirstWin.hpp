/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_RegAppFirstWin_hpp)
#define Mmi_RegAppFirstWin_hpp

#include <Gui/IpAddrEditor.hpp>
#include <GuiExtensions/MmiDialog.hpp>

class RegAppWin;

class RegAppFirstWin : public MmiDialog
{
    typedef MmiDialog Base;

public:
    
    RegAppFirstWin();
    
    virtual ~RegAppFirstWin();
    
    void Init();
        
    RegAppWin   *m_result_win1;


protected:

    virtual void OnLayoutClient();
    
    virtual BOOLEAN OnConfirm();

    virtual void OnOpen();
    
#if REGAPP_USE_NEW
    virtual BOOLEAN Close();
#endif


private:
    
    LineEditor      m_line_editor;
    IpAddrEditor    m_ip_editor;    

    TextLine    m_port_text;
    TextLine    m_ip_text;

};

#endif
