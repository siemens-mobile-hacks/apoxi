/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_AtcDispatcher_hpp)
#define Asc_AtcDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    AtcDispatcher
    ======================================================================== */
class AtcDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

    friend class AtcHandler;

    public:
        AtcDispatcher();
        virtual ~AtcDispatcher();

        static PbRequestBehaviour GetPbAlphaTagRequestBehaviour() {
            return m_pbrequesttype;
        }

    protected:
        BOOLEAN OnAtAlphaTagReq(const StackMsgArgument & arg);
        BOOLEAN OnAtPbSelectReq(const StackMsgArgument & arg);
        BOOLEAN OnAtPbListReq(const StackMsgArgument & arg);

    private:
        static const StackMsgArgMap<AtcDispatcher> m_arg_map[];
        StackMsgArgMapContainer<AtcDispatcher> m_arg_map_container;

        void SetPbAlphaTagRequestBehaviour(PbRequestBehaviour behaviour) {
            m_pbrequesttype = behaviour;
        }

        BOOLEAN ConfirmPbAlphaTagRequest(
            const WString & alphatag, const PhoneNumber & phno,BOOLEAN apoxilookup);

        void SetPbRecordRequestBehaviour(BOOLEAN mmicontrolled) {
            m_pbentry_mmicontrolled = mmicontrolled;
        }

        BOOLEAN CommitPbInformation(const MePhonebookDescription & description);
        BOOLEAN ConfirmPbSizeRequest(BOOLEAN capable, MePhoneBookType type, INT usedrecords);
        BOOLEAN ConfirmPbEntryRequest(BOOLEAN capable, MePhoneBookType type, INT recordnumber, 
                                      const WString & alphaidentifier, const PhoneNumber & phno);

        static BOOLEAN m_pbentry_mmicontrolled;
        static BOOLEAN m_alphatag_req_pending;  
        static PbRequestBehaviour m_pbrequesttype;  
};


#endif  // Asc_AtcDispatcher_hpp


