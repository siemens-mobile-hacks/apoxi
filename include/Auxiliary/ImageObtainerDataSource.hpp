/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_ImageObtainerDataSource_hpp)
#define Auxiliary_ImageObtainerDataSource_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Gui/ImageObtainer.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/DataSource.hpp>

class ImageObtainerDataSource : public DataSource
{
    typedef DataSource Base;

    public:
        ImageObtainerDataSource(const ImageObtainer& img_obt);

        virtual ~ImageObtainerDataSource();

        virtual BOOLEAN Open();
        virtual BOOLEAN Close();

        virtual BOOLEAN IsOpen() const;

        virtual BOOLEAN Read(void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(void HUGE *buffer, UINT32 max_count, UINT32&bytes_read);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 max_count, UINT32 &bytes_read);
        virtual BOOLEAN GetSize(UINT32 &size) const;

    protected:
        // The data source that is read from.
        ImageObtainer m_img_obt;

        BOOLEAN m_is_open;
        UINT32  m_offset;
};

#endif  // Auxiliary_ImageObtainerDataSource_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS

