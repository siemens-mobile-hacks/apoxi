/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined(APOXI_SER_DATACONN_SUPPORT) || defined(APOXI_COMPAT_1_13_0)

#if !defined(Apoxi_SerDataConnProfile_hpp)
#define Apoxi_SerDataConnProfile_hpp

#include <Socket/DataConnProfile.hpp>

class SerDataConnProfile : public DataConnProfile
{
    typedef DataConnProfile Base;

    public:
        SerDataConnProfile();
        virtual ~SerDataConnProfile();

    protected:
        virtual DataConnProfile* New() const;
};

#endif  // Apoxi_SerDataConnProfile_hpp

#endif  // APOXI_SER_DATACONN_SUPPORT || APOXI_COMPAT_1_13_0


