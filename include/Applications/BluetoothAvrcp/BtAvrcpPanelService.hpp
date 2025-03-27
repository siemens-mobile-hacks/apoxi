 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if ! defined(BtAvrcpPanelService_hpp)
#define BtAvrcpPanelService_hpp

#include "BtAvrcpPreComp.hpp"
#include "BtAvrcpCommandInterface.hpp"

/*  MmiSubUnitType specifies the type of Sub Unit.
   For example: Media Player is a sub-unit which is of type Audio*/
enum MmiSubUnitType {
    MSUMonitor,
    MSUAudio,
    MSUPrinter,
    MSUDisc,
    MSUTapeRecPlayer,
    MSUTuner,
    MSUCa,
    MSUCamera,
    MSUPanel,
    MSUBulletinBoard,
    MSUCameraStorage,
    MSUVendorUnique,
    MSUBtAstUnit
};

/*
    AvrcpPanelService is a service interface exposed which is used by plugin applications to register themselves to Panel application
    MMI Panel application inherits this class to implement virtual functions defined in this class.
*/
class BtAvrcpPanelService
{
    public:
        virtual BOOLEAN RegisterAvrcpApp (WString& app_name, BtAvrcpCommandInterface& cmd_handle, MmiSubUnitType sub_unit_info) const;
        virtual BOOLEAN DeregisterAvrcpApp (WString& app_name) const;

};

#endif //#define BtAvrcpPanelService_hpp
