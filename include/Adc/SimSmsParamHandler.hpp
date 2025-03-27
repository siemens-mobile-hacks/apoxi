/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_SimSmsParamHandler_hpp)
#define Adc_SimSmsParamHandler_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/FixedPtrArray.hpp>

#include <Apc/SignalTypes.hpp>

#include <Adc/BaseDataHandler.hpp>


class SimAccessor;

const INT c_size_smsparameters = 28;
const INT c_max_smsparameters = 10;

class SimSmsParameter
{
    public:
        struct Record {
            WString     m_name;
            PhoneNumber m_da;
            PhoneNumber m_sca;
            UINT8       m_protid;
            UINT8       m_dcs;
            UINT8       m_vp;
            
            BOOLEAN     m_exist_name;
            BOOLEAN     m_exist_da;
            BOOLEAN     m_exist_sca;
            BOOLEAN     m_exist_protid;
            BOOLEAN     m_exist_dcs;
            BOOLEAN     m_exist_vp;
        };

        SimSmsParameter(const WString & name, const UINT8 * buffer);
        ~SimSmsParameter();

        const UINT8 * GetSmspBuffer() const { return m_smsp_buffer; };

        const WString & GetName() const { return m_name; }

        BOOLEAN GetSmsParameter(SimSmsParameter::Record & record);
        BOOLEAN SetSmsParameter(const SimSmsParameter::Record & record);
    private:
        WString       m_name;
        UINT8         m_smsp_buffer[c_size_smsparameters];
};

const INT c_smsp_rw_buffer_len = c_max_smsparam_entry_len;

class SimSmsParamHandler : public BaseDataHandler
{
    typedef BaseDataHandler Base;

    typedef FixedPtrArray<SimSmsParameter> SmsParameterArray;

    public:
        SimSmsParamHandler();
        virtual ~SimSmsParamHandler();

        void Reset();
        void Refresh();

        BOOLEAN RefreshData(INT );

        BOOLEAN GetAlphaIdLength(INT & length);

        BOOLEAN GetSmsParameter(INT recno, SimSmsParameter::Record & record);
        BOOLEAN SetSmsParameter(INT recno, const SimSmsParameter::Record & record);

        BOOLEAN RetrieveSmsServiceParameter();
        BOOLEAN RetrieveUsimSmsServiceParameter();
        BOOLEAN UpdateSmsServiceParameter(INT recno, BOOLEAN deleterecord = FALSE);

        INT     GetMaxSmspCount() const { return m_smsp_entries; }

    private:
        void  Clear();

        SmsParameterArray m_entries;

        BOOLEAN     m_smsp_isupdated;
        UINT8       m_smsp_alpha_len;
        UINT8       m_smsp_entries;
        UINT8       m_smsp_rec_len;

        UINT8 m_rw_buffer[c_smsp_rw_buffer_len];
};

#endif


