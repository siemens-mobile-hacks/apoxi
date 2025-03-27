/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_GLTP_AssistanceData_hpp)
#define AddOns_Lcs_GLTP_AssistanceData_hpp

#include "GltpTypes.hpp"

class GltpAssistanceData
{
    public:

        GltpAssistanceData();

        ~GltpAssistanceData();

        BOOLEAN Append(const BYTE* ad_buf, INT size);

        const BYTE* GetBuffer() const { return m_ad_buf; }

        INT GetSize() const { return m_buf_pos; }

        void SetReferenceTime(const ReferenceTime& ref_time) { m_ref_time = ref_time; }

        const ReferenceTime& GetReferenceTime() const { return m_ref_time; }

        void SetReferenceLocation(const ReferenceLocation& ref_loc) { m_ref_loc = ref_loc; }

        const ReferenceLocation& GetReferenceLocation() const { return m_ref_loc; }

        BOOLEAN IsAidingStale() const { return m_is_stale; }

        void SetAidingStale(BOOLEAN stale) { m_is_stale = stale; }


    private:

        const BYTE* ValidateHeader(const BYTE* ad_buf, INT& size);


    private:

        enum
        {
            ASSIST_DATA_SIZE = 2400
        };

        BYTE m_ad_buf[ASSIST_DATA_SIZE];

        INT m_buf_pos;

        UINT8 m_total_packets;

        UINT8 m_packet_count;

        ReferenceTime m_ref_time;

        ReferenceLocation m_ref_loc;

        BOOLEAN m_is_stale;

}; // GltpAssistanceData

#endif // AddOns_Lcs_GLTP_AssistanceData_hpp

