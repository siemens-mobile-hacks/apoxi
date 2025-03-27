/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DataConnProfileStorage_hpp)
#define Apoxi_DataConnProfileStorage_hpp

#include <Socket/DataConnProfile.hpp>

class DataConnProfileStorage
{
    public:
        class Header
        {
            public:
                enum {
                    c_file_version = 1
                };

                UINT8 m_version;
                UINT8 m_rec_max_count;
                UINT8 m_free[10];
                UINT16 m_profile_rec_size;
                DataConnProfileId m_def_profile;
                DataConnProfileId m_last_id;
                DataConnProfileIdSet m_profile_id;

                Header();
        };

        virtual BOOLEAN Open() { return TRUE; }

        virtual void Close() { }

        virtual BOOLEAN Read(Header &header) { return FALSE; }

        virtual BOOLEAN Write(const Header &header) { return FALSE; }

        virtual BOOLEAN Read(INT recno, PersistDataConnProfile &pdcp) 
            { return FALSE; }

        virtual BOOLEAN Write(INT recno, const PersistDataConnProfile &pdcp) 
            { return FALSE; }

        virtual BOOLEAN ResetToFactoryDefaults();
};

#endif  // Apoxi_DataConnProfileStorage_hpp


