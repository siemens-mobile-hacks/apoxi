/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsTypes_hpp)
#define AddOns_Lcs_Common_LcsTypes_hpp

typedef BYTE TI_PD;

/*  ------------------------------------------------
    MT-LR Parameter Declarations
    ------------------------------------------------*/

enum LocationType
{
    CurrentLocation = MTLR_CURRENT_LOCATION,
    CurrentOrLastKnownLocation = MTLR_CURRENT_OR_LAST_KNOWN_LOCATION,
    InitialLocation = MTLR_INITIAL_LOCATION
};

enum LcsNotificationType
{
    Notify = MTLR_NOTIFY,
    VerifyLocAllowedNoResp = MTLR_VERIFY_LOC_ALLOWED_IF_NO_RSP,
    VerifyLocNotAllowedNoResp = MTLR_VERIFY_LOC_NOT_ALLOWED_IF_NO_RSP
};


/*  ----------------------------------------------------------
    MO-LR Response Parameter Declarations
    Note:   Few of the data-types are wider than needed for
            the purpose of alignment at 16-bit boundaries
    ----------------------------------------------------------  */

struct UnsignedValue
{
    void operator *=(const UnsignedValue& rhs)
    {
        m_mantissa *= rhs.m_mantissa;
        m_exponent += rhs.m_exponent;
    }

    BOOLEAN operator ==(const UnsignedValue& rhs) const
    {
        return (m_mantissa == rhs.m_mantissa);
    }

    BOOLEAN operator <(const UnsignedValue& rhs) const
    {
        return (m_mantissa < rhs.m_mantissa);
    }

    BOOLEAN operator >(const UnsignedValue& rhs) const
    {
        return (m_mantissa > rhs.m_mantissa);
    }

    UINT32  m_mantissa;

    UINT16  m_exponent;
};

struct SignedValue
{
    void operator *=(const SignedValue& rhs)
    {
        m_mantissa *= rhs.m_mantissa;
        m_exponent += rhs.m_exponent;
    }

    BOOLEAN operator ==(const SignedValue& rhs) const
    {
        return (m_mantissa == rhs.m_mantissa);
    }

    BOOLEAN operator <(const SignedValue& rhs) const
    {
        return (m_mantissa < rhs.m_mantissa);
    }

    BOOLEAN operator >(const SignedValue& rhs) const
    {
        return (m_mantissa > rhs.m_mantissa);
    }

    SignedValue& operator -()
    {
        m_mantissa = -m_mantissa;
        return *this;
    }

    INT32   m_mantissa;

    UINT16  m_exponent;
};

struct LcsPoint
{
    SignedValue m_latitude;

    SignedValue m_longitude;
};

struct LcsPointUncertCircle
{
    LcsPoint m_point;

    UnsignedValue   m_uncert_radius;
};

struct LcsPointUncertEllipse
{
    LcsPoint        m_point;
    UnsignedValue   m_semi_major_axis;
    UnsignedValue   m_semi_minor_axis;
    UINT16          m_orientation_angle;
    UINT16          m_confidence; // UINT8 is sufficient!
};

struct LcsPointAltitudeUncertEllipsoid
{
    LcsPoint        m_point;
    SignedValue     m_altitude;
    UnsignedValue   m_semi_major_axis;
    UnsignedValue   m_semi_minor_axis;
    UINT16          m_orientation_angle;
    UnsignedValue   m_uncert_altitude;
    UINT16          m_confidence; // UINT8 is sufficient!
};

struct LcsArc
{
    LcsPoint        m_point;
    UINT32          m_inner_radius;
    UnsignedValue   m_uncert_radius;
    UINT16          m_offset_angle;
    UINT16          m_included_angle;
    UINT16          m_confidence; // UINT8 is sufficient!
};

struct SatelliteInfo
{
    SatelliteInfo() : m_tracked(0), m_sat_id(0), m_elevation(0), m_azimuth(0), m_snr(0),
                    m_sig_strength(0), m_int_time(0)
    {
    }

    UINT8   m_tracked;
    UINT8   m_sat_id;
    INT16   m_elevation;
    INT16   m_azimuth;
    INT16   m_snr;
    INT16   m_sig_strength; 
    UINT32  m_int_time;
};

