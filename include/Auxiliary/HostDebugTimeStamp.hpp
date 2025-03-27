/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */



#if !defined(Apoxi_HostDebugTimeStamp_hpp)
#define Apoxi_HostDebugTimeStamp_hpp


#if defined(APOXI_RTOS_WIN32)

#include <Auxiliary/String.hpp>

/*  -------------------------------------------------------------------------
                                Types
    ------------------------------------------------------------------------- */


class HostDebugTimeStamp {
    public:

        HostDebugTimeStamp();
        ~HostDebugTimeStamp();



        String GetTimeStamp();


};

#endif // #if defined(APOXI_RTOS_WIN32)




#endif  // Apoxi_HostDebugTimeStamp_hpp



