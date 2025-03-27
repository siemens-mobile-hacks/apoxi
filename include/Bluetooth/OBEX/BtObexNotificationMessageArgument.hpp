/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXITEST_20_10_06-2_SV\lnz_apoxi\Apoxi\Bluetooth\OBEX\BtObexNotificationMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_OBEX_BtObexNotificationMessageArgument_hpp)
#define Bluetooth_OBEX_BtObexNotificationMessageArgument_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/OBEX/BtTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtObexServerNmaConnect
    ====================================================================== */

class BtObexServerNmaConnect : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaConnect(const BtResultCode& result);
        BtObexServerNmaConnect();
        ~BtObexServerNmaConnect();
        
        static const BtObexServerNmaConnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 20
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaConnect*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaConnect& BtObexServerNmaConnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaConnect!\n");
    return ((BtObexServerNmaConnect &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaDisconnect
    ====================================================================== */

class BtObexServerNmaDisconnect : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaDisconnect(const BtResultCode& result);
        BtObexServerNmaDisconnect();
        ~BtObexServerNmaDisconnect();
        
        static const BtObexServerNmaDisconnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 21
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaDisconnect*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaDisconnect& BtObexServerNmaDisconnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaDisconnect!\n");
    return ((BtObexServerNmaDisconnect &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaSetPath
    ====================================================================== */

class BtObexServerNmaSetPath : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaSetPath(const BtResultCode& result, BOOLEAN Backup, BOOLEAN Create);
        BtObexServerNmaSetPath();
        ~BtObexServerNmaSetPath();
        
        static const BtObexServerNmaSetPath& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        BOOLEAN IsBackup() const { return m_Backup; }
        BOOLEAN IsCreate() const { return m_Create; }
        
        enum  {
            ID = 22
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaSetPath*) arg); }
        
        BtResultCode m_result;
        BOOLEAN m_Backup;
        BOOLEAN m_Create;
        
    };

// Inline definitions
inline const BtObexServerNmaSetPath& BtObexServerNmaSetPath::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaSetPath!\n");
    return ((BtObexServerNmaSetPath &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaGet
    ====================================================================== */

class BtObexServerNmaGet : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaGet(const BtResultCode& result);
        BtObexServerNmaGet();
        ~BtObexServerNmaGet();
        
        static const BtObexServerNmaGet& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 23
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaGet*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaGet& BtObexServerNmaGet::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaGet!\n");
    return ((BtObexServerNmaGet &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaPut
    ====================================================================== */

class BtObexServerNmaPut : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaPut(const BtResultCode& result);
        BtObexServerNmaPut();
        ~BtObexServerNmaPut();
        
        static const BtObexServerNmaPut& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 24
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaPut*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaPut& BtObexServerNmaPut::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaPut!\n");
    return ((BtObexServerNmaPut &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaAbort
    ====================================================================== */

class BtObexServerNmaAbort : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaAbort(const BtResultCode& result);
        BtObexServerNmaAbort();
        ~BtObexServerNmaAbort();
        
        static const BtObexServerNmaAbort& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 25
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaAbort*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaAbort& BtObexServerNmaAbort::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaAbort!\n");
    return ((BtObexServerNmaAbort &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaHeaderSent
    ====================================================================== */

class BtObexServerNmaHeaderSent : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaHeaderSent(const BtResultCode& result);
        BtObexServerNmaHeaderSent();
        ~BtObexServerNmaHeaderSent();
        
        static const BtObexServerNmaHeaderSent& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 26
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaHeaderSent*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaHeaderSent& BtObexServerNmaHeaderSent::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaHeaderSent!\n");
    return ((BtObexServerNmaHeaderSent &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaHeaderIndication
    ====================================================================== */

class BtObexServerNmaHeaderIndication : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaHeaderIndication(const BtResultCode& result, const BtObexHeader& header);
        BtObexServerNmaHeaderIndication();
        ~BtObexServerNmaHeaderIndication();
        
        static const BtObexServerNmaHeaderIndication& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        const BtObexHeader& GetHeader() const { return m_header; }
        
        enum  {
            ID = 27
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaHeaderIndication*) arg); }
        
        BtResultCode m_result;
        BtObexHeader m_header;
        
    };

// Inline definitions
inline const BtObexServerNmaHeaderIndication& BtObexServerNmaHeaderIndication::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaHeaderIndication!\n");
    return ((BtObexServerNmaHeaderIndication &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaDataBufferIndication
    ====================================================================== */

class BtObexServerNmaDataBufferIndication : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaDataBufferIndication(const BtResultCode& result, UINT16 number_of_bytes, BOOLEAN delete_object, BOOLEAN create_empty);
        BtObexServerNmaDataBufferIndication();
        ~BtObexServerNmaDataBufferIndication();
        
        static const BtObexServerNmaDataBufferIndication& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        UINT16 GetNumberOfBytes() const { return m_number_of_bytes; }
        BOOLEAN IsDeleteObject() const { return m_delete_object; }
        BOOLEAN IsCreateEmpty() const { return m_create_empty; }
        
        enum  {
            ID = 28
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaDataBufferIndication*) arg); }
        
        BtResultCode m_result;
        UINT16 m_number_of_bytes;
        BOOLEAN m_delete_object;
        BOOLEAN m_create_empty;
        
    };

// Inline definitions
inline const BtObexServerNmaDataBufferIndication& BtObexServerNmaDataBufferIndication::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaDataBufferIndication!\n");
    return ((BtObexServerNmaDataBufferIndication &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaDataInidication
    ====================================================================== */

class BtObexServerNmaDataInidication : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaDataInidication(const BtResultCode& result);
        BtObexServerNmaDataInidication();
        ~BtObexServerNmaDataInidication();
        
        static const BtObexServerNmaDataInidication& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 29
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaDataInidication*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaDataInidication& BtObexServerNmaDataInidication::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaDataInidication!\n");
    return ((BtObexServerNmaDataInidication &) arg);
}



/*  ======================================================================
    Class BtObexServerNmaTransportDisconnect
    ====================================================================== */

class BtObexServerNmaTransportDisconnect : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexServerNmaTransportDisconnect(const BtResultCode& result);
        BtObexServerNmaTransportDisconnect();
        ~BtObexServerNmaTransportDisconnect();
        
        static const BtObexServerNmaTransportDisconnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 30
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexServerNmaTransportDisconnect*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexServerNmaTransportDisconnect& BtObexServerNmaTransportDisconnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexServerNmaTransportDisconnect!\n");
    return ((BtObexServerNmaTransportDisconnect &) arg);
}



/*  ======================================================================
    Class BtObexClientNmaHeaderSent
    ====================================================================== */

class BtObexClientNmaHeaderSent : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexClientNmaHeaderSent(const BtResultCode& result);
        BtObexClientNmaHeaderSent();
        ~BtObexClientNmaHeaderSent();
        
        static const BtObexClientNmaHeaderSent& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 40
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexClientNmaHeaderSent*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexClientNmaHeaderSent& BtObexClientNmaHeaderSent::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexClientNmaHeaderSent!\n");
    return ((BtObexClientNmaHeaderSent &) arg);
}



/*  ======================================================================
    Class BtObexClientNmaHeaderIndication
    ====================================================================== */

class BtObexClientNmaHeaderIndication : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexClientNmaHeaderIndication(const BtResultCode& result, const BtObexHeader& header);
        BtObexClientNmaHeaderIndication();
        ~BtObexClientNmaHeaderIndication();
        
        static const BtObexClientNmaHeaderIndication& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        const BtObexHeader& GetHeader() const { return m_header; }
        
        enum  {
            ID = 41
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexClientNmaHeaderIndication*) arg); }
        
        BtResultCode m_result;
        BtObexHeader m_header;
        
    };

// Inline definitions
inline const BtObexClientNmaHeaderIndication& BtObexClientNmaHeaderIndication::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexClientNmaHeaderIndication!\n");
    return ((BtObexClientNmaHeaderIndication &) arg);
}



/*  ======================================================================
    Class BtObexClientNmaDataBufferIndication
    ====================================================================== */

class BtObexClientNmaDataBufferIndication : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexClientNmaDataBufferIndication(const BtResultCode& result, UINT16 number_of_bytes, BOOLEAN delete_object, BOOLEAN create_empty);
        BtObexClientNmaDataBufferIndication();
        ~BtObexClientNmaDataBufferIndication();
        
        static const BtObexClientNmaDataBufferIndication& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        UINT16 GetNumberOfBytes() const { return m_number_of_bytes; }
        BOOLEAN IsDeleteObject() const { return m_delete_object; }
        BOOLEAN IsCreateEmpty() const { return m_create_empty; }
        
        enum  {
            ID = 42
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexClientNmaDataBufferIndication*) arg); }
        
        BtResultCode m_result;
        UINT16 m_number_of_bytes;
        BOOLEAN m_delete_object;
        BOOLEAN m_create_empty;
        
    };

