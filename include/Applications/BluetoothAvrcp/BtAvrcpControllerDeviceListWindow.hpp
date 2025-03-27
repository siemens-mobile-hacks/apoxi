/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpControllerDeviceListWindow_hpp)
#define BtAvrcpControllerDeviceListWindow_hpp

#include <Atl/Gui/AtlItemListWindow.hpp>

/*  ************************************************************************
    <em>BtAvrcpControllerDeviceListWindow<em> AltItemList window.
    ************************************************************************ */
//Forward declaration
class BtAvrcpPanelApplication;

class BtAvrcpControllerDeviceListWindow : public AtlItemListWindow
{
    typedef AtlItemListWindow Base;

    public:
        BtAvrcpControllerDeviceListWindow();

        virtual ~BtAvrcpControllerDeviceListWindow();

        void Init(BtAvrcpPanelApplication* avrcp_panel_app, AbstractItemContainer* item_container);

    protected:
        virtual void OnOpen();

        virtual void OnSelectionChanged();

        virtual void OnGetFocus();

        virtual BOOLEAN OnConfirm();

    private:
        BtAvrcpPanelApplication* m_avrcp_panel_app;//does not own

};

#endif /* BtAvrcpControllerDeviceListWindow_hpp*/

