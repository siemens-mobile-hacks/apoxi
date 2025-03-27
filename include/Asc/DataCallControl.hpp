/*  ------------------------------------------------------------------------
    Copyright (C) 2002 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AscDataCallControl)
#define AscDataCallControl

#include <Apc/SignalTypes.hpp>

class DataCallControl
{
    public:
        DataCallControl() {};
        ~DataCallControl() {};

        virtual void OnSetupCompleted(DcError error) = 0;


        virtual void OnReleaseCompleted(DcError error) = 0;
};

#endif // AscDataCallControl


