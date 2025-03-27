/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_ObexApp_hpp)
#define Mmi_ObexApp_hpp

#include <Common/MmiApplication.hpp>
#include <Common/CommonMsgTypes.hpp>
#include <Obex/ObexMngr.hpp>
#include <Obex/ObexTransportSet.hpp>
#include <Obex/ObexAppMsg.hpp>
#include <Obex/ObexTransport.hpp>

#include <ObexApp/ObexTransportWin.hpp>


class ObexApp : public MmiApplication {
    typedef MmiApplication Base;

    public:
        static ObexApp* GetInstance();

        void Init();
        virtual ~ObexApp();

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnOpen();

    private:
        ObexApp();
        
        ObexTransportWin m_transport_win;       
        static ObexApp m_obex_app;
        
};
#endif  // Mmi_VoiceMemoApp_hpp
