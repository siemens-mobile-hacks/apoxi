/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_GltpConnApp_hpp)
#define Mmi_GltpConnApp_hpp

#include <Kernel/Application.hpp>
#include <Socket/DataConnProfile.hpp>
#include <Socket/DataConnProfileManager.hpp>
#include <Socket/SocketHandler.hpp>

class LcsSocket;
class GltpProviderImpl;

class GltpConnApp : public Application
{
    typedef Application Base;

    public:

        ~GltpConnApp();

        static GltpConnApp* GetInstance();

        
    protected:

        virtual void OnStartup();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnOpen();

        virtual void OnClose();


    private:

        GltpConnApp();

        BOOLEAN Setup();

        BOOLEAN Send(const BYTE* request, INT size);

        BOOLEAN Close();


    private:

        static GltpConnApp m_self;

        GltpProviderImpl* m_provider;

        enum { INVALID_PROF_ID = 0 };
        DataConnProfileId m_prof_id;

        SocketHandler sock_handler;

        LcsSocket* m_socket;

}; // GltpConnApp

#endif // Mmi_GltpConnApp_hpp
