/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Threadlet_hpp)
#define Apoxi_Threadlet_hpp

#include <Auxiliary/Linkable.hpp>
#include <Kernel/Condition.hpp>

class ExecutionContext;

class Threadlet : public Linkable<Threadlet> {
    typedef Linkable<Threadlet> Base;

    public:
        Threadlet();

        virtual ~Threadlet();

        void Execute(BOOLEAN block = TRUE);

        virtual INT Fn() = 0;

        virtual void OnEndOfExecute();

        virtual UINT GetReqStackSize() const;

        virtual void ReleaseInstance();

        BOOLEAN IsBlocking() const { return m_block; }  
        
    private:
        friend class GenericWorkerTask;

        BOOLEAN m_block;
        ExecutionContext* m_context;
        BooleanCondition m_condition;
};

#endif  // Apoxi_Threadlet_hpp


