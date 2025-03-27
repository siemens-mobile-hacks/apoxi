/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SsHandler_hpp)
#define Asc_SsHandler_hpp

#include <Kernel/Types.hpp>

#include <Apc/TaggedProblemCode.hpp>

#include <Asc/BaseHandler.hpp>
#include <Asc/InputParser.hpp>

#include <Asc/SsDispatcher.hpp>
#include <Asc/SsWaitDispatcher.hpp>
#include <Apc/SsErrorCode.hpp>

/*  ========================================================================
    SsHandler
    ======================================================================== */
class SsHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = SsHandlerId };  
        
        SsHandler();
        virtual ~SsHandler();

        virtual HandlerId GetHandlerId() const;

        SsApiRc SendControlString(const WString &code) const;

        SsApiRc SendControlString(const WCHAR * code) const;


        SsApiRc TerminateSupplementaryService() const;
        

        SsApiRc SendPasswordResponse(const WString &password) const;
        

        SsApiRc SendDetectedError(const SsErrorCode::Code error_code) const;


        SsApiRc SendUssdReturnResult(SsOperationCode code, const WString &result) const;


        SsApiRc RejectUssdRequest(const TaggedProblemCode::ProblemCode code = TaggedProblemCode::ResourceLimitation) const;

        BOOLEAN IsSsPending() const;


        SsApiRc GetClipStatus() const; 

        SsApiRc GetClirStatus() const;

        SsApiRc GetColpStatus() const;

        SsApiRc GetColrStatus() const;

        SsApiRc ActivateCallWaiting(const InputParser::BasicServiceMmiCode bs = InputParser::AllServices) const; 

        SsApiRc DeactivateCallWaiting(const InputParser::BasicServiceMmiCode bs = InputParser::AllServices) const;

        SsApiRc GetCallWaitingStatus() const;


        SsApiRc ActivateCallForwarding(
            const InputParser::SsCode code, 
            const PhoneNumber & forward_to_no, 
            const InputParser::BasicServiceMmiCode bs = InputParser::AllServices,
            const WString & time = L"") const;

        SsApiRc DeactivateCallForwarding(
            const InputParser::SsCode code, 
            const InputParser::BasicServiceMmiCode bs = InputParser::AllServices) const;
        
        SsApiRc GetCallForwardingStatus(
            const InputParser::SsCode code, 
            const InputParser::BasicServiceMmiCode bs = InputParser::AllServices) const;


        SsApiRc ActivateCallBarring(
            const InputParser::SsCode code, 
            const WString & pw,
            const InputParser::BasicServiceMmiCode bs = InputParser::AllServices) const;

        SsApiRc DeactivateCallBarring(
            const InputParser::SsCode code, 
            const WString & pw, 
            const InputParser::BasicServiceMmiCode bs = InputParser::AllServices) const;

        SsApiRc GetCallBarringStatus(const InputParser::SsCode code) const;


        SsApiRc RegisterNewPw(const WString & old_pw, const WString & new_pw) const;

        SsApiRc ChangePin(const WString & old_pin, const WString & new_pin) const;

        SsApiRc ChangePin2(const WString & old_pin2, const WString & new_pin2) const;


        // Methods still available for compatibility reasons:
        inline SsApiRc InterrogateClip() const { return GetClipStatus(); }
        inline SsApiRc InterrogateClir() const { return GetClirStatus(); }
        inline SsApiRc InterrogateColp() const { return GetColpStatus(); }
        inline SsApiRc InterrogateColr() const { return GetColrStatus(); }

        inline SsApiRc ActivateCallForwarding(
            const InputParser::SsCode code, 
            const WString & forward_to_no, 
            const InputParser::BasicServiceMmiCode bs = InputParser::AllServices) const
        { return ActivateCallForwarding(code, PhoneNumber(PhoneNumber::Out, forward_to_no), bs); }


    private:
        SsDispatcher m_ss_dispatcher; // main dispatcher for retrieving asynchronous messages
        BOOLEAN m_rejected;
};

#endif // Asc_SsHandler_hpp


