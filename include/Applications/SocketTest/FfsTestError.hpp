/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTestError_hpp)
#define ApoxiApp_FfsTestError_hpp

enum eFfsTestErr
{
    FfsTestOK = 100, 
    FfsMemAllocErr, 
    FfsDeleteFileErr, 
    CreateErr = FfsTestOK + 100, 
    FileSizeErr, 
    OpenErr, 
    CloseErr, 
    FileRenameErr, 
    FileCopyErr, 
    StringCmpErr, 
    WriteErr = CreateErr + 100, 
    ReadErr, 
    AppendErr = WriteErr + 100
};

typedef eFfsTestErr ffsError;

#endif // ApoxiApp_FfsTestError_hpp
