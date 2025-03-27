/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_PlmnHandler_hpp)
#define Asc_PlmnHandler_hpp

#include <Apc/SignalTypes.hpp>
#include <Apc/PlmnScanList.hpp>

#include <Asc/BaseHandler.hpp>

#include <Apc/NetworkTypes.hpp>
#include <Asc/PlmnDispatcher.hpp>
#include <Asc/PlmnScanDispatcher.hpp>

/*  ========================================================================
PlmnHandler
======================================================================== */
class PlmnHandler : public BaseHandler {
    typedef BaseHandler Base;
public:
    enum { ID = PlmnHandlerId };

    PlmnHandler();
    virtual ~PlmnHandler();

    virtual HandlerId GetHandlerId() const;

    BOOLEAN Scan(PlmnScanList &plmn_scan_list);

    BOOLEAN Scan();

    void InterruptScan() const;

    void Register(const RegisterMode &mode, const Plmn &plmn = InvalidPlmn, RadioAccessTechnology plmn_rat_mode = RatNotAvailable) const;
    
    BOOLEAN IsRegistrationAllowed() const;

    BOOLEAN ChangeRatMode(RatChangeMode rat_change_mode, RadioAccessTechnology rat_mode = RatNotAvailable) const;

    BOOLEAN ChangePreferedRatMode(RadioAccessTechnology rat_mode) const;

    RadioAccessTechnology GetPreferedRatMode() const;

    BOOLEAN IsRatChangePossible() const;

#if defined(DOWNSTRIP_TO_GSM)
private:
#endif

    void Detach() const;

    void ChangeGprsClass(const GprsClass &gprs_class) const;

    BOOLEAN ChangePrefService(GsmService gsm_service) const;

    GsmService GetPrefService() const;
    
    BOOLEAN IsScanInProgress() const;

#if !defined(DOWNSTRIP_TO_GSM)
private:
#endif
    PlmnDispatcher m_plmn_dispatcher; // main dispatcher for retrieving asynchronous messages
    static PlmnScanDispatcher *m_plmn_scan_dispatcher;  // active scan dispatcher
};


#endif  // Asc_PlmnHandler_hpp

