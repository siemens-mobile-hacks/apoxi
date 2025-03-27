/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AppRoutingTable_hpp)
#define Apoxi_AppRoutingTable_hpp

#include <Kernel/Linkable.hpp>
#include <Kernel/LinkedList.hpp>

typedef LinkedList<DispatcherAction> DispatcherActionList;

class AppRoutingTableEntry : public Linkable<AppRoutingTableEntry> {
    public:
        AppRoutingTableEntry(const MsgId msg_id) : m_msg_id(msg_id) {};

        const MsgId GetMsgId() const { return m_msg_id; };

        const DispatcherActionList* GetDispatcherActionList() const { return& m_disp_action_list; }

        void AddDispatcherAction(DispatcherAction* app_entry) { 
            m_disp_action_list.PushBack(app_entry); 
        };

    private:
        MsgId m_msg_id;
        DispatcherActionList m_disp_action_list;
};

typedef LinkedList<AppRoutingTableEntry> AppRoutingTable;

#endif  // Apoxi_AppRoutingTable_hpp


