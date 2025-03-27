/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_ProcessNode_hpp)
#define Apc_SignalHandler_ProcessNode_hpp

#include <Auxiliary/Macros.hpp>
#include <Kernel/AbstractExternalData.hpp>

#include <Apc/SignalHandler/SignalMapTableEntry.hpp>

class ProcessNode : public AbstractExternalData {
    public:
        ProcessNode(const ProcessPtr process_ptr = 0);
        virtual ~ProcessNode();

        void Init(const ProcessPtr process_ptr);

        void Refresh(const ProcessPtr process_ptr);

        ProcessPtr GetProcessPtr() const { return (m_process_ptr); }
        
        BOOLEAN IsEqualSignal(const SignalMapTableEntry &signal) const;

        static BOOLEAN IsSignalNameAvailable();

        SdlSignalId GetSignalId() const;
        SdlSignalName GetSignalName() const;

    private:
        ProcessPtr m_process_ptr;
}; 

#endif  // Apc_SignalHandler_ProcessNode_hpp


