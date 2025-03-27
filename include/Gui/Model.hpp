/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Model_hpp)
#define Apoxi_Model_hpp

#include <Kernel/Dispatcher.hpp>

class Model : public Dispatcher {
    public:
        Model();

        virtual ~Model();

        void Init();

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);
};

#endif  // Apoxi_Model_hpp


