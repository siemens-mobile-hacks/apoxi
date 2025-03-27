/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Mmi_UpdatePbThreadlet_hpp)
#define Mmi_UpdatePbThreadlet_hpp

#include <Kernel/Threadlet.hpp>
#include <Auxiliary/MainProvider.hpp>

class UpdatePbThreadlet : public Threadlet {
    typedef Threadlet Base;
    
    public:
        //
        UpdatePbThreadlet();

        virtual ~UpdatePbThreadlet();

        void Init(Application* app, Provider* provider);

        virtual INT Fn();

        virtual void OnEndOfExecute();

        BOOLEAN IsRunning() { return m_is_running; }

    private:
        Application*        m_app;
        Provider*           m_provider;
        BOOLEAN             m_is_running;
};

#endif  // Mmi_UpdatePbThreadlet_hpp
