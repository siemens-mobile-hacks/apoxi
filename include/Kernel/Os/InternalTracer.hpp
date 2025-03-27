/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(INTERNAL_TRACER_HPP)
#define INTERNAL_TRACER_HPP

#include <Kernel/Types.hpp>


#define DECLARE_CLASS(id)       enum CLASS_ID { ID = (id) }; static CLASS_ID GetID() { CLASS_ID _id = ID; return _id; }

#if defined(APOXI_RTOS_WIN32)
#pragma pack( push, InternalTracer, 2 )
#endif

class InternalTracer {
    public:
        enum TraceMask {
            Always  = 0x0000,
            Adc     = 0x0001,
            Apc     = 0x0002,
            Asc     = 0x0004,
            Aux     = 0x0008,
            Gui     = 0x0010,
            Kernel  = 0x0020,
            Socket  = 0x0040,
            Mmi     = 0x0080,
            App1    = 0x0100,
            App2    = 0x0200,
            App3    = 0x0400,
            App4    = 0x0800,
                
            Mem     = 0x1000,
            Func    = 0x2000,
            Obj     = 0x4000,
            Data    = -32768,   // 0x8000
                
#if defined(APOXI_TRACE_MEM)
            DefaultMask = Mem
#else
            DefaultMask = 0xFFF | Func | Obj | Data
#endif
        };
        
        enum TraceId {
            Unknown         = 0x0000,
            UChar           = 0x0003,
            ULong           = 0x0007,
            String          = 0x000e,
            Int             = 0x0010,
            UInt            = 0x0012,
            Char            = 0x0013,
            Long            = 0x0014,
            Short           = 0x0015,
            UShort          = 0x0016,
            WString         = 0x001E,
                
            TestState       = 0x00E0,
            New             = 0x00F0,
            Delete          = 0x00F1,
            AppBegin        = 0x00F2,
            AppEnd          = 0x00F3,
            ObjectCreate    = 0x00F4,
            ObjectDestroy   = 0x00F5,
            DataTrace       = 0x00F6,
            Misc            = 0x00F7,
            Message         = 0x00F8,
            Version         = 0x00F9,
            Warning         = 0x00FA,
            FunctionBegin   = 0x00FB,
            CheckPoint      = 0x00FC,
            FuncStackTrace  = 0x00FD,
            FunctionEnd     = 0x00FE,
            Error           = 0x00FF
        };
        
        enum {
            APP_NAME_LENGTH = 20,
            STACK_TRACE_DEPTH = 10,
            MAX_DATA_LENGTH = 400
        };
        
        struct TsStruct {
            UINT32 ts;
        };

        struct TraceHeader {
            UINT16 id;          // id, type
            UINT8 nestedLevel;  //
            UINT8 appId;        // application id, provided by apoxi
            TsStruct ts;            // timestamp
            const void* codeAdr;  
        };

        static void SetGlobalTraceMask(TraceMask mask) {
            g_globalMask = mask;
        }
        
        static TraceMask GetGlobalTraceMask() {
            return g_globalMask;
        }
        
        static void Init();
        static void TraceMiscData      (TraceMask mask, const void* linkreg, const void* data, UINT16 len);
        static void TraceData          (TraceMask mask, const void* linkreg, const void* data, UINT16 len);
        static void TraceData          (TraceMask mask, const void* linkreg, TraceId id, const void* data, UINT16 len);
        static void TraceFuncBegin     (TraceMask mask, const void* linkreg, const void* this_ptr);
        static void TraceFuncCheckPoint(TraceMask mask, const void* linkreg);
        static void TraceFuncStackTrace(TraceMask mask, const void* linkreg);
        static void TraceFuncEnd       (TraceMask mask, const void* linkreg);
        static void TraceNew      (const void* linkreg, const void* ptr, UINT16 size);
        static void TraceDelete   (const void* linkreg, const void* ptr);
        static void TraceMessage  (const void* linkreg, UINT16 id, const void* ptr, UINT16 size);
        static void TraceBuffer   (const void* linkreg, UINT16 id, const void* str, UINT16 size);
        static void TraceAppAttach(const void* linkreg, const void* app, const void* container, 
                                                        const WCHAR* appName, UINT8 newAppId);
        static void TraceAppDetach(const void* linkreg, const void* app, UINT8 newAppId);
        static void TraceObj      (const void* linkreg, TraceId id, const void* ptr);
        static void TraceTestState(const void* linkreg, UINT16 testID, const void* str, UINT16 len);
        
    protected:
        static TraceMask g_globalMask;
        
        InternalTracer() {};
        
        static unsigned char NestedLevel();
        static const void* CallStackAdr(INT16 level);
        
    private:
        struct DataTraceHeader {
            TraceHeader h;
            const void* traceHelperAdr;
        };
        
        struct TraceMessageData {
            TraceHeader h;
            UINT16 message_id;
        };

        struct AttachData {
            const void* app;
            const void* container;
            UINT8 appId;
            WCHAR appName[APP_NAME_LENGTH];
        };
        
        struct DetachData {
            const void* app;
            UINT8 appId;
        };
        
        struct NewData {
            const void* adr1;
            const void* ptr;
            UINT16 size;
        };
        
        struct DelData {
            const void* adr1;
            const void* ptr;
        };
        
        struct TestStateData {
            TraceHeader h;
            UINT16 testID;
        };
        
        // don't allow cloning
        InternalTracer(const InternalTracer&);
        InternalTracer& operator=(const InternalTracer&);
        
        // don't allow creating on heap
        void* operator new(size_t size);
        void operator delete(void* ptr);
        
};  // Tracer



#if defined(APOXI_RTOS_WIN32)
#pragma pack( pop, InternalTracer )
#endif


#endif // INTERNAL_TRACER_HPP

