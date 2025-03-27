/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined(APOXI_RTOS_WIN32)
    // Host simulator for FFS.
    #include <Afs/Ffs/FfsSim.hpp>
#elif !defined(FFS_PRESENT)
    #error The flash file system (FFS) is a prerequisite for an APOXI target build - please enable feature FFS!
#else
    #include <stack/driver.h>
#endif

#include <AddOns/AuxExtensions/MimeCoding.hpp>

#include <AddOns/Services/Service.hpp>
#include <AddOns/Services/ServiceBroker.hpp>

#include <Afs/AfsMsgTypes.hpp>
#include <Afs/BackupFileHandler.hpp>
#include <Afs/DeletedNode.hpp>
#include <Afs/DirtyFileHandler.hpp>
#include <Afs/GuidServiceTable.hpp>
#include <Afs/LocalDataStore.hpp>
#include <Afs/LockTable.hpp>
#include <Afs/LockTableList.hpp>
#include <Afs/NodeFileHandler.hpp>
#include <Afs/NotificationTable.hpp>
#include <Afs/RegDefines.hpp>
#include <Afs/RegDeleteBuffer.hpp>
#include <Afs/Registry.hpp>
#include <Afs/RegistryTypes.hpp>
#include <Afs/RegIterator.hpp>
#include <Afs/RegManager.hpp>
#include <Afs/RegMemoryPool.hpp>
#include <Afs/RegNodeFile.hpp>
#include <Afs/ObjectDataConverter.hpp>
#include <Afs/ObjectTreeService.hpp>
#include <Afs/Uri.hpp>
#include <Afs/UriMappingTable.hpp>

#include <Afs/Ffs/FfsHandler.hpp>
#include <Afs/Ffs/FfsMimeTypeMap.hpp>
#include <Afs/Ffs/FfsTypes.hpp>
#include <Afs/Ffs/FlsFile.hpp>

#include <Afs/Rfs/DirectoryIterator.hpp>
#include <Afs/Rfs/File.hpp>
#include <Afs/Rfs/FileBinData.hpp>
#include <Afs/Rfs/FileChunkOperator.hpp>
#include <Afs/Rfs/FileDataSink.hpp>
#include <Afs/Rfs/FileDataSource.hpp>
#include <Afs/Rfs/FileFilter.hpp>
#include <Afs/Rfs/FileVisitor.hpp>
#include <Afs/Rfs/Path.hpp>
#include <Afs/Rfs/Pathname.hpp>
#include <Afs/Rfs/PathProfile.hpp>
#include <Afs/Rfs/RfsMsgTypes.hpp>
#include <Afs/Rfs/RootFileSystem.hpp>
#include <Afs/Rfs/StorageDevice.hpp>
#include <Afs/Rfs/StorageDeviceFilter.hpp>
#include <Afs/Rfs/StorageDeviceIterator.hpp>
#include <Afs/Rfs/StorageDeviceVisitor.hpp>

#include <ApoxiVersion.hpp>

#include <Auxiliary/BinData.hpp>
#include <Auxiliary/BitVector.hpp>
#include <Auxiliary/DataItem.hpp>
#include <Auxiliary/DataSink.hpp>
#include <Auxiliary/DataSource.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/Macros.hpp>
#include <Auxiliary/MimeTypeTable.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/RegBlobObject.hpp>
#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/Time.hpp>
#include <Auxiliary/WildcardStrncmp.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/WStrUtil.hpp>

#include <Config/FfsConfig.hpp>

#include <Devices/StartUp.hpp>

#include <Kernel/Application.hpp>
#include <Kernel/Condition.hpp>
#include <Kernel/ExecutionContext.hpp>
#include <Kernel/Message.hpp>
#include <Kernel/MessageRouter.hpp>
#include <Kernel/MsgTypes.hpp>
#include <Kernel/SubSystem.hpp>
#include <Kernel/System.hpp>
#include <Kernel/Types.hpp>
#include <Kernel/VersionInfo.hpp>

#include <Kernel/Os/Os.hpp>
#include <Kernel/Os/OsClass.hpp>
#include <Kernel/Os/Semaphore.hpp>
#include <Kernel/Os/SemObtainer.hpp>

#include <stdio.h>
#include <string.h>

#if defined(APOXI_RTOS_WIN32)
    #include <Auxiliary/Vector.hpp>
    #include <Auxiliary/DateTime.hpp>
    #include <Kernel/Os/Mutex.hpp>
    #include <Kernel/Os/MutexObtainer.hpp>
    #include <direct.h>
    #include <io.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <share.h>
#endif

#ifdef APOXI_LIB_ADDON_AFSRFS
    #include <AddOns/AfsRfs/RootStorageDeviceImp.hpp>
#endif

#ifdef APOXI_LIB_ADDON_AFSRAM
    #include <AddOns/AfsRam/RamStorageDeviceImp.hpp>
#endif

#ifdef APOXI_LIB_ADDON_AFSFFS
    #include <AddOns/AfsFfs/FlashStorageDeviceImp.hpp>
#endif

#ifdef APOXI_LIB_ADDON_AFSMMC
    #include <AddOns/AfsMmc/MmcStorageDeviceImp.hpp>
#endif

