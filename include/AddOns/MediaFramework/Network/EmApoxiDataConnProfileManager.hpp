/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(EmApoxiDataConnProfileManager_hpp)
#define EmApoxiDataConnProfileManager_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiInterface.hpp"

class EmApoxiDataConnProfileManager
{

    public:

        ~EmApoxiDataConnProfileManager();

        static EmApoxiDataConnProfileManager &Get();

        EmApoxiDataConnProfileId GetDefProfileId() const;


    protected:




    private:
        EmApoxiDataConnProfileManager();

        
}; // EmApoxiDataConnProfileManager

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiDataConnProfileManager_hpp

