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

#if !defined(Adc_SmsParamProvider_hpp)
#define Adc_SmsParamProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimSmsParamHandler.hpp>

/*------------------------------------------------------------------
                            SmsParamProvider
 ------------------------------------------------------------------*/

class SmsParamProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        SmsParamProvider();
        virtual ~SmsParamProvider();
        virtual INT GetProviderId() const;
        void Init(SimSmsParamHandler * smsp_handler, Protector * protector);
        virtual BOOLEAN SelectRow(INT row);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN AppendRow();
        virtual BOOLEAN Update(ProviderListener * listener = 0);


    private:
        void ClearBufferVariables();
        BOOLEAN WriteRow(INT row);

        SimSmsParamHandler * m_smsp_handler;

        SimSmsParameter::Record m_record;

};

#endif


