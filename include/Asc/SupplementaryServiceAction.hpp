/* ------------------------------------------------------------------------
   Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_SupplementaryServiceAction_hpp)
#define Asc_SupplementaryServiceAction_hpp

#include <Asc/InputAction.hpp>

class SelectedLineRetriever 
{
public:
    virtual LineSelector GetSelectedLine() const = 0;
};

class SsPasswordChangeActionImpl : public PasswordChangeSsAction {
    typedef PasswordChangeSsAction Base;

 public:
    SsPasswordChangeActionImpl();
    virtual ~SsPasswordChangeActionImpl();

    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }

    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};

class SsCallBarringActionImpl : public BarringSsAction {
    typedef BarringSsAction Base;

 public:
    SsCallBarringActionImpl();
    virtual ~SsCallBarringActionImpl();

    void Init(BOOLEAN registerOnly = FALSE, const SelectedLineRetriever* line_retriever = 0);

    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
    const SelectedLineRetriever*    m_line_retriever;
};

class SsCallForwardingActionImpl : public ForwardingSsAction {
    typedef ForwardingSsAction Base;
 public:
    SsCallForwardingActionImpl();
    virtual ~SsCallForwardingActionImpl();
    void Init(BOOLEAN registerOnly = FALSE, const SelectedLineRetriever* line_retriever = 0);

    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
    const SelectedLineRetriever*    m_line_retriever;
};

class SsCallWaitingActionImpl : public WaitSsAction {
    typedef WaitSsAction Base;
 public:
    SsCallWaitingActionImpl();
    virtual ~SsCallWaitingActionImpl();
    void Init(BOOLEAN registerOnly = FALSE, const SelectedLineRetriever* line_retriever = 0);

    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
    const SelectedLineRetriever*    m_line_retriever;
};

class SsClirActionImpl : public ClirAction {
    typedef ClirAction Base;
 public:
    SsClirActionImpl();
    virtual ~SsClirActionImpl();
    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }
    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};

class SsClipActionImpl : public ClipAction {
    typedef ClipAction Base;
 public:
    SsClipActionImpl();
    virtual ~SsClipActionImpl();
    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }
    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};

class SsColrActionImpl : public ColrAction {
    typedef ColrAction Base;
 public:
    SsColrActionImpl();
    virtual ~SsColrActionImpl();
    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }
    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};

class SsColpActionImpl : public ColpAction {
    typedef ColpAction Base;
 public:
    SsColpActionImpl();
    virtual ~SsColpActionImpl();
    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }
    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};


class SsCnapActionImpl : public CnapAction {
    typedef CnapAction Base;
 public:
    SsCnapActionImpl();
    virtual ~SsCnapActionImpl();
    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }
    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};

class SsUssdActionImpl : public UssdAction {
    typedef UssdAction Base;
 public:
    SsUssdActionImpl();
    virtual ~SsUssdActionImpl();
    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }
    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};


class SsEmlppActionImpl : public EmlppAction {
    typedef EmlppAction Base;
 public:
    SsEmlppActionImpl();
    virtual ~SsEmlppActionImpl();
    void Init(BOOLEAN registerOnly = FALSE) {
        m_register_only = registerOnly;
    }
    virtual BOOLEAN Execute();

 private:
    BOOLEAN m_register_only;
};


#endif  // Asc_SupplementaryServiceAction_hpp


