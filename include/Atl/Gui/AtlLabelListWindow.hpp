/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_AtlLabelListWindow_hpp)
#define Atl_Gui_AtlLabelListWindow_hpp

#include <Atl/Gui/AtlItemListWindow.hpp>
#include <Atl/Gui/ItemLabel.hpp>

class ItemRendererProperties;

class AtlLabelListWindow : public AtlItemListWindow {
    typedef AtlItemListWindow Base;

    public:
        AtlLabelListWindow();

        AtlLabelListWindow(AbstractItemContainer* item_container, const Item& label, BOOLEAN is_numbered = TRUE);

        virtual ~AtlLabelListWindow();

        void Init(AbstractItemContainer* item_container, const Item& label, BOOLEAN is_numbered = TRUE);
        
        void SetLabel(const Item& label);

        const Item& GetLabel() { return m_label.GetItem(); }

    protected:
        virtual void OnOpen();
        virtual BOOLEAN OnMessage(const Message& msg);
        virtual void OnLayoutClient();

        virtual void OnSelectionChanged();

    private:
        void SetFullScreenPerItem();

        ItemLabel m_label;
        WString m_label_txt;
        BOOLEAN m_is_numbered;
        ItemRendererProperties* m_cont_prop;
};

#endif  // Atl_Gui_AtlLabelListWindow_hpp

