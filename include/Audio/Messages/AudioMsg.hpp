/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "src\wickhara_apoxitest_host\lnz_apoxi\Apoxi\Audio\Messages\AudioTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apoxi_Audio_AudioMsg_hpp)
#define Apoxi_Audio_AudioMsg_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AudioMsg
    ====================================================================== */

class AudioMsg : public Message {
    public:
        AudioMsg(UINT8 handle, UINT16 drv_id, UINT16 funk_id, INT8 return_code, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);
        virtual ~AudioMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetHandle(UINT8 handle) { m_handle = handle; }
        UINT8 GetHandle() const { return m_handle; }
        void SetDrvId(UINT16 drv_id) { m_drv_id = drv_id; }
        UINT16 GetDrvId() const { return m_drv_id; }
        void SetFunkId(UINT16 funk_id) { m_funk_id = funk_id; }
        UINT16 GetFunkId() const { return m_funk_id; }
        void SetReturnCode(INT8 return_code) { m_return_code = return_code; }
        INT8 GetReturnCode() const { return m_return_code; }
        void SetParam1(UINT32 param1) { m_param1 = param1; }
        UINT32 GetParam1() const { return m_param1; }
        void SetParam2(UINT32 param2) { m_param2 = param2; }
        UINT32 GetParam2() const { return m_param2; }
        void SetParam3(UINT32 param3) { m_param3 = param3; }
        UINT32 GetParam3() const { return m_param3; }
        void SetParam4(UINT32 param4) { m_param4 = param4; }
        UINT32 GetParam4() const { return m_param4; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT8 m_handle;
        UINT16 m_drv_id;
        UINT16 m_funk_id;
        INT8 m_return_code;
        UINT32 m_param1;
        UINT32 m_param2;
        UINT32 m_param3;
        UINT32 m_param4;
        
    };

#endif // Apoxi_Audio_AudioMsg_hpp

