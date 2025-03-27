/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TimeZone_hpp)
#define Apoxi_TimeZone_hpp

#include <Auxiliary/WString.hpp>

class TimeZone {
    public:
        enum {
            InvalidOffset = 0xffff
        };

        enum DstIndication {
            StandardTime = 0,
            Plus1Hour = 1,
            Plus2Hours = 2,
            InvalidDst = 3
        };//DstIndication

        TimeZone();
        TimeZone(INT offset, DstIndication dst_ind) :
            m_offset(((offset >= -48) && (offset <= 51)) ? offset : InvalidOffset),
            m_dst_ind((dst_ind <= 2) ? dst_ind:InvalidDst) {}

        TimeZone(const TimeZone &tz);
        ~TimeZone() {}

        BOOLEAN IsOffsetInvalid() const { return m_offset == InvalidOffset; }
        BOOLEAN IsDstIndInvalid() const { return m_dst_ind == InvalidDst; }
        void SetOffset(INT offset) { m_offset = ((offset >= -48) && (offset <= 51)) ? offset : InvalidOffset; }
        INT  GetOffset() const { return m_offset; }
        void SetDstInd(DstIndication dst_ind) { m_dst_ind = ((dst_ind <= 2)) ? dst_ind : InvalidDst; }
        DstIndication GetDstInd() const { return m_dst_ind; }
        void SetTimeZone(const TimeZone &tz);

        WString Format(const WCHAR* wchr_format= L"GMT: %o DST: %d",
                       const WCHAR* wchr_invalid_offset= L"n/a",
                       const WCHAR* wchr_invalid_dst= L"n/a") const;
        BOOLEAN operator==(const TimeZone &tz) const { return (m_offset == tz.m_offset && m_dst_ind == tz.m_dst_ind); }
        BOOLEAN operator!=(const TimeZone &tz) const { return ! operator==(tz); }

    private:
         INT m_offset;

         DstIndication m_dst_ind;

};//class TimeZone

#endif


