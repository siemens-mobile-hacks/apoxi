/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObservableObject_hpp)
#define Apoxi_ObservableObject_hpp

#include <Kernel/Types.hpp>

class Observer;

class ObservableObject {
    public:
        typedef Observer* ObserverPtr;

        ObservableObject();

        ~ObservableObject();

        void Attach(Observer *observer);

        void Detach(Observer *observer);

        BOOLEAN IsAttached(Observer *observer) const;

        void NotifyObservers();

    private:
#ifndef APOXI_COMPAT_2_0_0

        ObservableObject(const ObservableObject& observable_object);

        ObservableObject& operator=(const ObservableObject& observable_object);
#endif

        INT m_observer_count;
        union {
            ObserverPtr instance;
            ObserverPtr *vector;
        } m_observer;
};

#endif  // Apoxi_ObservableObject_hpp

