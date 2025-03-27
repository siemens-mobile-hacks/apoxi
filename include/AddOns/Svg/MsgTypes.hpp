/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Views\schrette_view\lnz_apoxi\Apoxi\AddOns\Svg\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Svg_MsgTypes_hpp)
#define AddOns_Svg_MsgTypes_hpp

#include <Kernel/Message.hpp>


class SvgPlayer;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SvgDecodingFinishedMsg
    ====================================================================== */

class SvgDecodingFinishedMsg : public Message {
    public:
        SvgDecodingFinishedMsg(SvgPlayer* player, const Ticks& ticks);
        virtual ~SvgDecodingFinishedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        SvgPlayer* GetPlayer() const { return m_player; }
        const Ticks& GetTicks() const { return m_ticks; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4400
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SvgPlayer* m_player;
        Ticks m_ticks;
        
    };


/*  ======================================================================
    Class SvgStatusMsg
    ====================================================================== */

class SvgStatusMsg : public ContextMsg {
    public:
        SvgStatusMsg(ExecutionContext* context, SvgPlayer* player, INT8 status);
        virtual ~SvgStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        SvgPlayer* GetPlayer() const { return m_player; }
        INT8 GetStatus() const { return m_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4401
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SvgPlayer* m_player;
        INT8 m_status;
        
    };


/*  ======================================================================
    Class SvgHyperlinkSelectMsg
    ====================================================================== */

class SvgHyperlinkSelectMsg : public ContextMsg {
    public:
        SvgHyperlinkSelectMsg(ExecutionContext* context, SvgPlayer* player, const WString& hyperlink);
        virtual ~SvgHyperlinkSelectMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        SvgPlayer* GetPlayer() const { return m_player; }
        const WString& GetHyperlink() const { return m_hyperlink; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4402
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SvgPlayer* m_player;
        WString m_hyperlink;
        
    };

#endif // AddOns_Svg_MsgTypes_hpp

