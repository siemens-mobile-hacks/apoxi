/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AcacTypes_hpp)
#define Apoxi_AcacTypes_hpp

#define TEXTPACK_ID 0x74786574  //74 65 78 74 = text
#define FONTPACK_ID 0x746E6F66  //66 6F 6E 74 = font
#define T9PACK_ID   0x74636964  //64 69 63 74 = dict
#define FILEPACK_ID 0x656C6966  //66 69 6C 65 = file
//UINT32 CUSTPACK_HEADER =  0x48434353; // SCCH

#define TEXTPACK_KEYLANG_INDEX 0

#define INVALID_GLYPH_UNICODE 32

#if defined(APOXI_FACTORY_CUSTOMIZATION_SUPPORT)
    #if !defined (APOXI_RTOS_NUC32) && !defined (APOXI_RTOS_WIN32)
        #undef APOXI_FACTORY_CUSTOMIZATION_SUPPORT
    #endif
#endif

typedef UINT8 EntryId;
typedef UINT32 DataPackId;

// Use this pragma for defining another alignment than 4 UINT8s.
#pragma pack(push,ULOZ, 4)

// The following structures define the structures of the customization pack
// Details about the members of the structures and the structures themselves
// are described in Customization Pack Binary Structure.doc
typedef struct tagCustomizationPack
{
    UINT32      size;
    UINT32      header;
    UINT8       version;
    UINT8       running_version;
    UINT8       data_pack_count;
    UINT8       padding;
    UINT8       data_pack[1];
} CustomizationPackData;


typedef struct tagDataPackHeader
{
    UINT32      size; //size is the whole size of the DataPack, including the
                      //size of the fixed members (size, header,..)
    UINT16      entry_count;
    UINT16      padding;
    DataPackId  data_pack_id;
    UINT8       data_pack_data[1];
} DataPackHeaderData;


typedef struct tagTextPack
{
    UINT8   language[1];
} TextPackData;


typedef struct tagLanguage {
    UINT32      size;
    EntryId     id;
    UINT8       padding;
    UINT16      string_count;
    WCHAR       name[16];
    WCHAR       native_name[16];
    UINT16      offset_table[1];
} LanguageData;

typedef struct tagTranslationTable {
    WCHAR       data[1];
} TranslationTable;

typedef struct tagFontPack
{
    UINT8       font[1];
} FontPackData;

typedef struct tagFontFamily {
    WCHAR       family_name[16];
    BOOLEAN     serif;
    UINT8       padding[3];
} FontFamily;

typedef struct tagFont {
    UINT32      size;
    EntryId     id;
    UINT8       baseline;
    UINT8       height;
    UINT8       gap_to_next_char;
    WCHAR       name[16];
    FontFamily  font_family;
    UINT8       table_count;
    UINT8       bold_index;
    UINT8       italic_index;
    UINT8       padding2;
    UINT16      num_glyphs;
    UINT8       padding3[2];
    UINT8       index_table[256];
    UINT32      offset_table[1];
} FontData;

typedef struct tagGlyphData {
    UINT8 *     data_table;
} GlyphData;

typedef struct tagCPGlyph {
    UINT8       size;
    UINT8       width;                  // Character width in pixels
    UINT8       data[1];                    // Pointer to the character bitmap
} CPGlyph;

typedef struct tagT9Pack
{
    UINT8       t9_pack[1];
} T9PackData;

typedef struct tagLdbData {
    UINT32      size;
    UINT32      ldb_size;
    UINT16      ldb_id;
    UINT8       padding[2];
    UINT8       data[1];
} T9LdbData;


// Structures for storing arbitrary files

typedef struct  tagFilePackData
{
    UINT8       cust_file[1];
} FilePackData;

typedef struct tagCustFileData {
    UINT32      size;
    UINT8       mime_type;
    UINT8       padding[3];
    WCHAR       file_name[32];
    UINT32      file_size;
    UINT8       data[1];
} CustFileData;

#pragma pack(pop,ULOZ)


#endif //Apoxi_AcacTypes_hpp

