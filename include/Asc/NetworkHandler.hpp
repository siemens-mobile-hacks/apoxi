/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_NetworkHandler_hpp)
#define Asc_NetworkHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/NetworkDispatcher.hpp>


/*  ========================================================================
    NetworkHandler
    ======================================================================== */
class NetworkHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = NetworkHandlerId };

        NetworkHandler();
        virtual ~NetworkHandler();

        virtual HandlerId GetHandlerId() const;

        static BOOLEAN ReceiveEngineeringModeReport(BOOLEAN enable);

        static BOOLEAN SendEngineeringModeControlRequest(EngineeringModeControl function, ULONG param = 0);

        static BOOLEAN BandSelection(GsmBand first_band, GsmBand second_band);
        
        static BOOLEAN BandSelection(GsmBandList gsm_band_list);

        static BOOLEAN RequestBandConfig();
        
        static BOOLEAN SetNetworkSearchMode(NetworkSearchMode network_search_mode);

    private:
        NetworkDispatcher m_network_dispatcher; // main dispatcher for retrieving asynchronous messages
};

#endif // Asc_NetworkHandler_hpp