const UINT8 MAX_SATS = 14;
struct GpsFixData
{
    UINT16          m_gps_week;
    UINT32          m_gps_tow;
    UINT16          m_microsec;
    UINT8           m_speed_valid;
    UnsignedValue   m_speed;
    UnsignedValue   m_hdop;
    UINT32          m_time_tag_delta;
    UnsignedValue   m_loc_error;
    UINT8           m_num_sats;
    SatelliteInfo   m_sat_info[MAX_SATS];
};

enum LcsShapeType
{
    LST_PointUncertCircle,
    LST_PointUncertEllipse,
    LST_PointAltitudeUncertEllipsoid,
    LST_Arc,
    LST_Point,
    LST_NoLocation
};

struct LocationEstimate
{
    LocationEstimate() : m_lst(LST_NoLocation)
    {
    }
    
    LcsShapeType m_lst;
    union
    {
        LcsPointUncertCircle                m_pt_uncert_circle;
        LcsPointUncertEllipse               m_pt_uncert_ellipse;
        LcsPointAltitudeUncertEllipsoid     m_pt_alt_ellipsoid;
        LcsArc                              m_pt_arc;
        LcsPoint                            m_point;
    };
    GpsFixData m_fix_data;
};

class LastLocationEstimate : public LocationEstimate
{
    typedef LocationEstimate Base;

    public:

        void operator =(const LocationEstimate& loc_est)
        {
            Base::operator =(loc_est);
            m_time_stamp = DateTime();
        }


    public:

        DateTime m_time_stamp;

}; // LastLocationEstimate


/*  ------------------------------------------------
    Declarations related to application inputs
    ------------------------------------------------*/

enum MolrType
{
    location_estimate   = LOCATION_ESTIMATE,
    assistance_data     = MN_ASSISTANCE_DATA,
    stand_alone         = MN_STAND_ALONE
};

enum LcsCost
{
    None = 0,
    Low = 1,
    High = 2
};

enum LcsTransportType
{
    GPP = 0,
    WAP = 1,
    GLTP = 2,
    STAND_ALONE = 3,
    MAX_TRANSPORTS = 4
};

enum RespTimeCategory
{
    lcs_low_delay = LCS_LOW_DELAY,
    lcs_delay_tolerant = LCS_DELAY_TOLERANT
};

struct LcsMmiQos
{
    LcsMmiQos()
    {
        m_horiz_accuracy.m_mantissa = 5000; m_horiz_accuracy.m_exponent = 2;
        m_vert_accuracy.m_mantissa = 5000; m_vert_accuracy.m_exponent = 2;
        m_rsp_time_cat = lcs_low_delay;
    }

    UnsignedValue       m_horiz_accuracy;

    UnsignedValue       m_vert_accuracy;

    RespTimeCategory    m_rsp_time_cat;
};

typedef BYTE Dcs;

struct ClientId
{
    ClientId()
    {
        memset(m_client_id, 0, MAX_SIZE);
    }

    BOOLEAN IsValid()
    {
        for(INT idx = 0; idx < MAX_SIZE; ++idx)
            if(m_client_id[idx] != 0)
                return TRUE;
        return FALSE;
    }

    void ConvertToStr(String& client_id_str) const
    {
        // Client Id format:
        // m_client_id[0] = n - Size of client id
        // m_client_id[1] to m_client_id[n] - Client Id in BCD format
        // where each nibble is a binary-coded decimal digit
        
        // Masks to extract the 2 nibbles of every byte
        const BYTE c_lower_nibble = 0x0F;
        const BYTE c_upper_nibble = 0xF0;

        // Convert each nibble to a character in order to form the string
        BYTE val = 0;
        for(UINT16 idx = 1; idx <= m_client_id[0]; idx++) 
        {
            // Extract the upper nibble of the byte
            val = m_client_id[idx] & c_upper_nibble;
            val = val >> 4;
            client_id_str << val;

            // Extract the lower nibble of the byte
            client_id_str << (m_client_id[idx] & c_lower_nibble);
        }
    }

    enum { MAX_SIZE = 23 };

    BYTE m_client_id[MAX_SIZE];
};

struct ClientName
{
    ClientName()
    {
    }

