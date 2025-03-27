/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */     

#if !defined(Apoxi_BackupFileHandler_hpp)
#define Apoxi_BackupFileHandler_hpp
#include <Afs/RegDefines.hpp>
#include <Afs/RegNodeFile.hpp>


//RegBackUp File

class BackupFileHandler {
    public:
        static BOOLEAN RollBackTransaction(INT16 transaction_id);
        static BOOLEAN CreateBackupFile(INT16 org_file_id, INT16& backup_fileid, INT16 transaction_id);
        static BOOLEAN DeleteBackupFile(INT16 backup_file_id);
};

#endif


