/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_NodeFileHandler_hpp)
#define Apoxi_NodeFileHandler_hpp

#include <Afs/RegistryTypes.hpp>

class String;
class RegBlobObject;
class DataItem;
class Uri;

class NodeFileHandler {
    public:

        static RegResult AddNodeEntry(INT16 transaction_id, INT16 file_id, const String& node_name, const DataItem& dataitem, INT16& blob_file_id);

        static RegResult AddInteriorNodeEntry(INT16 transaction_id, INT16 file_id, const Uri& uri, INT16 int_file_id);

        static RegResult RemoveNodeEntry(INT16 transaction_id, INT16 file_id, const Uri& uri, INT16& blob_file_id);

        static RegResult ReplaceNodeEntry(INT16 transaction_id, INT16 file_id, const String& node_name, const DataItem& dataitem, INT16& old_blob_id, INT16& new_file_id);

        static RegResult GetNodeEntry(INT16 transaction_id, INT16 file_id, const Uri& uri, DataItem& dataitem);

        static RegResult CreateInteriorNodeEntry(INT16& file_id);

        static RegResult CreateInteriorNodeEntry(const Uri& abs_uri, INT16& file_id);

        static RegResult RemoveInteriorNodeEntry(INT16 file_id);

        static BOOLEAN IsNodeExisting(const Uri& passed_uri, INT16 parent_file_id);


    private:
        static BOOLEAN CreateBlobFile(RegBlobObject* blob_obj, INT16& file_id);

};
#endif







