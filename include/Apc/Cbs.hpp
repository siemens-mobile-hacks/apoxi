/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Cbs_hpp)
#define Apc_Cbs_hpp

#include <Kernel/Os/Os.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/BitField.hpp>
#include <Auxiliary/ElementList.hpp>

#include <Apc/DataCodingScheme.hpp>
#include <Apc/MessageIdentifier.hpp>

#include <Apc/SignalTypes.hpp>

#if ! defined(APOXI_CBS_DEFAULT_SLEEP_TIMER)
    const INT c_cbs_default_sleep_timer = 0;
#else
    const INT c_cbs_default_sleep_timer = APOXI_CBS_DEFAULT_SLEEP_TIMER;
#endif

#if ! defined(APOXI_CBS_DEFAULT_ACTIVE_TIMER)
    const INT c_cbs_default_active_timer = 0;
#else
    const INT c_cbs_default_active_timer = APOXI_CBS_DEFAULT_ACTIVE_TIMER;
#endif


/*  ========================================================================
    Cbs: Cell Broadcast Service - 3GPP TS 23.041 V4.1.0 [9.4]
    ======================================================================== */
class Cbs {
    public:

        /*  ========================================================================
            Serial Number - 3GPP TS 23.041 V4.1.0 [9.4.1.2.1]
            ======================================================================== */
        class SerialNumber {
            public:
                enum GeographicalScope {
                    CellWideImmediate,
                    PlmnWideNormal,
                    LocationAreaWideNormal,
                    CellWideNormal,
                    InvalidScope
                };

                SerialNumber();
                SerialNumber(UINT16 incoming_word);

                UINT16 Get() const { return (m_bit_field.Get()); }

                GeographicalScope GetGeographicalScope() const;
                void SetGeographicalScope(GeographicalScope geographical_scope);

                UINT16 GetMessageCode() const;
                void SetMessageCode(UINT16 serial_number);

                BOOLEAN IsIndex() const;

                UINT8 GetUpdateNumber() const;
                void SetUpdateNumber(UINT8 update_number);

                void Clear() { m_bit_field.Clear(); }

            private:
                BitField16 m_bit_field;
        };

        class Filter {
            public:
                enum Mode {
                    Normal = 0, 
                    Inverted = 1,
                };
            
                enum {
                    c_max_stack_no_of_message_identifiers = MN_MAX_CB_MSG_ID_LIST_LENGTH,
                    c_max_stack_no_of_data_coding_schemes = MN_MAX_CB_DCS_LIST_LENGTH,
                    c_max_apoxi_no_of_message_identifiers = MessageIdentifierContainer::c_max_apoxi_no_of_message_identifiers
                };

                Filter();
                Filter(const Filter & filter);
                Filter(BOOLEAN ignore_duplicates, 
                       INT sleep_duration = c_cbs_default_sleep_timer,
                       UINT8 no_of_pages = MAX_SMS_CB_MAX_NBR_PAGES,//c_maximum_no_of_pages, 
                       BOOLEAN dcs_list_filter_enabled = TRUE,
                       BOOLEAN mid_list_filter_enabled = TRUE, 
                       Mode mode = Normal,
                       INT wake_duration = c_cbs_default_active_timer);
                ~Filter();
                Filter& operator =(const Filter &filter);

                Mode GetMode() const { return (m_mode); }
                void SetMode(Mode mode) { m_mode = mode; }

                BOOLEAN Optimize();

                BOOLEAN MakeModeNormal();

                BOOLEAN IsDcsListFilterEnabled() const { return (m_dcs_list_filter_enabled); }
                void EnableDcsListFilter(BOOLEAN dcs_list_filter_enabled = TRUE) { m_dcs_list_filter_enabled = dcs_list_filter_enabled; } 

                BOOLEAN IsMidListFilterEnabled() const { return (m_mid_list_filter_enabled); }
                void EnableMidListFilter(BOOLEAN mid_list_filter_enabled = TRUE) { m_mid_list_filter_enabled = mid_list_filter_enabled; }

                UINT8 GetNoOfPages() const { return (m_no_of_pages); }
                void SetNoOfPages(UINT8 no_of_pages) { m_no_of_pages = no_of_pages; }

                BOOLEAN IgnoreDuplicates() const { return (m_ignore_duplicates); }
                void IgnoreDuplicates(BOOLEAN ignore_duplicates) { m_ignore_duplicates = ignore_duplicates; }

                INT GetSleepDuration() const { return (m_sleep_duration); }
                void SetSleepDuration(INT sleep_duration) { m_sleep_duration = sleep_duration; }
                INT GetActiveDuration() const { return (m_active_duration); }
                void SetActiveDuration(INT active_duration) { m_active_duration = active_duration; }

