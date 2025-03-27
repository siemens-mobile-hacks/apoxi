/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsSocket_hpp)
#define Mmi_LcsSocket_hpp

#include <Socket/DataConnProfile.hpp>
#include <Socket/UdpSocket.hpp>
#include <Socket/InetSocketAddr.hpp>
class LcsSocket : public UdpSocket
{
    typedef UdpSocket Base;

    public:

        LcsSocket();

        ~LcsSocket();

        BOOLEAN Init(DataConnProfileId prof_id);

        INT Write(const void *buf, INT buflen);


    protected:

        virtual void OnAsyncEvent(Event event);


    private:
    
        InetSocketAddr m_gl_svr_addr;
        
}; // LcsSocket

#endif // Mmi_LcsSocket_hpp
