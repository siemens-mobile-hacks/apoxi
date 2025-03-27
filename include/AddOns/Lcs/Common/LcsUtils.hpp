/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsUtils_hpp)
#define AddOns_Lcs_Common_LcsUtils_hpp

#include "LcsTypes.hpp"

struct LcsQos;

const UINT8 MAX_K_VALUE = 128;

struct UtcTime {
    INT16 m_year;
    INT16 m_month;
    INT16 m_day;
    INT16 m_hour;
    INT16 m_min;
    INT16 m_sec;
    INT16 m_milli_sec;
};

class LcsUtils
{
    public:

        ~LcsUtils();
        
        static LcsUtils* GetInstance();

        static void ReleaseInstance();

        void DecodeLatitude(UINT32 coded_latitude, SignedValue& actual_latitude) const;

        void DecodeLongitude(UINT32 coded_longitude, SignedValue& actual_longitude) const;

        void DecodeAltitude(SignedValue& actual_altitude) const;

        void FormQos(const LcsMmiQos& lcs_mmi_qos, LcsQos& lcs_qos) const;

        UINT8 EncodeUncertRadius(const UnsignedValue& uncert_radius) const;

        UnsignedValue DecodeUncertRadius(UINT8 k_value) const { return m_uncert_radius[k_value]; }

        UINT16 DecodeAngle(UINT8 angle) const { return ((angle << 1) + ((angle + 1) << 1)) >> 1; }

        UINT32 DecodeInnerRadius(UINT16 inner_radius) const { return 5 * inner_radius; }

        void DecodeUncertAltitude(UINT8 k_value, UnsignedValue& uncert_altitude) const;

        void DecodeLocEstimate(LocationEstimate& loc_estimate) const;

        INT32 Power(INT16 number, UINT8 exponent);

        void GpsToUtcTime(UINT16 gps_week, UINT32 gps_tow, UtcTime& utc_time);


    private:

        LcsUtils();

        void FillUncertRadiusMap();


    private:

        static LcsUtils* m_lcs_utils;

        UnsignedValue m_uncert_radius[MAX_K_VALUE];

}; // LcsUtils

#endif // AddOns_Lcs_Common_LcsUtils_hpp

