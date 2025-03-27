/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\grossau_mp1ue_sv\lnz_apoxi\Apoxi\Apc\PhoneBookArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_PhoneBookStackMsgArgs_hpp)
#define Apc_PhoneBookStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/UsimPbTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class PbInfoReadIndArg
    ====================================================================== */

class PbInfoReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbInfoReadIndArg();
        
        static const PbInfoReadIndArg& Cast(const StackMsgArgument& arg);
        void SetInfo(const PhoneBookInfo& info) { m_info = info; }
        const PhoneBookInfo& GetInfo() const { return m_info; }
        
        enum  {
            ID = 1200
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbInfoReadIndArg*) arg); }
        
        PhoneBookInfo m_info;
        
    };

// Inline definitions
inline const PbInfoReadIndArg& PbInfoReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbInfoReadIndArg!\n");
    return ((PbInfoReadIndArg &) arg);
}



/*  ======================================================================
    Class PbEntryReadIndArg
    ====================================================================== */

class PbEntryReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbEntryReadIndArg();
        
        static const PbEntryReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetPbtype(const PhoneBookType& pbtype) { m_pbtype = pbtype; }
        const PhoneBookType& GetPbtype() const { return m_pbtype; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetAlphaLength(INT alpha_length) { m_alpha_length = alpha_length; }
        INT GetAlphaLength() const { return m_alpha_length; }
        void SetDataLength(INT data_length) { m_data_length = data_length; }
        INT GetDataLength() const { return m_data_length; }
        void SetEntry(const SimPhoneBookEntry& entry) { m_entry = entry; }
        const SimPhoneBookEntry& GetEntry() const { return m_entry; }
        
        enum  {
            ID = 1201
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbEntryReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        PhoneBookType m_pbtype;
        INT m_recno;
        INT m_alpha_length;
        INT m_data_length;
        SimPhoneBookEntry m_entry;
        
    };

// Inline definitions
inline const PbEntryReadIndArg& PbEntryReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbEntryReadIndArg!\n");
    return ((PbEntryReadIndArg &) arg);
}



/*  ======================================================================
    Class PbEntryUpdIndArg
    ====================================================================== */

class PbEntryUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbEntryUpdIndArg();
        
        static const PbEntryUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1202
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbEntryUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const PbEntryUpdIndArg& PbEntryUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbEntryUpdIndArg!\n");
    return ((PbEntryUpdIndArg &) arg);
}



/*  ======================================================================
    Class PbCountIndArg
    ====================================================================== */

class PbCountIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbCountIndArg();
        
        static const PbCountIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetPbCntType(const PhoneBookCntType& pb_cnt_type) { m_pb_cnt_type = pb_cnt_type; }
        const PhoneBookCntType& GetPbCntType() const { return m_pb_cnt_type; }
        void SetCount(UINT8 count) { m_count = count; }
        UINT8 GetCount() const { return m_count; }
        
        enum  {
            ID = 1203
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbCountIndArg*) arg); }
        
        SimUpdateStatus m_status;
        PhoneBookCntType m_pb_cnt_type;
        UINT8 m_count;
        
    };

// Inline definitions
inline const PbCountIndArg& PbCountIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbCountIndArg!\n");
    return ((PbCountIndArg &) arg);
}



/*  ======================================================================
    Class UsimPbLocationIndArg
    ====================================================================== */

class UsimPbLocationIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbLocationIndArg();
        
        static const UsimPbLocationIndArg& Cast(const StackMsgArgument& arg);
        void SetReport(const UsimPbLocReport& report) { m_report = report; }
        const UsimPbLocReport& GetReport() const { return m_report; }
        
        enum  {
            ID = 1210
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbLocationIndArg*) arg); }
        
        UsimPbLocReport m_report;
        
    };

// Inline definitions
inline const UsimPbLocationIndArg& UsimPbLocationIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbLocationIndArg!\n");
    return ((UsimPbLocationIndArg &) arg);
}



/*  ======================================================================
    Class UsimPbSelectResArg
    ====================================================================== */

class UsimPbSelectResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbSelectResArg();
        
        static const UsimPbSelectResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetPbLocation(const UsimPbLocation& pb_location) { m_pb_location = pb_location; }
        const UsimPbLocation& GetPbLocation() const { return m_pb_location; }
        void SetPbDescriptor(const T_PB_DESCRIPTOR& pb_descriptor) { m_pb_descriptor = pb_descriptor; }
        const T_PB_DESCRIPTOR& GetPbDescriptor() const { return m_pb_descriptor; }
        
        enum  {
            ID = 1211
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbSelectResArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        UsimPbLocation m_pb_location;
        T_PB_DESCRIPTOR m_pb_descriptor;
        
    };

// Inline definitions
inline const UsimPbSelectResArg& UsimPbSelectResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbSelectResArg!\n");
    return ((UsimPbSelectResArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadResArg
    ====================================================================== */

class UsimPbReadResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadResArg();
        
        static const UsimPbReadResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetPbRwRecord(const UsimPbRwRecord& pb_rw_record) { m_pb_rw_record = pb_rw_record; }
        const UsimPbRwRecord& GetPbRwRecord() const { return m_pb_rw_record; }
        void SetPbRefRecord(const UsimPbRefRecord& pb_ref_record) { m_pb_ref_record = pb_ref_record; }
        const UsimPbRefRecord& GetPbRefRecord() const { return m_pb_ref_record; }
        
        enum  {
            ID = 1212
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadResArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        INT m_recno;
        UsimPbRwRecord m_pb_rw_record;
        UsimPbRefRecord m_pb_ref_record;
        
    };

// Inline definitions
inline const UsimPbReadResArg& UsimPbReadResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadResArg!\n");
    return ((UsimPbReadResArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadAsyncIndArg
    ====================================================================== */

class UsimPbReadAsyncIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadAsyncIndArg();
        
        static const UsimPbReadAsyncIndArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetPbRwRecord(const UsimPbRwRecord& pb_rw_record) { m_pb_rw_record = pb_rw_record; }
        const UsimPbRwRecord& GetPbRwRecord() const { return m_pb_rw_record; }
        void SetPbRefRecord(const UsimPbRefRecord& pb_ref_record) { m_pb_ref_record = pb_ref_record; }
        const UsimPbRefRecord& GetPbRefRecord() const { return m_pb_ref_record; }
        
        enum  {
            ID = 1213
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadAsyncIndArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        INT m_recno;
        UsimPbRwRecord m_pb_rw_record;
        UsimPbRefRecord m_pb_ref_record;
        
    };

// Inline definitions
inline const UsimPbReadAsyncIndArg& UsimPbReadAsyncIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadAsyncIndArg!\n");
    return ((UsimPbReadAsyncIndArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadRefResArg
    ====================================================================== */

class UsimPbReadRefResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadRefResArg();
        
        static const UsimPbReadRefResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetPbRefType(const UsimPbRefType& pb_ref_type) { m_pb_ref_type = pb_ref_type; }
        const UsimPbRefType& GetPbRefType() const { return m_pb_ref_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetRefRecno(INT ref_recno) { m_ref_recno = ref_recno; }
        INT GetRefRecno() const { return m_ref_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 1214
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadRefResArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        UsimPbRefType m_pb_ref_type;
        INT m_recno;
        INT m_ref_recno;
        INT m_handle;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbReadRefResArg& UsimPbReadRefResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadRefResArg!\n");
    return ((UsimPbReadRefResArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadRefAsyncIndArg
    ====================================================================== */

class UsimPbReadRefAsyncIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadRefAsyncIndArg();
        
        static const UsimPbReadRefAsyncIndArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetPbRefType(const UsimPbRefType& pb_ref_type) { m_pb_ref_type = pb_ref_type; }
        const UsimPbRefType& GetPbRefType() const { return m_pb_ref_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetRefRecno(INT ref_recno) { m_ref_recno = ref_recno; }
        INT GetRefRecno() const { return m_ref_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 1215
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadRefAsyncIndArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        UsimPbRefType m_pb_ref_type;
        INT m_recno;
        INT m_ref_recno;
        INT m_handle;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbReadRefAsyncIndArg& UsimPbReadRefAsyncIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadRefAsyncIndArg!\n");
    return ((UsimPbReadRefAsyncIndArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadDataResArg
    ====================================================================== */

class UsimPbReadDataResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadDataResArg();
        
        static const UsimPbReadDataResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetPbAddType(const UsimPbAddType& pb_add_type) { m_pb_add_type = pb_add_type; }
        const UsimPbAddType& GetPbAddType() const { return m_pb_add_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 1216
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadDataResArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        UsimPbAddType m_pb_add_type;
        INT m_recno;
        INT m_handle;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbReadDataResArg& UsimPbReadDataResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadDataResArg!\n");
    return ((UsimPbReadDataResArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadDataAsyncIndArg
    ====================================================================== */

class UsimPbReadDataAsyncIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadDataAsyncIndArg();
        
        static const UsimPbReadDataAsyncIndArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetPbAddType(const UsimPbAddType& pb_add_type) { m_pb_add_type = pb_add_type; }
        const UsimPbAddType& GetPbAddType() const { return m_pb_add_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 1217
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadDataAsyncIndArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        UsimPbAddType m_pb_add_type;
        INT m_recno;
        INT m_handle;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbReadDataAsyncIndArg& UsimPbReadDataAsyncIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadDataAsyncIndArg!\n");
    return ((UsimPbReadDataAsyncIndArg &) arg);
}



/*  ======================================================================
    Class UsimPbUpdResArg
    ====================================================================== */

class UsimPbUpdResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbUpdResArg();
        
        static const UsimPbUpdResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetUid(UINT16 uid) { m_uid = uid; }
        UINT16 GetUid() const { return m_uid; }
        
        enum  {
            ID = 1218
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbUpdResArg*) arg); }
        
        UsimPbResult m_pb_result;
        INT m_recno;
        UINT16 m_uid;
        
    };

// Inline definitions
inline const UsimPbUpdResArg& UsimPbUpdResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbUpdResArg!\n");
    return ((UsimPbUpdResArg &) arg);
}



/*  ======================================================================
    Class UsimPbUpdRefResArg
    ====================================================================== */

class UsimPbUpdRefResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbUpdRefResArg();
        
        static const UsimPbUpdRefResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbRefType(const UsimPbRefType& pb_ref_type) { m_pb_ref_type = pb_ref_type; }
        const UsimPbRefType& GetPbRefType() const { return m_pb_ref_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetRefRecno(INT ref_recno) { m_ref_recno = ref_recno; }
        INT GetRefRecno() const { return m_ref_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        
        enum  {
            ID = 1219
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbUpdRefResArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbRefType m_pb_ref_type;
        INT m_recno;
        INT m_ref_recno;
        INT m_handle;
        
    };

// Inline definitions
inline const UsimPbUpdRefResArg& UsimPbUpdRefResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbUpdRefResArg!\n");
    return ((UsimPbUpdRefResArg &) arg);
}



/*  ======================================================================
    Class UsimPbUpdDataResArg
    ====================================================================== */

class UsimPbUpdDataResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbUpdDataResArg();
        
        static const UsimPbUpdDataResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbAddType(const UsimPbAddType& pb_add_type) { m_pb_add_type = pb_add_type; }
        const UsimPbAddType& GetPbAddType() const { return m_pb_add_type; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        
        enum  {
            ID = 1220
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbUpdDataResArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbAddType m_pb_add_type;
        INT m_handle;
        INT m_recno;
        
    };

// Inline definitions
inline const UsimPbUpdDataResArg& UsimPbUpdDataResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbUpdDataResArg!\n");
    return ((UsimPbUpdDataResArg &) arg);
}



/*  ======================================================================
    Class UsimPbFillStatusResArg
    ====================================================================== */

class UsimPbFillStatusResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbFillStatusResArg();
        
        static const UsimPbFillStatusResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        void SetPbSignalType(const UsimPbSignalType& pb_signal_type) { m_pb_signal_type = pb_signal_type; }
        const UsimPbSignalType& GetPbSignalType() const { return m_pb_signal_type; }
        void SetPbFillStatus(const UsimPbFillStatus& pb_fill_status) { m_pb_fill_status = pb_fill_status; }
        const UsimPbFillStatus& GetPbFillStatus() const { return m_pb_fill_status; }
        
        enum  {
            ID = 1221
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbFillStatusResArg*) arg); }
        
        UsimPbResult m_pb_result;
        UsimPbSignalType m_pb_signal_type;
        UsimPbFillStatus m_pb_fill_status;
        
    };

// Inline definitions
inline const UsimPbFillStatusResArg& UsimPbFillStatusResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbFillStatusResArg!\n");
    return ((UsimPbFillStatusResArg &) arg);
}



/*  ======================================================================
    Class UsimPbStopResArg
    ====================================================================== */

class UsimPbStopResArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbStopResArg();
        
        static const UsimPbStopResArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        
        enum  {
            ID = 1222
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbStopResArg*) arg); }
        
        UsimPbResult m_pb_result;
        
    };

// Inline definitions
inline const UsimPbStopResArg& UsimPbStopResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbStopResArg!\n");
    return ((UsimPbStopResArg &) arg);
}



/*  ======================================================================
    Class UsimPbUidRefreshIndArg
    ====================================================================== */

class UsimPbUidRefreshIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbUidRefreshIndArg();
        
        static const UsimPbUidRefreshIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1223
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbUidRefreshIndArg*) arg); }
        
    };

// Inline definitions
inline const UsimPbUidRefreshIndArg& UsimPbUidRefreshIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbUidRefreshIndArg!\n");
    return ((UsimPbUidRefreshIndArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadyIndArg
    ====================================================================== */

class UsimPbReadyIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadyIndArg();
        
        static const UsimPbReadyIndArg& Cast(const StackMsgArgument& arg);
        void SetPbResult(const UsimPbResult& pb_result) { m_pb_result = pb_result; }
        const UsimPbResult& GetPbResult() const { return m_pb_result; }
        
        enum  {
            ID = 1224
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadyIndArg*) arg); }
        
        UsimPbResult m_pb_result;
        
    };

// Inline definitions
inline const UsimPbReadyIndArg& UsimPbReadyIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadyIndArg!\n");
    return ((UsimPbReadyIndArg &) arg);
}



