/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PngEncodingThreadlet_hpp)
#define Apoxi_PngEncodingThreadlet_hpp


class PngEncoder;
class PngImage;

#include <Gui/EncodingThreadlet.hpp>

class PngEncodingThreadlet : public EncodingThreadlet {
    typedef EncodingThreadlet Base;
    
    public: 
        virtual ~PngEncodingThreadlet();
    
        static PngEncodingThreadlet* CreateInstance(PngEncoder& encoder,
                                                     const Image& source,
                                                     DataSink& dest);
    
        static PngEncodingThreadlet* CreateInstance(PngEncoder& encoder,
                                                     BinData& source,
                                                     const Image::MetaData& src_params,
                                                     DataSink& dest);

    protected:
        PngEncodingThreadlet(PngEncoder& encoder,
                              const Image& source,
                              DataSink& dest);

        PngEncodingThreadlet(PngEncoder& encoder,
                              BinData& source,
                              const Image::MetaData& src_params,
                              DataSink& dest);

};

#endif  // Apoxi_PngEncodingThreadlet_hpp

