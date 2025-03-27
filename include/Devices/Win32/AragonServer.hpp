/* ----------------------------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
   ----------------------------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted withOut prior written authorisation.
   ---------------------------------------------------------------------------------------------- */

#if !defined(Apoxi_AragonServer_hpp)
#define Apoxi_AragonServer_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

class String;
class Component;
class Control;
#include <Devices/Win32/GatiServer.hpp>
#include <Kernel/Os/Semaphore.hpp>

class AragonServer : public GatiServer {
    public:
        enum {
            ID = 1
        };
        
        static AragonServer& GetInstance();
        virtual ~AragonServer();
        
        virtual INT GetId() const;

        virtual void Destroy();
        
        virtual void OnConnect();

        virtual void OnDisconnect();            
    
        virtual void OnDataReceived(UINT32 cmd, UINT32 length, void* data);

        static GatiServer* CreateInstance();

        BOOLEAN HasRequests() const { return m_has_requests; }
        
        void MarkResponseReady() { m_response_ready = TRUE; }
        
        BOOLEAN IsResponseReady() const { return m_response_ready; }

        void SendResponse();

#ifdef APOXI_COMPAT_2_0_0

        void MarkDisplayEvent() {}

        BOOLEAN HasDisplayEvent() const { return FALSE; }
#endif

    private:
        AragonServer();
        void SendComponentBoundaries();
        void TraverseControls(const Control* control);
        void WriteBoundary(const Component& comp);
        
        BOOLEAN m_has_requests;
        BOOLEAN m_response_ready;
        INT m_clients_count;
        INT32 m_request_id;
        CHAR* m_output_string;  
        INT32 m_output_idx;
        XYDIM m_display_width;
        XYDIM m_display_height;
        Semaphore m_sem;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  // Apoxi_AragonServer_hpp


