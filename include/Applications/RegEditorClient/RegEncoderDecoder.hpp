/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if !defined(Mmi_RegEncoderDecoder_hpp)
#define Mmi_RegEncoderDecoder_hpp

#include <Afs/RegIterator.hpp>
#include <Afs/Uri.hpp>
#include <Afs/RegDefines.hpp>

//Constants to define little and big endian
static const INT32 c_reg_little_endian   = 0x00;
static const INT32 c_reg_big_endian      = 0x18;
static const CHAR c_reg_protocol_version = 0x01;
static const CHAR c_processor_type       = 0x00;

static const INT16 c_max_buffer_size = 0x1000;

static UINT8 buffer[c_max_buffer_size]; 

typedef BOOLEAN FLAG;

static const UINT8 c_reg_16_bit = 0x00;
static const UINT8 c_reg_32_bit = 0x01;


class RegEncoderDecoder
{
public:


    enum ResponseType
    {
        RegSuccess              = 0x00,
        RegError                = 0x01,
        NoData                  = 0x03,
        Locked                  = 0x04,
        Unlocked                = 0x05,
        RegNoService            = 0x06,
        UnSuppotedType          = 0x07,
        RegResNoGetOnInterior   = 0x08,
        RegResNodeAlreadyExists = 0x09,
        RegResChildLocked       = 0x0A,
        InvalidRequest          = 0xF0
    };

    /*
    enum ProtocolPayloadType
    {
        Boolean             = 0x0A,
        Integer             = 0x01,
        String              = 0x03,
        Blob                = 0x09,
        Uri                 = 0x20,
        NumberOfChildren    = 0x21,
        InteriorOrLeaf      = 0x22,
    };

    */

    enum MsgID
    {
        //Mobile --> PC
        MobileShutdown      = 0x01,
        Notification        = 0x02,
        ResponseMessage     = 0x03,

        //PC --->Mobile

        Get                 = 0x80,
        Set                 = 0x81,
        CreateInterior      = 0x82,
        Delete              = 0x83,
        Lock                = 0x84,
        Unlock              = 0x85,
        RegisterNotify      = 0x86,
        ConnectionClose     = 0x87,
        ConnectionResponse  = 0x88,
        BlobResponse        = 0x89,
        SetExtn             = 0x90,

        //Iterator
        GetIterator         = 0xC0,
        SetIterator         = 0xC1,
        TraverseNext        = 0xC2,
        TraverseUp          = 0xC3, 
        TraverseDown        = 0xC4,
        GetLeafMetaData     = 0xC5,
        GetInteriorMetaData = 0xC6,

        //Transaction
        EnableTransaction   = 0xD0,
        Commit              = 0xD1

    };

     enum PayloadType
     {
        PayloadDataItem,
        PayloadIteratorObj,
        PayloadInteger = 0x30
     };


     enum IteratorType
     {
        IteratorUri                 = 0x20,
        IteratorInteriorMetaData    = 0x21,
        IteratorNodeType            = 0x22,
        IteratorLeafMetaData        = 0x23
     };


    struct RegIteratorNodeType {
         RegIterator::NodeType          m_node_type; //Bool or Number or Generic etc
         Uri                            *m_uri;
    };


     struct IteratorObjResult
     {
        IteratorType    m_iterator_type;

        union
        {
            Uri                             *m_uri;
            RegIteratorNodeType             m_iter_nodetype;
    #if 0
            RegIterator::NodeType           m_node_type;
    #endif
            RegIterator::LeafMetaData       m_leaf_meta_data;
            RegIterator::InteriorMetaData   m_interior_meta_data;
        } m_iterator_obj;
     };

     struct Payload
     {
        PayloadType m_type; // dataitem or iterator
        union
        {
            DataItem            *m_dataitem;
            IteratorObjResult   *m_iterator_res_obj;
            INT16               m_lockinfo;
        } payload_obj;
     };


    typedef struct Response 
    {
        ResponseType    m_res_type;
        UINT8           m_additional_info;
        Payload         m_payload;
    }Response;



    typedef struct UriAndPayload 
    {
        Uri             *m_uri;
        Payload         m_payload;
    }UriAndPayload;



    typedef struct Mobile2PCMsg 
    {
        MsgID   m_msg_id;
        
        union msg 
        {
            Uri         *m_uri;
            Response    m_response;

        }msg;

    }Mobile2PCMsg;

    typedef struct PC2MobileMsg
    {
        MsgID   msg_id;
        
        union msg 
        {
            Uri                 *m_uri;
            UriAndPayload       m_uri_payload;
            ResponseType        m_res_type;
            INT16               m_lock_id;
        }msg;   
    }PC2MobileMsg;

    typedef struct SetUpMsg 
    {
        UINT8       m_endianess;
        UINT8       m_protocol_version;
        UINT8       m_processor_type;
        INT16       m_max_message_size;
        INT16       m_max_blob_size;
    }SetUpMsg;



    static UINT8 extra_bytes;



    ~RegEncoderDecoder(){}

    BOOLEAN EncodeSetupMsg(UINT8 *buffer, UINT16* NoOfBytesEncoded);


    BOOLEAN Encode(UINT8* buffer, Mobile2PCMsg& msg, UINT8 packetnumber, UINT16* NoOfBytesEncoded);
    //NoOfBytesEncoded will be output parameter
    //In case of blob objects, RegApp will give the packet number to encode to Encode()


    BOOLEAN Decode(UINT8* buffer, PC2MobileMsg&, FLAG& in_out);
    //- flag is in/out parameter 
    //Flag will be FALSSE initially, but decode will make TRUE if the blob size is more than 4K
    
    static RegEncoderDecoder* GetInstance();

private:

    BOOLEAN EncodePayload(UINT8* buffer, Payload& payload, UINT8 packetnumber, UINT16* NoOfBytesEncoded);

    BOOLEAN EncodeDataItem(UINT8* buffer, Payload& payload, UINT8 packetnumber, UINT16* NoOfBytesEncoded);

    BOOLEAN EncodeIteratorObj(UINT8* buffer, Payload& payload, UINT16* NoOfBytesEncoded);

    BOOLEAN DecodeDataItem(UINT8 *buffer, PC2MobileMsg& pc_2_mob, FLAG& in_out);

    BOOLEAN DecodeSetExtn(UINT8 *buffer, PC2MobileMsg& pc_2_mob, FLAG& in_out);

    RegEncoderDecoder(){}

    static RegEncoderDecoder m_encoder_decoder_obj;
    static INT32 blob_size;
};

#endif
