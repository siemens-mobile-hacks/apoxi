/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_UriMappingTable_hpp)
#define Apoxi_UriMappingTable_hpp
#include <Afs/RegDefines.hpp>

struct InteriorNodeRecord {
    CHAR    m_tree_level;
    CHAR    m_flag; //for blob files
    CHAR    m_node_name[c_reg_node_name_size_max];
    INT16   m_file_id;
    INT16   m_parent_file_id;   
    INT16   m_transaction_id;
    INT16   m_backup_file_id;
};

struct RegUriMapFile {
    RegFileHeader           m_map_file_header;
    InteriorNodeRecord      m_interior_node_record[c_max_interior_node_records];
};

class Uri;


class UriMappingTable {
    public:
                
        ~UriMappingTable() {};

        BOOLEAN Init();

        void Reset();

        static UriMappingTable* GetTable();
        
        INT16 GetFileId(const Uri& uri);

        INT16 GetFileId(INT index);

        INT GetFileIndex(INT16 file_id);

        BOOLEAN InsertURIRecord(const Uri& uri, INT16 file_id);

        BOOLEAN InsertURIRecord(const CHAR* node_name, INT16 file_id, INT16 parent_file_id, INT depth);

        BOOLEAN InsertBlobRecord(INT16 blob_file_id, INT16 parent_file_id);

        BOOLEAN RemoveURIRecord(const Uri& uri, INT16 file_id);

        BOOLEAN RemoveURIRecord(INT16 file_id);

        BOOLEAN RemoveBlobFileRecord(INT16 blob_file_id);

        void ReplaceFileId(INT16 old_blob_id, INT16 new_blob_id);

        INT16 GetChildFileId(INT16 parent_file_id, INT& index);

        BOOLEAN FlushMapFile();

        UINT GetNoOfNodes();

        //to check for blob file
        BOOLEAN IsBlobFile(UINT index);

        INT16 GetTransactionId(INT16 file_id);

        BOOLEAN SetTransactionId(INT16 file_id, INT16 transaction_id);

        
        INT16 GetBackupFileId(INT16 file_id);

        BOOLEAN SetBackupFileId(INT16 file_id, INT16 backup_file_id);

        BOOLEAN RemoveBackupFiles(INT16 transaction_id);

        BOOLEAN SearchFileId(INT16 file_id);

        //to check any backup file id existing in map table
        BOOLEAN SearchBackupFileId();


    private:

        RegUriMapFile m_reg_map_file;

        static UriMappingTable m_map_table;

        UriMappingTable() {};

        INT ResolveFile(const Uri& passed_uri, INT first_index, INT second_index);

        INT ResolveUsingParent(const Uri& passed_uri, INT first_index, INT second_index);

        BOOLEAN OpenAndVerifyFileId(const Uri& uri, INT16 file_id); 

        const CHAR* GetNodeName(INT16 file_id, INT& file_index);
};
#endif


