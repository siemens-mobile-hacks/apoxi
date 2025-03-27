/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_JpegEncodingThreadlet_hpp)
#define Apoxi_JpegEncodingThreadlet_hpp

class JpegEncoder;
class JpegImage;
#include <Gui/EncodingThreadlet.hpp>

class JpegEncodingThreadlet : public EncodingThreadlet {
    typedef EncodingThreadlet Base;
    
    public: 
        virtual ~JpegEncodingThreadlet();
    
        static JpegEncodingThreadlet* CreateInstance(JpegEncoder& encoder,
                                                     const Image& source,
                                                     DataSink& dest);
    
        static JpegEncodingThreadlet* CreateInstance(JpegEncoder& encoder,
                                                     BinData& source,
                                                     const Image::MetaData& src_params,
                                                     DataSink& dest);

    protected:
        JpegEncodingThreadlet(JpegEncoder& encoder,
                              const Image& source,
                              DataSink& dest);

        JpegEncodingThreadlet(JpegEncoder& encoder,
                              BinData& source,
                              const Image::MetaData& src_params,
                              DataSink& dest);

};

#endif // Apoxi_JpegEncodingThreadlet_hpp


