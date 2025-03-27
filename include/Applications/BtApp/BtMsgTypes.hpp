/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "UserData\project\huangtr_view_apoxi22\lnz_apps_int\Applications\BtApp\BtMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(BtApplication_BtMsgTypes_hpp)
#define BtApplication_BtMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDevice.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtIndicatorMsg
    ====================================================================== */

class BtIndicatorMsg : public Message {
    public:
        BtIndicatorMsg(const BtProfile& profile, BOOLEAN connected);
        virtual ~BtIndicatorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const BtProfile& GetProfile() const { return m_profile; }
        BOOLEAN IsConnected() const { return m_connected; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 22500
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtProfile m_profile;
        BOOLEAN m_connected;
        
    };

#endif // BtApplication_BtMsgTypes_hpp

