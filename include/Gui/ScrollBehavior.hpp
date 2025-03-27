/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ScrollBehavior_hpp)
#define Apoxi_ScrollBehavior_hpp

// provide backward compatibility with older APOXI-version < 1.6.2
#if !defined(Behavior)
#define Behavior ScrollBehavior
#endif

enum ScrollBehavior {
    DefaultBehavior,
    BlockScrollBehavior,
    RotateBehavior,
    EndlessLoopBehavior
};

#endif  // Apoxi_Scroll_Behaviour_hpp


