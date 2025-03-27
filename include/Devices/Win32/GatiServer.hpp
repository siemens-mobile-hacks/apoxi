/* ----------------------------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
   ----------------------------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted withOut prior written authorisation.
   ---------------------------------------------------------------------------------------------- */

#if !defined(Apoxi_GatiServer_hpp)
#define Apoxi_GatiServer_hpp

#include <Kernel/Types.hpp>

class GatiServer {
    public:
        virtual INT GetId() const = 0;

        virtual void Destroy() = 0;
                    
        virtual void OnConnect() = 0;
        
        virtual void OnDisconnect() = 0;            
    
        virtual void OnDataReceived(UINT32 cmd, UINT32 length, void* data) = 0;                 
};

#endif  // Apoxi_GatiServer_hpp


