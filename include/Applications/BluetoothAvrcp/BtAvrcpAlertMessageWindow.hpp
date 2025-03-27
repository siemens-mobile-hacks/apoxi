/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpAlertMessageWindow_hpp)
#define BtAvrcpAlertMessageWindow_hpp

#include <GuiExtensions/MmiAlert.hpp>


/*  ************************************************************************
    <em>BtAvrcpAlertMessageWindow<em> alert window used to display some alert message
    to inform user about the status or result of the progress.
    ************************************************************************ */
class BtAvrcpAlertMessageWindow : public MmiAlert
{
    private:
        typedef MmiAlert Base;

    public:
        // Enumeration for text display in allert box
        typedef enum
        {
            // BT AVRCP registration notification
            BtAmwAvrcpRegister,
            // BT AVRCP deregistration notification
            BtAmwAvrcpDeRegister,
            // BT AVRCP connection established notification
            BtAmwAvrcpConnect,
            // BT AVRCP connection released notification
            BtAmwAvrcpDisconnect,
            // BT AVRCP panel pass through notification
            BtAmwAvrcpPanelPassthrough,
            // BT AVRCP raw frame notification
            BtAmwAvrcpRawFrame,
            // BT AVRCP unit info notification
            BtAmwAvrcpUnitInfo,
            // BT AVRCP subunit info notification
            BtAmwAvrcpSubunitInfo,
            // BT AVRCP not congested
            BtAmwNotCongested,
            // BT AVRCP device selected
            BtAmwAvrcpDeviceSelected
        } BtAmwType;

        BtAvrcpAlertMessageWindow();

        virtual ~BtAvrcpAlertMessageWindow();

        void Init();

        void Display(BtAmwType amw_type, BOOLEAN success);
};

#endif /* BtAvrcpAlertMessageWindow_hpp*/

