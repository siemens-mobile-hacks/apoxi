/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EncodingThreadlet_hpp)
#define Apoxi_EncodingThreadlet_hpp

class ImageEncoder;
class DataSink;
#include <Kernel/Threadlet.hpp>
#include <Gui/Image.hpp>

class EncodingThreadlet : public Threadlet {
    typedef Threadlet Base;
    
    public: 
        virtual ~EncodingThreadlet();

        virtual void ReleaseInstance(); 

        virtual INT Fn();

    protected:
        EncodingThreadlet(ImageEncoder& encoder, const Image& source, DataSink& dest);

        EncodingThreadlet(ImageEncoder& encoder,
                          BinData& source,
                          const Image::MetaData& src_params,
                          DataSink& dest);

        ImageEncoder& GetEncoder() { return m_encoder; }

        // Returns the source image. 0 is returned if a binary data as source is used.
        const Image* GetImage() const { return m_src_image; }

        BinData* GetBinData() const { return m_src_data; }
        
        const Image::MetaData* GetMetaData() const { return m_src_params; }

        DataSink& GetDataSink() { return m_data_sink; }
        
    private:
        // References instead of pointers are used, as it may never be allowed to change
        // the properties during the lifetime of the instance and also because the
        // properties never may be 0.
        ImageEncoder& m_encoder;
        DataSink& m_data_sink;

        BinData* m_src_data;
        const Image::MetaData* m_src_params;
        const Image* m_src_image;
};

#endif // Apoxi_EncodingThreadlet_hpp


