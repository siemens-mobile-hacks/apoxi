/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MimeTypeTableUtils_hpp)
#define MimeTypeTableUtils_hpp

#include <Auxiliary/MimeTypeTable.hpp>


#define APOXI_DCL_MIME_TYPE_DEFS(tab_name) \
    static const MimeTypeTableEntry     tab_name[]; \
    static MimeTypeTable::Partition     tab_name##_part

#define APOXI_MIME_EXT(fileext) fileext "\0"

#define APOXI_MIME_STR(mimestr) mimestr "\0"

#define APOXI_COUNTOF(array) ( sizeof(array) / sizeof(array[0]) )

#define APOXI_ADD_MIME_TYPE_DEFS(class_name, tab_name) \
    const MimeTypeTableEntry    class_name##::##tab_name[] =

#define APOXI_END_MIME_TYPE_DEFS(class_name, tab_name) \
    ; \
    MimeTypeTable::Partition \
        class_name##::##tab_name##_part( class_name##::##tab_name, \
                                         APOXI_COUNTOF(class_name##::##tab_name) );

#define APOXI_DEF_MIME_TYPE(mime_type, mime_str, is_binary, file_ext_substr_list) \
    { mime_type, is_binary, mime_str, file_ext_substr_list }

#endif  // MimeTypeTableUtils_hpp

