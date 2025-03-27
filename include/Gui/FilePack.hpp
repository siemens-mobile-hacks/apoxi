/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FilePack_hpp)
#define Apoxi_FilePack_hpp

#include <Gui/AcacTypes.hpp>
#include <Gui/DataPack.hpp>

class FilePack : public DataPack {
    typedef DataPack Base;

    public:
        FilePack(const UINT8 *data);
        virtual ~FilePack();

        const CustFileData *GetFile(UINT16 index);

    private:
        CustFileData *  m_cust_file_data;
};

#endif  // Apoxi_FilePack_hpp

