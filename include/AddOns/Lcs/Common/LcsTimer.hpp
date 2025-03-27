/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsTimer_hpp)
#define AddOns_Lcs_Common_LcsTimer_hpp

#include <Kernel/Timer.hpp>

class LcsProviderImplBase;

enum LcsTimerType
{
    MtlrTimer,
    MolrTimer,
    InvalidTimer
};

class LcsTimer : public Timer
{
    typedef Timer Base;

    public:

        LcsTimer();

        virtual ~LcsTimer();

        void Start();

        void Init(  LcsTimerType timer_type, UINT32 timeout, 
                    const LcsProviderImplBase* provider, BOOLEAN autotimer = FALSE);


    protected:

        virtual void OnTimer();


    private:

        LcsTimerType m_timer_type;

        const LcsProviderImplBase* m_provider;

}; // LcsTimer

#endif // AddOns_Lcs_Common_LcsTimer_hpp

