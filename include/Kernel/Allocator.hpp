/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Allocator_hpp)
#define Apoxi_Allocator_hpp

#include <Kernel/Os/Os.hpp>

typedef void (*ApoxiNewHandlerFn)();

extern ApoxiNewHandlerFn ApoxiNewHandler;

/*  ------------------------------------------------------------------------
                    Global Operator new and delete
    ------------------------------------------------------------------------ */

#if defined(APOXI_RTOS_NUC32)
    extern void* operator new(size_t size) throw();
    extern void operator delete(void* p) throw();
#elif ! defined(APOXI_RTOS_WIN32)
    extern void* operator new(size_t size);
    extern void operator delete(void* p);
#else
    inline void* operator new(size_t size) { return Os::Alloc(size); }
    inline void operator delete(void* p) { Os::Free(p); }
#endif

/*  ------------------------------------------------------------------------
                                    Types
    ------------------------------------------------------------------------ */
typedef void (*NewHandlerFn)();

extern NewHandlerFn NewHandler;

/*  ------------------------------------------------------------------------
                    Constructors and Deconstructors
    ------------------------------------------------------------------------ */


/*  ------------------------------------------------------------------------
                                    Allocator
    ------------------------------------------------------------------------ */

inline void* operator new(size_t, void* p) { return p; }

inline void operator delete(void*, void*) { }


template <class T> class Allocator {
    public:
        typedef Allocator<T> ThisType;

        static T* Alloc() { 
            return((T* ) Os::Alloc(sizeof(T))); 
            }

        static T* Alloc(INT n) { 
            return((T* ) Os::Alloc(n*  sizeof(T))); 
            }

        static void Free(T* p) { 
            Os::Free(p); 
            }

        static void Construct(T* p, const T& val) { 
            new (p) T(val); 
            } 

        static void Destruct(T* p) { 
            p->~T(); 
            }
};

#endif  // Apoxi_Allocator_hpp

