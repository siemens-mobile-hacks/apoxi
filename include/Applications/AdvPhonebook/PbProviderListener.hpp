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

#if ! defined(Mmi_PbProvider_hpp)
#define Mmi_PbProvider_hpp

#include <Auxiliary/ProviderListener.hpp>

/*------------------------------------------------------------------
                            PbProviderListener
 ------------------------------------------------------------------*/
class PbProviderListener : public ProviderListener {
    public:
        PbProviderListener(ProviderListener * child_listener);

        virtual ~PbProviderListener();

        virtual void OnStarted(Provider *prov);
        virtual void OnExecuting();

        void SetChildListener(ProviderListener* listener) { m_child_listener = listener; }

private:
        ProviderListener * m_child_listener;

};

#endif  
