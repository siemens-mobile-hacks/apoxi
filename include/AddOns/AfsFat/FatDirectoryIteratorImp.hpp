/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FatDirectoryIteratorImp_hpp)
#define Apoxi_FatDirectoryIteratorImp_hpp

#include <Afs/Rfs/DirectoryIterator.hpp>
#include <AddOns/AfsFat/FatTypes.hpp>

class FatDirectoryIteratorImp : public DirectoryIterator
{
    protected:
        explicit FatDirectoryIteratorImp(const Pathname &dir_pathname,
            const WString &device_id, const FileFilterPtr &filter);

        virtual ~FatDirectoryIteratorImp();

        virtual DirectoryIterator& AtomicIncrement();

        friend class FatStorageDeviceImp;

    private:
        BOOLEAN FindNext();

        inline BOOLEAN IsCurrentDir(const FatFindData &find_data) const;
        inline BOOLEAN IsParentDir(const FatFindData &find_data) const;

        void GetFileNameFromFindData(const FatFindData &find_data);

        FatFindData m_find_data;
};

#endif  // Apoxi_FatDirectoryIteratorImp_hpp

