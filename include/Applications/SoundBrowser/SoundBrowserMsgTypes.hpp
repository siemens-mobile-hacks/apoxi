/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\nageshra_win_2.5\lnz_apps_int\Applications\SoundBrowser\SoundBrowserMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Common_SoundBrowserMsgTypes_hpp)
#define Common_SoundBrowserMsgTypes_hpp
#include <Kernel/Message.hpp>
#include <Afs/Rfs/Path.hpp>
#include <SoundBrowser/Common/MediaFilter.hpp>
#include <SoundBrowser/SoundRef.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class SoundBrowserServiceMsg
    ====================================================================== */
class SoundBrowserServiceMsg : public ContextMsg {
    public:
        SoundBrowserServiceMsg(ExecutionContext* context);
        virtual ~SoundBrowserServiceMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 21355
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
#endif // Common_SoundBrowserMsgTypes_hpp
