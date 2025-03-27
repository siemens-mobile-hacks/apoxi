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
    defined in "src\koglerm_snap_apoxi_tester\lnz_apoxi\Apoxi\Afs\Rfs\RfsMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(RfsMsgTypes_hpp__ST_1128347704782)
#define RfsMsgTypes_hpp__ST_1128347704782

#include <Kernel/Message.hpp>
#include <Auxiliary/WString.hpp>


class File;
class StorageDevice;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class FileChunkOperationProgressMsg
    ====================================================================== */

class FileChunkOperationProgressMsg : public ContextMsg {
    public:
        FileChunkOperationProgressMsg(ExecutionContext* context, const File& file, UINT progress);
        virtual ~FileChunkOperationProgressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const File& GetFile() const { return m_file; }
        UINT GetProgress() const { return m_progress; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 16050
            };
        
    private:
        static const MsgMetaData m_meta_data;
        const File &m_file;
        UINT m_progress;
        
    };


/*  ======================================================================
    Class RfsMediaAvailableStatusMsg
    ====================================================================== */

class RfsMediaAvailableStatusMsg : public Message {
    public:
        RfsMediaAvailableStatusMsg(const WString& storage_device_id, BOOLEAN media_present);
        virtual ~RfsMediaAvailableStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetStorageDeviceId() const { return m_storage_device_id; }
        BOOLEAN IsMediaPresent() const { return m_media_present; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 16051
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_storage_device_id;
        BOOLEAN m_media_present;
        
    };


/*  ======================================================================
    Class RfsStorageDeviceRegistrationStatusMsg
    ====================================================================== */

class RfsStorageDeviceRegistrationStatusMsg : public Message {
    public:
        RfsStorageDeviceRegistrationStatusMsg(const WString& storage_device_id, BOOLEAN device_registered);
        virtual ~RfsStorageDeviceRegistrationStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetStorageDeviceId() const { return m_storage_device_id; }
        BOOLEAN IsDeviceRegistered() const { return m_device_registered; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 16052
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_storage_device_id;
        BOOLEAN m_device_registered;
        
    };

#endif // RfsMsgTypes_hpp__ST_1128347704782

