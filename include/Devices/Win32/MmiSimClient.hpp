/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_MmiSimClient_hpp)
#define Apoxi_MmiSimClient_hpp

#include <Gui/Bitmap.hpp>
#include <Gui/Rect.hpp>
#include <Kernel/Os/Semaphore.hpp>

class MmiSimClient {
    public:
        virtual ~MmiSimClient();

        static MmiSimClient* GetClient();
        void Connect();
        void Disconnect();
        void UpdateDisplay(const Bitmap& bitmap, const Rect& blit_rect, int display_idx);
        void SetBacklightState(BOOLEAN state, UINT8 display_idx = 0);
        void SetVibrationState(BOOLEAN state);
        void SetLedState(BOOLEAN state, UINT32 color);

    private:
        MmiSimClient();

        static unsigned long __stdcall Receive(void* p);
        static BOOLEAN FillReadBuffer(UINT32 sock, char* dst, int len);
        static MmiSimClient m_client;

        UINT32 m_server_socket;
        bool m_sockets_initialized;
        Semaphore m_sem;
};

#endif  // Apoxi_MmiSimClient_hpp

