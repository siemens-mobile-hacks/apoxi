/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_ValidityPeriod_hpp)
#define Apc_ValidityPeriod_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>
#include <Auxiliary/DateTime.hpp>
#include <Auxiliary/TimeSpan.hpp>


/*  ========================================================================
    CodedTimeStamp - (ServiceCentreTimeStamp) 3GPP 23.040 V5.1.0 [9.2.3.11]
    ======================================================================== */
class CodedTimeStamp {
    public:
        CodedTimeStamp();
        CodedTimeStamp(const UINT8 *data, BOOLEAN time_only = FALSE);

        DateTime GetAbsoluteDateTime() const;
        void SetAbsoluteDateTime(const DateTime &date_time);

        TimeSpan GetRelativeTime() const;
        void SetRelativeTime(const TimeSpan &time_span);

        INT GetTimeZone() const;
        void SetTimeZone(INT time_zone);

        void UpdateData(UINT8 *data) const;

    private:
        BOOLEAN m_time_only;
        UINT8 m_data[7];
};


/*  ========================================================================
    PackedTimePeriod - 3GPP 23.040 V5.1.0 [9.2.3.12.1]
    ======================================================================== */
class PackedTimePeriod {
    public:
        enum Unit {
            FiveMinutes = 5,
            HalfHourAfter12 = 30,
            Day = 1440,
            Week = 10080,
        };

        PackedTimePeriod(UINT8 code = 0);
        PackedTimePeriod(const TimeSpan &time_span);
        PackedTimePeriod(UINT8 times, Unit unit);

        UINT8 GetTimes() const { return (m_times); }
        Unit GetUnit() const { return (m_unit); }

        TimeSpan GetTimeSpan() const;
        UINT8 GetCode() const;

    private:
        UINT8   m_times;
        Unit    m_unit;
};


/*  ========================================================================
    ValidityPeriodFormat - 3GPP 23.040 V5.1.0 [9.2.3.3]
    ======================================================================== */
class ValidityPeriodFormat {
    public:
        enum Format { // do not change order 
            NotPresent = 0,
            Enhanced,
            Relative,
            Absolute

        };

        ValidityPeriodFormat();
        ValidityPeriodFormat(Format format);
        ValidityPeriodFormat(UINT8 bit_field);

        Format GetFormat() const;
        void SetFormat(Format format);

        void UpdateData(UINT8 *data) const;

    private:
        // bitmask for relevant data (00011000)
        static const UINT8 m_mask;
        // the format is stored within the bits 3 and 4 of one byte
        BitField8 m_bit_field;
};

/*  ========================================================================
    FunctionalityIndicator - 3GPP 23.040 V5.1.0 [9.2.3.12.3]
    ======================================================================== */
class FunctionalityIndicator {
    public:
        enum TimeFormat {   // do not change order
            Unspecified = 0,
            Packed,
            Seconds,
            Relative,
            ReservedTimeFormat,
        };

        FunctionalityIndicator();
        FunctionalityIndicator(UINT8 incoming_byte);

        UINT8 Get() const { return (m_bit_field.Get()); }

        BOOLEAN ExtensionExists() const { return (m_bit_field.GetBit(7)); }
        void SetExtensionExists(BOOLEAN flag) { m_bit_field.SetBit(7, flag); }

        BOOLEAN IsSingleShot() const { return (m_bit_field.GetBit(6)); }
        void SetSingleShot(BOOLEAN flag) { m_bit_field.SetBit(6, flag); }

        TimeFormat GetTimeFormat() const;
        void SetTimeFormat(TimeFormat time_format);

        void Clear() { m_bit_field.Clear(); }
        
    private:
        BitField8 m_bit_field;
};

/*  ========================================================================
    ValidityPeriod - 3GPP 23.040 V5.1.0 [9.2.3.12]
    ======================================================================== */
class ValidityPeriod {
    public:
        ValidityPeriod();
        ValidityPeriod(const ValidityPeriodFormat &format, const UINT8 *data);
        ValidityPeriod(UINT8 data);

        BOOLEAN IsInvalid() const;
        BOOLEAN IsPacked() const;
        BOOLEAN IsInSeconds() const;
        BOOLEAN IsRelative() const;
        BOOLEAN IsAbsolute() const;

        BOOLEAN IsSingleShot() const;

        PackedTimePeriod GetPackedTime() const;
        void SetPackedTime(const PackedTimePeriod &packed_time_period);

        UINT8 GetSeconds() const;
        void SetSeconds(UINT8 seconds);

        TimeSpan GetRelativeTime() const;
        void SetRelativeTime(const TimeSpan &time_span);

        DateTime GetAbsoluteTime() const;   
        INT GetTimeZone() const;    
        void SetAbsolutTime(const DateTime &date_time, INT time_zone = 0);

        UINT8 GetSize() const;
        void UpdateData(UINT8 *period_format_data, UINT8 *period_data) const;
        void UpdateData(UINT8 *period_data) const;

        ValidityPeriodFormat GetFormat() { return (m_format); }

    private:
        ValidityPeriodFormat m_format;
        UINT8 m_data[7];

        FunctionalityIndicator GetFunctionalityIndicator() const;
};



inline INT BcdByteToInt(UINT8 bcd) { return ((((INT)((bcd) & 0xf0) >> 4)) + (INT)((bcd) & 0x0f) * 10); };
inline UINT8 IntToBcdByte(INT val) { INT tmp = (val / 10) & 0x0f; return ((UINT8) (tmp | ((((val - tmp * 10) & 0x0f) << 4) & 0xf0))); };


#endif  // Apc_ValidityPeriod_hpp


