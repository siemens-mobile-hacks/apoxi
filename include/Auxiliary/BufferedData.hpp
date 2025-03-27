/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_BufferedData_hpp)
#define Auxiliary_BufferedData_hpp

#include <Auxiliary/RamData.hpp>

class BufferedData : public RamData
{
    typedef RamData Base;
    public:
        static BufferedData* CreateInstance(UINT8 HUGE* buffer,
                                            UINT32 length,
                                            DrmLocalId id = c_drm_invalid_local_id);

        virtual void ReleaseInstance();

        virtual BinData* Clone() const;

    protected:
        BufferedData(void HUGE* buffer, UINT32 length, DrmLocalId id = c_drm_invalid_local_id);
        
        virtual ~BufferedData();

    private:
        UINT8 HUGE* m_internal_data;
};

#endif  // Auxiliary_BufferedData_hpp

