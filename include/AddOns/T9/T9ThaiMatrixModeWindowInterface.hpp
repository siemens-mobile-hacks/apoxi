/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(T9ThaiMatrixModeWindowInterface_hpp)
#define T9ThaiMatrixModeWindowInterface_hpp

class T9ThaiMatrixModeWindowInterface {
    public:
        virtual INT OpenMatrixWindow(KeyCode key_code) = 0;
};


#endif  // T9ThaiMatrixModeWindowInterface_hpp


