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

#if ! defined(_Adc_ProviderListener_hpp)
#define _Adc_ProviderListener_hpp

#include <Kernel/Types.hpp>

// #include <Auxiliary/Provider.hpp>


class Provider;

class ProviderListener {
    public:
        ProviderListener();

        virtual ~ProviderListener();

        virtual void OnStarted(Provider * provider);

        virtual void OnFinished();

        virtual void OnExecuting();

        Provider * GetProvider() const { return m_provider; }

    private:
        Provider * m_provider;

};


#endif


