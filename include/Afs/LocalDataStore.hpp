/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */     

#if !defined(Apoxi_LocalDataStore_hpp)
#define Apoxi_LocalDataStore_hpp
class Uri;
class String;
class DataItem;

class LocalDataStore {
    public:
        static RegResult Get(const Uri& uri, DataItem& dataitem, INT16 transac_id); 

        static RegResult Set(const Uri& parent_uri, const String& node_name, const DataItem& dataitem, INT16 transac_id);

        static RegResult Replace(const Uri& uri, const DataItem& dataitem, INT16 transac_id);
        static RegResult AddLeafNode(const Uri& parent_uri, const String& node_name, const DataItem& dataitem, INT16 transac_id);

        static RegResult AddInteriorNode(const Uri& parent_uri, const Uri& node_uri, INT16 transac_id);

        static RegResult Delete(const Uri& uri, INT16 transac_id);

        static void RegCommitTransaction(INT16 transaction_id);


    private:
        static void DeleteInteriorRecord(INT file_id, INT16 transaction_id);

        static BOOLEAN TakeBackup(INT16 file_id, INT16 transac_id);

};
#endif

