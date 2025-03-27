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
    defined in "src\koglerm_snap_apoxi_tester\lnz_apoxi\Apoxi\AddOns\AfsFat\FatFsMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(FatFsMsgTypes_hpp__ST_1128347975150)
#define FatFsMsgTypes_hpp__ST_1128347975150

#include <Kernel/Message.hpp>
#include <Auxiliary/WString.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class FatFsUsbMassStorageRequestMsg
    ====================================================================== */

class FatFsUsbMassStorageRequestMsg : public Message {
    public:
        FatFsUsbMassStorageRequestMsg(const WString& storage_device_id, BOOLEAN request_granted);
        virtual ~FatFsUsbMassStorageRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetStorageDeviceId() const { return m_storage_device_id; }
        BOOLEAN IsRequestGranted() const { return m_request_granted; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 16060
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_storage_device_id;
        BOOLEAN m_request_granted;
        
    };


/*  ======================================================================
    Class FatFsUsbMassStorageReleaseMsg
    ====================================================================== */

class FatFsUsbMassStorageReleaseMsg : public Message {
    public:
        FatFsUsbMassStorageReleaseMsg(const WString& storage_device_id);
        virtual ~FatFsUsbMassStorageReleaseMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetStorageDeviceId() const { return m_storage_device_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 16061
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_storage_device_id;
        
    };

#endif // FatFsMsgTypes_hpp__ST_1128347975150

