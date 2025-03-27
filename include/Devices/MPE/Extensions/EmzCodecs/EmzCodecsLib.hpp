/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzCodecsLib_hpp)
#define EmzCodecsLib_hpp


class EmzCodecsLib {
    private:

        static void LoadLib();

    friend class CodecConfig; // loads this library

};

#endif // EmzCodecsLib_hpp

