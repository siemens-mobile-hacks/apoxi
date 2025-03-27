/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SingleArgHook_hpp)
#define Apoxi_SingleArgHook_hpp

#include <Kernel/Types.hpp>

template <class T> class SingleArgHook {
    public:
        typedef void (*HookFn)(T);

        SingleArgHook() : m_hook(0) {}
        virtual ~SingleArgHook() { m_hook = 0; }

        BOOLEAN Add(HookFn fn) {
            if (m_hook == 0)
                m_hook = fn;

            return (m_hook == fn);
        }

        BOOLEAN Remove(HookFn fn) {
            if (m_hook == fn)
                fn = 0;

            return (fn == 0);
        }

        void Call(T t) {
            if (m_hook != 0)
                m_hook(t);
        }

    private:
        HookFn m_hook;
};

#endif  // Apoxi_SingleArgHook_hpp