/*  ======================================================================
    Class PbInfoReadReqArg
    ====================================================================== */

class PbInfoReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbInfoReadReqArg();
        
        static const PbInfoReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2200
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbInfoReadReqArg*) arg); }
        
    };

// Inline definitions
inline const PbInfoReadReqArg& PbInfoReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbInfoReadReqArg!\n");
    return ((PbInfoReadReqArg &) arg);
}



/*  ======================================================================
    Class PbEntryReadReqArg
    ====================================================================== */

class PbEntryReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbEntryReadReqArg(INT recno, const PhoneBookType& pbtype);
        PbEntryReadReqArg();
        
        static const PbEntryReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetPbtype(const PhoneBookType& pbtype) { m_pbtype = pbtype; }
        const PhoneBookType& GetPbtype() const { return m_pbtype; }
        
        enum  {
            ID = 2201
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbEntryReadReqArg*) arg); }
        
        INT m_recno;
        PhoneBookType m_pbtype;
        
    };

// Inline definitions
inline const PbEntryReadReqArg& PbEntryReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbEntryReadReqArg!\n");
    return ((PbEntryReadReqArg &) arg);
}



/*  ======================================================================
    Class PbEntryUpdReqArg
    ====================================================================== */

class PbEntryUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbEntryUpdReqArg(INT recno, const PhoneBookType& pbtype, INT length, const UINT8* pData);
        PbEntryUpdReqArg(INT recno, const PhoneBookType& pbtype, const T_DATA& data);
        PbEntryUpdReqArg();
        
        static const PbEntryUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetPbtype(const PhoneBookType& pbtype) { m_pbtype = pbtype; }
        const PhoneBookType& GetPbtype() const { return m_pbtype; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 2202
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbEntryUpdReqArg*) arg); }
        
        INT m_recno;
        PhoneBookType m_pbtype;
        T_DATA m_data;
        
    };

