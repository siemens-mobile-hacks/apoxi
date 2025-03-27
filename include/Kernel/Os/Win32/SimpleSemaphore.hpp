/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SimpleSemaphore_hpp)
#define Apoxi_SimpleSemaphore_hpp

#include <Auxiliary/NonCloneable.hpp>
#include <Kernel/Types.hpp>

class SimpleSemaphore : public NonCloneable {
    public:
        SimpleSemaphore();

        virtual ~SimpleSemaphore();

        BOOLEAN Create(INT init_val = 0, INT max_val = -1);

        void Obtain();

        void Release();

    private:
        UINT32 m_hdl;
};

#endif  // Apoxi_SimpleSemaphore_hpp