                static void EnableGlobalSleepDuration(INT duration);
                static void DisableGlobalSleepDuration();
                static void EnableGlobalActiveDuration(INT duration);
                static void DisableGlobalActiveDuration();

                BOOLEAN Append(const MessageIdentifier &mid);
                BOOLEAN Append(const MessageIdentifierRange &mid_range);

                BOOLEAN Append(const DataCodingScheme &dcs);
                BOOLEAN Append(const DataCodingSchemeRange &dcs_range);
                BOOLEAN MergeDataCodingSchemeRanges(const Filter & filter);

                BOOLEAN Exists(const DataCodingScheme &dcs) const;
                BOOLEAN Exists(const DataCodingSchemeRange &dcs_range) const;

                BOOLEAN Exists(const MessageIdentifier &mid) const;
                BOOLEAN Exists(const MessageIdentifierRange &mid_range) const;
                BOOLEAN MergeMessageIdentifierRanges(const Filter & filter);

                void Remove(const MessageIdentifier &mid);
                void Remove(const MessageIdentifierRange &mid_range);

                void Remove(const DataCodingScheme &dcs);
                void Remove(const DataCodingSchemeRange &dcs_range);

                static INT GetMaxNoOfMidRanges() { return (c_max_apoxi_no_of_message_identifiers); }
                static INT GetMaxNoOfDcsRanges() { return (c_max_stack_no_of_data_coding_schemes); }

                INT GetNoOfMidRanges() const { return (m_mid_range_list.GetSize()); }
                INT GetNoOfDcsRanges() const { return (m_dcs_range_list.GetSize()); }


                void ClearMessageIdentifierList();
                void ClearDataCodingSchemeList();

                void Convert2SdlFilter(T_MN_SMS_CB_START_REQ &sdl_filter) const;
                BOOLEAN IsMatching(const DataCodingScheme & dcs, const MessageIdentifier & mid) const;

                //
                void DbgOut() const;

                UINT8 GetNextLowDcs(UINT8 dcs);
                UINT8 GetNextHighDcs(UINT8 dcs);
                UINT16 GetNextLowMid(UINT16 mid);
                UINT16 GetNextHighMid(UINT16 mid);

            private:
                BOOLEAN m_ignore_duplicates;
                INT m_sleep_duration;
                INT m_active_duration;
                UINT8 m_no_of_pages;
                BOOLEAN m_dcs_list_filter_enabled;
                BOOLEAN m_mid_list_filter_enabled;
                Mode m_mode;

                MessageIdentifierContainer m_mid_range_list;
                ElementList<DataCodingSchemeRange> m_dcs_range_list;

                static INT m_global_sleep_duration;
                static INT m_global_active_duration;
                static BOOLEAN m_global_sleep_duration_activated;
                static BOOLEAN m_global_active_duration_activated;

        };

        Cbs();
        Cbs(const SerialNumber &serial_number, const MessageIdentifier &message_identifier = 0xffff, 
            const DataCodingScheme &dcs = DataCodingScheme(), INT length = 0, const UINT8 *data = 0);
        Cbs(const T_SMS_CB_MESSAGE &sdl_cbs);
        ~Cbs();
        Cbs(const Cbs &cbs);
        Cbs& operator =(const Cbs &cbs);

        const SerialNumber& GetSerialNumber() const { return (m_serial_number); }
        const MessageIdentifier& GetMessageIdentifier() const { return (m_message_identifier); }
        const DataCodingScheme& GetDataCodingScheme() const { return (m_dcs); }
        INT GetLength() const { return (m_length); }
        UINT8* GetData() const { return (m_data); }

        BOOLEAN IsIndex() const { return (GetSerialNumber().IsIndex()); };

        WString GetText() const;

        void GetBlobObject(BlobObject & object) const;

        INT GetMaxDataSize() const { return (sizeof(T_SMS_CB_MESSAGE_FIELD)); }

        static INT GetMaxPages() { return (c_maximum_no_of_pages); }

        INT ReallocateData(INT length);

        INT ResizeData(INT length);

        void CopyData(const UINT8 *data);

        void ClearData();

        void Clear();

    private:
        static const INT c_maximum_no_of_pages;

        SerialNumber m_serial_number;
        MessageIdentifier m_message_identifier;
        DataCodingScheme m_dcs;
        INT m_length;
        UINT8 *m_data;
        
        void SetDataBuffer(INT length, const UINT8 *data);

};

#endif  // Apc_Cbs_hpp


