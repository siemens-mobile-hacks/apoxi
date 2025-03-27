/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_CallDeflectionDispatcher_hpp)
#define Asc_CallDeflectionDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

class CallDeflectionDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

    public:
        CallDeflectionDispatcher();
        virtual ~CallDeflectionDispatcher();
        void SetDeflectionTipd(Tipd deflection_tipd){ m_Tipd = deflection_tipd; }
        Tipd GetDeflectionTipd(){ return m_Tipd; }
        
    protected:
        BOOLEAN OnCallDeflectionCnf(const StackMsgArgument &arg);
        BOOLEAN OnCallDeflectErrInd(const StackMsgArgument &arg);
        BOOLEAN OnCallDeflectRejectInd(const StackMsgArgument &arg);
        
    private:
        static const StackMsgArgMap<CallDeflectionDispatcher> m_arg_map[];
        StackMsgArgMapContainer<CallDeflectionDispatcher> m_arg_map_container;

        Tipd        m_Tipd;
        
};


#endif  // Asc_CallDeflectionCnfRejDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS


