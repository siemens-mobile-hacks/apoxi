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

#if !defined(Adc_AuxProvider_hpp)
#define Adc_AuxProvider_hpp

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>
#include <Auxiliary/ThreadSafeProvider.hpp>

/*------------------------------------------------------------------
                            AuxProvider
 ------------------------------------------------------------------*/

class AuxProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        AuxProvider();
        virtual ~AuxProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN Update(ProviderListener * listener = 0);
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN CommitRow(INT row);

    private:
        void ClearBufferVariables();

        SimAuxHandler * m_aux_handler;
        UINT32   m_commit_acm;
        UINT32   m_commit_acm2;
        UINT32   m_commit_acmmax;
        WString  m_commit_cur_code;
        INT      m_commit_exp;
        UINT     m_commit_eppu;
        INT      m_columnid;
};

#endif

