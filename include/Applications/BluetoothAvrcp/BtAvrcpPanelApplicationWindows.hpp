/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpPanelApplicationWindows_hpp)
#define BtAvrcpPanelApplicationWindows_hpp

#include <Atl/Gui/AtlItemListWindow.hpp>

/*  ************************************************************************
    <em>BtAvrcpDeviceListWin<em> AltItemList window used to display the subunit(device) names
    in order to prompt the user to set one of the device as active.
    ************************************************************************ */
//Forward declaration
class BtAvrcpPanelApplication;

class BtAvrcpDeviceListWin : public AtlItemListWindow
{
    typedef AtlItemListWindow Base;

    public:
        BtAvrcpDeviceListWin();

        virtual ~BtAvrcpDeviceListWin();

        void Init(BtAvrcpPanelApplication* avrcp_panel_app, AbstractItemContainer* item_container);

    protected:
        virtual void OnOpen();

        virtual void OnSelectionChanged();

        virtual void OnGetFocus();

        virtual BOOLEAN OnConfirm();

    private:
        BtAvrcpPanelApplication*    m_avrcp_panel_app;//does not own
};

#endif /* BtAvrcpPanelApplicationWindows_hpp*/

