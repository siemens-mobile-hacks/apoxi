/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Linkable_hpp)
#define Apoxi_Linkable_hpp

#include <Kernel/Types.hpp>

class LinkableBase {
    public:
        LinkableBase(LinkableBase *next = 0);

        virtual ~LinkableBase();

        LinkableBase* GetNext() const {
            return(m_next);
        }

        void SetNext(LinkableBase *next) {
            m_next = next;
        }

    private:
        LinkableBase *m_next;
};

template<class T> class Linkable : public LinkableBase {
    typedef LinkableBase Base;

    public:
        T* GetNext() const {
            return (T*)Base::GetNext();
        }
};

#endif  // Apoxi_Linkable_hpp


