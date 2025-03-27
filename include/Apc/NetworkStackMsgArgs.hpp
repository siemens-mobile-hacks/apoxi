/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\Schwenkr_LeoR16\lnz_apoxi\Apoxi\Apc\NetworkArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_NetworkStackMsgArgs_hpp)
#define Apc_NetworkStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Auxiliary/DateTime.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class ConnectionIndArg
    ====================================================================== */

class ConnectionIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ConnectionIndArg();
        
        static const ConnectionIndArg& Cast(const StackMsgArgument& arg);
        void SetConnected(BOOLEAN connected) { m_connected = connected; }
        BOOLEAN IsConnected() const { return m_connected; }
        void SetEnciphered(BOOLEAN enciphered) { m_enciphered = enciphered; }
        BOOLEAN IsEnciphered() const { return m_enciphered; }
        
        enum  {
            ID = 2180
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ConnectionIndArg*) arg); }
        
        BOOLEAN m_connected;
        BOOLEAN m_enciphered;
        
    };

// Inline definitions
inline const ConnectionIndArg& ConnectionIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ConnectionIndArg!\n");
    return ((ConnectionIndArg &) arg);
}



/*  ======================================================================
    Class CellInfoIndArg
    ====================================================================== */

class CellInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CellInfoIndArg();
        
        static const CellInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetCellId(const CellId& cell_id) { m_cell_id = cell_id; }
        const CellId& GetCellId() const { return m_cell_id; }
        void SetLai(const Lai& lai) { m_lai = lai; }
        const Lai& GetLai() const { return m_lai; }
        void SetGprsAvailable(BOOLEAN gprs_available) { m_gprs_available = gprs_available; }
        BOOLEAN IsGprsAvailable() const { return m_gprs_available; }
        
        enum  {
            ID = 2181
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CellInfoIndArg*) arg); }
        
        CellId m_cell_id;
        Lai m_lai;
        BOOLEAN m_gprs_available;
        
    };

// Inline definitions
inline const CellInfoIndArg& CellInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CellInfoIndArg!\n");
    return ((CellInfoIndArg &) arg);
}



/*  ======================================================================
    Class MnInformationIndArg
    ====================================================================== */

class MnInformationIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MnInformationIndArg();
        
        static const MnInformationIndArg& Cast(const StackMsgArgument& arg);
        void SetGsmService(const GsmService& gsm_service) { m_gsm_service = gsm_service; }
        const GsmService& GetGsmService() const { return m_gsm_service; }
        void SetNetworkNameLong(const WString& network_name_long) { m_network_name_long = network_name_long; }
        const WString& GetNetworkNameLong() const { return m_network_name_long; }
        void SetNetworkNameShort(const WString& network_name_short) { m_network_name_short = network_name_short; }
        const WString& GetNetworkNameShort() const { return m_network_name_short; }
        void SetNetworkNameLongAddCi(BOOLEAN network_name_long_add_ci) { m_network_name_long_add_ci = network_name_long_add_ci; }
        BOOLEAN IsNetworkNameLongAddCi() const { return m_network_name_long_add_ci; }
        void SetNetworkNameShortAddCi(BOOLEAN network_name_short_add_ci) { m_network_name_short_add_ci = network_name_short_add_ci; }
        BOOLEAN IsNetworkNameShortAddCi() const { return m_network_name_short_add_ci; }
        void SetTimeZonePresent(BOOLEAN time_zone_present) { m_time_zone_present = time_zone_present; }
        BOOLEAN IsTimeZonePresent() const { return m_time_zone_present; }
        void SetDateTimePresent(BOOLEAN date_time_present) { m_date_time_present = date_time_present; }
        BOOLEAN IsDateTimePresent() const { return m_date_time_present; }
        void SetDaylightSavingTimePresent(BOOLEAN daylight_saving_time_present) { m_daylight_saving_time_present = daylight_saving_time_present; }
        BOOLEAN IsDaylightSavingTimePresent() const { return m_daylight_saving_time_present; }
        void SetTimeZone(INT time_zone) { m_time_zone = time_zone; }
        INT GetTimeZone() const { return m_time_zone; }
        void SetDaylightSavingTime(UINT8 daylight_saving_time) { m_daylight_saving_time = daylight_saving_time; }
        UINT8 GetDaylightSavingTime() const { return m_daylight_saving_time; }
        void SetDateTime(const DateTime& date_time) { m_date_time = date_time; }
        const DateTime& GetDateTime() const { return m_date_time; }
        void SetLsaIdentifierPresent(BOOLEAN lsa_identifier_present) { m_lsa_identifier_present = lsa_identifier_present; }
        BOOLEAN IsLsaIdentifierPresent() const { return m_lsa_identifier_present; }
        void SetLsaIdentifier(const LsaIdentifier& lsa_identifier) { m_lsa_identifier = lsa_identifier; }
        const LsaIdentifier& GetLsaIdentifier() const { return m_lsa_identifier; }
        
        enum  {
            ID = 2182
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MnInformationIndArg*) arg); }
        
        GsmService m_gsm_service;
        WString m_network_name_long;
        WString m_network_name_short;
        BOOLEAN m_network_name_long_add_ci;
        BOOLEAN m_network_name_short_add_ci;
        BOOLEAN m_time_zone_present;
        BOOLEAN m_date_time_present;
        BOOLEAN m_daylight_saving_time_present;
        INT m_time_zone;
        UINT8 m_daylight_saving_time;
        DateTime m_date_time;
        BOOLEAN m_lsa_identifier_present;
        LsaIdentifier m_lsa_identifier;
        
    };

