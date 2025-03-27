/* ----------------------------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
   ----------------------------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted withOut prior written authorisation.
   ---------------------------------------------------------------------------------------------- */

#if !defined(Apoxi_HostAudioGatiServer_hpp)
#define Apoxi_HostAudioGatiServer_hpp

#include <Devices/Win32/GatiServer.hpp>

class AudioGatiServer : public GatiServer {
    public:
        enum {
            ID = 3
        };
        
        static AudioGatiServer& GetInstance();

        virtual ~AudioGatiServer();
        
        virtual INT GetId() const;

        virtual void Destroy();
        
        virtual void OnConnect();

        virtual void OnDisconnect();            
    
        virtual void OnDataReceived(UINT32 cmd, UINT32 length, void* data);

        static GatiServer* CreateInstance();

        void SendData(UINT32 cmd, UINT32 length, void* data);

    private:
        AudioGatiServer();
        void SendSdlSignal(INT8 ret_code, UINT16 drv_id, UINT32 param1);


        INT m_clients_count;
        INT m_request_id;

};

#endif  // Apoxi_HostAudioGatiServer_hpp

