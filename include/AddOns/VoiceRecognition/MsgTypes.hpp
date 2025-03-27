/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "hauth_voicerec_dv\lnz_apoxi\Apoxi\AddOns\VoiceRecognition\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(VoiceRecognition_MsgTypes_hpp)
#define VoiceRecognition_MsgTypes_hpp

#include <Kernel/Message.hpp>
#include <AddOns/VoiceRecognition/VrHandler.hpp>
#include <Apc/SignalTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class VrPromptMsg
    ====================================================================== */

class VrPromptMsg : public ContextMsg {
    public:
        VrPromptMsg(ExecutionContext* context);
        virtual ~VrPromptMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class VrResultMsg
    ====================================================================== */

class VrResultMsg : public ContextMsg {
    public:
        VrResultMsg(ExecutionContext* context, const VrHandler::VrCommand& command, UINT32 template_id, UINT32 quality, BOOLEAN last_result);
        virtual ~VrResultMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const VrHandler::VrCommand& GetCommand() const { return m_command; }
        UINT32 GetTemplateId() const { return m_template_id; }
        UINT32 GetQuality() const { return m_quality; }
        BOOLEAN IsLastResult() const { return m_last_result; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        VrHandler::VrCommand m_command;
        UINT32 m_template_id;
        UINT32 m_quality;
        BOOLEAN m_last_result;
        
    };


/*  ======================================================================
    Class VrErrorMsg
    ====================================================================== */

class VrErrorMsg : public ContextMsg {
    public:
        VrErrorMsg(ExecutionContext* context, const VrErrorCode& error_code);
        virtual ~VrErrorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const VrErrorCode& GetErrorCode() const { return m_error_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19002
            };
        
    private:
        static const MsgMetaData m_meta_data;
        VrErrorCode m_error_code;
        
    };


/*  ======================================================================
    Class VrWarningMsg
    ====================================================================== */

class VrWarningMsg : public ContextMsg {
    public:
        VrWarningMsg(ExecutionContext* context, const VrWarningCode& warning_code);
        virtual ~VrWarningMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const VrWarningCode& GetWarningCode() const { return m_warning_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19003
            };
        
    private:
        static const MsgMetaData m_meta_data;
        VrWarningCode m_warning_code;
        
    };


/*  ======================================================================
    Class VrRecognitionAbortedMsg
    ====================================================================== */

class VrRecognitionAbortedMsg : public ContextMsg {
    public:
        VrRecognitionAbortedMsg(ExecutionContext* context);
        virtual ~VrRecognitionAbortedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19004
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class VrTrainingAbortedMsg
    ====================================================================== */

class VrTrainingAbortedMsg : public ContextMsg {
    public:
        VrTrainingAbortedMsg(ExecutionContext* context);
        virtual ~VrTrainingAbortedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19005
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class VrRecognitionStoppedMsg
    ====================================================================== */

class VrRecognitionStoppedMsg : public ContextMsg {
    public:
        VrRecognitionStoppedMsg(ExecutionContext* context);
        virtual ~VrRecognitionStoppedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19006
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class VrTrainingResultMsg
    ====================================================================== */

class VrTrainingResultMsg : public ContextMsg {
    public:
        VrTrainingResultMsg(ExecutionContext* context, UINT32 template_id);
        virtual ~VrTrainingResultMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT32 GetTemplateId() const { return m_template_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19007
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT32 m_template_id;
        
    };


/*  ======================================================================
    Class VrPlaybackFinishedMsg
    ====================================================================== */

class VrPlaybackFinishedMsg : public ContextMsg {
    public:
        VrPlaybackFinishedMsg(ExecutionContext* context, UINT32 template_id);
        virtual ~VrPlaybackFinishedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT32 GetTemplateId() const { return m_template_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19008
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT32 m_template_id;
        
    };


/*  ======================================================================
    Class VrTrainingFailedMsg
    ====================================================================== */

class VrTrainingFailedMsg : public ContextMsg {
    public:
        VrTrainingFailedMsg(ExecutionContext* context);
        virtual ~VrTrainingFailedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19009
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class VrRecognitionFailedMsg
    ====================================================================== */

class VrRecognitionFailedMsg : public ContextMsg {
    public:
        VrRecognitionFailedMsg(ExecutionContext* context);
        virtual ~VrRecognitionFailedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 19010
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // VoiceRecognition_MsgTypes_hpp

