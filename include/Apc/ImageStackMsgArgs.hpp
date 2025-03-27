/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_development\src\Apoxi\Apc\ImageArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_ImageStackMsgArgs_hpp)
#define Apc_ImageStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/ImageData.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class ImageReadIndArg
    ====================================================================== */

class ImageReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ImageReadIndArg();
        
        static const ImageReadIndArg& Cast(const StackMsgArgument& arg);
        void SetImage(const SimImage& image) { m_image = image; }
        const SimImage& GetImage() const { return m_image; }
        
        enum  {
            ID = 1080
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ImageReadIndArg*) arg); }
        
        SimImage m_image;
        
    };

// Inline definitions
inline const ImageReadIndArg& ImageReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ImageReadIndArg!\n");
    return ((ImageReadIndArg &) arg);
}



/*  ======================================================================
    Class IconDescReadIndArg
    ====================================================================== */

class IconDescReadIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        IconDescReadIndArg();
        
        static const IconDescReadIndArg& Cast(const StackMsgArgument& arg);
        void SetIcondesc(const SimIconDescription& icondesc) { m_icondesc = icondesc; }
        const SimIconDescription& GetIcondesc() const { return m_icondesc; }
        
        enum  {
            ID = 1081
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((IconDescReadIndArg*) arg); }
        
        SimIconDescription m_icondesc;
        
    };

// Inline definitions
inline const IconDescReadIndArg& IconDescReadIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to IconDescReadIndArg!\n");
    return ((IconDescReadIndArg &) arg);
}



/*  ======================================================================
    Class ImageReadReqArg
    ====================================================================== */

class ImageReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        ImageReadReqArg(const SimImageRequestType& img_request_type, const SimImageDescriptor& imgdescriptor);
        ImageReadReqArg();
        
        static const ImageReadReqArg& Cast(const StackMsgArgument& arg);
        void SetImgRequestType(const SimImageRequestType& img_request_type) { m_img_request_type = img_request_type; }
        const SimImageRequestType& GetImgRequestType() const { return m_img_request_type; }
        void SetImgdescriptor(const SimImageDescriptor& imgdescriptor) { m_imgdescriptor = imgdescriptor; }
        const SimImageDescriptor& GetImgdescriptor() const { return m_imgdescriptor; }
        
        enum  {
            ID = 2080
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((ImageReadReqArg*) arg); }
        
        SimImageRequestType m_img_request_type;
        SimImageDescriptor m_imgdescriptor;
        
    };

// Inline definitions
inline const ImageReadReqArg& ImageReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to ImageReadReqArg!\n");
    return ((ImageReadReqArg &) arg);
}



/*  ======================================================================
    Class IconDescReadReqArg
    ====================================================================== */

class IconDescReadReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        IconDescReadReqArg(INT recno = 0);
        
        static const IconDescReadReqArg& Cast(const StackMsgArgument& arg);
        void SetRecno(INT recno) { m_recno = recno; }
        INT GetRecno() const { return m_recno; }
        
        enum  {
            ID = 2081
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((IconDescReadReqArg*) arg); }
        
        INT m_recno;
        
    };

// Inline definitions
inline const IconDescReadReqArg& IconDescReadReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to IconDescReadReqArg!\n");
    return ((IconDescReadReqArg &) arg);
}


#endif // Apc_ImageStackMsgArgs_hpp

