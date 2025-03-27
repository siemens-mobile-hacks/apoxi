/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\grossau_mp1ue_sv\lnz_apoxi\Apoxi\Apc\SimMiscArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_SimMiscStackMsgArgs_hpp)
#define Apc_SimMiscStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Apc/SimMiscTypes.hpp>
#include <Apc/LockTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SimErrorIndArg
    ====================================================================== */

class SimErrorIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimErrorIndArg();
        
        static const SimErrorIndArg& Cast(const StackMsgArgument& arg);
        void SetErrorCode(const SimErrorCode& error_code) { m_error_code = error_code; }
        const SimErrorCode& GetErrorCode() const { return m_error_code; }
        
        enum  {
            ID = 1400
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimErrorIndArg*) arg); }
        
        SimErrorCode m_error_code;
        
    };

// Inline definitions
inline const SimErrorIndArg& SimErrorIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimErrorIndArg!\n");
    return ((SimErrorIndArg &) arg);
}



/*  ======================================================================
    Class SimRefreshIndArg
    ====================================================================== */

class SimRefreshIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimRefreshIndArg();
        
        static const SimRefreshIndArg& Cast(const StackMsgArgument& arg);
        void SetRefreshType(const SimRefreshType& refresh_type) { m_refresh_type = refresh_type; }
        const SimRefreshType& GetRefreshType() const { return m_refresh_type; }
        void SetSmsStatus(UINT8 sms_status) { m_sms_status = sms_status; }
        UINT8 GetSmsStatus() const { return m_sms_status; }
        void SetFileType(INT file_type) { m_file_type = file_type; }
        INT GetFileType() const { return m_file_type; }
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        
        enum  {
            ID = 1401
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimRefreshIndArg*) arg); }
        
        SimRefreshType m_refresh_type;
        UINT8 m_sms_status;
        INT m_file_type;
        INT m_rec_no;
        
    };

// Inline definitions
inline const SimRefreshIndArg& SimRefreshIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimRefreshIndArg!\n");
    return ((SimRefreshIndArg &) arg);
}



/*  ======================================================================
    Class SimSstReadIndArg
    ====================================================================== */

class SimSstReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSstReadIndArg();
        
        static const SimSstReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetSst(const SimServiceTable& sst) { m_sst = sst; }
        const SimServiceTable& GetSst() const { return m_sst; }
        
        enum  {
            ID = 1403
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSstReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        SimServiceTable m_sst;
        
    };

// Inline definitions
inline const SimSstReadIndArg& SimSstReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSstReadIndArg!\n");
    return ((SimSstReadIndArg &) arg);
}



/*  ======================================================================
    Class SimAcmReadIndArg
    ====================================================================== */

class SimAcmReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmReadIndArg();
        
        static const SimAcmReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetAcm(const Acm& acm) { m_acm = acm; }
        const Acm& GetAcm() const { return m_acm; }
        void SetCount(INT count) { m_count = count; }
        INT GetCount() const { return m_count; }
        void SetSelector(const AcmSelector& selector) { m_selector = selector; }
        const AcmSelector& GetSelector() const { return m_selector; }
        
        enum  {
            ID = 1404
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        INT m_recno;
        Acm m_acm;
        INT m_count;
        AcmSelector m_selector;
        
    };

// Inline definitions
inline const SimAcmReadIndArg& SimAcmReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmReadIndArg!\n");
    return ((SimAcmReadIndArg &) arg);
}



/*  ======================================================================
    Class SimAcmUpdIndArg
    ====================================================================== */

class SimAcmUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmUpdIndArg();
        
        static const SimAcmUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetSelector(const AcmSelector& selector) { m_selector = selector; }
        const AcmSelector& GetSelector() const { return m_selector; }
        
        enum  {
            ID = 1405
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        AcmSelector m_selector;
        
    };

// Inline definitions
inline const SimAcmUpdIndArg& SimAcmUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmUpdIndArg!\n");
    return ((SimAcmUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimAcmMaxReadIndArg
    ====================================================================== */

class SimAcmMaxReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmMaxReadIndArg();
        
        static const SimAcmMaxReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetAcm(const Acm& acm) { m_acm = acm; }
        const Acm& GetAcm() const { return m_acm; }
        
        enum  {
            ID = 1406
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmMaxReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        Acm m_acm;
        
    };

// Inline definitions
inline const SimAcmMaxReadIndArg& SimAcmMaxReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmMaxReadIndArg!\n");
    return ((SimAcmMaxReadIndArg &) arg);
}



/*  ======================================================================
    Class SimAcmMaxUpdIndArg
    ====================================================================== */

class SimAcmMaxUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmMaxUpdIndArg();
        
        static const SimAcmMaxUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1407
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmMaxUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimAcmMaxUpdIndArg& SimAcmMaxUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmMaxUpdIndArg!\n");
    return ((SimAcmMaxUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimPuctReadIndArg
    ====================================================================== */

class SimPuctReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimPuctReadIndArg();
        
        static const SimPuctReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetPuct(const Puct& puct) { m_puct = puct; }
        const Puct& GetPuct() const { return m_puct; }
        
        enum  {
            ID = 1408
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimPuctReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        Puct m_puct;
        
    };

// Inline definitions
inline const SimPuctReadIndArg& SimPuctReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimPuctReadIndArg!\n");
    return ((SimPuctReadIndArg &) arg);
}



/*  ======================================================================
    Class SimPuctUpdIndArg
    ====================================================================== */

class SimPuctUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimPuctUpdIndArg();
        
        static const SimPuctUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1409
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimPuctUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimPuctUpdIndArg& SimPuctUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimPuctUpdIndArg!\n");
    return ((SimPuctUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimGenericIndArg
    ====================================================================== */

class SimGenericIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimGenericIndArg();
        
        static const SimGenericIndArg& Cast(const StackMsgArgument& arg);
        void SetDfId(const SimFileId& df_id) { m_df_id = df_id; }
        const SimFileId& GetDfId() const { return m_df_id; }
        void SetDfLength(INT df_length) { m_df_length = df_length; }
        INT GetDfLength() const { return m_df_length; }
        void SetDfParams(const SimDfParameters& df_params) { m_df_params = df_params; }
        const SimDfParameters& GetDfParams() const { return m_df_params; }
        void SetEfId(const SimFileId& ef_id) { m_ef_id = ef_id; }
        const SimFileId& GetEfId() const { return m_ef_id; }
        void SetEfLength(INT ef_length) { m_ef_length = ef_length; }
        INT GetEfLength() const { return m_ef_length; }
        void SetEfParams(const SimEfParameters& ef_params) { m_ef_params = ef_params; }
        const SimEfParameters& GetEfParams() const { return m_ef_params; }
        void SetApduDataPtr(SimApduData * apdu_data_ptr) { m_apdu_data_ptr = apdu_data_ptr; }
        SimApduData * GetApduDataPtr() const { return m_apdu_data_ptr; }
        
        enum  {
            ID = 1410
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimGenericIndArg*) arg); }
        
        SimFileId m_df_id;
        INT m_df_length;
        SimDfParameters m_df_params;
        SimFileId m_ef_id;
        INT m_ef_length;
        SimEfParameters m_ef_params;
        SimApduData * m_apdu_data_ptr;
        
    };

// Inline definitions
inline const SimGenericIndArg& SimGenericIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimGenericIndArg!\n");
    return ((SimGenericIndArg &) arg);
}



/*  ======================================================================
    Class SimLangReadIndArg
    ====================================================================== */

class SimLangReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimLangReadIndArg();
        
        static const SimLangReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetLanguageArray(const LanguageArray& language_array) { m_language_array = language_array; }
        const LanguageArray& GetLanguageArray() const { return m_language_array; }
        
        enum  {
            ID = 1411
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimLangReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        LanguageArray m_language_array;
        
    };

// Inline definitions
inline const SimLangReadIndArg& SimLangReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimLangReadIndArg!\n");
    return ((SimLangReadIndArg &) arg);
}



/*  ======================================================================
    Class SimLangUpdIndArg
    ====================================================================== */

class SimLangUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimLangUpdIndArg();
        
        static const SimLangUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1412
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimLangUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimLangUpdIndArg& SimLangUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimLangUpdIndArg!\n");
    return ((SimLangUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimExtLangReadIndArg
    ====================================================================== */

class SimExtLangReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimExtLangReadIndArg();
        
        static const SimExtLangReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetLanguageArray(const ExtLanguageArray& language_array) { m_language_array = language_array; }
        const ExtLanguageArray& GetLanguageArray() const { return m_language_array; }
        
        enum  {
            ID = 1413
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimExtLangReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        ExtLanguageArray m_language_array;
        
    };

// Inline definitions
inline const SimExtLangReadIndArg& SimExtLangReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimExtLangReadIndArg!\n");
    return ((SimExtLangReadIndArg &) arg);
}



/*  ======================================================================
    Class SimExtLangUpdIndArg
    ====================================================================== */

class SimExtLangUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimExtLangUpdIndArg();
        
        static const SimExtLangUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1414
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimExtLangUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimExtLangUpdIndArg& SimExtLangUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimExtLangUpdIndArg!\n");
    return ((SimExtLangUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimSpnReadIndArg
    ====================================================================== */

class SimSpnReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSpnReadIndArg();
        
        static const SimSpnReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetSpnStruct(const ServiceProviderStruct& spn_struct) { m_spn_struct = spn_struct; }
        const ServiceProviderStruct& GetSpnStruct() const { return m_spn_struct; }
        
        enum  {
            ID = 1416
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSpnReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        ServiceProviderStruct m_spn_struct;
        
    };

// Inline definitions
inline const SimSpnReadIndArg& SimSpnReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSpnReadIndArg!\n");
    return ((SimSpnReadIndArg &) arg);
}



/*  ======================================================================
    Class SimFileInfoIndArg
    ====================================================================== */

class SimFileInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimFileInfoIndArg();
        
        static const SimFileInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetFileId(INT file_id) { m_file_id = file_id; }
        INT GetFileId() const { return m_file_id; }
        void SetFileType(const SimFileType& file_type) { m_file_type = file_type; }
        const SimFileType& GetFileType() const { return m_file_type; }
        void SetChvNo(const ChvNo& chv_no) { m_chv_no = chv_no; }
        const ChvNo& GetChvNo() const { return m_chv_no; }
        void SetFileSize(UINT file_size) { m_file_size = file_size; }
        UINT GetFileSize() const { return m_file_size; }
        void SetRecordLength(UINT8 record_length) { m_record_length = record_length; }
        UINT8 GetRecordLength() const { return m_record_length; }
        void SetInvalidation(UINT8 invalidation) { m_invalidation = invalidation; }
        UINT8 GetInvalidation() const { return m_invalidation; }
        
        enum  {
            ID = 1417
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimFileInfoIndArg*) arg); }
        
        SimUpdateStatus m_status;
        INT m_file_id;
        SimFileType m_file_type;
        ChvNo m_chv_no;
        UINT m_file_size;
        UINT8 m_record_length;
        UINT8 m_invalidation;
        
    };

