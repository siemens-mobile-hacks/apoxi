/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AbstractTransport_hpp)
#define Apoxi_AbstractTransport_hpp

#include <Auxiliary/ObservableObject.hpp>

// Forward declarations of classes
class Application;

class AbstractTransport : public ObservableObject {

    public:
        typedef ObservableObject    Base;

        enum AvState {
            AvsReady,       
            AvsBusy,        
            AvsConflict,    
            AvsDisabled     
        };

        enum NotificationMsgType {
            NotifyAvStateChanged    
        };

        BOOLEAN                 RegisterTransportApp(Application *  app_ptr);

        inline  WString         GetMmiName() const;

        virtual void            Enable() = 0;

        virtual AvState         GetAvState() const = 0;

    protected:
        AbstractTransport(const WCHAR *     mmi_name_str);

        inline  Application *   GetAppPtr() const;

        void                    OnAvStateChanged();

    private:
        const WCHAR *   m_mmi_name_str;     
        Application *   m_app_ptr;          
};

/*  ----------------------------------------------------------------------
    GetAppPtr
    ---------------------------------------------------------------------- */
Application *   AbstractTransport::GetAppPtr()
const
{
    return m_app_ptr;
}// GetAppPtr

/*  ----------------------------------------------------------------------
    GetMmiName
    ---------------------------------------------------------------------- */
WString     AbstractTransport::GetMmiName()
const
{
    return WString(m_mmi_name_str);
}// GetMmiName


#endif  // Apoxi_AbstractTransport_hpp

