/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiDataConnManager_hpp)
#define EmApoxiDataConnManager_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiInterface.hpp"

class EmApoxiDataConnManager
{

    public:

        ~EmApoxiDataConnManager();

        static EmApoxiDataConnManager &Get();

        EmApoxiBOOLEAN IsDataConnRegistered(EmApoxiDataConnProfileId id) const;

        EmApoxiBOOLEAN RegisterDataConn(EmApoxiDataConnProfileId id);  
 
    protected:




    private:
        EmApoxiDataConnManager();

        
}; // EmApoxiDataConnManager

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiDataConnManager_hpp