// Inline definitions
inline const SimFileInfoIndArg& SimFileInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimFileInfoIndArg!\n");
    return ((SimFileInfoIndArg &) arg);
}



/*  ======================================================================
    Class CphsIstReadIndArg
    ====================================================================== */

class CphsIstReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsIstReadIndArg();
        
        static const CphsIstReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCphsIstArray(const CphsIstArray& cphs_ist_array) { m_cphs_ist_array = cphs_ist_array; }
        const CphsIstArray& GetCphsIstArray() const { return m_cphs_ist_array; }
        
        enum  {
            ID = 1418
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsIstReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CphsIstArray m_cphs_ist_array;
        
    };

// Inline definitions
inline const CphsIstReadIndArg& CphsIstReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsIstReadIndArg!\n");
    return ((CphsIstReadIndArg &) arg);
}



/*  ======================================================================
    Class CphsVmwfReadIndArg
    ====================================================================== */

class CphsVmwfReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsVmwfReadIndArg();
        
        static const CphsVmwfReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCphsVmwfArray(const CphsVmwfArray& cphs_vmwf_array) { m_cphs_vmwf_array = cphs_vmwf_array; }
        const CphsVmwfArray& GetCphsVmwfArray() const { return m_cphs_vmwf_array; }
        
        enum  {
            ID = 1419
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsVmwfReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CphsVmwfArray m_cphs_vmwf_array;
        
    };

// Inline definitions
inline const CphsVmwfReadIndArg& CphsVmwfReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsVmwfReadIndArg!\n");
    return ((CphsVmwfReadIndArg &) arg);
}



/*  ======================================================================
    Class CphsCfufReadIndArg
    ====================================================================== */

class CphsCfufReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCfufReadIndArg();
        
        static const CphsCfufReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCphsCfufArray(const CphsCfufArray& cphs_cfuf_array) { m_cphs_cfuf_array = cphs_cfuf_array; }
        const CphsCfufArray& GetCphsCfufArray() const { return m_cphs_cfuf_array; }
        
        enum  {
            ID = 1420
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCfufReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CphsCfufArray m_cphs_cfuf_array;
        
    };

// Inline definitions
inline const CphsCfufReadIndArg& CphsCfufReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCfufReadIndArg!\n");
    return ((CphsCfufReadIndArg &) arg);
}



/*  ======================================================================
    Class CphsOnmReadIndArg
    ====================================================================== */

class CphsOnmReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsOnmReadIndArg();
        
        static const CphsOnmReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCphsOnmName(const CphsOnmName& cphs_onm_name) { m_cphs_onm_name = cphs_onm_name; }
        const CphsOnmName& GetCphsOnmName() const { return m_cphs_onm_name; }
        
        enum  {
            ID = 1421
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsOnmReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CphsOnmName m_cphs_onm_name;
        
    };

// Inline definitions
inline const CphsOnmReadIndArg& CphsOnmReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsOnmReadIndArg!\n");
    return ((CphsOnmReadIndArg &) arg);
}



/*  ======================================================================
    Class CphsOnsReadIndArg
    ====================================================================== */

class CphsOnsReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsOnsReadIndArg();
        
        static const CphsOnsReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCphsOnsName(const CphsOnsName& cphs_ons_name) { m_cphs_ons_name = cphs_ons_name; }
        const CphsOnsName& GetCphsOnsName() const { return m_cphs_ons_name; }
        
        enum  {
            ID = 1422
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsOnsReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CphsOnsName m_cphs_ons_name;
        
    };

// Inline definitions
inline const CphsOnsReadIndArg& CphsOnsReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsOnsReadIndArg!\n");
    return ((CphsOnsReadIndArg &) arg);
}



/*  ======================================================================
    Class CphsVmwfUpdIndArg
    ====================================================================== */

class CphsVmwfUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsVmwfUpdIndArg();
        
        static const CphsVmwfUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1423
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsVmwfUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const CphsVmwfUpdIndArg& CphsVmwfUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsVmwfUpdIndArg!\n");
    return ((CphsVmwfUpdIndArg &) arg);
}



/*  ======================================================================
    Class CphsCfufUpdIndArg
    ====================================================================== */

class CphsCfufUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCfufUpdIndArg();
        
        static const CphsCfufUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1424
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCfufUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const CphsCfufUpdIndArg& CphsCfufUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCfufUpdIndArg!\n");
    return ((CphsCfufUpdIndArg &) arg);
}



/*  ======================================================================
    Class CphsCspReadIndArg
    ====================================================================== */

class CphsCspReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCspReadIndArg();
        
        static const CphsCspReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetLineSelector(const LineSelector& line_selector) { m_line_selector = line_selector; }
        const LineSelector& GetLineSelector() const { return m_line_selector; }
        void SetNoOfGroups(INT no_of_groups) { m_no_of_groups = no_of_groups; }
        INT GetNoOfGroups() const { return m_no_of_groups; }
        void SetCphsCspArray(const CphsCspArray& cphs_csp_array) { m_cphs_csp_array = cphs_csp_array; }
        const CphsCspArray& GetCphsCspArray() const { return m_cphs_csp_array; }
        
        enum  {
            ID = 1425
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCspReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        LineSelector m_line_selector;
        INT m_no_of_groups;
        CphsCspArray m_cphs_csp_array;
        
    };

// Inline definitions
inline const CphsCspReadIndArg& CphsCspReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCspReadIndArg!\n");
    return ((CphsCspReadIndArg &) arg);
}



/*  ======================================================================
    Class CphsCspUpdIndArg
    ====================================================================== */

class CphsCspUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCspUpdIndArg();
        
        static const CphsCspUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetLineSelector(const LineSelector& line_selector) { m_line_selector = line_selector; }
        const LineSelector& GetLineSelector() const { return m_line_selector; }
        
        enum  {
            ID = 1426
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCspUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        LineSelector m_line_selector;
        
    };

// Inline definitions
inline const CphsCspUpdIndArg& CphsCspUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCspUpdIndArg!\n");
    return ((CphsCspUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimCbmiReadIndArg
    ====================================================================== */

class SimCbmiReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmiReadIndArg();
        
        static const SimCbmiReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCbmiData(const CbmiData& cbmi_data) { m_cbmi_data = cbmi_data; }
        const CbmiData& GetCbmiData() const { return m_cbmi_data; }
        
        enum  {
            ID = 1428
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmiReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CbmiData m_cbmi_data;
        
    };

// Inline definitions
inline const SimCbmiReadIndArg& SimCbmiReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmiReadIndArg!\n");
    return ((SimCbmiReadIndArg &) arg);
}



/*  ======================================================================
    Class SimCbmirReadIndArg
    ====================================================================== */

class SimCbmirReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmirReadIndArg();
        
        static const SimCbmirReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCbmiRange(const CbmiRange& cbmi_range) { m_cbmi_range = cbmi_range; }
        const CbmiRange& GetCbmiRange() const { return m_cbmi_range; }
        
        enum  {
            ID = 1429
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmirReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CbmiRange m_cbmi_range;
        
    };

// Inline definitions
inline const SimCbmirReadIndArg& SimCbmirReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmirReadIndArg!\n");
    return ((SimCbmirReadIndArg &) arg);
}



/*  ======================================================================
    Class SimCbmiUpdIndArg
    ====================================================================== */

class SimCbmiUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmiUpdIndArg();
        
        static const SimCbmiUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1430
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmiUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimCbmiUpdIndArg& SimCbmiUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmiUpdIndArg!\n");
    return ((SimCbmiUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimCbmirUpdIndArg
    ====================================================================== */

class SimCbmirUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmirUpdIndArg();
        
        static const SimCbmirUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1431
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmirUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimCbmirUpdIndArg& SimCbmirUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmirUpdIndArg!\n");
    return ((SimCbmirUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimCcpReadIndArg
    ====================================================================== */

class SimCcpReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCcpReadIndArg();
        
        static const SimCcpReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCcpData(const CcpData& ccp_data) { m_ccp_data = ccp_data; }
        const CcpData& GetCcpData() const { return m_ccp_data; }
        
        enum  {
            ID = 1432
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCcpReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CcpData m_ccp_data;
        
    };

// Inline definitions
inline const SimCcpReadIndArg& SimCcpReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCcpReadIndArg!\n");
    return ((SimCcpReadIndArg &) arg);
}



/*  ======================================================================
    Class SimCcpUpdIndArg
    ====================================================================== */

class SimCcpUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCcpUpdIndArg();
        
        static const SimCcpUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1433
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCcpUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimCcpUpdIndArg& SimCcpUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCcpUpdIndArg!\n");
    return ((SimCcpUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimSmsrReadIndArg
    ====================================================================== */

class SimSmsrReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSmsrReadIndArg();
        
        static const SimSmsrReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetLink(UINT8 link) { m_link = link; }
        UINT8 GetLink() const { return m_link; }
        void SetSmsrData(const SmsrData& smsr_data) { m_smsr_data = smsr_data; }
        const SmsrData& GetSmsrData() const { return m_smsr_data; }
        
        enum  {
            ID = 1434
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSmsrReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        INT m_rec_no;
        UINT8 m_link;
        SmsrData m_smsr_data;
        
    };

// Inline definitions
inline const SimSmsrReadIndArg& SimSmsrReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSmsrReadIndArg!\n");
    return ((SimSmsrReadIndArg &) arg);
}



/*  ======================================================================
    Class SimSmsrUpdIndArg
    ====================================================================== */

class SimSmsrUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSmsrUpdIndArg();
        
        static const SimSmsrUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        
        enum  {
            ID = 1435
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSmsrUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        INT m_rec_no;
        
    };

// Inline definitions
inline const SimSmsrUpdIndArg& SimSmsrUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSmsrUpdIndArg!\n");
    return ((SimSmsrUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimMccMncIndArg
    ====================================================================== */

class SimMccMncIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimMccMncIndArg();
        
        static const SimMccMncIndArg& Cast(const StackMsgArgument& arg);
        void SetBcdPlmn(const BcdPlmn& bcd_plmn) { m_bcd_plmn = bcd_plmn; }
        const BcdPlmn& GetBcdPlmn() const { return m_bcd_plmn; }
        
        enum  {
            ID = 1436
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimMccMncIndArg*) arg); }
        
        BcdPlmn m_bcd_plmn;
        
    };

// Inline definitions
inline const SimMccMncIndArg& SimMccMncIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimMccMncIndArg!\n");
    return ((SimMccMncIndArg &) arg);
}



/*  ======================================================================
    Class UsimUstReadIndArg
    ====================================================================== */

class UsimUstReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimUstReadIndArg();
        
        static const UsimUstReadIndArg& Cast(const StackMsgArgument& arg);
        void SetLength(INT length) { m_length = length; }
        INT GetLength() const { return m_length; }
        void SetUst(const UsimUst& ust) { m_ust = ust; }
        const UsimUst& GetUst() const { return m_ust; }
        void SetFlag(BOOLEAN flag) { m_flag = flag; }
        BOOLEAN IsFlag() const { return m_flag; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1437
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimUstReadIndArg*) arg); }
        
        INT m_length;
        UsimUst m_ust;
        BOOLEAN m_flag;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimUstReadIndArg& UsimUstReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimUstReadIndArg!\n");
    return ((UsimUstReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimPlmnReadIndArg
    ====================================================================== */

class UsimPlmnReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPlmnReadIndArg();
        
        static const UsimPlmnReadIndArg& Cast(const StackMsgArgument& arg);
        void SetReadType(const UsimReadType& read_type) { m_read_type = read_type; }
        const UsimReadType& GetReadType() const { return m_read_type; }
        void SetLength(INT length) { m_length = length; }
        INT GetLength() const { return m_length; }
        void SetPlmnList(const UsimPlmnList& plmn_list) { m_plmn_list = plmn_list; }
        const UsimPlmnList& GetPlmnList() const { return m_plmn_list; }
        void SetEndReached(BOOLEAN end_reached) { m_end_reached = end_reached; }
        BOOLEAN IsEndReached() const { return m_end_reached; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1438
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPlmnReadIndArg*) arg); }
        
        UsimReadType m_read_type;
        INT m_length;
        UsimPlmnList m_plmn_list;
        BOOLEAN m_end_reached;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimPlmnReadIndArg& UsimPlmnReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPlmnReadIndArg!\n");
    return ((UsimPlmnReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimReadRejArg
    ====================================================================== */

class UsimReadRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimReadRejArg();
        
        static const UsimReadRejArg& Cast(const StackMsgArgument& arg);
        void SetReadType(const UsimReadType& read_type) { m_read_type = read_type; }
        const UsimReadType& GetReadType() const { return m_read_type; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1439
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimReadRejArg*) arg); }
        
        UsimReadType m_read_type;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimReadRejArg& UsimReadRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimReadRejArg!\n");
    return ((UsimReadRejArg &) arg);
}



/*  ======================================================================
    Class UsimCsLociReadIndArg
    ====================================================================== */

class UsimCsLociReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimCsLociReadIndArg();
        
        static const UsimCsLociReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetLociData(const LociData& loci_data) { m_loci_data = loci_data; }
        const LociData& GetLociData() const { return m_loci_data; }
        
        enum  {
            ID = 1440
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimCsLociReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        LociData m_loci_data;
        
    };

// Inline definitions
inline const UsimCsLociReadIndArg& UsimCsLociReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimCsLociReadIndArg!\n");
    return ((UsimCsLociReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimPsLociReadIndArg
    ====================================================================== */

class UsimPsLociReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPsLociReadIndArg();
        
        static const UsimPsLociReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetPsLociData(const PsLociData& ps_loci_data) { m_ps_loci_data = ps_loci_data; }
        const PsLociData& GetPsLociData() const { return m_ps_loci_data; }
        
        enum  {
            ID = 1441
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPsLociReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        PsLociData m_ps_loci_data;
        
    };

// Inline definitions
inline const UsimPsLociReadIndArg& UsimPsLociReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPsLociReadIndArg!\n");
    return ((UsimPsLociReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimLangReadIndArg
    ====================================================================== */

class UsimLangReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimLangReadIndArg();
        
        static const UsimLangReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetLangFileType(const UsimLangFileType& lang_file_type) { m_lang_file_type = lang_file_type; }
        const UsimLangFileType& GetLangFileType() const { return m_lang_file_type; }
        void SetLength(INT length) { m_length = length; }
        INT GetLength() const { return m_length; }
        void SetLanguageList(const UsimLanguageList& language_list) { m_language_list = language_list; }
        const UsimLanguageList& GetLanguageList() const { return m_language_list; }
        
        enum  {
            ID = 1442
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimLangReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        UsimLangFileType m_lang_file_type;
        INT m_length;
        UsimLanguageList m_language_list;
        
    };

// Inline definitions
inline const UsimLangReadIndArg& UsimLangReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimLangReadIndArg!\n");
    return ((UsimLangReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimEccReadIndArg
    ====================================================================== */

class UsimEccReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimEccReadIndArg();
        
        static const UsimEccReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetEccRecord(const UsimEccRecord& ecc_record) { m_ecc_record = ecc_record; }
        const UsimEccRecord& GetEccRecord() const { return m_ecc_record; }
        
        enum  {
            ID = 1443
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimEccReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        UsimEccRecord m_ecc_record;
        
    };

// Inline definitions
inline const UsimEccReadIndArg& UsimEccReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimEccReadIndArg!\n");
    return ((UsimEccReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimReadRecordRejArg
    ====================================================================== */

class UsimReadRecordRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimReadRecordRejArg();
        
        static const UsimReadRecordRejArg& Cast(const StackMsgArgument& arg);
        void SetReadType(const UsimReadType& read_type) { m_read_type = read_type; }
        const UsimReadType& GetReadType() const { return m_read_type; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1444
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimReadRecordRejArg*) arg); }
        
        UsimReadType m_read_type;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimReadRecordRejArg& UsimReadRecordRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimReadRecordRejArg!\n");
    return ((UsimReadRecordRejArg &) arg);
}



/*  ======================================================================
    Class UsimSmsParamReadIndArg
    ====================================================================== */

class UsimSmsParamReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimSmsParamReadIndArg();
        
        static const UsimSmsParamReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetAlphaSize(INT alpha_size) { m_alpha_size = alpha_size; }
        INT GetAlphaSize() const { return m_alpha_size; }
        void SetData(const SimData& data) { m_data = data; }
        const SimData& GetData() const { return m_data; }
        void SetAddData(BOOLEAN add_data) { m_add_data = add_data; }
        BOOLEAN IsAddData() const { return m_add_data; }
        
        enum  {
            ID = 1445
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimSmsParamReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        INT m_recno;
        INT m_alpha_size;
        SimData m_data;
        BOOLEAN m_add_data;
        
    };

// Inline definitions
inline const UsimSmsParamReadIndArg& UsimSmsParamReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimSmsParamReadIndArg!\n");
    return ((UsimSmsParamReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimSmsParamExtIndArg
    ====================================================================== */

class UsimSmsParamExtIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimSmsParamExtIndArg();
        
        static const UsimSmsParamExtIndArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetData(const SimData& data) { m_data = data; }
        const SimData& GetData() const { return m_data; }
        void SetAddData(BOOLEAN add_data) { m_add_data = add_data; }
        BOOLEAN IsAddData() const { return m_add_data; }
        
        enum  {
            ID = 1446
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimSmsParamExtIndArg*) arg); }
        
        INT m_recno;
        SimData m_data;
        BOOLEAN m_add_data;
        
    };

// Inline definitions
inline const UsimSmsParamExtIndArg& UsimSmsParamExtIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimSmsParamExtIndArg!\n");
    return ((UsimSmsParamExtIndArg &) arg);
}



/*  ======================================================================
    Class UsimUpdCnfArg
    ====================================================================== */

class UsimUpdCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimUpdCnfArg();
        
        static const UsimUpdCnfArg& Cast(const StackMsgArgument& arg);
        void SetReadType(const UsimReadType& read_type) { m_read_type = read_type; }
        const UsimReadType& GetReadType() const { return m_read_type; }
        
        enum  {
            ID = 1447
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimUpdCnfArg*) arg); }
        
        UsimReadType m_read_type;
        
    };

// Inline definitions
inline const UsimUpdCnfArg& UsimUpdCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimUpdCnfArg!\n");
    return ((UsimUpdCnfArg &) arg);
}



/*  ======================================================================
    Class UsimUpdRejArg
    ====================================================================== */

class UsimUpdRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimUpdRejArg();
        
        static const UsimUpdRejArg& Cast(const StackMsgArgument& arg);
        void SetReadType(const UsimReadType& read_type) { m_read_type = read_type; }
        const UsimReadType& GetReadType() const { return m_read_type; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1448
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimUpdRejArg*) arg); }
        
        UsimReadType m_read_type;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimUpdRejArg& UsimUpdRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimUpdRejArg!\n");
    return ((UsimUpdRejArg &) arg);
}



/*  ======================================================================
    Class UsimPlmnUpdIndArg
    ====================================================================== */

class UsimPlmnUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPlmnUpdIndArg();
        
        static const UsimPlmnUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1449
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPlmnUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimPlmnUpdIndArg& UsimPlmnUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPlmnUpdIndArg!\n");
    return ((UsimPlmnUpdIndArg &) arg);
}



/*  ======================================================================
    Class UsimCardTypeReadIndArg
    ====================================================================== */

class UsimCardTypeReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimCardTypeReadIndArg();
        
        static const UsimCardTypeReadIndArg& Cast(const StackMsgArgument& arg);
        void SetCardType(const SimCardType& card_type) { m_card_type = card_type; }
        const SimCardType& GetCardType() const { return m_card_type; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1450
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimCardTypeReadIndArg*) arg); }
        
        SimCardType m_card_type;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimCardTypeReadIndArg& UsimCardTypeReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimCardTypeReadIndArg!\n");
    return ((UsimCardTypeReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimSmsParamUpdIndArg
    ====================================================================== */

class UsimSmsParamUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimSmsParamUpdIndArg();
        
        static const UsimSmsParamUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        
        enum  {
            ID = 1451
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimSmsParamUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        INT m_recno;
        
    };

// Inline definitions
inline const UsimSmsParamUpdIndArg& UsimSmsParamUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimSmsParamUpdIndArg!\n");
    return ((UsimSmsParamUpdIndArg &) arg);
}



/*  ======================================================================
    Class UsimEstReadIndArg
    ====================================================================== */

class UsimEstReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimEstReadIndArg();
        
        static const UsimEstReadIndArg& Cast(const StackMsgArgument& arg);
        void SetLength(INT length) { m_length = length; }
        INT GetLength() const { return m_length; }
        void SetEst(const UsimEst& est) { m_est = est; }
        const UsimEst& GetEst() const { return m_est; }
        void SetFlag(BOOLEAN flag) { m_flag = flag; }
        BOOLEAN IsFlag() const { return m_flag; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1452
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimEstReadIndArg*) arg); }
        
        INT m_length;
        UsimEst m_est;
        BOOLEAN m_flag;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimEstReadIndArg& UsimEstReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimEstReadIndArg!\n");
    return ((UsimEstReadIndArg &) arg);
}



/*  ======================================================================
    Class UsimLangUpdIndArg
    ====================================================================== */

class UsimLangUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimLangUpdIndArg();
        
        static const UsimLangUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1453
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimLangUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimLangUpdIndArg& UsimLangUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimLangUpdIndArg!\n");
    return ((UsimLangUpdIndArg &) arg);
}



/*  ======================================================================
    Class UsimFilePropertyIndArg
    ====================================================================== */

class UsimFilePropertyIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimFilePropertyIndArg();
        
        static const UsimFilePropertyIndArg& Cast(const StackMsgArgument& arg);
        void SetProperty(const UsimFileProperty& property) { m_property = property; }
        const UsimFileProperty& GetProperty() const { return m_property; }
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1454
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimFilePropertyIndArg*) arg); }
        
        UsimFileProperty m_property;
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const UsimFilePropertyIndArg& UsimFilePropertyIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimFilePropertyIndArg!\n");
    return ((UsimFilePropertyIndArg &) arg);
}



/*  ======================================================================
    Class SimCmiReadIndArg
    ====================================================================== */

class SimCmiReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCmiReadIndArg();
        
        static const SimCmiReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetCmiRecord(const CmiRecord& cmi_record) { m_cmi_record = cmi_record; }
        const CmiRecord& GetCmiRecord() const { return m_cmi_record; }
        
        enum  {
            ID = 1470
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCmiReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        CmiRecord m_cmi_record;
        
    };

// Inline definitions
inline const SimCmiReadIndArg& SimCmiReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCmiReadIndArg!\n");
    return ((SimCmiReadIndArg &) arg);
}



/*  ======================================================================
    Class SimODynReadIndArg
    ====================================================================== */

class SimODynReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODynReadIndArg();
        
        static const SimODynReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetFlag(UINT8 flag) { m_flag = flag; }
        UINT8 GetFlag() const { return m_flag; }
        
        enum  {
            ID = 1471
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODynReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        UINT8 m_flag;
        
    };

// Inline definitions
inline const SimODynReadIndArg& SimODynReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODynReadIndArg!\n");
    return ((SimODynReadIndArg &) arg);
}



/*  ======================================================================
    Class SimODyn2ReadIndArg
    ====================================================================== */

class SimODyn2ReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODyn2ReadIndArg();
        
        static const SimODyn2ReadIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetFlag(UINT8 flag) { m_flag = flag; }
        UINT8 GetFlag() const { return m_flag; }
        
        enum  {
            ID = 1472
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODyn2ReadIndArg*) arg); }
        
        SimUpdateStatus m_status;
        UINT8 m_flag;
        
    };

// Inline definitions
inline const SimODyn2ReadIndArg& SimODyn2ReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODyn2ReadIndArg!\n");
    return ((SimODyn2ReadIndArg &) arg);
}



/*  ======================================================================
    Class SimODynUpdIndArg
    ====================================================================== */

class SimODynUpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODynUpdIndArg();
        
        static const SimODynUpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1473
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODynUpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimODynUpdIndArg& SimODynUpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODynUpdIndArg!\n");
    return ((SimODynUpdIndArg &) arg);
}



/*  ======================================================================
    Class SimODyn2UpdIndArg
    ====================================================================== */

class SimODyn2UpdIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODyn2UpdIndArg();
        
        static const SimODyn2UpdIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        
        enum  {
            ID = 1474
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODyn2UpdIndArg*) arg); }
        
        SimUpdateStatus m_status;
        
    };

// Inline definitions
inline const SimODyn2UpdIndArg& SimODyn2UpdIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODyn2UpdIndArg!\n");
    return ((SimODyn2UpdIndArg &) arg);
}



/*  ======================================================================
    Class SimMruPropertyUpdCnfArg
    ====================================================================== */

class SimMruPropertyUpdCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimMruPropertyUpdCnfArg();
        
        static const SimMruPropertyUpdCnfArg& Cast(const StackMsgArgument& arg);
        void SetChangedState(const SimChangedState& changed_state) { m_changed_state = changed_state; }
        const SimChangedState& GetChangedState() const { return m_changed_state; }
        
        enum  {
            ID = 1475
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimMruPropertyUpdCnfArg*) arg); }
        
        SimChangedState m_changed_state;
        
    };

// Inline definitions
inline const SimMruPropertyUpdCnfArg& SimMruPropertyUpdCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimMruPropertyUpdCnfArg!\n");
    return ((SimMruPropertyUpdCnfArg &) arg);
}



/*  ======================================================================
    Class SimMruPropertyRefreshIndArg
    ====================================================================== */

class SimMruPropertyRefreshIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimMruPropertyRefreshIndArg();
        
        static const SimMruPropertyRefreshIndArg& Cast(const StackMsgArgument& arg);
        void SetType(UINT16 type) { m_type = type; }
        UINT16 GetType() const { return m_type; }
        void SetIndex(UINT8 index) { m_index = index; }
        UINT8 GetIndex() const { return m_index; }
        void SetBitNumber(UINT8 bit_number) { m_bit_number = bit_number; }
        UINT8 GetBitNumber() const { return m_bit_number; }
        void SetBitValue(UINT8 bit_value) { m_bit_value = bit_value; }
        UINT8 GetBitValue() const { return m_bit_value; }
        
        enum  {
            ID = 1476
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimMruPropertyRefreshIndArg*) arg); }
        
        UINT16 m_type;
        UINT8 m_index;
        UINT8 m_bit_number;
        UINT8 m_bit_value;
        
    };

// Inline definitions
inline const SimMruPropertyRefreshIndArg& SimMruPropertyRefreshIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimMruPropertyRefreshIndArg!\n");
    return ((SimMruPropertyRefreshIndArg &) arg);
}



/*  ======================================================================
    Class SimInitIndArg
    ====================================================================== */

class SimInitIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimInitIndArg();
        
        static const SimInitIndArg& Cast(const StackMsgArgument& arg);
        void SetStatus(const SimUpdateStatus& status) { m_status = status; }
        const SimUpdateStatus& GetStatus() const { return m_status; }
        void SetInitResult(const SimInitResult& init_result) { m_init_result = init_result; }
        const SimInitResult& GetInitResult() const { return m_init_result; }
        void SetImsi(const Imsi& imsi) { m_imsi = imsi; }
        const Imsi& GetImsi() const { return m_imsi; }
        void SetAdnByte(UINT8 adn_byte) { m_adn_byte = adn_byte; }
        UINT8 GetAdnByte() const { return m_adn_byte; }
        void SetBdnByte(UINT8 bdn_byte) { m_bdn_byte = bdn_byte; }
        UINT8 GetBdnByte() const { return m_bdn_byte; }
        
        enum  {
            ID = 1480
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimInitIndArg*) arg); }
        
        SimUpdateStatus m_status;
        SimInitResult m_init_result;
        Imsi m_imsi;
        UINT8 m_adn_byte;
        UINT8 m_bdn_byte;
        
    };

// Inline definitions
inline const SimInitIndArg& SimInitIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimInitIndArg!\n");
    return ((SimInitIndArg &) arg);
}



/*  ======================================================================
    Class SimInfoIndArg
    ====================================================================== */

class SimInfoIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimInfoIndArg();
        
        static const SimInfoIndArg& Cast(const StackMsgArgument& arg);
        void SetSimInfo(const SimInfo& sim_info) { m_sim_info = sim_info; }
        const SimInfo& GetSimInfo() const { return m_sim_info; }
        
        enum  {
            ID = 1481
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimInfoIndArg*) arg); }
        
        SimInfo m_sim_info;
        
    };

// Inline definitions
inline const SimInfoIndArg& SimInfoIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimInfoIndArg!\n");
    return ((SimInfoIndArg &) arg);
}



/*  ======================================================================
    Class SimLockStatusIndArg
    ====================================================================== */

class SimLockStatusIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimLockStatusIndArg();
        
        static const SimLockStatusIndArg& Cast(const StackMsgArgument& arg);
        void SetLockStates(const SecLockStates& lock_states) { m_lock_states = lock_states; }
        const SecLockStates& GetLockStates() const { return m_lock_states; }
        
        enum  {
            ID = 1482
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimLockStatusIndArg*) arg); }
        
        SecLockStates m_lock_states;
        
    };

// Inline definitions
inline const SimLockStatusIndArg& SimLockStatusIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimLockStatusIndArg!\n");
    return ((SimLockStatusIndArg &) arg);
}



/*  ======================================================================
    Class SimFullAccessIndArg
    ====================================================================== */

class SimFullAccessIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimFullAccessIndArg();
        
        static const SimFullAccessIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1483
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimFullAccessIndArg*) arg); }
        
    };

// Inline definitions
inline const SimFullAccessIndArg& SimFullAccessIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimFullAccessIndArg!\n");
    return ((SimFullAccessIndArg &) arg);
}



/*  ======================================================================
    Class FdnIndArg
    ====================================================================== */

class FdnIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        FdnIndArg();
        
        static const FdnIndArg& Cast(const StackMsgArgument& arg);
        void SetFdnState(const FdnState& fdn_state) { m_fdn_state = fdn_state; }
        const FdnState& GetFdnState() const { return m_fdn_state; }
        void SetSimUpdateStatus(const SimUpdateStatus& sim_update_status) { m_sim_update_status = sim_update_status; }
        const SimUpdateStatus& GetSimUpdateStatus() const { return m_sim_update_status; }
        void SetFileStatus(UINT8 file_status) { m_file_status = file_status; }
        UINT8 GetFileStatus() const { return m_file_status; }
        
        enum  {
            ID = 1484
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((FdnIndArg*) arg); }
        
        FdnState m_fdn_state;
        SimUpdateStatus m_sim_update_status;
        UINT8 m_file_status;
        
    };

// Inline definitions
inline const FdnIndArg& FdnIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to FdnIndArg!\n");
    return ((FdnIndArg &) arg);
}



/*  ======================================================================
    Class BdnIndArg
    ====================================================================== */

class BdnIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        BdnIndArg();
        
        static const BdnIndArg& Cast(const StackMsgArgument& arg);
        void SetBdnState(const BdnState& bdn_state) { m_bdn_state = bdn_state; }
        const BdnState& GetBdnState() const { return m_bdn_state; }
        void SetSimUpdateStatus(const SimUpdateStatus& sim_update_status) { m_sim_update_status = sim_update_status; }
        const SimUpdateStatus& GetSimUpdateStatus() const { return m_sim_update_status; }
        void SetFileStatus(UINT8 file_status) { m_file_status = file_status; }
        UINT8 GetFileStatus() const { return m_file_status; }
        
        enum  {
            ID = 1485
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BdnIndArg*) arg); }
        
        BdnState m_bdn_state;
        SimUpdateStatus m_sim_update_status;
        UINT8 m_file_status;
        
    };

// Inline definitions
inline const BdnIndArg& BdnIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BdnIndArg!\n");
    return ((BdnIndArg &) arg);
}



/*  ======================================================================
    Class SimModifyLockIndArg
    ====================================================================== */

class SimModifyLockIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimModifyLockIndArg();
        
        static const SimModifyLockIndArg& Cast(const StackMsgArgument& arg);
        void SetLockStates(const SecLockStates& lock_states) { m_lock_states = lock_states; }
        const SecLockStates& GetLockStates() const { return m_lock_states; }
        void SetLockAction(const SecLockAction& lock_action) { m_lock_action = lock_action; }
        const SecLockAction& GetLockAction() const { return m_lock_action; }
        
        enum  {
            ID = 1486
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimModifyLockIndArg*) arg); }
        
        SecLockStates m_lock_states;
        SecLockAction m_lock_action;
        
    };

// Inline definitions
inline const SimModifyLockIndArg& SimModifyLockIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimModifyLockIndArg!\n");
    return ((SimModifyLockIndArg &) arg);
}



/*  ======================================================================
    Class SimRefreshReqArg
    ====================================================================== */

class SimRefreshReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimRefreshReqArg();
        
        static const SimRefreshReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2400
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimRefreshReqArg*) arg); }
        
    };

// Inline definitions
inline const SimRefreshReqArg& SimRefreshReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimRefreshReqArg!\n");
    return ((SimRefreshReqArg &) arg);
}



/*  ======================================================================
    Class SimSstReadReqArg
    ====================================================================== */

class SimSstReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSstReadReqArg();
        
        static const SimSstReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2401
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSstReadReqArg*) arg); }
        
    };

// Inline definitions
inline const SimSstReadReqArg& SimSstReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSstReadReqArg!\n");
    return ((SimSstReadReqArg &) arg);
}



/*  ======================================================================
    Class SimAcmReadReqArg
    ====================================================================== */

class SimAcmReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmReadReqArg(INT rec_no, const AcmSelector& selector);
        SimAcmReadReqArg();
        
        static const SimAcmReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetSelector(const AcmSelector& selector) { m_selector = selector; }
        const AcmSelector& GetSelector() const { return m_selector; }
        
        enum  {
            ID = 2402
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmReadReqArg*) arg); }
        
        INT m_rec_no;
        AcmSelector m_selector;
        
    };

// Inline definitions
inline const SimAcmReadReqArg& SimAcmReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmReadReqArg!\n");
    return ((SimAcmReadReqArg &) arg);
}



/*  ======================================================================
    Class SimAcmUpdReqArg
    ====================================================================== */

class SimAcmUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmUpdReqArg(INT rec_no, const Acm& acm, const AcmSelector& selector);
        SimAcmUpdReqArg();
        
        static const SimAcmUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetAcm(const Acm& acm) { m_acm = acm; }
        const Acm& GetAcm() const { return m_acm; }
        void SetSelector(const AcmSelector& selector) { m_selector = selector; }
        const AcmSelector& GetSelector() const { return m_selector; }
        
        enum  {
            ID = 2403
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmUpdReqArg*) arg); }
        
        INT m_rec_no;
        Acm m_acm;
        AcmSelector m_selector;
        
    };

// Inline definitions
inline const SimAcmUpdReqArg& SimAcmUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmUpdReqArg!\n");
    return ((SimAcmUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimAcmMaxReadReqArg
    ====================================================================== */

class SimAcmMaxReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmMaxReadReqArg();
        
        static const SimAcmMaxReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2404
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmMaxReadReqArg*) arg); }
        
    };

// Inline definitions
inline const SimAcmMaxReadReqArg& SimAcmMaxReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmMaxReadReqArg!\n");
    return ((SimAcmMaxReadReqArg &) arg);
}



/*  ======================================================================
    Class SimAcmMaxUpdReqArg
    ====================================================================== */

class SimAcmMaxUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimAcmMaxUpdReqArg(const Acm& acm);
        SimAcmMaxUpdReqArg();
        
        static const SimAcmMaxUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetAcm(const Acm& acm) { m_acm = acm; }
        const Acm& GetAcm() const { return m_acm; }
        
        enum  {
            ID = 2405
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimAcmMaxUpdReqArg*) arg); }
        
        Acm m_acm;
        
    };

// Inline definitions
inline const SimAcmMaxUpdReqArg& SimAcmMaxUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimAcmMaxUpdReqArg!\n");
    return ((SimAcmMaxUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimPuctReadReqArg
    ====================================================================== */

class SimPuctReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimPuctReadReqArg();
        
        static const SimPuctReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2406
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimPuctReadReqArg*) arg); }
        
    };

// Inline definitions
inline const SimPuctReadReqArg& SimPuctReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimPuctReadReqArg!\n");
    return ((SimPuctReadReqArg &) arg);
}



/*  ======================================================================
    Class SimPuctUpdReqArg
    ====================================================================== */

class SimPuctUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimPuctUpdReqArg(const Puct& puct);
        SimPuctUpdReqArg();
        
        static const SimPuctUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetPuct(const Puct& puct) { m_puct = puct; }
        const Puct& GetPuct() const { return m_puct; }
        
        enum  {
            ID = 2407
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimPuctUpdReqArg*) arg); }
        
        Puct m_puct;
        
    };

// Inline definitions
inline const SimPuctUpdReqArg& SimPuctUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimPuctUpdReqArg!\n");
    return ((SimPuctUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimGenericReqArg
    ====================================================================== */

class SimGenericReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimGenericReqArg(const SimFileId& df_id, BOOLEAN df_id_flag, const SimFileId& ef_id, BOOLEAN ef_id_flag, SimApduData* apdu_data_ptr);
        SimGenericReqArg();
        
        static const SimGenericReqArg& Cast(const StackMsgArgument& arg);
        void SetDfId(const SimFileId& df_id) { m_df_id = df_id; }
        const SimFileId& GetDfId() const { return m_df_id; }
        void SetDfIdFlag(BOOLEAN df_id_flag) { m_df_id_flag = df_id_flag; }
        BOOLEAN IsDfIdFlag() const { return m_df_id_flag; }
        void SetEfId(const SimFileId& ef_id) { m_ef_id = ef_id; }
        const SimFileId& GetEfId() const { return m_ef_id; }
        void SetEfIdFlag(BOOLEAN ef_id_flag) { m_ef_id_flag = ef_id_flag; }
        BOOLEAN IsEfIdFlag() const { return m_ef_id_flag; }
        void SetApduDataPtr(SimApduData* apdu_data_ptr) { m_apdu_data_ptr = apdu_data_ptr; }
        SimApduData* GetApduDataPtr() const { return m_apdu_data_ptr; }
        
        enum  {
            ID = 2408
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimGenericReqArg*) arg); }
        
        SimFileId m_df_id;
        BOOLEAN m_df_id_flag;
        SimFileId m_ef_id;
        BOOLEAN m_ef_id_flag;
        SimApduData* m_apdu_data_ptr;
        
    };

// Inline definitions
inline const SimGenericReqArg& SimGenericReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimGenericReqArg!\n");
    return ((SimGenericReqArg &) arg);
}



/*  ======================================================================
    Class SimLangReadReqArg
    ====================================================================== */

class SimLangReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimLangReadReqArg(INT start_pos);
        SimLangReadReqArg();
        
        static const SimLangReadReqArg& Cast(const StackMsgArgument& arg);
        void SetStartPos(INT start_pos) { m_start_pos = start_pos; }
        INT GetStartPos() const { return m_start_pos; }
        
        enum  {
            ID = 2409
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimLangReadReqArg*) arg); }
        
        INT m_start_pos;
        
    };

// Inline definitions
inline const SimLangReadReqArg& SimLangReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimLangReadReqArg!\n");
    return ((SimLangReadReqArg &) arg);
}



/*  ======================================================================
    Class SimLangUpdReqArg
    ====================================================================== */

class SimLangUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimLangUpdReqArg(INT start_pos, const LanguageArray& language_array);
        SimLangUpdReqArg();
        
        static const SimLangUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetStartPos(INT start_pos) { m_start_pos = start_pos; }
        INT GetStartPos() const { return m_start_pos; }
        void SetLanguageArray(const LanguageArray& language_array) { m_language_array = language_array; }
        const LanguageArray& GetLanguageArray() const { return m_language_array; }
        
        enum  {
            ID = 2410
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimLangUpdReqArg*) arg); }
        
        INT m_start_pos;
        LanguageArray m_language_array;
        
    };

// Inline definitions
inline const SimLangUpdReqArg& SimLangUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimLangUpdReqArg!\n");
    return ((SimLangUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimExtLangReadReqArg
    ====================================================================== */

class SimExtLangReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimExtLangReadReqArg(INT start_pos);
        SimExtLangReadReqArg();
        
        static const SimExtLangReadReqArg& Cast(const StackMsgArgument& arg);
        void SetStartPos(INT start_pos) { m_start_pos = start_pos; }
        INT GetStartPos() const { return m_start_pos; }
        
        enum  {
            ID = 2411
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimExtLangReadReqArg*) arg); }
        
        INT m_start_pos;
        
    };

// Inline definitions
inline const SimExtLangReadReqArg& SimExtLangReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimExtLangReadReqArg!\n");
    return ((SimExtLangReadReqArg &) arg);
}



/*  ======================================================================
    Class SimExtLangUpdReqArg
    ====================================================================== */

class SimExtLangUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimExtLangUpdReqArg(INT start_pos, const ExtLanguageArray& language_array);
        SimExtLangUpdReqArg();
        
        static const SimExtLangUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetStartPos(INT start_pos) { m_start_pos = start_pos; }
        INT GetStartPos() const { return m_start_pos; }
        void SetLanguageArray(const ExtLanguageArray& language_array) { m_language_array = language_array; }
        const ExtLanguageArray& GetLanguageArray() const { return m_language_array; }
        
        enum  {
            ID = 2412
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimExtLangUpdReqArg*) arg); }
        
        INT m_start_pos;
        ExtLanguageArray m_language_array;
        
    };

// Inline definitions
inline const SimExtLangUpdReqArg& SimExtLangUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimExtLangUpdReqArg!\n");
    return ((SimExtLangUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimSpnReadReqArg
    ====================================================================== */

class SimSpnReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSpnReadReqArg();
        
        static const SimSpnReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2414
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSpnReadReqArg*) arg); }
        
    };

// Inline definitions
inline const SimSpnReadReqArg& SimSpnReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSpnReadReqArg!\n");
    return ((SimSpnReadReqArg &) arg);
}



/*  ======================================================================
    Class SimFileInfoReqArg
    ====================================================================== */

class SimFileInfoReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimFileInfoReqArg(INT file_id);
        SimFileInfoReqArg();
        
        static const SimFileInfoReqArg& Cast(const StackMsgArgument& arg);
        void SetFileId(INT file_id) { m_file_id = file_id; }
        INT GetFileId() const { return m_file_id; }
        
        enum  {
            ID = 2415
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimFileInfoReqArg*) arg); }
        
        INT m_file_id;
        
    };

// Inline definitions
inline const SimFileInfoReqArg& SimFileInfoReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimFileInfoReqArg!\n");
    return ((SimFileInfoReqArg &) arg);
}



/*  ======================================================================
    Class CphsIstReadReqArg
    ====================================================================== */

class CphsIstReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsIstReadReqArg();
        
        static const CphsIstReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2416
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsIstReadReqArg*) arg); }
        
    };

// Inline definitions
inline const CphsIstReadReqArg& CphsIstReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsIstReadReqArg!\n");
    return ((CphsIstReadReqArg &) arg);
}



/*  ======================================================================
    Class CphsVmwfReadReqArg
    ====================================================================== */

class CphsVmwfReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsVmwfReadReqArg();
        
        static const CphsVmwfReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2417
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsVmwfReadReqArg*) arg); }
        
    };

// Inline definitions
inline const CphsVmwfReadReqArg& CphsVmwfReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsVmwfReadReqArg!\n");
    return ((CphsVmwfReadReqArg &) arg);
}



/*  ======================================================================
    Class CphsCfufReadReqArg
    ====================================================================== */

class CphsCfufReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCfufReadReqArg();
        
        static const CphsCfufReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2418
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCfufReadReqArg*) arg); }
        
    };

// Inline definitions
inline const CphsCfufReadReqArg& CphsCfufReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCfufReadReqArg!\n");
    return ((CphsCfufReadReqArg &) arg);
}



/*  ======================================================================
    Class CphsOnmReadReqArg
    ====================================================================== */

class CphsOnmReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsOnmReadReqArg();
        
        static const CphsOnmReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2419
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsOnmReadReqArg*) arg); }
        
    };

// Inline definitions
inline const CphsOnmReadReqArg& CphsOnmReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsOnmReadReqArg!\n");
    return ((CphsOnmReadReqArg &) arg);
}



/*  ======================================================================
    Class CphsOnsReadReqArg
    ====================================================================== */

class CphsOnsReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsOnsReadReqArg();
        
        static const CphsOnsReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2420
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsOnsReadReqArg*) arg); }
        
    };

// Inline definitions
inline const CphsOnsReadReqArg& CphsOnsReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsOnsReadReqArg!\n");
    return ((CphsOnsReadReqArg &) arg);
}



/*  ======================================================================
    Class CphsVmwfUpdReqArg
    ====================================================================== */

class CphsVmwfUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsVmwfUpdReqArg(const CphsVmwfArray& cphs_vmwf_array);
        CphsVmwfUpdReqArg();
        
        static const CphsVmwfUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetCphsVmwfArray(const CphsVmwfArray& cphs_vmwf_array) { m_cphs_vmwf_array = cphs_vmwf_array; }
        const CphsVmwfArray& GetCphsVmwfArray() const { return m_cphs_vmwf_array; }
        
        enum  {
            ID = 2421
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsVmwfUpdReqArg*) arg); }
        
        CphsVmwfArray m_cphs_vmwf_array;
        
    };

// Inline definitions
inline const CphsVmwfUpdReqArg& CphsVmwfUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsVmwfUpdReqArg!\n");
    return ((CphsVmwfUpdReqArg &) arg);
}



/*  ======================================================================
    Class CphsCfufUpdReqArg
    ====================================================================== */

class CphsCfufUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCfufUpdReqArg(const CphsCfufArray& cphs_cfuf_array);
        CphsCfufUpdReqArg();
        
        static const CphsCfufUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetCphsCfufArray(const CphsCfufArray& cphs_cfuf_array) { m_cphs_cfuf_array = cphs_cfuf_array; }
        const CphsCfufArray& GetCphsCfufArray() const { return m_cphs_cfuf_array; }
        
        enum  {
            ID = 2422
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCfufUpdReqArg*) arg); }
        
        CphsCfufArray m_cphs_cfuf_array;
        
    };

// Inline definitions
inline const CphsCfufUpdReqArg& CphsCfufUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCfufUpdReqArg!\n");
    return ((CphsCfufUpdReqArg &) arg);
}



/*  ======================================================================
    Class CphsCspReadReqArg
    ====================================================================== */

class CphsCspReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCspReadReqArg(const LineSelector& line_selector, INT no_of_groups, const CphsCspArray& cphs_csp_array);
        CphsCspReadReqArg();
        
        static const CphsCspReadReqArg& Cast(const StackMsgArgument& arg);
        void SetLineSelector(const LineSelector& line_selector) { m_line_selector = line_selector; }
        const LineSelector& GetLineSelector() const { return m_line_selector; }
        void SetNoOfGroups(INT no_of_groups) { m_no_of_groups = no_of_groups; }
        INT GetNoOfGroups() const { return m_no_of_groups; }
        void SetCphsCspArray(const CphsCspArray& cphs_csp_array) { m_cphs_csp_array = cphs_csp_array; }
        const CphsCspArray& GetCphsCspArray() const { return m_cphs_csp_array; }
        
        enum  {
            ID = 2423
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCspReadReqArg*) arg); }
        
        LineSelector m_line_selector;
        INT m_no_of_groups;
        CphsCspArray m_cphs_csp_array;
        
    };

// Inline definitions
inline const CphsCspReadReqArg& CphsCspReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCspReadReqArg!\n");
    return ((CphsCspReadReqArg &) arg);
}



/*  ======================================================================
    Class CphsCspUpdReqArg
    ====================================================================== */

class CphsCspUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        CphsCspUpdReqArg(const LineSelector& line_selector, INT no_of_groups, const CphsCspArray& cphs_csp_array);
        CphsCspUpdReqArg();
        
        static const CphsCspUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetLineSelector(const LineSelector& line_selector) { m_line_selector = line_selector; }
        const LineSelector& GetLineSelector() const { return m_line_selector; }
        void SetNoOfGroups(INT no_of_groups) { m_no_of_groups = no_of_groups; }
        INT GetNoOfGroups() const { return m_no_of_groups; }
        void SetCphsCspArray(const CphsCspArray& cphs_csp_array) { m_cphs_csp_array = cphs_csp_array; }
        const CphsCspArray& GetCphsCspArray() const { return m_cphs_csp_array; }
        
        enum  {
            ID = 2424
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((CphsCspUpdReqArg*) arg); }
        
        LineSelector m_line_selector;
        INT m_no_of_groups;
        CphsCspArray m_cphs_csp_array;
        
    };

