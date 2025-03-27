/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "hauth_voicerec_dv\lnz_apoxi\Apoxi\AddOns\VoiceRecognition\VrArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_VoiceRecognition_VrStackMsgArgs_hpp)
#define AddOns_VoiceRecognition_VrStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <AddOns/VoiceRecognition/VrHandler.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class VrParamReqArg
    ====================================================================== */

class VrParamReqArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrParamReqArg();
        ~VrParamReqArg();
        
        static const VrParamReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5000
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrParamReqArg*) arg); }
        
    };

// Inline definitions
inline const VrParamReqArg& VrParamReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrParamReqArg!\n");
    return ((VrParamReqArg &) arg);
}



/*  ======================================================================
    Class VrInitCnfArg
    ====================================================================== */

class VrInitCnfArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrInitCnfArg();
        ~VrInitCnfArg();
        
        static const VrInitCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5001
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrInitCnfArg*) arg); }
        
    };

// Inline definitions
inline const VrInitCnfArg& VrInitCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrInitCnfArg!\n");
    return ((VrInitCnfArg &) arg);
}



/*  ======================================================================
    Class VrLoadTemplateReqArg
    ====================================================================== */

class VrLoadTemplateReqArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrLoadTemplateReqArg(UINT32 template_id);
        VrLoadTemplateReqArg();
        ~VrLoadTemplateReqArg();
        
        static const VrLoadTemplateReqArg& Cast(const StackMsgArgument& arg);
        UINT32 GetTemplateId() const { return m_template_id; }
        
        enum  {
            ID = 5002
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrLoadTemplateReqArg*) arg); }
        
        UINT32 m_template_id;
        
    };

// Inline definitions
inline const VrLoadTemplateReqArg& VrLoadTemplateReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrLoadTemplateReqArg!\n");
    return ((VrLoadTemplateReqArg &) arg);
}



/*  ======================================================================
    Class VrSayNameIndArg
    ====================================================================== */

class VrSayNameIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrSayNameIndArg();
        ~VrSayNameIndArg();
        
        static const VrSayNameIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5003
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrSayNameIndArg*) arg); }
        
    };

// Inline definitions
inline const VrSayNameIndArg& VrSayNameIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrSayNameIndArg!\n");
    return ((VrSayNameIndArg &) arg);
}



/*  ======================================================================
    Class VrIntrmRecResultIndArg
    ====================================================================== */

class VrIntrmRecResultIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrIntrmRecResultIndArg(UINT32 template_id, UINT32 quality);
        VrIntrmRecResultIndArg();
        ~VrIntrmRecResultIndArg();
        
        static const VrIntrmRecResultIndArg& Cast(const StackMsgArgument& arg);
        UINT32 GetTemplateId() const { return m_template_id; }
        UINT32 GetQuality() const { return m_quality; }
        
        enum  {
            ID = 5004
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrIntrmRecResultIndArg*) arg); }
        
        UINT32 m_template_id;
        UINT32 m_quality;
        
    };

// Inline definitions
inline const VrIntrmRecResultIndArg& VrIntrmRecResultIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrIntrmRecResultIndArg!\n");
    return ((VrIntrmRecResultIndArg &) arg);
}



/*  ======================================================================
    Class VrRecogResultIndArg
    ====================================================================== */

class VrRecogResultIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrRecogResultIndArg(UINT32 template_id, UINT32 quality);
        VrRecogResultIndArg();
        ~VrRecogResultIndArg();
        
        static const VrRecogResultIndArg& Cast(const StackMsgArgument& arg);
        UINT32 GetTemplateId() const { return m_template_id; }
        UINT32 GetQuality() const { return m_quality; }
        
        enum  {
            ID = 5005
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrRecogResultIndArg*) arg); }
        
        UINT32 m_template_id;
        UINT32 m_quality;
        
    };

// Inline definitions
inline const VrRecogResultIndArg& VrRecogResultIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrRecogResultIndArg!\n");
    return ((VrRecogResultIndArg &) arg);
}



/*  ======================================================================
    Class VrTrainResultIndArg
    ====================================================================== */

class VrTrainResultIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrTrainResultIndArg();
        ~VrTrainResultIndArg();
        
        static const VrTrainResultIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5006
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrTrainResultIndArg*) arg); }
        
    };

// Inline definitions
inline const VrTrainResultIndArg& VrTrainResultIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrTrainResultIndArg!\n");
    return ((VrTrainResultIndArg &) arg);
}



/*  ======================================================================
    Class VrAbortEngineIndArg
    ====================================================================== */

class VrAbortEngineIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrAbortEngineIndArg();
        ~VrAbortEngineIndArg();
        
        static const VrAbortEngineIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5007
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrAbortEngineIndArg*) arg); }
        
    };

// Inline definitions
inline const VrAbortEngineIndArg& VrAbortEngineIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrAbortEngineIndArg!\n");
    return ((VrAbortEngineIndArg &) arg);
}



