/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_AuxExtensions_ObjectObtainer_hpp)
#define AddOns_AuxExtensions_ObjectObtainer_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Mutex.hpp>

class ObtainableObject {
    public:
        ObtainableObject();     
        virtual ~ObtainableObject();
        INT GetObtainedCount();

    private:
        INT m_obtain_count;
        Mutex m_mutex;

        friend class ObjectObtainer;
        void AddObtainCount(INT cnt);
};

class ObjectObtainer {
    public:
        ObjectObtainer();

        ObjectObtainer(ObtainableObject *object, BOOLEAN disposable, UINT8 object_hint = 0);

        ObjectObtainer(const ObjectObtainer& obtainer);

        virtual ~ObjectObtainer();

        ObjectObtainer& operator=(const ObjectObtainer& obtainer);
 
        ObtainableObject* GetObject() { return m_object; }

        const ObtainableObject* GetObject() const { return m_object; }

        UINT GetObjectHint() const { return m_object_hint; }

    private:
        BOOLEAN m_disposable;
        UINT8 m_object_hint;
        ObtainableObject* m_object;

        void Clear();
};

#endif // AddOns_AuxExtensions_ObjectObtainer_hpp

