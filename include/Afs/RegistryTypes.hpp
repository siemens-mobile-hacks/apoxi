/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

/* Contains Registry Interface declarations and global defines */

#if !defined(Apoxi_RegistryTypes_hpp)
#define Apoxi_RegistryTypes_hpp

#include <Kernel/Types.hpp>

#define APOXI_REG_INVALID_LOCKID -1

enum RegDataFormat {
    RegDataFormatBool,
    RegDataFormatB64,
    RegDataFormatChar,
    RegDataFormatInt,
    RegDataFormatNode,
    RegDataFormatNull,
    RegDataFormatXml
};

enum RegChangeType {
    RegChangeTypeAdd,
    RegChangeTypeDelete,
    RegChangeTypeSftDel,
    RegChangeTypeReplace,
    RegChangeTypeUnknown
};

struct RegObjectData {
    CHAR* data;
    INT32 datasize;
    RegDataFormat dataformat;
    const CHAR* datatype;
};

enum RegResult {
    RegResSuccess,
    RegResError,
    RegResInsufficientBuffer,
    RegResNoData,
    RegResLocked,
    RegResUnlocked,
    RegResNoService,
    RegResTypeNotSupported,
    RegResNoGetOnInterior,
    RegResNodeAlreadyExists,
    //children locked
    RegResChildLocked
};



typedef RegObjectData Dmr_DMObjectData;
#endif


