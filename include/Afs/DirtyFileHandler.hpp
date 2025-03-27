/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */     

#if !defined(Apoxi_DirtyFileHandler_hpp)
#define Apoxi_DirtyFileHandler_hpp
#include <Afs/RegDefines.hpp>

//Dirty file

struct RegDirtyFile {
    RegFileHeader   m_file_header;
    INT16           m_last_commited_transaction;
    BOOLEAN         m_dirty_flag;
};

class DirtyFileHandler {
    public:

        ~DirtyFileHandler() {}

        static BOOLEAN Init();

        static BOOLEAN GetDirtyFlag();

        static INT16 GetLastTransaction();

        static void SetDirtyFlag(BOOLEAN flag);

        static void SetLastTransaction(INT16 last_commited_transaction);

        static BOOLEAN FlushDirtyFile();

    private:

        DirtyFileHandler() {}

        static RegDirtyFile m_dirty_file_buffer;
};
#endif

