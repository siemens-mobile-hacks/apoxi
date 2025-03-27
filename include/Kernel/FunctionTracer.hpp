/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(FUNCTION_TRACER_HPP)
#define FUNCTION_TRACER_HPP

#include <Auxiliary/WStrUtil.hpp>

#if (__ARMCC_VERSION>=200000)
    #include <string.h>
#else
    extern "C" size_t strlen(const char *string);
#endif

class _NullFunctionTracer {
    public:
        _NullFunctionTracer() {}
        _NullFunctionTracer(const void* this_ptr) {}
        ~_NullFunctionTracer() {}
        void TraceCheckPoint() {}
        void StackTrace() {}

        static void TraceNew(const void* linkreg, const void* ptr, UINT16 size) {}
        static void TraceDelete(const void* linkreg, const void* ptr) {}
        static void TraceMessage(int id, const void* ptr, UINT16 size) {}
        static void TraceVersion(const CHAR* str) {}
        static void TraceWarning(const CHAR* str) {}
        static void TraceError(const CHAR* str) {}
        static void TraceObjectCreate(const void* ptr) {}
        static void TraceObjectDestroy(const void* ptr) {}
        static void TraceTestState(UINT16 testID, const CHAR* str, const void* linkreg) {}

        template<class T>
        void TraceVariable(const T& obj) {}
};  // _NullFunctionTracer



template<class T>
void TraceDataHelper(InternalTracer::TraceMask mask, const void* linkreg, T* obj) {
    InternalTracer::TraceData(mask, linkreg, obj, sizeof(T));
}



template<InternalTracer::TraceMask mask>
class _FunctionTracer {
    public:
        _FunctionTracer() {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceFuncBegin(mask, linkreg, 0);
        }
        
        _FunctionTracer(const void* this_ptr) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceFuncBegin(mask, linkreg, this_ptr);
        }
        
        ~_FunctionTracer() {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceFuncEnd(mask, linkreg);
        }
        
        void TraceCheckPoint() {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceFuncCheckPoint(mask, linkreg);
        }
        
        void StackTrace() {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceFuncStackTrace(mask, linkreg);
        }

        static void TraceNew(const void* linkreg, const void* ptr, UINT16 size) {
            InternalTracer::TraceNew(linkreg, ptr, size);
        }

        static void TraceDelete(const void* linkreg, const void* ptr) {
            InternalTracer::TraceDelete(linkreg, ptr);
        }

        static void TraceMessage(UINT16 id, const void* ptr, UINT16 size) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceMessage(linkreg, id, ptr, size);
        }
        
        static void TraceVersion(const CHAR* str) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceBuffer(linkreg, InternalTracer::Version, str, strlen(str)+1);
        }
        
        static void TraceWarning(const CHAR* str) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceBuffer(linkreg, InternalTracer::Warning, str, strlen(str)+1);
        }

        static void TraceError(const CHAR* str) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceBuffer(linkreg, InternalTracer::Error, str, strlen(str)+1);
        }
        
        static void TraceObjectCreate(const void* ptr) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceObj(linkreg, InternalTracer::ObjectCreate, ptr);
        }

        static void TraceObjectDestroy(const void* ptr) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceObj(linkreg, InternalTracer::ObjectDestroy, ptr);
        }

        static void TraceTestState(UINT16 testID, const CHAR* str, const void* linkreg) {
            InternalTracer::TraceTestState(linkreg, testID, str, strlen(str)+1);
        }
        
        
        template<class T>
            void TraceVariable(const T& obj) {
                const void* linkreg=0;
                #if defined(APOXI_RTOS_NUC32)
                    // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
                #endif
            TraceDataHelper(mask, linkreg, &obj);
        }
        
        
        void TraceVariable(const long& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::Long, &val, sizeof(long));
        }
        
        void TraceVariable(const unsigned long& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::ULong, &val, sizeof(unsigned long));
        }
        
        void TraceVariable(const int& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::Int, &val, sizeof(int));
        }
        
        void TraceVariable(const unsigned int& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::UInt, &val, sizeof(unsigned int));
        }
        
        void TraceVariable(const short& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::Short, &val, sizeof(short));
        }
        
        void TraceVariable(const unsigned short& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::UShort, &val, sizeof(unsigned short));
        }
        
        void TraceVariable(const char& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::Char, &val, sizeof(char));
        }
        
        void TraceVariable(const unsigned char& val) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::UChar, &val, sizeof(unsigned char));
        }
        
        void TraceVariable(const char* str) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::String, str, strlen(str)+1);
        }
        
        void TraceVariable(const WCHAR* str) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceData(mask, linkreg, InternalTracer::WString, (char*)str, WStrLen(str)*2+2);
        }
        
};  // _FunctionTracer

#endif // FUNCTION_TRACER_HPP