/*  ======================================================================
    Class VrStopRecogIndArg
    ====================================================================== */

class VrStopRecogIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrStopRecogIndArg();
        ~VrStopRecogIndArg();
        
        static const VrStopRecogIndArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 5008
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrStopRecogIndArg*) arg); }
        
    };

// Inline definitions
inline const VrStopRecogIndArg& VrStopRecogIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrStopRecogIndArg!\n");
    return ((VrStopRecogIndArg &) arg);
}



/*  ======================================================================
    Class VrStoreTemplateReqArg
    ====================================================================== */

class VrStoreTemplateReqArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrStoreTemplateReqArg(UINT16* template_data, UINT32 template_data_length, UINT8* playback_samples, UINT32 sample_data_length);
        VrStoreTemplateReqArg();
        ~VrStoreTemplateReqArg();
        
        static const VrStoreTemplateReqArg& Cast(const StackMsgArgument& arg);
        UINT16* GetTemplateData() const { return m_template_data; }
        UINT32 GetTemplateDataLength() const { return m_template_data_length; }
        UINT8* GetPlaybackSamples() const { return m_playback_samples; }
        UINT32 GetSampleDataLength() const { return m_sample_data_length; }
        
        enum  {
            ID = 5009
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrStoreTemplateReqArg*) arg); }
        
        UINT16* m_template_data;
        UINT32 m_template_data_length;
        UINT8* m_playback_samples;
        UINT32 m_sample_data_length;
        
    };

// Inline definitions
inline const VrStoreTemplateReqArg& VrStoreTemplateReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrStoreTemplateReqArg!\n");
    return ((VrStoreTemplateReqArg &) arg);
}



/*  ======================================================================
    Class VrG2AResultIndArg
    ====================================================================== */

class VrG2AResultIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrG2AResultIndArg(UINT16* template_data, UINT32 template_data_length);
        VrG2AResultIndArg();
        ~VrG2AResultIndArg();
        
        static const VrG2AResultIndArg& Cast(const StackMsgArgument& arg);
        UINT16* GetTemplateData() const { return m_template_data; }
        UINT32 GetTemplateDataLength() const { return m_template_data_length; }
        
        enum  {
            ID = 5012
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrG2AResultIndArg*) arg); }
        
        UINT16* m_template_data;
        UINT32 m_template_data_length;
        
    };

// Inline definitions
inline const VrG2AResultIndArg& VrG2AResultIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrG2AResultIndArg!\n");
    return ((VrG2AResultIndArg &) arg);
}



/*  ======================================================================
    Class VrErrorIndArg
    ====================================================================== */

class VrErrorIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrErrorIndArg(const VrErrorCode& error_code);
        VrErrorIndArg();
        ~VrErrorIndArg();
        
        static const VrErrorIndArg& Cast(const StackMsgArgument& arg);
        const VrErrorCode& GetErrorCode() const { return m_error_code; }
        
        enum  {
            ID = 5010
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrErrorIndArg*) arg); }
        
        VrErrorCode m_error_code;
        
    };

// Inline definitions
inline const VrErrorIndArg& VrErrorIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrErrorIndArg!\n");
    return ((VrErrorIndArg &) arg);
}



/*  ======================================================================
    Class VrWarningIndArg
    ====================================================================== */

class VrWarningIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrWarningIndArg(const VrWarningCode& warning_code);
        VrWarningIndArg();
        ~VrWarningIndArg();
        
        static const VrWarningIndArg& Cast(const StackMsgArgument& arg);
        const VrWarningCode& GetWarningCode() const { return m_warning_code; }
        
        enum  {
            ID = 5011
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrWarningIndArg*) arg); }
        
        VrWarningCode m_warning_code;
        
    };

// Inline definitions
inline const VrWarningIndArg& VrWarningIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrWarningIndArg!\n");
    return ((VrWarningIndArg &) arg);
}



/*  ======================================================================
    Class VrPropertyResultIndArg
    ====================================================================== */

class VrPropertyResultIndArg : public StackMsgArgument {
    friend class VrStackMsgArgTableDestroyTableNode;
    public:
        VrPropertyResultIndArg(const VrProperty& property);
        VrPropertyResultIndArg();
        ~VrPropertyResultIndArg();
        
        static const VrPropertyResultIndArg& Cast(const StackMsgArgument& arg);
        const VrProperty& GetProperty() const { return m_property; }
        
        enum  {
            ID = 5013
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((VrPropertyResultIndArg*) arg); }
        
        VrProperty m_property;
        
    };

// Inline definitions
inline const VrPropertyResultIndArg& VrPropertyResultIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to VrPropertyResultIndArg!\n");
    return ((VrPropertyResultIndArg &) arg);
}


#endif // AddOns_VoiceRecognition_VrStackMsgArgs_hpp

