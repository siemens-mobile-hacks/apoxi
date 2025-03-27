/* ----------------------------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
   ----------------------------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted withOut prior written authorisation.
   ---------------------------------------------------------------------------------------------- */

#if !defined(Apoxi_MmiSimServer_hpp)
#define Apoxi_MmiSimServer_hpp

class Rect;
#include <Devices/Win32/GatiServer.hpp>

class MmiSimServer {

    // MmiSimServer::ClientHandler forward declaration
    class ClientHandler;

    // The ClientHandler class has to be a friend class in order to access private components of the MmiSimServer
    friend class ClientHandler;
    
    public:

        enum {
            ID = 0
        };      

        enum MmiSimCmdId {
            MmiSimDisplayUpdateHeaderId = 1,
            MmiSimDisplayUpdateDataId = 2,
            MmiSimBacklightStateId = 10,
            MmiSimVibrationStateId = 11,
            MmiSimLedStateId = 12,
            MmiSimPowerStateId = 13,
            MmiSimClipStateId = 14,
            MmiSimKeyDownId = 200,
            MmiSimKeyUpId = 201,
            MmiSimCharId = 220,
            MmiSimPenDownId = 250,
            MmiSimPenUpId = 251,
            MmiSimPenMoveId = 252
        };  
        
        static MmiSimServer& GetInstance();

        static GatiServer* CreateInstance();

        void UpdateDisplay(const Rect& blit_rect, INT display_idx);

        void SetBacklightState(BOOLEAN state, INT backlight_idx = 0);

        void SetVibrationState(BOOLEAN state);

        void SetLedState(BOOLEAN state, UINT32 color, INT led_idx = 0);

        void SetPowerState(BOOLEAN state, INT display_idx);

        void SetClipState(BOOLEAN state);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        virtual ~MmiSimServer();

    private:

        class ClientHandler : public GatiServer {

            public:

                virtual INT GetId() const;

                virtual void Destroy();
            
                virtual void OnConnect();
        
                virtual void OnDisconnect();            
            
                virtual void OnDataReceived(UINT32 cmd, UINT32 length, void* data);
        };      

        MmiSimServer();

        MmiSimServer(const MmiSimServer& obj);

        void Init();

        void OnDataReceived(UINT32 cmd, UINT32 length, void* data);

        void PerformDisplayUpdate(const Rect& blit_rect, INT display_idx, GatiServer* sender);

        static UINT8** m_display_buffers;       

        static UINT8 m_num_clients;

        static MmiSimServer m_instance;

        static BOOLEAN m_is_initialized;

#endif // DOXYGEN_SHOULD_SKIP_THIS

};

#endif  // Apoxi_MmiSimServer_hpp


