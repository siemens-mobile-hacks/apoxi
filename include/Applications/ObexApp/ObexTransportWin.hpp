/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_ObexTransportWin_hpp)
#define Mmi_ObexTransportWin_hpp
//#include <GuiExtensions/MmiMenuWindow.hpp>    
#include <Gui/RadioButtonControl.hpp>
#include <Gui/ItemGrid.hpp>
#include <Obex/ObexConfig.hpp>
#include <Obex/ObexTransport.hpp>

class ObexTransportWin : public MmiWindow {
    typedef MmiWindow Base;

    public:
        ObexTransportWin();
        virtual ~ObexTransportWin();
        void Init();

    protected:
        
        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();
        virtual void OnClose();
        virtual void OnLayoutClient();
        BOOLEAN OnKeyDown(KeyCode key_code);

    private:

        RadioButtonAction m_rb_action[APOXI_OBEX_MAX_NO_TRANSPORTS];
        RadioButtonGroup    m_rb_group;
        ItemGrid m_item_grid;

        
};
#endif  // Mmi_ObexTransportWin_hpp