// Inline definitions
inline const MnInformationIndArg& MnInformationIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MnInformationIndArg!\n");
    return ((MnInformationIndArg &) arg);
}



/*  ======================================================================
    Class TestparamReportArg
    ====================================================================== */

class TestparamReportArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        TestparamReportArg();
        
        static const TestparamReportArg& Cast(const StackMsgArgument& arg);
        void SetReport(const TestparamReport& report) { m_report = report; }
        const TestparamReport& GetReport() const { return m_report; }
        
        enum  {
            ID = 2183
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((TestparamReportArg*) arg); }
        
        TestparamReport m_report;
        
    };

// Inline definitions
inline const TestparamReportArg& TestparamReportArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to TestparamReportArg!\n");
    return ((TestparamReportArg &) arg);
}



/*  ======================================================================
    Class BandSelectionIndArg
    ====================================================================== */

class BandSelectionIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        BandSelectionIndArg();
        
        static const BandSelectionIndArg& Cast(const StackMsgArgument& arg);
        void SetConfirmed(BOOLEAN confirmed) { m_confirmed = confirmed; }
        BOOLEAN IsConfirmed() const { return m_confirmed; }
        
        enum  {
            ID = 2184
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BandSelectionIndArg*) arg); }
        
        BOOLEAN m_confirmed;
        
    };

// Inline definitions
inline const BandSelectionIndArg& BandSelectionIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BandSelectionIndArg!\n");
    return ((BandSelectionIndArg &) arg);
}



/*  ======================================================================
    Class HomezoneIndArg
    ====================================================================== */

class HomezoneIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        HomezoneIndArg();
        
        static const HomezoneIndArg& Cast(const StackMsgArgument& arg);
        void SetLineSelector(const LineSelector& line_selector) { m_line_selector = line_selector; }
        const LineSelector& GetLineSelector() const { return m_line_selector; }
        void SetIndicator(const HomezoneIndicator& indicator) { m_indicator = indicator; }
        const HomezoneIndicator& GetIndicator() const { return m_indicator; }
        void SetText(const HomezoneText& text) { m_text = text; }
        const HomezoneText& GetText() const { return m_text; }
        
        enum  {
            ID = 2185
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((HomezoneIndArg*) arg); }
        
        LineSelector m_line_selector;
        HomezoneIndicator m_indicator;
        HomezoneText m_text;
        
    };

// Inline definitions
inline const HomezoneIndArg& HomezoneIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to HomezoneIndArg!\n");
    return ((HomezoneIndArg &) arg);
}



/*  ======================================================================
    Class MnTriggerReqArg
    ====================================================================== */

class MnTriggerReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MnTriggerReqArg(BOOLEAN flip_open);
        MnTriggerReqArg();
        
        static const MnTriggerReqArg& Cast(const StackMsgArgument& arg);
        BOOLEAN IsFlipOpen() const { return m_flip_open; }
        
        enum  {
            ID = 2186
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MnTriggerReqArg*) arg); }
        
        BOOLEAN m_flip_open;
        
    };

// Inline definitions
inline const MnTriggerReqArg& MnTriggerReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MnTriggerReqArg!\n");
    return ((MnTriggerReqArg &) arg);
}



/*  ======================================================================
    Class MnNetworkSearchModeReqArg
    ====================================================================== */

class MnNetworkSearchModeReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        MnNetworkSearchModeReqArg(const NetworkSearchMode& network_search_mode);
        MnNetworkSearchModeReqArg();
        
        static const MnNetworkSearchModeReqArg& Cast(const StackMsgArgument& arg);
        const NetworkSearchMode& GetNetworkSearchMode() const { return m_network_search_mode; }
        
        enum  {
            ID = 2187
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MnNetworkSearchModeReqArg*) arg); }
        
        NetworkSearchMode m_network_search_mode;
        
    };

// Inline definitions
inline const MnNetworkSearchModeReqArg& MnNetworkSearchModeReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MnNetworkSearchModeReqArg!\n");
    return ((MnNetworkSearchModeReqArg &) arg);
}


#endif // Apc_NetworkStackMsgArgs_hpp