// Inline definitions
inline const BtObexClientNmaDataBufferIndication& BtObexClientNmaDataBufferIndication::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexClientNmaDataBufferIndication!\n");
    return ((BtObexClientNmaDataBufferIndication &) arg);
}



/*  ======================================================================
    Class BtObexClientNmaDataInidication
    ====================================================================== */

class BtObexClientNmaDataInidication : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexClientNmaDataInidication(const BtResultCode& result);
        BtObexClientNmaDataInidication();
        ~BtObexClientNmaDataInidication();
        
        static const BtObexClientNmaDataInidication& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 43
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexClientNmaDataInidication*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexClientNmaDataInidication& BtObexClientNmaDataInidication::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexClientNmaDataInidication!\n");
    return ((BtObexClientNmaDataInidication &) arg);
}



/*  ======================================================================
    Class BtObexClientNmaTransportDisconnect
    ====================================================================== */

class BtObexClientNmaTransportDisconnect : public StackMsgArgument {
    friend class BtObexMessageArgumentsDestroyTableNode;
    public:
        BtObexClientNmaTransportDisconnect(const BtResultCode& result);
        BtObexClientNmaTransportDisconnect();
        ~BtObexClientNmaTransportDisconnect();
        
        static const BtObexClientNmaTransportDisconnect& Cast(const StackMsgArgument& arg);
        const BtResultCode& GetResult() const { return m_result; }
        
        enum  {
            ID = 44
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtObexClientNmaTransportDisconnect*) arg); }
        
        BtResultCode m_result;
        
    };

// Inline definitions
inline const BtObexClientNmaTransportDisconnect& BtObexClientNmaTransportDisconnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtObexClientNmaTransportDisconnect!\n");
    return ((BtObexClientNmaTransportDisconnect &) arg);
}


#endif // Bluetooth_OBEX_BtObexNotificationMessageArgument_hpp

