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

#if !defined(Adc_SimTkMainMenuProvider_hpp)
#define Adc_SimTkMainMenuProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Apc/SignalTypes.hpp>
#include <Apc/SimTkStackMsgArgs.hpp>

#include <Adc/ProvIds.hpp>

/*------------------------------------------------------------------
                            SimTkMainMenuProvider
 ------------------------------------------------------------------*/

class SimTkMainMenuProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        SimTkMainMenuProvider();
        virtual ~SimTkMainMenuProvider();
        virtual INT GetProviderId() const;
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

        void SetSimTkMainMenu(const SetupMenuReqArg & arg);

        void Reset();

    private:
        SimSetupMenuOptions      m_options;
        SimAlphaIdentifier       m_title;
        SimIconIdentifier        m_titleicon;
        SimItemIdentifierList    m_item_list;
        SimNextActionIdentifier  m_nextaction_list;
        SimIconIdentifier        m_icon_list;
};

#endif


