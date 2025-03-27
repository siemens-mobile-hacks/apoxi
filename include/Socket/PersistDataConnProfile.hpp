 /*    ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PersistDataConnProfile_hpp)
#define Apoxi_PersistDataConnProfile_hpp

#include <Socket/CsdDataConnProfile.hpp>
#include <Socket/PsdDataConnProfile.hpp>

class PersistDataConnProfile
{
    friend class DataConnProfile;
    friend class CsdDataConnProfile;
    friend class PsdDataConnProfile;
    friend class DataConnProfileManager;

    public:
        PersistDataConnProfile() 
            { memset(this, 0, sizeof(*this)); }

        DataConnProfilePtr CreateDataConnProfile() const;

    private:
        UINT8 m_free[8];
        DataConnProfile::Persist m_common;

        union {
            CsdDataConnProfile::Persist m_csd_data;
            PsdDataConnProfile::Persist m_psd_data;
        } m_data;
};

#endif  // Apoxi_PersistDataConnProfile_hpp


