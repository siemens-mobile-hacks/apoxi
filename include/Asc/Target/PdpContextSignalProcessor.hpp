/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_Target_PdpContextSignalProcessor_hpp)
#define Asc_Target_PdpContextSignalProcessor_hpp

#include <Apc/SignalHandler/ProcessNode.hpp>

/*  ========================================================================
    PdpContextSignalProcessor
    ======================================================================== */
class PdpContextSignalProcessor {
    public:
        /*  ================================================================
            Packet data protocol context signal-transformation
            ================================================================ */
        // attach
        static void ProcessPchAttachCnf(const ProcessPtr &process_ptr);
        static void ProcessPchAttachRej(const ProcessPtr &process_ptr);
        static void ProcessPchAttachRep(const ProcessPtr &process_ptr);

        // detach
        static void ProcessPchDetachCnf(const ProcessPtr &process_ptr);
        static void ProcessPchDetachInd(const ProcessPtr &process_ptr);

        // attach status indication
        static void ProcessMnAttachStatusInd(const ProcessPtr &process_ptr);

        // primary context definition
        static void ProcessPchDefContCnf(const ProcessPtr &process_ptr);
        static void ProcessPchDefContRej(const ProcessPtr &process_ptr);
        
        // secondary context definition
        static void ProcessPchCgdsContCnf(const ProcessPtr &process_ptr);
        static void ProcessPchCgdsContRej(const ProcessPtr &process_ptr);

        // authentication
        static void ProcessPchAuthCnf(const ProcessPtr &process_ptr);
        static void ProcessPchAuthRej(const ProcessPtr &process_ptr);

        // request quality of service
        static void ProcessPchSetQosCnf(const ProcessPtr &process_ptr);
        static void ProcessPchSetQosRej(const ProcessPtr &process_ptr);

        // set minimum quality of service
        static void ProcessPchSetQosMinCnf(const ProcessPtr &process_ptr);
        static void ProcessPchSetQosMinRej(const ProcessPtr &process_ptr);

        // mobile originated context activation
        static void ProcessPchActivateCnf(const ProcessPtr &process_ptr);       
        static void ProcessPchActivateRej(const ProcessPtr &process_ptr);

        static void ProcessPchPppActCnf(const ProcessPtr &process_ptr); 

        // mobile terminated context activation
        static void ProcessPchActivateInd(const ProcessPtr &process_ptr);
        static void ProcessPchActCompleteInd(const ProcessPtr &process_ptr);
        static void ProcessPchActFailedInd(const ProcessPtr &process_ptr);

        static void ProcessPchReactivateInd(const ProcessPtr &process_ptr);

        // status indication for successful/unsuccessful context activation
        static void ProcessPchActivateStatusInd(const ProcessPtr &process_ptr);

        // context deactivation
        static void ProcessPchDeactivateCnf(const ProcessPtr &process_ptr);
        static void ProcessPchDeactivateInd(const ProcessPtr &process_ptr);

        // context connection establishment
        static void ProcessPchDataStateCnf(const ProcessPtr &process_ptr);
        static void ProcessPchDataStateRej(const ProcessPtr &process_ptr);

        // set data counters
        static void ProcessPchSetCntCnf(const ProcessPtr &process_ptr);
        static void ProcessPchSetCntRej(const ProcessPtr &process_ptr);
        
        // read data counters
        static void ProcessPchReadCntInd(const ProcessPtr &process_ptr);
        static void ProcessPchReadCntRej(const ProcessPtr &process_ptr);
        
        // Traffic Flow Template
        static void ProcessPchCgTftCnf(const ProcessPtr &process_ptr);
        static void ProcessPchCgTftRej(const ProcessPtr &process_ptr);

        // DNS server address 
        static void ProcessPchSetDnsRej(const ProcessPtr &process_ptr);
        static void ProcessPchSetDnsCnf(const ProcessPtr &process_ptr);
        static void ProcessPchReadDnsRej(const ProcessPtr &process_ptr);
        static void ProcessPchReadDnsCnf(const ProcessPtr &process_ptr);
};

#endif  // Asc_Target_PdpContextSignalProcessor_hpp

