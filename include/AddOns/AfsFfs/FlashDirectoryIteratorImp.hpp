/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FlashDirectoryIteratorImp_hpp)
#define Apoxi_FlashDirectoryIteratorImp_hpp

#include <Afs/Rfs/DirectoryIterator.hpp>
#include <Afs/Ffs/FfsTypes.hpp>

class FlashDirectoryIteratorImp : public DirectoryIterator
{
    protected:
        explicit FlashDirectoryIteratorImp(const Pathname &dir_pathname,
            const FileFilterPtr &filter, BOOLEAN find_dirs);

        virtual ~FlashDirectoryIteratorImp();

        virtual DirectoryIterator& AtomicIncrement();

        friend class FlashStorageDeviceImp;

    private:
        BOOLEAN FindNext(FfsFileId last_Id);

        FfsRefType m_ref_file;
        FfsFileId m_file_Id;

        BOOLEAN m_find_dirs;
        String m_working_dir;
};

#endif  // Apoxi_FlashDirectoryIteratorImp_hpp

