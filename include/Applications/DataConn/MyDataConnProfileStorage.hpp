/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_MyDataConnProfileStorage_hpp)
#define Apoxi_MyDataConnProfileStorage_hpp

#include <Socket/DataConnProfile.hpp>
#include <Socket/PersistDataConnProfile.hpp>
#include <Socket/DataConnProfileStorage.hpp>

#if defined(APOXI_RTOS_WIN32) || defined(FFS_PRESENT)
#include <Afs/Ffs/FlsFile.hpp>

#if !defined(APOXI_DATA_CONN_PROFILE_FFS_FILE_ID)
#define APOXI_DATA_CONN_PROFILE_FFS_FILE_ID 1000
#endif
#if !defined(APOXI_DATA_CONN_PROFILE_FFS_USER_TYPE)
#define APOXI_DATA_CONN_PROFILE_FFS_USER_TYPE 0
#endif

const UINT32 c_fsize_data_conn_profiles = sizeof(DataConnProfileStorage::Header) +
                                          (UINT32) c_data_conn_profile_count * 
                                          (UINT32) sizeof(PersistDataConnProfile);


class FfsDataConnProfileStorage : public DataConnProfileStorage {
    public:
        FfsDataConnProfileStorage();

        virtual BOOLEAN Open() { return TRUE; }

        virtual void Close();

        virtual BOOLEAN Read(Header &header);
        virtual BOOLEAN Write(const Header &header);

        virtual BOOLEAN Read(INT recno, PersistDataConnProfile &pdcp);
        virtual BOOLEAN Write(INT recno, const PersistDataConnProfile &pdcp);

    public:
        BOOLEAN OpenFfsFile();

        FlsFile m_file;

        UINT32 GetProfileOffset(INT recno) const {
            return (UINT32) sizeof(Header) +
                   (UINT32) recno * (UINT32) sizeof(PersistDataConnProfile);
        }
};

typedef FfsDataConnProfileStorage MyDataConnProfileStorage;

#else

class RamDataConnProfileStorage : public DataConnProfileStorage {
    public:
        virtual BOOLEAN Open() { return TRUE; }
        virtual void Close() { };

        virtual BOOLEAN Read(Header &header) { 
            header = m_header;
            return TRUE;
        }

        virtual BOOLEAN Write(const Header &header) {
            m_header = header;
            return TRUE;
        }

        virtual BOOLEAN Read(INT recno, PersistDataConnProfile &pdcp) {
            pdcp = m_pdcp[recno];
            return TRUE;
        }

        virtual BOOLEAN Write(INT recno, const PersistDataConnProfile &pdcp) {
            m_pdcp[recno] = pdcp;
            return TRUE;
        }

    public:
        static Header m_header;
        static PersistDataConnProfile m_pdcp[c_data_conn_profile_count];

};

typedef RamDataConnProfileStorage MyDataConnProfileStorage;

#endif

#endif  // Apoxi_DataConnProfileStorage_hpp

