/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MimeTypeTable_hpp)
#define MimeTypeTable_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>

#if defined(APOXI_COMPAT_1_13_0)
    #include <Afs/Ffs/FfsTypes.hpp>
#endif

typedef INT MimeType;


enum ApoxiMimeTypeId {
    c_mime_unknown,
    c_mime_app_j2me_archieve,
    c_mime_app_j2me_jrs,
    c_mime_app_mmf,
    c_mime_audio_amr,
    c_mime_audio_imelody,
    c_mime_audio_midi,
    c_mime_audio_mpeg,
    c_mime_audio_wav,
    c_mime_drm_ro,
    c_mime_drm_message,
    c_mime_drm_textual,
    c_mime_drm_encoded,
    c_mime_drm_content,
    c_mime_image_bmp,
    c_mime_image_ems,
    c_mime_image_gif,
    c_mime_image_jpeg,
    c_mime_image_png,
    c_mime_image_tiff,
    c_mime_image_wbmp,
    c_mime_text_calendar,
    c_mime_text_html,
    c_mime_text_j2me_appdesc,
    c_mime_text_plain,
    c_mime_text_vcard,
    c_mime_text_wml,
    c_mime_text_wmlscript,
    c_mime_text_xhtml,
    c_mime_text_xml,
    c_mime_video_mpeg,
    c_mime_video_msvideo,
    c_mime_video_quicktime,
    c_mime_video_3gpp,
    c_mime_audio_3gpp,
    c_mime_image_svg,
    c_mime_image_svgz,
    c_mime_app_spf,
    c_mime_apoxi_settings,
    c_mime_audio_aac,
    c_mime_audio_m4a,
    c_mime_audio_mobile_xmf,
    c_mime_app_sdp,
    //  Please add new APOXI mime type constants just above this line !

    c_mime_user_offset  
};

#if defined(APOXI_COMPAT_1_13_0)
    typedef const CHAR* FileExtension;
    typedef const CHAR* MimeStr;
#endif

struct MimeTypeTableEntry {

    MimeType        mime_type;

    BOOLEAN         is_binary;

    const CHAR *    mime_str;

    const CHAR *    file_ext_substr_list;
};

class MimeTypeTable {

    public:
        class Partition {

            friend class MimeTypeTable;

            public:
                Partition(const MimeTypeTableEntry  table[], UINT  no_entries);

                MimeType GetMinMimeTypeId() const;
                MimeType GetMaxMimeTypeId() const;

            private:
                const UINT                  m_no_entries;
                const MimeTypeTableEntry *  m_table;
                Partition *                 m_next_ptr;

                Partition(const Partition &);

                Partition&  operator=(const Partition &);

                static BOOLEAN ListContainsString(const CHAR* str_list,
                                                  const CHAR* key_str,
                                                  UINT8& key_pos);
                const MimeTypeTableEntry *   Begin() const { return &(m_table[0]); }
                const MimeTypeTableEntry *   End() const { return &(m_table[m_no_entries]); }
                const MimeTypeTableEntry &   At(UINT  index) const {
                    ASSERT_DEBUG(index < m_no_entries);
                    return  m_table[index];
                }
                BOOLEAN HasNext() const { return m_next_ptr != 0; }
                const Partition* GetNext() const { return  m_next_ptr; }
                Partition* GetNext() { return  m_next_ptr; }
                void SetNext(Partition* next_ptr) { m_next_ptr = next_ptr; }
                const MimeTypeTableEntry &  FindByMimeTypeId(MimeType id) const;
                const MimeTypeTableEntry &  FindByMimeString(const CHAR* mime_str) const;
                const MimeTypeTableEntry &  FindByExtension(const CHAR* file_ext, UINT8 &idx) const;
        };

        friend class Partition;

        static MimeType GetMimeTypeByExt(const CHAR* file_ext, UINT8& idx);

        static MimeType GetMimeTypeByExt(const CHAR* file_ext);

        static MimeType GetMimeTypeByMimeStr(const CHAR* mime_str);

        static const CHAR* GetMimeStrByExt(const CHAR* file_ext);

        static const CHAR* GetMimeStrByMimeType(MimeType mime_type);

        static const CHAR* GetExtByMimeType(MimeType mime_type, UINT8 offset = 0);

        static  const CHAR* GetExtByMimeStr(const CHAR* mime_str);

        static const CHAR* GetFirstExtByMimeType(MimeType mime_type);

        static const CHAR* GetFirstExtByMimeStr(const CHAR* mime_str);

        static  MimeType GetMaxMimeTypeId();

        static const CHAR* GetNextExtension(const CHAR* file_ext);

        static INT IsTextByMimeStr(const CHAR* mime_str);

        static INT IsTextByExt(const CHAR* file_ext);

        static INT IsBinaryByMimeStr(const CHAR*  mime_str);

        static INT IsBinaryByExt(const CHAR* file_ext);

#if defined(APOXI_COMPAT_1_13_0)

        static  MimeType    GetMimeTypeByFileType(FfsFileType file_type);

        static  const CHAR* GetMimeStrByFileType(FfsFileType file_type);

        static  FfsFileType GetFileTypeByExt(const CHAR *extension);

        static  FfsFileType GetFileTypeByMimeType(MimeType mime_type);

        static  FfsFileType GetFileTypeByMimeStr(const CHAR *mime_str);

        static  const CHAR* GetExtByFileType(FfsFileType file_type);

        static  INT         IsTextByFileType(FfsFileType file_type);

        static  INT         IsBinaryByFileType(FfsFileType file_type);

#endif

    private:
        static const MimeTypeTableEntry     s_apoxi_types[];
        static MimeTypeTable::Partition     s_apoxi_types_part;

        static const CHAR *                 c_no_file_extension;
        static Partition *                  s_root_part_ptr;

        MimeTypeTable();

        MimeTypeTable(const MimeTypeTable&);

        ~MimeTypeTable();

        MimeTypeTable& operator=(const MimeTypeTable&);

        static const MimeTypeTableEntry &  GetUnknownMimeTypeInfo() { return  s_apoxi_types[c_mime_unknown]; }
        static  const CHAR* GetNextStringInList(const CHAR* str_list);
};

#endif  // MimeTypeTable_hpp

