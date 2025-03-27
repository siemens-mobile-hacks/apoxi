/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "APOXI\SDK\bin\MessageGenerator\samples\SampleMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(EmServThreadMsg_hpp__ST_1128926169290)
#define EmServThreadMsg_hpp__ST_1128926169290

#include <Kernel/Message.hpp>
#include <Auxiliary/WString.hpp>
#include <EmApoxiDataTypes.hpp>
#include <EmApoxiAudioDeviceImpl.hpp>
#include <Kernel/InputStream.hpp>
#include <Kernel/OutputStream.hpp>

typedef EmApoxiUINT32 (*tCallbackFnPtr)(EmApoxiUINT32);

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class EmServThreadMsg
    ====================================================================== */

class EmServThreadMsg : public ContextMsg  {

    public:
        EmServThreadMsg(ExecutionContext* application, const tEmApxAudDeviceHdl& m_h_aud_device, const tCallbackFnPtr& m_cb_fn_ptr, void * m_cb_data, const EmApoxiBOOLEAN& m_is_audio_muted, const EmApoxiBOOLEAN& m_start_stop_audio);
        virtual ~EmServThreadMsg();

        virtual const MsgMetaData& GetMetaData() const;
        void SetMHAudDevice(const tEmApxAudDeviceHdl& m_h_aud_device) { m_m_h_aud_device = m_h_aud_device; }
        const tEmApxAudDeviceHdl& GetMHAudDevice() const { return m_m_h_aud_device; }
        void SetMCbFnPtr(const tCallbackFnPtr& m_cb_fn_ptr) { m_m_cb_fn_ptr = m_cb_fn_ptr; }
        const tCallbackFnPtr& GetMCbFnPtr() const { return m_m_cb_fn_ptr; }
        void SetMCbData(void * m_cb_data) { m_m_cb_data = m_cb_data; }
        void * GetMCbData() const { return m_m_cb_data; }
        void SetMIsAudioMuted(const EmApoxiBOOLEAN& m_is_audio_muted) { m_m_is_audio_muted = m_is_audio_muted; }
        const EmApoxiBOOLEAN& GetMIsAudioMuted() const { return m_m_is_audio_muted; }
        void SetMStartStopAudio(const EmApoxiBOOLEAN& m_start_stop_audio) { m_m_start_stop_audio = m_start_stop_audio; }
        const EmApoxiBOOLEAN& GetMStartStopAudio() const { return m_m_start_stop_audio; }
        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const EmServThreadMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, EmServThreadMsg& cls);
#endif // APOXI_NOSTREAMING

        enum {
            ID = 54002
        };

    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        tEmApxAudDeviceHdl m_m_h_aud_device;
        tCallbackFnPtr m_m_cb_fn_ptr;
        void * m_m_cb_data;
        EmApoxiBOOLEAN m_m_is_audio_muted;
        EmApoxiBOOLEAN m_m_start_stop_audio;
        
};

#endif // EmServThreadMsg_hpp__ST_1128926169290

