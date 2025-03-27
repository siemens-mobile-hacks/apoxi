/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObservableService_hpp)
#define BtObservableService_hpp

#include <Bluetooth/BtService.hpp>
#include <Bluetooth/BtServiceObserver.hpp>
#include <Bluetooth/BtEvent.hpp>

class BtObservableService: public BtService
{
    private:
        typedef BtService Base;

    public:
        BtObservableService();

        virtual ~BtObservableService();


        BOOLEAN GetUseMessageInterface() const;


        void SetUseMessageInterface(BOOLEAN use_message_interface);

    protected:

        BOOLEAN Attach(BtServiceObserver* service_observer);


        BOOLEAN Detach(BtServiceObserver* service_observer);


        void Notify(const BtEvent& event);

    private:
        BOOLEAN m_use_message_interface;

    private:
        class BtServiceObserverListElement
        {
            public:
                BtServiceObserverListElement(BtServiceObserver* observer, BtServiceObserverListElement* next = 0);

                virtual ~BtServiceObserverListElement();


                BtServiceObserver* GetObserver() const;


                void SetObserver(BtServiceObserver* observer);


                BtServiceObserverListElement* GetNext() const;


                void SetNext(BtServiceObserverListElement* next);

            private:
                BtServiceObserver* m_observer;

                BtServiceObserverListElement* m_next;
        };

    private:
        BtServiceObserverListElement* m_anchor;
};

#endif  // BtObservableService_hpp


