/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ScicosCodecIfLib_hpp)
#define ScicosCodecIfLib_hpp


class ScicosCodecIfLib {
    private:

        static void LoadLib();

    friend class CodecConfig; // loads this library

};

#endif // ScicosCodecIfLib_hpp


