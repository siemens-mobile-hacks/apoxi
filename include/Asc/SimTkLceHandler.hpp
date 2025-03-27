/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifdef  APOXI_LETTERCLASSE_SUPPORT
#if !defined(Asc_SimTkLceHandler_hpp)
#define Asc_SimTkLceHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/SimTkLceDispatcher.hpp>

class SimIconDescription;
class SimImage;
class SimItemId;
class WString;

/*  ========================================================================
    SimTkLceHandler
    ======================================================================== */
class SimTkLceHandler : public BaseHandler {
    typedef BaseHandler Base;
    friend class BattDispatcher; //for testing purposes only
    public:
        enum { ID = SimTkLceHandlerId };

        SimTkLceHandler();
        virtual ~SimTkLceHandler();

        virtual HandlerId GetHandlerId() const;



        BOOLEAN LceChannelOpenPromptRes(const GenResultCode gen_result) const;

        BOOLEAN LceChannelCloseReq(const UINT8 cidx) const;

        BOOLEAN LceChannelCloseInfoRes(const UINT8 cidx, const GenResultCode gen_result) const;

        BOOLEAN LceChannelSendInfoRes(const UINT8 cidx, const GenResultCode gen_result) const;

        BOOLEAN LceChannelReceiveInfoRes(const UINT8 cidx, const GenResultCode gen_result) const;




        BOOLEAN LceDhChannelOpenCnf(const UINT8 cidx, const UINT16 buffer_size, const SiBearerDesc bearer_desc,  const GenResultCode gen_result,  const UINT8 adn_result ) const;

        BOOLEAN LceDhChannelOpenRej(const UINT8 cidx, const GenResultCode gen_result,  const UINT8 adn_result ) const;

        BOOLEAN LceDhChannelCloseInd(const UINT8 cidx, const GenResultCode gen_result,  const UINT8 adn_result ) const;


    private:
        SimTkLceDispatcher m_stkletclasse_dispatcher;       // main dispatcher for retrieving asynchronous messages

        friend class BattDispatcher;
};

#endif // Asc_SimTkLceHandler_hpp
#endif // APOXI_LETTERCLASSE_SUPPORT


