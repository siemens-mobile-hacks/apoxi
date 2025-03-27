/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_GLTP_GltpTypes_hpp)
#define AddOns_Lcs_GLTP_GltpTypes_hpp

#include <AddOns/Lcs/Common/LcsTypes.hpp>

struct ReferenceTime
{
    ReferenceTime() : m_gps_week(0), m_gps_tow(0), m_precision(0)
    {
    }

    ReferenceTime(UINT16 gps_week, UINT32 gps_tow, UINT32 precision) : 
                m_gps_week(gps_week), m_gps_tow(gps_tow), m_precision(precision)
    {       
    }

    ReferenceTime(const ReferenceTime& rhs)
    {
        m_gps_week = rhs.m_gps_week;
        m_gps_tow = rhs.m_gps_tow;
        m_precision = rhs.m_precision;
    }
    
    UINT16 m_gps_week;
    UINT32 m_gps_tow;
    UINT32 m_precision;
};

struct ReferenceLocation
{
    enum { InvalidValue = 0xFFFFFFFF };

    ReferenceLocation() : m_altitude(InvalidValue)
    {
        const INT32 INIT_LAT = 49429090;
        m_latitude = INIT_LAT;
        const INT32 INIT_LONG = 11017610;
        m_longitude = INIT_LONG;
    }

    ReferenceLocation(INT32 latitude, INT32 longitude, INT32 altitude = InvalidValue) :
                    m_latitude(latitude), m_longitude(longitude), m_altitude(altitude)
    {
    }

    ReferenceLocation(const ReferenceLocation& rhs)
    {
        m_latitude = rhs.m_latitude;
        m_longitude = rhs.m_longitude;
        m_altitude = rhs.m_altitude;
    }
    
    INT32 m_latitude;
    INT32 m_longitude;
    INT32 m_altitude;
};

class AidingData
{
    public:
        
        AidingData(INT length, const BYTE* aid_data)
        {
            m_aid_data.length = (SdlInteger) length;
            m_aid_data.apdu_ptr = (T_APDU_DATA_PTR) aid_data;
        }

        ~AidingData() { }

        const T_BYTE_STR& GetAidingData() const { return m_aid_data; }


    private:

        AidingData();


    private:

        T_BYTE_STR m_aid_data;

}; // AidingData

struct GpsFixDataInt
{
    UINT16          m_gps_week;
    UINT32          m_gps_tow;
    UINT16          m_microsec;
    UINT8           m_speed_valid;
    UINT32          m_speed;
    UINT32          m_hdop;
    UINT32          m_time_tag_delta;
    UINT32          m_loc_error;
    UINT8           m_num_sats;
    SatelliteInfo   m_sat_info[MAX_SATS];

    void Convert(GpsFixData& fix_data) const
    {
        fix_data.m_gps_week = m_gps_week;
        fix_data.m_gps_tow = m_gps_tow;
        fix_data.m_microsec = m_microsec;
        fix_data.m_speed_valid = m_speed_valid;
        fix_data.m_speed.m_mantissa = m_speed;
        const UINT16 c_exponent = 3; // As defined within Lcs stack
        if(m_speed > 0)
        {
            // Set the exponent to the hard-coded value
            fix_data.m_speed.m_exponent = c_exponent;
            
            // Convert the speed from knots to m/sec: 1 knot = 0.5144444444444 m/sec
            UnsignedValue conv_factor;
            conv_factor.m_mantissa = 5144; conv_factor.m_exponent = 4;
            fix_data.m_speed *= conv_factor;
        }
        else
        {
            fix_data.m_speed.m_exponent = 0;
        }
        fix_data.m_hdop.m_mantissa = m_hdop;
        fix_data.m_hdop.m_exponent = (m_hdop != 0) ? c_exponent : 0;
        fix_data.m_time_tag_delta = m_time_tag_delta;
        fix_data.m_loc_error.m_mantissa = m_loc_error;
        fix_data.m_loc_error.m_exponent = (m_loc_error != 0) ? c_exponent : 0;
        fix_data.m_num_sats = m_num_sats;
        memcpy(&fix_data.m_sat_info[0], &m_sat_info[0], sizeof(m_sat_info));
    }

}; // GpsFixDataInt

class MeasurementData
{
    public:

        MeasurementData() : m_status(0), m_length(0), m_msr_data(NULL)
        {
        }

        MeasurementData(UINT8 status, INT size, const BYTE* buffer, const GpsFixDataInt& fix_data_int)
            : m_status(status)
        {
            SetMsrData(size, buffer);
            fix_data_int.Convert(m_fix_data);
        }

        MeasurementData(const MeasurementData& rhs)
        {
            if(&rhs != this)
            {
                SetMsrData(rhs.m_length, rhs.m_msr_data);
                m_status = rhs.m_status;
                m_fix_data = rhs.m_fix_data;
            }
        }

        ~MeasurementData()
        {
            delete [] m_msr_data;
        }

        UINT32 GetStatus() const { return m_status; }

        INT GetLength() const { return m_length; }

        BYTE* GetMsrData() const { return m_msr_data; }

        const GpsFixData& GetGpsFixData() const { return m_fix_data; }

        
    private:

        void SetMsrData(INT size, const BYTE* buffer)
        {
            m_length = size;
            if(buffer == NULL)
            {
                m_msr_data = NULL;
                return;
            }
            ASSERT_DEBUG(size > 0);
            m_msr_data = new BYTE[size];
            memcpy(m_msr_data, buffer, size);
        }

        
    private:

        UINT8 m_status;

        INT m_length;

        BYTE* m_msr_data;

        GpsFixData m_fix_data;

}; // MeasurementData

enum GltpConnStatus
{
    PositionDataReceived = 0,
    MeasurementDataSent,
    AidingAckReceived,
    HelloAckRxed,
    ConnectionReqSent,
    ConnectionError

}; // GltpConnStatus

#endif // AddOns_Lcs_GLTP_GltpTypes_hpp

