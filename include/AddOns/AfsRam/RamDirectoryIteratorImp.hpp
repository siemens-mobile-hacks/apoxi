/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RamDirectoryIteratorImp_hpp)
#define Apoxi_RamDirectoryIteratorImp_hpp

#include <Afs/Rfs/DirectoryIterator.hpp>
#include <AddOns/AfsRam/RamFileNode.hpp>

class RamDirectoryIteratorImp : public DirectoryIterator
{
    protected:
        explicit RamDirectoryIteratorImp(const Pathname &dir_pathname,
            const FileFilterPtr &filter);

        virtual ~RamDirectoryIteratorImp();

        virtual DirectoryIterator& AtomicIncrement();

        friend class RamStorageDeviceImp;

    private:
        inline BOOLEAN FindNext();
        BOOLEAN     IsCurrentDir(RamHandle dir_handle) const;
        //BOOLEAN       IsParentDir(RamHandle dir_handle);

        void        GetFileNameFromFoundFile(RamHandle found_file);
        BOOLEAN     IsMatchTheFilter(FileFilterPtr filter) const;

        RamHandle       m_found_file;
        BOOLEAN         m_has_next;
};

#endif  // Apoxi_RamDirectoryIteratorImp_hpp


