/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(APOXI_LIB_ADDON_AFSFAT)
    #error The FAT file system (FAT) add-on is not activated properly - please enable feature AFSFAT!
#elif defined(APOXI_RTOS_WIN32)
    // Host simulator for FAT.
    #include <AddOns/AfsFat/FatSim.hpp>
#else
    #include <stack/driver.h>
#endif

#include <ApoxiVersion.hpp>

#include <AddOns/AfsFat/FatDirectoryIteratorImp.hpp>
#include <AddOns/AfsFat/FatFile.hpp>
#include <AddOns/AfsFat/FatFileImp.hpp>
#include <AddOns/AfsFat/FatHandler.hpp>
#include <AddOns/AfsFat/FatStorageDeviceImp.hpp>
#include <AddOns/AfsFat/FatTypes.hpp>

#include <Afs/Rfs/DirectoryIterator.hpp>
#include <Afs/Rfs/File.hpp>
#include <Afs/Rfs/FileFilter.hpp>
#include <Afs/Rfs/StorageDevice.hpp>

#include <Auxiliary/Date.hpp>
#include <Auxiliary/Macros.hpp>
#include <Auxiliary/String.hpp>

#include <Kernel/Types.hpp>
#include <Kernel/VersionInfo.hpp>

#include <string.h>

