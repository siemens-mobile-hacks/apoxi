/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_ToDoListWin_hpp)
#define Mmi_ToDoListWin_hpp

#include <GuiExtensions/MmiItemListWindow.hpp>
#include <Common/Items/ProviderProxyContainer.hpp>

class ToDoListWin : public MmiItemListWindow {

    typedef MmiItemListWindow Base;

    public:
        
        ToDoListWin();

        virtual ~ToDoListWin();

        void Init(Dispatcher* dispatcher, Provider* provider = 0);      

        void UpdateProvider();

        INT GetSelectedIndex() {return m_selected_index;};

        
    protected:
        virtual void OnOpen();

        virtual void OnClose();

        virtual void OnGetFocus();

        void OnSelectionChanged(INT selected_index);

        BOOLEAN OnMessage(const Message& message);      

    private:        
        ProviderProxyContainer      m_provider_cont;
        INT                         m_selected_index;
};

#endif


