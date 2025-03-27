/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObjectReferrer_hpp)
#define Apoxi_ObjectReferrer_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <Kernel/Os/SemObtainer.hpp>
#include <Auxiliary/Macros.hpp>

class ReferableObject {
    public:
        ReferableObject(INT refcount = 0) : m_refcount(refcount) {
            DBG_OUT((10000, L"create referable object (%p)!", this));
        }

        virtual ~ReferableObject() { ASSERT_DEBUG(m_refcount == 0); }

        virtual INT RefCount() const { return m_refcount; }

        virtual void AddRef() const {
            m_refcount++;
            DBG_OUT((10001, L"add reference to object(%p)! ref_count = %d", this, m_refcount));
        }

        virtual void Release() const {
            ASSERT_DEBUG(m_refcount > 0);

            m_refcount--;
            DBG_OUT((10002, L"release reference to object(%p)! ref_count = %d", this, m_refcount));

            if (m_refcount == 0)
                OnZeroReferrers();
        }

    protected:
        virtual void OnZeroReferrers() const {
            ASSERT_DEBUG(m_refcount == 0);
            DBG_OUT((10003, L"Delete ReferableObject (%p)", this));

            delete this;
        }

    private:

        //This must be mutable so that AddRef and Release can be const.
        //AddRef and Release must be const so that const objects can be refcounted.
        mutable INT m_refcount; 

        ReferableObject(const ReferableObject& obj);

        ReferableObject& operator=(const ReferableObject& obj);

};

/*  template<class T> class ThreadSafeReferableObject : public ReferableObject {
    no templates with virtual functions for target compiler */
#define DefThreadSafeReferableObject(Name, SemClass)        \
    class Name : public ReferableObject {       \
        public:                                             \
            typedef ReferableObject Base;       \
                                                            \
            Name(INT refcount = 0) : Base(refcount) {       \
            }                                           \
                                                            \
            virtual INT RefCount() const {                  \
                SemObtainer semob(&SemClass::m_sem);    \
                return Base::RefCount();                    \
            }                                           \
                                                            \
            virtual void AddRef() const {                           \
                SemObtainer semob(&SemClass::m_sem);    \
                Base::AddRef();                             \
            }                                           \
                                                            \
            virtual void Release() const {                      \
                SemObtainer semob(&SemClass::m_sem);    \
                Base::Release();                            \
            }                                           \
    }


/*  template<class T> class ObjectReferrer {
    no templates with virtual functions for target compiler */
#define DefObjectReferrer(Name, RefClass)                   \
    class Name {                                            \
        public:                                             \
            Name(RefClass *ref = 0) : m_ref(0) {            \
                SetReference(ref);                          \
            }                                           \
                                                            \
            Name(const Name &or) : m_ref(or.m_ref) {        \
                if (m_ref != 0)                             \
                    m_ref->AddRef();                        \
            }                                           \
                                                            \
            virtual ~Name() {                               \
                if (m_ref != 0)                             \
                    m_ref->Release();                       \
            }                                           \
                                                            \
            RefClass* GetReference() const {                \
                return(m_ref);                              \
            }                                           \
                                                            \
            void SetReference(RefClass *ref = 0) {  \
                if (m_ref != 0)                             \
                    m_ref->Release();                       \
                                                            \
                m_ref = ref;                                \
                                                            \
                if (m_ref != 0)                             \
                    m_ref->AddRef();                        \
            }                                           \
                                                            \
            virtual Name& operator=(const Name &or) {       \
                SetReference(or.m_ref);                     \
                return(*this);                              \
            }                                           \
                                                            \
            RefClass* operator->() const {                  \
                return(m_ref);                              \
            }                                           \
                                                            \
        private:                                            \
            RefClass *m_ref;                                \
    }

#endif  // Apoxi_ObjectReferrer_hpp


