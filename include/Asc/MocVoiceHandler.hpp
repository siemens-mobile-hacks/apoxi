/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MocVoiceHandler_hpp)
#define Asc_MocVoiceHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/MocVoiceDispatcher.hpp>
#include <Asc/RedialDispatcher.hpp>
#include <Asc/Types.hpp>
#include <Apc/SimTkTypes.hpp>

class CallHandler;

class MocVoiceHandler : public BaseHandler {
#ifndef DOXYGEN_SHOULD_SKIP_THIS 
    typedef BaseHandler Base;           // typedef if base class's name changes
#ifdef APOXI_COMPAT_1_7_0
    friend class SsWaitDispatcher; // SsWaitDispatcher needs method PrepareCallData
#endif
    friend class CallControlDispatcher; // CallDispatcher needs method PrepareCallData
    public:
        enum { ID = MocVoiceHandlerId };

        MocVoiceHandler();
        virtual ~MocVoiceHandler();

        virtual HandlerId GetHandlerId() const;

        CallApiRc Setup(const PhoneNumber &phone_no,
                        CallIndex & call_index,
                        ClirMode clir_mode,
                        const CugDescriptor * cug,
                        BOOLEAN redial,
                        LineSelector call_line = Line1,
                        BOOLEAN ctm = FALSE,
                        CallEstCause est_cause = HalfTchSpeech,
                        const EccCategory * ecc_category = 0);


        //CTM - 4th param is added for CTM
        CallApiRc SimTkSetup(ProactiveCause cause, 
                             const PhoneNumber & phone_no, 
                             UINT8 sim_qualifier,
                             BOOLEAN ctm = FALSE);


        void CancelRedialling() const;
    protected:
        BOOLEAN PrepareCallData(PhoneNumber phnr,LineSelector call_line);
        
    private:
        CallApiRc MocWaitForResponse(MocVoiceDispatcher &moc_voice_disp, 
                                     CallHandler * ch, 
                                     CallIndex &call_index,
                                     const PhoneNumber & phone_no);

        // BOOLEAN m_tmp_redial_mode;
        RedialDispatcher m_redial_disp;
        BOOLEAN m_call_disconnected;
};
#endif // DOXYGEN_SHOULD_SKIP_THIS 

#endif // Asc_MocVoiceHandler_hpp

