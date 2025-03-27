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
    defined in "wickhara_latest_dv\lnz_apoxi\Apoxi\Devices\DisplayMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Devices_DisplayMsgTypes_hpp)
#define Devices_DisplayMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Devices/Display.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class DisplayInfoMsg
    ====================================================================== */

class DisplayInfoMsg : public Message {
    public:
        DisplayInfoMsg(const Display::Info& info, INT index = 0);
        virtual ~DisplayInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Display::Info& GetInfo() const { return m_info; }
        INT GetIndex() const { return m_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9060
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Display::Info m_info;
        INT m_index;
    };

#endif // Devices_DisplayMsgTypes_hpp

