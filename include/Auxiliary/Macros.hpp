/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Macros_hpp)
#define Apoxi_Macros_hpp

#include <Kernel/Os/Trap.hpp>
#include <Kernel/Os/OsClass.hpp>

/*  ----------------------------------------------------------------
    SaveDelete
    ---------------------------------------------------------------- */
#define SaveDelete(p)       { delete (p); (p) = 0; }

// Obsolete - use ASSERT_ALWAYS or ASSERT_DEBUG instead
#if !defined(ASSERT)
    #if defined(_MSC)
        #include <assert.h>
        #define ASSERT(cond)            assert(cond)
    #else
        #define ASSERT(cond)            Trap::Assertion(cond, __FILE__, __LINE__);
    #endif
#endif

// Obsolete - use ASSERT_DEBUG_INFO instead
#if !defined(ASSERT_INFO)
/*
    #define ASSERT_INFO(cond, text) {                   \
        if (!(cond)) {                                  \
            DBG_OUT((0, L"ASSERTION: "text L"\n"));     \
        }                                               \
        ASSERT(cond);                                   \
    }
*/
    #define ASSERT_INFO ASSERT_DEBUG_INFO
#endif

/*  ----------------------------------------------------------------
    ASSERT_ALWAYS
    ---------------------------------------------------------------- */
#if !defined(ASSERT_ALWAYS)
    #if defined(_MSC)
        #include <assert.h>
        #define ASSERT_ALWAYS(cond)     assert(cond)
    #else
        #define ASSERT_ALWAYS(cond)     Trap::Assertion(cond, __FILE__, __LINE__);
    #endif
#endif

/*  ----------------------------------------------------------------
    ASSERT_DEBUG
    ---------------------------------------------------------------- */
#if defined(_DEBUG)
    #if !defined(ASSERT_DEBUG)
        #if defined(_MSC)
            #include <assert.h>
            #define ASSERT_DEBUG(cond)  assert(cond)
        #else
            #define ASSERT_DEBUG(cond)  Trap::Assertion(cond, __FILE__, __LINE__);
        #endif
    #endif
    #if !defined(ASSERT_DEBUG_INFO)
        #define ASSERT_DEBUG_INFO(cond, text)   {           \
            if (!(cond)) {                                  \
                DBG_OUT((0, L"ASSERTION: "text L"\n"));     \
            }                                               \
            ASSERT_DEBUG(cond);                             \
        }
    #endif
#else
    #if !defined(ASSERT_DEBUG)
        #define ASSERT_DEBUG(cond)
    #endif
    #if !defined(ASSERT_DEBUG_INFO)
        #define ASSERT_DEBUG_INFO(cond, text)
    #endif
#endif

/*  ----------------------------------------------------------------
    ASSERT_DEBUG_HOST
    ---------------------------------------------------------------- */
#if !defined(ASSERT_DEBUG_HOST)
    #if defined(_DEBUG)
        #if defined(_MSC)
            #include <assert.h>
            #define ASSERT_DEBUG_HOST(cond)         assert(cond)
        #else
            #define ASSERT_DEBUG_HOST(cond)
        #endif
    #else
        #define ASSERT_DEBUG_HOST(cond)
    #endif
#endif

/*  ----------------------------------------------------------------
    DBG_OUT
    ---------------------------------------------------------------- */
#if ( defined(_DEBUG) || defined(APOXI_ENABLE_DBG_OUT) )
    #define DBG_OUT(args)   Os::DbgOut args
#else
    #define DBG_OUT(args)
#endif

/*  ----------------------------------------------------------------
    DBG_OUT_STACK_USAGE
    ---------------------------------------------------------------- */
#if ( defined(_DEBUG) || defined(APOXI_ENABLE_DBG_OUT) )
    #define DBG_OUT_STACK_USAGE()   Os::DbgOutStackUsage()
#else
    #define DBG_OUT_STACK_USAGE()
#endif

/*  ----------------------------------------------------------------
    Unused
    ---------------------------------------------------------------- */
template<class T> inline void Unused(const T &t)
{
    const T *x = &t;
    x++;
}

/*  ----------------------------------------------------------------
    Disable warning C4355 for the Microsoft Visual-Studio Compiler:
    << 'this' : used in base member initializer list >>
    because 'this' is always used in a clean way.
    ---------------------------------------------------------------- */
#if defined(APOXI_COMPILER_MSVC)
    #pragma warning(disable : 4355)
#endif

/*  ----------------------------------------------------------------
    #pragma message (LOC_W("iii to do"))
    dumps 
      z:\lnz_development\src\apoxi\devices\win32\Dummy.cpp(15): Warning: iii to do
    into build window of Visual Studio.
    That row can be double clicked to go to the source.
    ---------------------------------------------------------------- */
#if defined(APOXI_COMPILER_MSVC)
    #define LOC_HELPER2(z) #z
    #define LOC_HELPER1(y) LOC_HELPER2(y)

    #define LOC_W(x) __FILE__ "(" LOC_HELPER1(__LINE__) "): Warning: " x
    #define LOC(x) __FILE__ "(" LOC_HELPER1(__LINE__) "): " x
#else
    #define LOC(x)
    #define LOC_W(x)
#endif

#undef min
#define min(a,b) (((a) < (b)) ? (a) : (b))

#undef max
#define max(a,b) (((a) > (b)) ? (a) : (b))

#endif  // Apoxi_Macros_hpp

