/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AppContainerRoutingTable_hpp)
#define Apoxi_AppContainerRoutingTable_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Auxiliary/ElementList.hpp>
#include <Auxiliary/HashTable.hpp>

class Application;

class ApplicationListEntry : public Linkable<ApplicationListEntry> {
    public:
        ApplicationListEntry(Application* app) : m_app(app), m_reg_count(1) {}
        Application* GetApplication() const { return m_app; }
        BOOLEAN operator == (const ApplicationListEntry& app_list_entry) const {
            return (m_app == app_list_entry.m_app); 
        }
        void IncrementRegCount() {m_reg_count++;}
        void DecrementRegCount() {m_reg_count--;}
        BOOLEAN IsEmpty() {return (m_reg_count == 0);}

    private:
        Application* m_app;
        INT m_reg_count;
};

typedef ElementList<ApplicationListEntry> AppElemList;

class AppContainerRoutingTableEntry : public Hashable {
    typedef Hashable Base;
    public:
        AppContainerRoutingTableEntry(const HashKey hash_key);
        virtual ~AppContainerRoutingTableEntry();

        ApplicationListEntry* GetFirstApplicationListEntry() const {  return (m_application_list.GetFront()); }
        INT GetNoOfApplications() const {  return (m_application_list.GetSize()); }

        void AddApplication(Application* app);
        void RemoveApplication(const Application* app);

    private:
        LinkedList<ApplicationListEntry> m_application_list;
};

typedef HashTable AppContainerRoutingTable;

#endif  // Apoxi_AppContainerRoutingTable_hpp