// Inline definitions
inline const CphsCspUpdReqArg& CphsCspUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to CphsCspUpdReqArg!\n");
    return ((CphsCspUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimCbmiReadReqArg
    ====================================================================== */

class SimCbmiReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmiReadReqArg(INT rec_no);
        SimCbmiReadReqArg();
        
        static const SimCbmiReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        
        enum  {
            ID = 2426
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmiReadReqArg*) arg); }
        
        INT m_rec_no;
        
    };

// Inline definitions
inline const SimCbmiReadReqArg& SimCbmiReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmiReadReqArg!\n");
    return ((SimCbmiReadReqArg &) arg);
}



/*  ======================================================================
    Class SimCbmirReadReqArg
    ====================================================================== */

class SimCbmirReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmirReadReqArg(INT rec_no);
        SimCbmirReadReqArg();
        
        static const SimCbmirReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        
        enum  {
            ID = 2427
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmirReadReqArg*) arg); }
        
        INT m_rec_no;
        
    };

// Inline definitions
inline const SimCbmirReadReqArg& SimCbmirReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmirReadReqArg!\n");
    return ((SimCbmirReadReqArg &) arg);
}



/*  ======================================================================
    Class SimCbmiUpdReqArg
    ====================================================================== */

class SimCbmiUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmiUpdReqArg(INT rec_no, const CbmiData& cbmi_data);
        SimCbmiUpdReqArg();
        
        static const SimCbmiUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetCbmiData(const CbmiData& cbmi_data) { m_cbmi_data = cbmi_data; }
        const CbmiData& GetCbmiData() const { return m_cbmi_data; }
        
        enum  {
            ID = 2428
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmiUpdReqArg*) arg); }
        
        INT m_rec_no;
        CbmiData m_cbmi_data;
        
    };

// Inline definitions
inline const SimCbmiUpdReqArg& SimCbmiUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmiUpdReqArg!\n");
    return ((SimCbmiUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimCbmirUpdReqArg
    ====================================================================== */

class SimCbmirUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCbmirUpdReqArg(INT rec_no, const CbmiRange& cbmi_range);
        SimCbmirUpdReqArg();
        
        static const SimCbmirUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetCbmiRange(const CbmiRange& cbmi_range) { m_cbmi_range = cbmi_range; }
        const CbmiRange& GetCbmiRange() const { return m_cbmi_range; }
        
        enum  {
            ID = 2429
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCbmirUpdReqArg*) arg); }
        
        INT m_rec_no;
        CbmiRange m_cbmi_range;
        
    };

// Inline definitions
inline const SimCbmirUpdReqArg& SimCbmirUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCbmirUpdReqArg!\n");
    return ((SimCbmirUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimCcpReadReqArg
    ====================================================================== */

class SimCcpReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCcpReadReqArg(INT rec_no);
        SimCcpReadReqArg();
        
        static const SimCcpReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        
        enum  {
            ID = 2430
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCcpReadReqArg*) arg); }
        
        INT m_rec_no;
        
    };

// Inline definitions
inline const SimCcpReadReqArg& SimCcpReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCcpReadReqArg!\n");
    return ((SimCcpReadReqArg &) arg);
}



/*  ======================================================================
    Class SimCcpUpdReqArg
    ====================================================================== */

class SimCcpUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCcpUpdReqArg(INT rec_no, const CcpData& ccp_data);
        SimCcpUpdReqArg();
        
        static const SimCcpUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetCcpData(const CcpData& ccp_data) { m_ccp_data = ccp_data; }
        const CcpData& GetCcpData() const { return m_ccp_data; }
        
        enum  {
            ID = 2431
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCcpUpdReqArg*) arg); }
        
        INT m_rec_no;
        CcpData m_ccp_data;
        
    };

// Inline definitions
inline const SimCcpUpdReqArg& SimCcpUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCcpUpdReqArg!\n");
    return ((SimCcpUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimSmsrReadReqArg
    ====================================================================== */

class SimSmsrReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSmsrReadReqArg(INT rec_no);
        SimSmsrReadReqArg();
        
        static const SimSmsrReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        
        enum  {
            ID = 2432
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSmsrReadReqArg*) arg); }
        
        INT m_rec_no;
        
    };

// Inline definitions
inline const SimSmsrReadReqArg& SimSmsrReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSmsrReadReqArg!\n");
    return ((SimSmsrReadReqArg &) arg);
}



/*  ======================================================================
    Class SimSmsrUpdReqArg
    ====================================================================== */

class SimSmsrUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimSmsrUpdReqArg(INT rec_no, UINT8 link, const SmsrData& smsr_data);
        SimSmsrUpdReqArg();
        
        static const SimSmsrUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        void SetLink(UINT8 link) { m_link = link; }
        UINT8 GetLink() const { return m_link; }
        void SetSmsrData(const SmsrData& smsr_data) { m_smsr_data = smsr_data; }
        const SmsrData& GetSmsrData() const { return m_smsr_data; }
        
        enum  {
            ID = 2433
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimSmsrUpdReqArg*) arg); }
        
        INT m_rec_no;
        UINT8 m_link;
        SmsrData m_smsr_data;
        
    };

// Inline definitions
inline const SimSmsrUpdReqArg& SimSmsrUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimSmsrUpdReqArg!\n");
    return ((SimSmsrUpdReqArg &) arg);
}



/*  ======================================================================
    Class UsimUstReadReqArg
    ====================================================================== */

class UsimUstReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimUstReadReqArg();
        
        static const UsimUstReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2434
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimUstReadReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimUstReadReqArg& UsimUstReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimUstReadReqArg!\n");
    return ((UsimUstReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimPlmnReadReqArg
    ====================================================================== */

class UsimPlmnReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPlmnReadReqArg(const UsimReadType& read_type);
        UsimPlmnReadReqArg();
        
        static const UsimPlmnReadReqArg& Cast(const StackMsgArgument& arg);
        void SetReadType(const UsimReadType& read_type) { m_read_type = read_type; }
        const UsimReadType& GetReadType() const { return m_read_type; }
        
        enum  {
            ID = 2435
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPlmnReadReqArg*) arg); }
        
        UsimReadType m_read_type;
        
    };

// Inline definitions
inline const UsimPlmnReadReqArg& UsimPlmnReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPlmnReadReqArg!\n");
    return ((UsimPlmnReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimCsLociReadReqArg
    ====================================================================== */

class UsimCsLociReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimCsLociReadReqArg();
        
        static const UsimCsLociReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2436
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimCsLociReadReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimCsLociReadReqArg& UsimCsLociReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimCsLociReadReqArg!\n");
    return ((UsimCsLociReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimPsLociReadReqArg
    ====================================================================== */

class UsimPsLociReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPsLociReadReqArg();
        
        static const UsimPsLociReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2437
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPsLociReadReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimPsLociReadReqArg& UsimPsLociReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPsLociReadReqArg!\n");
    return ((UsimPsLociReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimLangReadReqArg
    ====================================================================== */

class UsimLangReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimLangReadReqArg(const UsimLangFileType& lang_file_type, INT list_index);
        UsimLangReadReqArg();
        
        static const UsimLangReadReqArg& Cast(const StackMsgArgument& arg);
        void SetLangFileType(const UsimLangFileType& lang_file_type) { m_lang_file_type = lang_file_type; }
        const UsimLangFileType& GetLangFileType() const { return m_lang_file_type; }
        void SetListIndex(INT list_index) { m_list_index = list_index; }
        INT GetListIndex() const { return m_list_index; }
        
        enum  {
            ID = 2438
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimLangReadReqArg*) arg); }
        
        UsimLangFileType m_lang_file_type;
        INT m_list_index;
        
    };

// Inline definitions
inline const UsimLangReadReqArg& UsimLangReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimLangReadReqArg!\n");
    return ((UsimLangReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimEccReadReqArg
    ====================================================================== */

class UsimEccReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimEccReadReqArg(INT recno);
        UsimEccReadReqArg();
        
        static const UsimEccReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        
        enum  {
            ID = 2439
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimEccReadReqArg*) arg); }
        
        INT m_recno;
        
    };

// Inline definitions
inline const UsimEccReadReqArg& UsimEccReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimEccReadReqArg!\n");
    return ((UsimEccReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimSmsParamReadReqArg
    ====================================================================== */

class UsimSmsParamReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimSmsParamReadReqArg(INT recno);
        UsimSmsParamReadReqArg();
        
        static const UsimSmsParamReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        
        enum  {
            ID = 2440
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimSmsParamReadReqArg*) arg); }
        
        INT m_recno;
        
    };

// Inline definitions
inline const UsimSmsParamReadReqArg& UsimSmsParamReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimSmsParamReadReqArg!\n");
    return ((UsimSmsParamReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimPlmnUpdReqArg
    ====================================================================== */

class UsimPlmnUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimPlmnUpdReqArg(INT recno, const UsimPlmn& plmn, const UsimUpdateAction& update_action);
        UsimPlmnUpdReqArg();
        
        static const UsimPlmnUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetPlmn(const UsimPlmn& plmn) { m_plmn = plmn; }
        const UsimPlmn& GetPlmn() const { return m_plmn; }
        void SetUpdateAction(const UsimUpdateAction& update_action) { m_update_action = update_action; }
        const UsimUpdateAction& GetUpdateAction() const { return m_update_action; }
        
        enum  {
            ID = 2441
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimPlmnUpdReqArg*) arg); }
        
        INT m_recno;
        UsimPlmn m_plmn;
        UsimUpdateAction m_update_action;
        
    };

// Inline definitions
inline const UsimPlmnUpdReqArg& UsimPlmnUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimPlmnUpdReqArg!\n");
    return ((UsimPlmnUpdReqArg &) arg);
}



/*  ======================================================================
    Class UsimCardTypeReadReqArg
    ====================================================================== */

class UsimCardTypeReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimCardTypeReadReqArg();
        
        static const UsimCardTypeReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2442
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimCardTypeReadReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimCardTypeReadReqArg& UsimCardTypeReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimCardTypeReadReqArg!\n");
    return ((UsimCardTypeReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimSmsParamUpdReqArg
    ====================================================================== */

class UsimSmsParamUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimSmsParamUpdReqArg(INT recno, const SmsParamRecord& sms_param_record);
        UsimSmsParamUpdReqArg();
        
        static const UsimSmsParamUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetSmsParamRecord(const SmsParamRecord& sms_param_record) { m_sms_param_record = sms_param_record; }
        const SmsParamRecord& GetSmsParamRecord() const { return m_sms_param_record; }
        
        enum  {
            ID = 2443
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimSmsParamUpdReqArg*) arg); }
        
        INT m_recno;
        SmsParamRecord m_sms_param_record;
        
    };

// Inline definitions
inline const UsimSmsParamUpdReqArg& UsimSmsParamUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimSmsParamUpdReqArg!\n");
    return ((UsimSmsParamUpdReqArg &) arg);
}



/*  ======================================================================
    Class UsimEstReadReqArg
    ====================================================================== */

class UsimEstReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimEstReadReqArg();
        
        static const UsimEstReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2444
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimEstReadReqArg*) arg); }
        
    };

// Inline definitions
inline const UsimEstReadReqArg& UsimEstReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimEstReadReqArg!\n");
    return ((UsimEstReadReqArg &) arg);
}



/*  ======================================================================
    Class UsimLangUpdReqArg
    ====================================================================== */

class UsimLangUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimLangUpdReqArg(const UsimLangFileType& lang_file_type, INT recno, const UsimLanguage& language, const UsimUpdateAction& update_action);
        UsimLangUpdReqArg();
        
        static const UsimLangUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetLangFileType(const UsimLangFileType& lang_file_type) { m_lang_file_type = lang_file_type; }
        const UsimLangFileType& GetLangFileType() const { return m_lang_file_type; }
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        void SetLanguage(const UsimLanguage& language) { m_language = language; }
        const UsimLanguage& GetLanguage() const { return m_language; }
        void SetUpdateAction(const UsimUpdateAction& update_action) { m_update_action = update_action; }
        const UsimUpdateAction& GetUpdateAction() const { return m_update_action; }
        
        enum  {
            ID = 2445
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimLangUpdReqArg*) arg); }
        
        UsimLangFileType m_lang_file_type;
        INT m_recno;
        UsimLanguage m_language;
        UsimUpdateAction m_update_action;
        
    };

// Inline definitions
inline const UsimLangUpdReqArg& UsimLangUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimLangUpdReqArg!\n");
    return ((UsimLangUpdReqArg &) arg);
}



/*  ======================================================================
    Class UsimFilePropertyReqArg
    ====================================================================== */

class UsimFilePropertyReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        UsimFilePropertyReqArg(const UsimReadType& read_type);
        UsimFilePropertyReqArg();
        
        static const UsimFilePropertyReqArg& Cast(const StackMsgArgument& arg);
        void SetReadType(const UsimReadType& read_type) { m_read_type = read_type; }
        const UsimReadType& GetReadType() const { return m_read_type; }
        
        enum  {
            ID = 2446
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((UsimFilePropertyReqArg*) arg); }
        
        UsimReadType m_read_type;
        
    };

// Inline definitions
inline const UsimFilePropertyReqArg& UsimFilePropertyReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to UsimFilePropertyReqArg!\n");
    return ((UsimFilePropertyReqArg &) arg);
}



/*  ======================================================================
    Class SimCmiReadReqArg
    ====================================================================== */

class SimCmiReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimCmiReadReqArg(INT rec_no);
        SimCmiReadReqArg();
        
        static const SimCmiReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecNo(INT rec_no) { m_rec_no = rec_no; }
        INT GetRecNo() const { return m_rec_no; }
        
        enum  {
            ID = 2460
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimCmiReadReqArg*) arg); }
        
        INT m_rec_no;
        
    };

// Inline definitions
inline const SimCmiReadReqArg& SimCmiReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimCmiReadReqArg!\n");
    return ((SimCmiReadReqArg &) arg);
}



/*  ======================================================================
    Class SimODynReadReqArg
    ====================================================================== */

class SimODynReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODynReadReqArg();
        
        static const SimODynReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2461
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODynReadReqArg*) arg); }
        
    };

// Inline definitions
inline const SimODynReadReqArg& SimODynReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODynReadReqArg!\n");
    return ((SimODynReadReqArg &) arg);
}



/*  ======================================================================
    Class SimODyn2ReadReqArg
    ====================================================================== */

class SimODyn2ReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODyn2ReadReqArg();
        
        static const SimODyn2ReadReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2462
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODyn2ReadReqArg*) arg); }
        
    };

// Inline definitions
inline const SimODyn2ReadReqArg& SimODyn2ReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODyn2ReadReqArg!\n");
    return ((SimODyn2ReadReqArg &) arg);
}



/*  ======================================================================
    Class SimODynUpdReqArg
    ====================================================================== */

class SimODynUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODynUpdReqArg(UINT8 flag);
        SimODynUpdReqArg();
        
        static const SimODynUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetFlag(UINT8 flag) { m_flag = flag; }
        UINT8 GetFlag() const { return m_flag; }
        
        enum  {
            ID = 2463
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODynUpdReqArg*) arg); }
        
        UINT8 m_flag;
        
    };

// Inline definitions
inline const SimODynUpdReqArg& SimODynUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODynUpdReqArg!\n");
    return ((SimODynUpdReqArg &) arg);
}



/*  ======================================================================
    Class SimODyn2UpdReqArg
    ====================================================================== */

class SimODyn2UpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimODyn2UpdReqArg(UINT8 flag);
        SimODyn2UpdReqArg();
        
        static const SimODyn2UpdReqArg& Cast(const StackMsgArgument& arg);
        void SetFlag(UINT8 flag) { m_flag = flag; }
        UINT8 GetFlag() const { return m_flag; }
        
        enum  {
            ID = 2464
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimODyn2UpdReqArg*) arg); }
        
        UINT8 m_flag;
        
    };

// Inline definitions
inline const SimODyn2UpdReqArg& SimODyn2UpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimODyn2UpdReqArg!\n");
    return ((SimODyn2UpdReqArg &) arg);
}



/*  ======================================================================
    Class SimMruPropertyUpdReqArg
    ====================================================================== */

class SimMruPropertyUpdReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimMruPropertyUpdReqArg(UINT16 type, UINT8 index, UINT8 bit_number, UINT8 bit_value);
        SimMruPropertyUpdReqArg();
        
        static const SimMruPropertyUpdReqArg& Cast(const StackMsgArgument& arg);
        void SetType(UINT16 type) { m_type = type; }
        UINT16 GetType() const { return m_type; }
        void SetIndex(UINT8 index) { m_index = index; }
        UINT8 GetIndex() const { return m_index; }
        void SetBitNumber(UINT8 bit_number) { m_bit_number = bit_number; }
        UINT8 GetBitNumber() const { return m_bit_number; }
        void SetBitValue(UINT8 bit_value) { m_bit_value = bit_value; }
        UINT8 GetBitValue() const { return m_bit_value; }
        
        enum  {
            ID = 2465
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimMruPropertyUpdReqArg*) arg); }
        
        UINT16 m_type;
        UINT8 m_index;
        UINT8 m_bit_number;
        UINT8 m_bit_value;
        
    };

// Inline definitions
inline const SimMruPropertyUpdReqArg& SimMruPropertyUpdReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimMruPropertyUpdReqArg!\n");
    return ((SimMruPropertyUpdReqArg &) arg);
}



/*  ======================================================================
    Class FdnReqArg
    ====================================================================== */

class FdnReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        FdnReqArg(const FdnState& fdn_state);
        FdnReqArg();
        
        static const FdnReqArg& Cast(const StackMsgArgument& arg);
        void SetFdnState(const FdnState& fdn_state) { m_fdn_state = fdn_state; }
        const FdnState& GetFdnState() const { return m_fdn_state; }
        
        enum  {
            ID = 2470
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((FdnReqArg*) arg); }
        
        FdnState m_fdn_state;
        
    };

// Inline definitions
inline const FdnReqArg& FdnReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to FdnReqArg!\n");
    return ((FdnReqArg &) arg);
}



/*  ======================================================================
    Class BdnReqArg
    ====================================================================== */

class BdnReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        BdnReqArg(const BdnState& bdn_state);
        BdnReqArg();
        
        static const BdnReqArg& Cast(const StackMsgArgument& arg);
        void SetBdnState(const BdnState& bdn_state) { m_bdn_state = bdn_state; }
        const BdnState& GetBdnState() const { return m_bdn_state; }
        
        enum  {
            ID = 2471
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BdnReqArg*) arg); }
        
        BdnState m_bdn_state;
        
    };

// Inline definitions
inline const BdnReqArg& BdnReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BdnReqArg!\n");
    return ((BdnReqArg &) arg);
}



/*  ======================================================================
    Class SimModifyLockReqArg
    ====================================================================== */

class SimModifyLockReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SimModifyLockReqArg(const SecLockStates& lock_states, const SecLockCommand& lock_command);
        SimModifyLockReqArg();
        
        static const SimModifyLockReqArg& Cast(const StackMsgArgument& arg);
        void SetLockStates(const SecLockStates& lock_states) { m_lock_states = lock_states; }
        const SecLockStates& GetLockStates() const { return m_lock_states; }
        void SetLockCommand(const SecLockCommand& lock_command) { m_lock_command = lock_command; }
        const SecLockCommand& GetLockCommand() const { return m_lock_command; }
        
        enum  {
            ID = 2472
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SimModifyLockReqArg*) arg); }
        
        SecLockStates m_lock_states;
        SecLockCommand m_lock_command;
        
    };

// Inline definitions
inline const SimModifyLockReqArg& SimModifyLockReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SimModifyLockReqArg!\n");
    return ((SimModifyLockReqArg &) arg);
}


#endif // Apc_SimMiscStackMsgArgs_hpp

