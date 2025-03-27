/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_Drm_Asset_hpp)
#define Apoxi_Drm_Asset_hpp


class DrmRightsObjectContainer;

#include <Kernel/Types.hpp>
#include <Auxiliary/Vector.hpp>
#include <Auxiliary/DateTime.hpp>

#include <Auxiliary/String.hpp>
#include <Auxiliary/DrmCore.hpp>

class DrmAsset {
    public:
        DrmAsset(DrmLocalId id = c_drm_invalid_local_id);

        void SetLocalDrmId(DrmLocalId id);

        DrmLocalId GetDrmLocalId() const;

        DrmStatus ValidateAsset(DrmOperation op) const;

        BOOLEAN OnContentConsumedStart(DrmOperation op) const;

        BOOLEAN OnContentConsumedEnd(DrmOperation op) const;

        BOOLEAN OnRollback(DrmOperation op) const;

        DrmStatus GetCount(DrmOperation op,INT32& cnt) const;
#if defined(APOXI_COMPAT_2_6_0)
        INT32 GetCount(DrmOperation op) const;
#endif

        DrmStatus GetStartDate(DrmOperation op, Date& start_date) const;

        DrmStatus GetEndDate(DrmOperation op, Date& end_date) const;

        DrmStatus GetValidityPeriod(DrmOperation op, TimeSpan& validity_period) const;

        DrmStatus IncrementRefCount();


        DrmStatus DeleteDrmRights() const;

        DrmUid GetUid(DrmStatus &status) const;

    protected:
        DrmStatus CreateContainer(DrmOperation op, DrmRightsObjectContainer &ro_holder) const;

    private:
        DrmLocalId m_id;

};


#endif  // Apoxi_Drm_Asset_hpp