// Inline definitions
inline const PbEntryUpdReqArg& PbEntryUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbEntryUpdReqArg!\n");
    return ((PbEntryUpdReqArg &) arg);
}



/*  ======================================================================
    Class PbCountReqArg
    ====================================================================== */

class PbCountReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        PbCountReqArg(const PhoneBookCntType& pb_cnt_type);
        PbCountReqArg();
        
        static const PbCountReqArg& Cast(const StackMsgArgument& arg);
        void SetPbCntType(const PhoneBookCntType& pb_cnt_type) { m_pb_cnt_type = pb_cnt_type; }
        const PhoneBookCntType& GetPbCntType() const { return m_pb_cnt_type; }
        
        enum  {
            ID = 2203
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((PbCountReqArg*) arg); }
        
        PhoneBookCntType m_pb_cnt_type;
        
    };

// Inline definitions
inline const PbCountReqArg& PbCountReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to PbCountReqArg!\n");
    return ((PbCountReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbLocationReqArg
    ====================================================================== */

class UsimPbLocationReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbLocationReqArg();
        
        static const UsimPbLocationReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2210
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbLocationReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimPbLocationReqArg& UsimPbLocationReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbLocationReqArg!\n");
    return ((UsimPbLocationReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbSelectReqArg
    ====================================================================== */

class UsimPbSelectReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbSelectReqArg(const UsimPbLocation& pb_location, BOOLEAN cache_filling);
        UsimPbSelectReqArg();
        
        static const UsimPbSelectReqArg& Cast(const StackMsgArgument& arg);
        void SetPbLocation(const UsimPbLocation& pb_location) { m_pb_location = pb_location; }
        const UsimPbLocation& GetPbLocation() const { return m_pb_location; }
        void SetCacheFilling(BOOLEAN cache_filling) { m_cache_filling = cache_filling; }
        BOOLEAN IsCacheFilling() const { return m_cache_filling; }
        
        enum  {
            ID = 2211
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbSelectReqArg*) arg); }
        
        UsimPbLocation m_pb_location;
        BOOLEAN m_cache_filling;
        
    };

// Inline definitions
inline const UsimPbSelectReqArg& UsimPbSelectReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbSelectReqArg!\n");
    return ((UsimPbSelectReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadReqArg
    ====================================================================== */

class UsimPbReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadReqArg(INT recno, const UsimPbRwRecord& pb_rw_record);
        UsimPbReadReqArg();
        
        static const UsimPbReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetPbRwRecord(const UsimPbRwRecord& pb_rw_record) { m_pb_rw_record = pb_rw_record; }
        const UsimPbRwRecord& GetPbRwRecord() const { return m_pb_rw_record; }
        
        enum  {
            ID = 2212
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadReqArg*) arg); }
        
        INT m_recno;
        UsimPbRwRecord m_pb_rw_record;
        
    };

