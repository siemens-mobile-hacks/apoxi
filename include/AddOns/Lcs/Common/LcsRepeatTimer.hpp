/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsRepeatTimer_hpp)
#define AddOns_Lcs_Common_LcsRepeatTimer_hpp

#include <Kernel/Timer.hpp>

class LcsRepeatTimer : public Timer
{
    typedef Timer Base;

    public:

        LcsRepeatTimer();

        virtual ~LcsRepeatTimer();

        void Init(UINT16 invoke_id, UINT32 timeout, BOOLEAN autotimer = FALSE);

        void Start();


    protected:

        virtual void OnTimer();


    private:

        UINT16 m_invoke_id;

}; // LcsRepeatTimer

#endif // AddOns_Lcs_Common_LcsRepeatTimer_hpp

