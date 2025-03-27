/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

/* Contains Registry Interface declarations and global defines */

#if !defined(Apoxi_RegNodeFile_hpp)
#define Apoxi_RegNodeFile_hpp

#include <Afs/RegDefines.hpp>


enum RegPayloadType {
    RegNoNode        ,
    RegBooleanNode   ,
    RegStringNode    ,
    RegIntegerNode   ,
    RegBlobNode      ,
    RegBlobFileNode  ,
    RegInteriorNode
};

struct RegNodeFileHeader {
       RegFileHeader m_file_header;
       CHAR m_uri[c_reg_uri_size_max];
};

struct RegNodeRecord {
       CHAR m_name[c_reg_node_name_size_max];
       struct {
           UINT16 m_payload_type; // mimetype of payload (see above table)
           UINT16 m_offset_node_payload; //offset of payload (max = 64 KB)
       } m_payload_bits;
};

class Uri;
class RegBlobObject;
class String;


/*
@code
  +-->   +-------------------------------------------------------------------+
  |      | 0 1 2 3 4 5 6 7| 0 1 2 3 4 5 6 7| 0 1 2 3 4 5 6 7| 0 1 2 3 4 5 6 7|
  |      +----------------+----------------+----------------+----------------+
  |      |     Version    |    File Type   |         Node Count (n)          |
  |      +----------------+----------------+---------------------------------+
  |      |                         .                                         |
Header   |                         .                                         |
  |      |                         URI (255 Bytes)                           |
  |      |                         .                                         |
  |      |                         .                                         |
  |      |                                                                   |
  |      |                                                  +----------------+
  |      |                                                  |                |
  +-->   +--------------------------------------------------+----------------+
  |      |                        .                                          |
  |      |                        Node Name (50 Bytes) (Node 1)              |
  |      |                        .        +---------------------------------+
  |      |                                 |                                 |
  |      +---------------------------------+---------------------------------+
  |      |          Payload Type           |         Payload Offset          |--------+
  |      +---------------------------------+---------------------------------+        |
 Node    |                           .                                       |        |
Records  |                           .                                       |        |
  |      |                           .                                       |        |
  |      +-------------------------------------------------------------------+        |
  |      |                        .                                          |        |
  |      |                        Node Name (50 Bytes) (Node n)              |        |
  |      |                        .        +---------------------------------+        |
  |      |                                 |                                 |        |
  |      +---------------------------------+---------------------------------+        |
  |      |          Payload Type           |         Payload Offset          |-----+  |
  +-->   +-------------------------------------------------------------------+     |  |
  |      |                                                                   |     |  |
  |      |                           .                                       |     |  |
  |      |                                                                   |     |  |
  |      |                                                                   |     |  |
  |      |                                                                   |     |  |
  |      |                                                                   |     |  |
  |      |                                                          +--------+-----+  |
  |      |                                                          |        |        |
  |      |                                                          V        |        |
  |      +-------------------------------------------------------------------+        |
Payload  |                           Payload n                               |        |
  |      |                                                                   |        |
  |      +-------------------------------------------------------------------+        |
  |      |   .                                                               |        |
  |      |   .                          +------------------------------------+--------+
  |      |   .                          |                                    |
  |      |   .                          V                                    |
  |      +-------------------------------------------------------------------+
  |      |                          Payload 1                                |
  |      |                                                                   |
  +-->   +-------------------------------------------------------------------+
@endcode
*/

class RegNodeBuffer {

    public:

        RegNodeBuffer() {}

        ~RegNodeBuffer() {}

        void SetRootFileType();

        void Init(UINT8* raw_memory);

        BOOLEAN Read(UINT16 fileid);

        BOOLEAN Write(UINT16 fileid);

        void ResetFileId();

        INT16 GetFileId();

        //Misc Functions

        void GetUri(Uri& uri);

        void SetUri(Uri& uri);

        BOOLEAN GetNodeIndex(String& node_name, UINT& idx);

        BOOLEAN GetNodeRecord(UINT idx, RegNodeRecord* rec);

        RegNodeRecord* GetNodeRecordPtr(UINT idx);

        UINT GetNumOfNodeRecord();

        void SetNumOfNodeRecord(UINT no_of_records);

        BOOLEAN AddInteriorHeader(const Uri& node_uri);


        BOOLEAN GetBooleanPayload(BOOLEAN* val, UINT idx);
        BOOLEAN GetIntegerPayload(INT* val, UINT idx);
        BOOLEAN GetStringPayload(String* val, UINT idx);
        BOOLEAN GetBlobPayload(RegBlobObject* val, UINT idx);
        BOOLEAN GetInteriorPayload(INT16* val, UINT idx);
        BOOLEAN GetBlobFileNodePayload(INT16* val, UINT idx);

        //Add Functions

        BOOLEAN AddBooleanNode(BOOLEAN val, const String& node_name);
        BOOLEAN AddIntegerNode(INT val, const String& node_name);
        BOOLEAN AddStringNode(String* val, const String& node_name);
        BOOLEAN AddBlobNode(RegBlobObject* val, const String& node_name);
        BOOLEAN AddInteriorNode(INT16 val, const String& node_name);
        BOOLEAN AddBlobFileNode(INT16 val, const String& node_name);

        //Set Functions

        BOOLEAN SetBooleanNode(BOOLEAN val, UINT idx);
        BOOLEAN SetIntegerNode(INT val, UINT idx);
        BOOLEAN SetStringNode(String* val, UINT idx);
        BOOLEAN SetBlobNode(RegBlobObject* val, UINT idx);
        BOOLEAN SetInteriorNode(INT16 val, UINT idx);
        BOOLEAN SetBlobFileNode(INT16 val, UINT idx);

        //Delete Functions

        BOOLEAN DeleteNode(UINT idx);
        UINT8* GetNodeBufferRawMemory();


    private:

        INT16 m_file_id;
        UINT8* m_reg_node_buffer; // SIZE = c_reg_node_file_size_max
        BOOLEAN m_update_necessary;
        BOOLEAN InsertPayloadPossible(UINT payload_size, INT no_of_nodes);
        BOOLEAN AddNode(const String& uri, void* payload_to_insert, UINT payload_size, RegPayloadType payload_type);
        BOOLEAN UpdateNode(void* val, UINT idx, UINT payload_size);
        BOOLEAN IsReplacePossible(UINT idx, UINT new_payload_size, UINT no_of_nodes, UINT&  existing_payload_size);

}; //RegNodeBuffer

#endif


