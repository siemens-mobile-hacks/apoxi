/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Observer_hpp)
#define Apoxi_Observer_hpp

class ObservableObject; 

class Observer {
    public:
        Observer();

        virtual ~Observer();

    protected:
        virtual void OnUpdate(ObservableObject *obs_obj);
#ifndef APOXI_COMPAT_2_0_0  
    private:
        Observer(const Observer& observer);

        Observer& operator=(const Observer& observer);
#endif
    friend class ObservableObject;
};

#endif  // Apoxi_Observer_hpp


