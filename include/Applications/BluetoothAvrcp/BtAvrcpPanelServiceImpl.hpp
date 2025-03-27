// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */

#if ! defined(BtAvrcpPanelServiceImpl_hpp)
#define BtAvrcpPanelServiceImpl_hpp

#include <Common/BtAvrcpPanelService.hpp>

class Application;
class BtAvrcpCommandInterface;

class BtAvrcpPanelServiceImpl : public BtAvrcpPanelService
{
    public:

        BtAvrcpPanelServiceImpl();

        virtual ~BtAvrcpPanelServiceImpl();

        void Init(Application* app);

        virtual ServiceResult RegisterAvrcpApp (WString& app_name, BtAvrcpCommandInterface& cmd_handle, MmiSubUnitType sub_unit_info) const;

        virtual ServiceResult DeregisterAvrcpApp (WString& app_name) const;

    private:
        Application* m_app;

};

#endif // BtAvrcpPanelServiceImpl_hpp

