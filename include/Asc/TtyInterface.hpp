 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_TtyInterface_hpp)
#define Asc_TtyInterface_hpp

class TtyInterface {
    public:

        TtyInterface() {}

        virtual ~TtyInterface() {}
        
        BOOLEAN TtySupported(BOOLEAN & supported);

        BOOLEAN TtySupported();

        BOOLEAN GetTtyMode(TtyMode & mode);

        TtyMode GetTtyMode();
        
        BOOLEAN SetTtyMode(TtyMode mode);

        BOOLEAN GetTtySpeed(TtySpeed & speed);

        TtySpeed GetTtySpeed();


        BOOLEAN SetTtySpeed(TtySpeed speed);
};

#endif // Asc_TtyInterface_hpp


