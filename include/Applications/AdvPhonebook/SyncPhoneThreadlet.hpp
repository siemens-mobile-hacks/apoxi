/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SyncPhoneThreadlet_hpp)
#define Mmi_SyncPhoneThreadlet_hpp

#include <Kernel/Threadlet.hpp>

class PbSynchronizer;
class Application;
class SyncPhoneThreadlet : public Threadlet {
    typedef Threadlet Base;

    public:
        //
        SyncPhoneThreadlet();

        //
        virtual ~SyncPhoneThreadlet();

        //
        void Init(Application *app, PbSynchronizer *synchronizer);

        virtual INT Fn();
        
        virtual void OnEndOfExecute();

        BOOLEAN IsRunning() { return m_is_running; }

        BOOLEAN SyncSucceeded() { return m_successful; }

    private:
        Application*    m_pb_app;
        PbSynchronizer* m_synchronizer;
        BOOLEAN         m_successful;
        BOOLEAN         m_is_running;
};

#endif  // Apoxi_Threadlet_hpp
