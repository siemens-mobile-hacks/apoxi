/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (EmApoxiTicks_hpp)
#define EmApoxiTicks_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
class Ticks;


class EmApoxiTicks {
    public:

        EmApoxiTicks(EmApoxiUINT32* l_p_result = 0);
        
        ~EmApoxiTicks();
        
        EmApoxiUINT32 GetExpiredTime(); 

    private:
        
        Ticks *m_p_ticks;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiTicks_hpp

