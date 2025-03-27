/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_SsStackMsgArgument_hpp)
#define Asc_SsStackMsgArgument_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Apc/StackMsgArgument.hpp>

class SsStackMsgArgument {

public:

    SsStackMsgArgument(const SsStackMsgArgument &arg);

    SsStackMsgArgument(const StackMsgArgument &arg);

    virtual ~SsStackMsgArgument();

    StackMsgArgId Id() const;

    Tipd GetTipd() const;

    BOOLEAN IsReleaseComplete() const;

    const StackMsgArgument& GetStackMsgArgument() const;
    static BOOLEAN IsReleaseComplete(const StackMsgArgument &arg);
    static Tipd GetTipd(const StackMsgArgument &arg);

    SsStackMsgArgument& operator=(const SsStackMsgArgument& arg);

private:
    Tipd m_tipd;

    BOOLEAN m_is_release_complete;

    StackMsgArgument *m_arg;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  // Asc_SsStackMsgArgument_hpp


