/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_IrdaApp_hpp)
#define Mmi_IrdaApp_hpp

#include <Common/MmiApplication.hpp>
#include <Kernel/Timer.hpp>
#include <Devices/AbstractTransport.hpp>



class IrdaApp : public MmiApplication {
    typedef MmiApplication Base;

    public:


        virtual ~IrdaApp();
        
        static IrdaApp * GetInstance() {return &m_irda_app;}

    protected:

        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification, const Property* property, 
                                               const DataItem& value);
        
        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnOpen();      

                
    private:
        Property m_disable_prop;    
    
        static IrdaApp m_irda_app;

        IrdaApp();

//      MenuAction m_irda_action;
        AbstractTransport::AvState m_state;

        Property m_irda_prop;

    
#if defined(MMI_COMPAT_2_6_0)

        void ToggleIndicator(BOOLEAN visible);
        
#endif
};
#endif  // Mmi_IrdaApp_hpp

