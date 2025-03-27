/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\nageshra_BP2_2.5\lnz_apps_int\Applications\ImageBrowser\ImageBrowserMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Common_ImageBrowserMsgTypes_hpp)
#define Common_ImageBrowserMsgTypes_hpp
#include <Kernel/Message.hpp>
#include <Afs/Rfs/Path.hpp>
#include <ImageBrowser/Common/MediaFilter.hpp>
#include <ImageBrowser/ImageRef.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class ImageBrowserDeleteImageMsg
    ====================================================================== */
class ImageBrowserDeleteImageMsg : public Message {
    public:
        ImageBrowserDeleteImageMsg();
        virtual ~ImageBrowserDeleteImageMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21352
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
/*  ======================================================================
    Class ImageBrowserRenameImageMsg
    ====================================================================== */
class ImageBrowserRenameImageMsg : public Message {
    public:
        ImageBrowserRenameImageMsg(const WString& new_name);
        virtual ~ImageBrowserRenameImageMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetNewName() const { return m_new_name; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 21353
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_new_name;
        
    };
/*  ======================================================================
    Class ImageBrowserServiceMsg
    ====================================================================== */
class ImageBrowserServiceMsg : public ContextMsg {
    public:
        ImageBrowserServiceMsg(ExecutionContext* context);
        virtual ~ImageBrowserServiceMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21354
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
#endif // Common_ImageBrowserMsgTypes_hpp
