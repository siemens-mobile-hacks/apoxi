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

#if !defined(Adc_MbiProvider_hpp)
#define Adc_MbiProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>

/*------------------------------------------------------------------
                            MbiProvider
 ------------------------------------------------------------------*/

class MbiProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        MbiProvider();
        virtual ~MbiProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * handler, Protector * protector);
        virtual BOOLEAN SelectRow(INT row);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN Update(ProviderListener * listener = 0);


    private:
        void ClearBufferVariables();

        SimAuxHandler * m_aux_handler;
        UINT8 m_buffer[c_max_mbi_record_length];

};

#endif


