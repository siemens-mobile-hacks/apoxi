/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CsdDataConnProfile_hpp)
#define Apoxi_CsdDataConnProfile_hpp

#include <Socket/DataConnProfile.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Asc/DataCallContext.hpp>

class CsdDataConnProfile : public DataConnProfile
{
    typedef DataConnProfile Base;

    public:
        enum CallType {
            c_isdn = 0, 
            c_analog = 1
        };

        enum DataRate {
            c_data_rate_2400 = 1, 
            c_data_rate_4800 = 2, 
            c_data_rate_9600 = 4, 
            c_data_rate_14400 = 6, 
            c_data_rate_19200 = 8, 
            c_data_rate_28800 = 12
        };

        struct Bit {
            UINT m_call_type    :  1;
            UINT m_data_rate    :  4;
        };

    public:
        CsdDataConnProfile();
        virtual ~CsdDataConnProfile();

        CallType GetCallType() const 
            { return (CallType)m_bit.m_call_type; }

        void SetCallType(CallType ct) 
            { m_bit.m_call_type = ct; }

        DataRate GetDataRate() const 
            { return (DataRate)m_bit.m_data_rate; }

        void SetDataRate(DataRate dr) 
            { m_bit.m_data_rate = dr; }

        UINT32 GetDataBaudRate() const 
            { return ((UINT32)m_bit.m_data_rate) * 2400UL; }

        const PhoneNumber& GetPhoneNumber() const 
            { return m_phone_no; }

        void SetPhoneNumber(const PhoneNumber &pn) 
            { m_phone_no = pn; }

        const DataCallContext& GetDataCallContext() const
            { return m_context; }

        void SetDataCallContext(const DataCallContext &context)
            { m_context = context; }

    protected:
        virtual void SaveFrom(const PersistDataConnProfile &bpp);
        virtual void SaveTo(PersistDataConnProfile &bpp) const;

        virtual DataConnProfile* New() const;

        virtual void Assign(const DataConnProfile& from_dcp);

    private:
        Bit m_bit;
        PhoneNumber m_phone_no;
        DataCallContext m_context;

    public:
        struct Persist {
            UINT8 m_phone_no[c_max_bcd_number_size]; 
            Bit m_bit;
        };
};

#endif  // Apoxi_CsdDataConnProfile_hpp