// Inline definitions
inline const UsimPbReadReqArg& UsimPbReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadReqArg!\n");
    return ((UsimPbReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadRefReqArg
    ====================================================================== */

class UsimPbReadRefReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadRefReqArg(const UsimPbRefType& pb_ref_type, INT recno, INT ref_recno, INT handle, const T_DATA& data);
        UsimPbReadRefReqArg();
        
        static const UsimPbReadRefReqArg& Cast(const StackMsgArgument& arg);
        void SetPbRefType(const UsimPbRefType& pb_ref_type) { m_pb_ref_type = pb_ref_type; }
        const UsimPbRefType& GetPbRefType() const { return m_pb_ref_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetRefRecno(INT ref_recno) { m_ref_recno = ref_recno; }
        INT GetRefRecno() const { return m_ref_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 2213
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadRefReqArg*) arg); }
        
        UsimPbRefType m_pb_ref_type;
        INT m_recno;
        INT m_ref_recno;
        INT m_handle;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbReadRefReqArg& UsimPbReadRefReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadRefReqArg!\n");
    return ((UsimPbReadRefReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadDataReqArg
    ====================================================================== */

class UsimPbReadDataReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadDataReqArg(const UsimPbAddType& pb_add_type, INT recno, INT handle, const T_DATA& data);
        UsimPbReadDataReqArg();
        
        static const UsimPbReadDataReqArg& Cast(const StackMsgArgument& arg);
        void SetPbAddType(const UsimPbAddType& pb_add_type) { m_pb_add_type = pb_add_type; }
        const UsimPbAddType& GetPbAddType() const { return m_pb_add_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 2214
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadDataReqArg*) arg); }
        
        UsimPbAddType m_pb_add_type;
        INT m_recno;
        INT m_handle;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbReadDataReqArg& UsimPbReadDataReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadDataReqArg!\n");
    return ((UsimPbReadDataReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbUpdReqArg
    ====================================================================== */

class UsimPbUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbUpdReqArg(INT recno, INT start_recno, const UsimPbChangedField& pb_changed_field, const UsimPbRwRecord& pb_rw_record);
        UsimPbUpdReqArg();
        
        static const UsimPbUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetStartRecno(INT start_recno) { m_start_recno = start_recno; }
        INT GetStartRecno() const { return m_start_recno; }
        void SetPbChangedField(const UsimPbChangedField& pb_changed_field) { m_pb_changed_field = pb_changed_field; }
        const UsimPbChangedField& GetPbChangedField() const { return m_pb_changed_field; }
        void SetPbRwRecord(const UsimPbRwRecord& pb_rw_record) { m_pb_rw_record = pb_rw_record; }
        const UsimPbRwRecord& GetPbRwRecord() const { return m_pb_rw_record; }
        
        enum  {
            ID = 2215
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbUpdReqArg*) arg); }
        
        INT m_recno;
        INT m_start_recno;
        UsimPbChangedField m_pb_changed_field;
        UsimPbRwRecord m_pb_rw_record;
        
    };

