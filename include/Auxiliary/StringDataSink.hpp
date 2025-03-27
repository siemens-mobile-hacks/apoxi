/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(StringDataSink_hpp)
#define StringDataSink_hpp

#include <Auxiliary/DataSink.hpp>
#include <Auxiliary/String.hpp>
class StringDataSink : public DataSink
{
    private:
        typedef DataSink Base;

    public:
        StringDataSink();
        
        virtual ~StringDataSink();

        virtual BOOLEAN Open();

        virtual BOOLEAN Close();

        virtual BOOLEAN IsOpen() const;

        virtual UINT32 Write(const void HUGE *buf, UINT32 nbytes);

        virtual UINT32 Write(UINT32 offset, const void HUGE *buf,
            UINT32 nbytes);

        virtual BOOLEAN GetSize(UINT32 &size) const;

        const String& GetString() { return m_string; }

    private:
        String m_string;
        BOOLEAN m_is_open;

};

#endif  // StringDataSink_hpp

