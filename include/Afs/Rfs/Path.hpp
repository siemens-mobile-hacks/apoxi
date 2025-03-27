/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Path_hpp)
#define Apoxi_Path_hpp

#include <Afs/Rfs/RootFileSystem.hpp>
#include <Afs/Rfs/Pathname.hpp>

class PathProfile;

class Path
{
public:
    Path();

    explicit Path(const Pathname &pathname, const WString &device_Id = L"rfs");

    Path(const PathProfile &profile);

    ~Path();

    const WString& GetStorageDeviceId() const
        { return m_storage_device_Id; }

    const Pathname& GetPathname() const
        { return m_pathname; }

    Pathname& GetPathname()
        { return m_pathname; }

    MimeType GetMimeType() const
        { return m_pathname.GetMimeType(); }

    void WriteTo(PathProfile &profile) const;

    void ReadFrom(const PathProfile &profile);

    BOOLEAN operator==(const Path &rhs) const;

private:
    WString m_storage_device_Id;
    Pathname m_pathname;
};

#endif  // Apoxi_Path_hpp

