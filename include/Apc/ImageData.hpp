/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_ImageData_hpp)
#define Apc_ImageData_hpp

#include <Apc/SignalTypes.hpp>


/*  ------------------------------------------------------------------------
     SimClutEntry
    ------------------------------------------------------------------------ */

class SimClutEntry {
    public:
        SimClutEntry() : red(0), green(0), blue(0) {};

        UINT8 red;
        UINT8 green;
        UINT8 blue;
};

/*  ------------------------------------------------------------------------
     SimImageCodingScheme
    ------------------------------------------------------------------------ */

enum SimImageCodingScheme {
    SimBasicImageCoding = 0x11,
    SimColorImageCoding = 0x21
};

/*  ------------------------------------------------------------------------
     ImageRequestType    T_SI_IMAGE_REQ_TYPE 
    ------------------------------------------------------------------------ */

enum SimImageRequestType {
    SimImageHeader = 0,
    SimImageHeaderBody = 1,
    SimImageHeaderBodyClut = 2,
    SimImageHeaderClut = 3,
};

/*  ------------------------------------------------------------------------
    SimImageDescriptor T_SI_IMAGE_DESCRIPTOR
    ------------------------------------------------------------------------ */

class SimImageDescriptor {
    public:
        SimImageDescriptor();
        SimImageDescriptor(const SimImageDescriptor & desc);

        void Fill(const T_SI_IMAGE_DESCRIPTOR * descriptor);
        void Get(T_SI_IMAGE_DESCRIPTOR * descriptor) const;

        SimImageDescriptor & operator = (const SimImageDescriptor & desc);
        UINT8 s_width;
        UINT8 s_height;
        UINT8 s_coding_scheme_type;
        UINT8 s_file_id_high;
        UINT8 s_file_id_low;
        UINT8 s_file_instance_offset_high;
        UINT8 s_file_instance_offset_low;
        UINT8 s_file_instance_length_high;
        UINT8 s_file_instance_length_low;

        void DbgOut() const;

};

/*  ========================================================================
    SimIconDescription T_SI_ICON_DESCRIPTOR
    ======================================================================== */

class SimIconDescription
{
    public:
        SimIconDescription();
        SimIconDescription(const SimIconDescription & data);
        ~SimIconDescription();

        void Fill(const T_SI_ICON_DESCRIPTOR * descriptor);
        const SimImageDescriptor & GetSimImageDescriptor(INT idx) const;
        UINT8 GetIconId() const { return (m_icon_id); }
        UINT8 GetNoImages() const { return (m_number_of_instances); }

        UINT8 GetRfu() const { return (m_rfu); }
        SimIconDescription & operator = (const SimIconDescription & szCopy);

        void DbgOut() const;

    private:
        INT                     m_icon_id;
        UINT8                   m_number_of_instances;
        SimImageDescriptor *    m_image_descriptions_ptr;
        UINT8                   m_rfu;
};

/*  ========================================================================
    SimImage T_SI_IMAGE_HEADER
        holds the data of an Image with dyn. alloc. mem
    ======================================================================== */

class SimImage
{
    public:
        SimImage();
        SimImage(const SimImage & imagedata);
        ~SimImage();

        void Fill(const T_SI_IMAGE_HEADER * imgheader);
        INT GetCoding() const { return (m_coding); }
        SimImageCodingScheme GetSimImageCodingScheme() const { return (SimImageCodingScheme)(m_coding); }
        INT GetWidth() const { return (m_width); }
        INT GetHeight() const { return (m_height); }
        INT GetBpp() const { return (m_bpp); }
        INT GetNrClutEntries() const { return (m_nr_clut_entries); }
        INT GetClutLocation() const { return (m_clut_location); }
        UINT8 * GetImageBuffer() const { return m_image_body; }
        INT  GetImageBufferLength() const;
        UINT8 * GetClutBuffer() const { return m_image_clut; }
        INT  GetClutBufferLength() const;
        SimClutEntry GetSimClutEntry(INT idx) const;

        SimImage & operator = (const SimImage & szCopy);
        
        void DbgOut() const;

    private:
        INT     m_coding;
        INT     m_width;
        INT     m_height;
        INT     m_bpp;
        INT     m_nr_clut_entries;
        INT     m_clut_location;
        UINT8 * m_image_body;
        UINT8 * m_image_clut;
};

#endif 