// Inline definitions
inline const UsimPbUpdReqArg& UsimPbUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbUpdReqArg!\n");
    return ((UsimPbUpdReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbUpdRefReqArg
    ====================================================================== */

class UsimPbUpdRefReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbUpdRefReqArg(const UsimPbRefType& pb_ref_type, INT recno, INT ref_recno, INT handle, const T_DATA& data);
        UsimPbUpdRefReqArg();
        
        static const UsimPbUpdRefReqArg& Cast(const StackMsgArgument& arg);
        void SetPbRefType(const UsimPbRefType& pb_ref_type) { m_pb_ref_type = pb_ref_type; }
        const UsimPbRefType& GetPbRefType() const { return m_pb_ref_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetRefRecno(INT ref_recno) { m_ref_recno = ref_recno; }
        INT GetRefRecno() const { return m_ref_recno; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 2216
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbUpdRefReqArg*) arg); }
        
        UsimPbRefType m_pb_ref_type;
        INT m_recno;
        INT m_ref_recno;
        INT m_handle;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbUpdRefReqArg& UsimPbUpdRefReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbUpdRefReqArg!\n");
    return ((UsimPbUpdRefReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbUpdDataReqArg
    ====================================================================== */

class UsimPbUpdDataReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbUpdDataReqArg(const UsimPbAddType& pb_add_type, INT handle, INT recno, const T_DATA& data);
        UsimPbUpdDataReqArg();
        
        static const UsimPbUpdDataReqArg& Cast(const StackMsgArgument& arg);
        void SetPbAddType(const UsimPbAddType& pb_add_type) { m_pb_add_type = pb_add_type; }
        const UsimPbAddType& GetPbAddType() const { return m_pb_add_type; }
        void SetHandle(INT handle) { m_handle = handle; }
        INT GetHandle() const { return m_handle; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetData(const T_DATA& data) { m_data = data; }
        const T_DATA& GetData() const { return m_data; }
        
        enum  {
            ID = 2217
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbUpdDataReqArg*) arg); }
        
        UsimPbAddType m_pb_add_type;
        INT m_handle;
        INT m_recno;
        T_DATA m_data;
        
    };

// Inline definitions
inline const UsimPbUpdDataReqArg& UsimPbUpdDataReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbUpdDataReqArg!\n");
    return ((UsimPbUpdDataReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbFillStatusReqArg
    ====================================================================== */

class UsimPbFillStatusReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbFillStatusReqArg();
        
        static const UsimPbFillStatusReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2218
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbFillStatusReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimPbFillStatusReqArg& UsimPbFillStatusReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbFillStatusReqArg!\n");
    return ((UsimPbFillStatusReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbStopReqArg
    ====================================================================== */

class UsimPbStopReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbStopReqArg();
        
        static const UsimPbStopReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2219
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbStopReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimPbStopReqArg& UsimPbStopReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbStopReqArg!\n");
    return ((UsimPbStopReqArg &) arg);
}



/*  ======================================================================
    Class UsimPbReadCnfArg
    ====================================================================== */

class UsimPbReadCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPbReadCnfArg();
        
        static const UsimPbReadCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2220
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPbReadCnfArg*) arg); }
        
    };

// Inline definitions
inline const UsimPbReadCnfArg& UsimPbReadCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPbReadCnfArg!\n");
    return ((UsimPbReadCnfArg &) arg);
}


#endif // Apc_PhoneBookStackMsgArgs_hpp

