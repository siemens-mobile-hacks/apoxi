/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DirectoryIterator_hpp)
#define Apoxi_DirectoryIterator_hpp

#include <Afs/Rfs/Path.hpp>
#include <Afs/Rfs/File.hpp>

class DirectoryIterator
{
    public:
        virtual ~DirectoryIterator();

        BOOLEAN IsValid() const;

        virtual File::Error GetLastError() const;

        virtual const Pathname& GetPathname() const;

        virtual const Path& GetPath() const;

        virtual void Increment();

    protected:
        explicit DirectoryIterator(const Pathname &dir_pathname,
            const FileFilterPtr &filter, const WString &device_Id);

        void ApplyInitialFilter();

        virtual DirectoryIterator& AtomicIncrement() = 0;

    protected:
        const Pathname m_dir_pathname;

        Path m_cur_path;

        FileFilterPtr m_filter;

        mutable File::Error m_last_error;
};

#endif  // Apoxi_DirectoryIterator_hpp

