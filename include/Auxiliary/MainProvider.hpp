/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if !defined(Auxiliary_MainProvider_hpp)
#define Auxiliary_MainProvider_hpp

#include <Auxiliary/ElementList.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/Provider.hpp>

/*------------------------------------------------------------------
                            ProviderPtr
 ------------------------------------------------------------------*/

class ProviderPtr : public Linkable<ProviderPtr>
{
    public:
        ProviderPtr() : m_provider(0), m_refcount(0) {};

        ProviderPtr(Provider * provider) : m_provider(provider), m_refcount(0) {
            ASSERT(provider!=0);
        }

        virtual ~ProviderPtr() {
            ASSERT(m_refcount==0);
        }

        BOOLEAN operator == (const ProviderPtr &ptr) const { return (m_provider == ptr.m_provider); }

        Provider * GetProvider() const { return m_provider; }
        INT GetId() const { ASSERT(m_provider!=0); return m_provider->GetProviderId(); }
        INT GetRefCount() const { return m_refcount; }
        void IncRefCount() { m_refcount++; }
        void DecRefCount() { m_refcount--; }

    private:
        Provider * m_provider;
        INT        m_refcount;
};

typedef ElementList<ProviderPtr> ProviderPtrList;

/*------------------------------------------------------------------
                            MainProvider
 ------------------------------------------------------------------*/
class MainProvider
{
    public:
        MainProvider();

        virtual ~MainProvider();

        void Init();

        virtual Provider * GetProvider(INT providerid);

        BOOLEAN HasProvider(INT providerid) { return GetProvider(providerid)!=0; }

        static BOOLEAN    RegisterGlobalProvider(Provider * provider);

        static BOOLEAN    AcquireGlobalProvider(INT providerid);

        static BOOLEAN    ReleaseGlobalProvider(INT providerid);

        static BOOLEAN    UnregisterGlobalProvider(Provider * provider);

    protected:
        static Provider * GetGlobalProvider(INT columnid);

    private:
        static ProviderPtr * GetGlobalProviderPtr(INT columnid);

        static ProviderPtrList m_globalproviders;
        static BOOLEAN         m_semexisting;
        static Semaphore       m_semaphore;
        static INT             m_refcount;
};

#endif  // Auxiliary_MainProvider_hpp