    ClientName(const BYTE* client_name, Dcs dcs)
    {
        // The received client name is encoded in 7-bit format and
        // packed using USSD packing as per the GSM 03.38 spec Sec 6.
        const BYTE c_dcs = 0x0F;
        if(dcs != c_dcs)
            return;

        // mask
        const BYTE c_value_mask_ref = 0x7F;
        const BYTE c_carry_mask_ref = 0x80;

        BYTE value_mask = c_value_mask_ref;
        BYTE carry_mask = c_carry_mask_ref;
        BYTE carry_val = 0;
        BYTE temp_val = 0;
        UINT16 shift_idx = 0;

        for(UINT16 idx = 0; client_name[idx] != '\0'; idx++)
        {
            shift_idx = idx % 7;

            temp_val = client_name[idx] & value_mask;
            temp_val = temp_val << shift_idx;
            temp_val = temp_val | carry_val;

            // Append the value in the string
            m_client_name.Insert((m_client_name.GetLength() + 1), temp_val);

            // Update the carry value from this byte
            carry_val = (client_name[idx] & carry_mask) >> (7 - shift_idx); 

            // Update the value of value mask and carry mask
            value_mask = value_mask >> 1;
            carry_mask = carry_mask | (carry_mask >> 1);

            if((shift_idx == 0) && (idx != 0))
            {
                temp_val = client_name[idx] & 0xFE;
                temp_val = temp_val >> 1;

                // Append the value in the string
                m_client_name.Insert((m_client_name.GetLength() + 1), temp_val);

                value_mask = c_value_mask_ref;
                carry_mask = c_carry_mask_ref;
            }
        }

    } // Argument Constructor

    enum { MAX_SIZE = 63 };

    String m_client_name;
};

struct ClientInfo
{
    ClientInfo()
    {
    }

    ClientInfo(const ClientId& client_id, const ClientName& client_name) :
                m_client_id(client_id), m_client_name(client_name)
    {
    }

    ClientId    m_client_id;

    ClientName  m_client_name;
};

struct MlcNumber
{
    MlcNumber()
    {
        memset(m_mlc_number, 0, MAX_SIZE);
    }

    enum { MAX_SIZE = 10 };

    BYTE m_mlc_number[MAX_SIZE];
};

enum LcsErrorCode
{
    /*****      GSM 04.80, Annex A      *****/
    LcsSystemFailure,

    LcsUnexpectedDataValue,

    LcsDataMissing,

    LcsFacilityNotSupported,

    LcsSsSubscriptionViolation,

    LcsPosMethodFailure,
    
    /*****      Lcs-defined errors      *****/

    LcsNoError,

    LcsTimeOut,

    LcsInternalError,

    LcsProviderNotAvailable,

    LcsInvalidInvokation,

    /*****      GLTP-specific errors    *****/

    LcsGltpConnSetupFailure,

    LcsGltpTimeOut,

    LcsGltpSendFailure,

    LcsGltpInvalidData,

    LcsGltpMolrInProgress
};

enum UartBaudRate {
    Ubd2400 = 2400,
    Ubd4800 = 4800,
    Ubd9600 = 9600,
    Ubd19200 = 19200,
    Ubd38400 = 38400,
    Ubd57600 = 57600,
    Ubd115200 = 115200,
    Ubd230400 = 230400,
    Ubd460800 = 460800,
    Ubd921600 = 921600
};

enum UartDataBits {
    #ifdef APOXI_RTOS_WIN32
        UdbFive = 0x00, // Same as CS5
        UdbSix = 0x04, // Same as CS6
        UdbSeven = 0x08, // Same as CS7
        UdbEight = 0x0c // Same as CS8
    #else
        UdbFive = CS5,
        UdbSix = CS6,
        UdbSeven = CS7,
        UdbEight = CS8
    #endif
};

enum UartParity {
    ParityNone = 0,
    ParityEven = PARENB,
    ParityOdd = PARODD  
};

enum UartStopBits {
    OneStopBit = 0,
    TwoStopBits = STOPB
};

enum UartFlowControl {
    UfcXonXoff = SIO_FCTL_SW,
    UfcHardware = SIO_FCTL_HW,
    UfcNone = SIO_FCTL_OFF
};

struct NmeaUartSettings
{
    NmeaUartSettings() {
        m_baud_rate = Ubd115200;
        m_data_bits = UdbEight;
        m_parity = ParityNone;
        m_stop_bits = OneStopBit;
        m_flow_control = UfcHardware;
    }

    UartBaudRate m_baud_rate;
    UartDataBits m_data_bits;
    UartParity m_parity;
    UartStopBits m_stop_bits;
    UartFlowControl m_flow_control;
};

#endif // AddOns_Lcs_Common_LcsTypes_hpp

