/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PathProfile_hpp)
#define Apoxi_PathProfile_hpp

#include <Afs/Rfs/RootFileSystem.hpp>
#include <Afs/Rfs/Path.hpp>

class PathProfile
{
    protected:
        struct Persist {
            WCHAR m_Id[RootFileSystem::MAX_STORAGE_DEVICE_ID_LENGTH];
            WCHAR m_sPathname[Pathname::MAX_PATHNAME_LENGTH];

            Persist();
        };

    public:
        PathProfile();

        virtual ~PathProfile();

    protected:
        void SetStorageDeviceId(const WString &Id);
        WString GetStorageDeviceId() const;

        void SetPathname(const Pathname &pathname);
        Pathname GetPathname() const;

        void SetData(const Persist &data);

        const Persist& GetData() const;

        friend class Path;

    private:
        Persist m_data;
};

#endif  // Apoxi_PathProfile_hpp

