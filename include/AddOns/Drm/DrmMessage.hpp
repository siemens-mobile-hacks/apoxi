    /*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_Drm_Message_hpp)
#define Apoxi_Drm_Message_hpp


struct DrmMediaObject;

#include <Kernel/Types.hpp>
#include <Auxiliary/Vector.hpp>
#include <Auxiliary/DateTime.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/DrmCore.hpp>

#include <AddOns/Drm/Drm.hpp>
#include <AddOns/Drm/DrmRights.hpp>
#include <AddOns/Drm/DrmRightsStore.hpp>
#include <AddOns/Drm/MultipartParser.hpp>

#ifdef APOXI_INCLUDE_DRM_V2

struct DrmCryptInfo {
    DrmEncMethod            enc_method;
    DrmPaddingScheme        enc_padding;
    INT                     plaintext_length;
    UINT8*                  iv;                 // 16bytes
};

typedef INT DrmHeaderType;

struct DrmMessageInfo{
    int                 content_offset;
    int                 content_size;
    DrmCryptInfo        crypt_info;
};
#endif


class DrmMessage {
    public:

        DrmMessage(const BinData *drm_message,  DrmMimeType drm_mime_type) ; 

        DrmMessage(const BinData *drm_message,  const CHAR * headers ) ; 
        
#ifdef APOXI_INCLUDE_DRM_V2
        // ############# V2 Constructors ################

        DrmMessage(FilePtr file_ptr, DrmMimeType drm_mime_type);
        // Copy constructor
        DrmMessage(const DrmMessage &obj) ; 
    
        //default Constructor
        DrmMessage();

        // ############# V2 APIs added ################

        void SetDrmHeaderInfo(DrmMessageInfo header_info);  
        
        DrmStatus StartMediaBlockAccess(BlockData& block_data);

        DrmStatus GetNextMediaBlock(BYTE* content_buffer, INT& content_size);

        DrmStatus GetPrevMediaBlock(BYTE* content_buffer, INT& content_size);

        DrmStatus ResetMediaBlockAccess(BlockData& block_data);

        DrmStatus   GetCryptInfo(DrmCryptInfo* drm_crypt_info);

        String  GetContentURL() const;  // Get content URL

        String  GetIconURL() const;     // Get Icon URI

        String  GetInfoURL() const;             // Get Info URL

        FilePtr GetFilePtr() const;             // Get File Ptr (NULL if it is buffer based)

        INT GetContentOffset() const;
        INT GetContentSize() const;

        DrmStatus GetDrmHeader(DrmHeaderType header_type, String& header_value);

        // ############# End V2 additions ################
#endif

        ~DrmMessage() ; 

        static DrmMimeType GetDrmMimeType(const BinData *drm_message,const CHAR * base_mime_type) ;
        
        DrmLocalId ProcessDrmMessage();

        DrmStatus StripRelXml(UINT8** buf);

        void SetDrmLocalId(const DrmLocalId local_id);
    
        static String GetMediaMimeType(const BinData *drm_message, DrmMimeType drm_mime_type) ;

        static String GetRawMediaMimeType(const BinData *drm_message, DrmMimeType drm_mime_type, BOOLEAN &more) ;

        DrmStatus GetMediaObject(DrmOperation op, DrmMediaObject *media_object);
        

        BinData* GetMediaObject(DrmOperation op, DrmStatus& status);

        DrmStatus  GetMediaObject(DrmOperation op, DrmMediaObject *media_object, BlockData *block_data);

        BinData*  GetMediaObject(DrmOperation op,BlockData *block_data, DrmStatus& status);

        DrmStatus GetRawMediaObject(BOOLEAN decrypt, DrmMediaObject *media_object);

        DrmStatus  GetRawMediaObject(BOOLEAN decrypt, DrmMediaObject *media_object, BlockData *block_data);

        BinData* GetRawMediaObject(BOOLEAN decrypt, DrmStatus& status);

        BinData*  GetRawMediaObject(BOOLEAN decrypt,BlockData *block_data, DrmStatus& status);

        static DrmLocalId ProcessRightsMessage(const BinData * drm_rights_msg);
        
        String GetRightsIssuer() const; 

        DrmUid GetUid(DrmStatus &status) const; 

    private :

        void Init(const BinData *drm_message, const CHAR * headers, DrmMimeType drm_mime_type) ;

        DrmStatus CreateContainer(DrmLocalId localid, DrmOperation op, DrmRightsObjectContainer &ro_holder) ;

        BOOLEAN UpdateMoMimeType(DrmLocalId local_id, String mime);

        // Parses the Combined Delivery message
        DrmLocalId ParseCDMsg() ;

        // Gets the offset in the block - base is the offset of media object
        BOOLEAN GetOffset(BlockData * block_data,INT buflen,INT* offset, INT* datalen);

        // Gets the block and fills up media object structure - to be used with decoded/decrypted buf
        BOOLEAN GetBlockData(UINT8* buf,INT buflen,BlockData* block_data,DrmMediaObject *media_object);
        BOOLEAN GetBlockData(UINT8* buf,INT buflen,BlockData* block_data,BinData** media_object);       

        // Gets the block and fills up media object structure - to be used with non-decoded/plaintext data
        BOOLEAN GetBlockData(INT buflen,MultiPartData* b,BlockData* block_data,DrmMediaObject *media_object);
        BOOLEAN GetBlockData(INT buflen,MultiPartData* b,BlockData* block_data,BinData** media_object);
#ifdef APOXI_INCLUDE_DRM_V2
        // Data members added for V2
        INT                 m_content_offset;
        INT                 m_content_size;
        FilePtr             m_file_ptr;
        DrmCryptInfo            m_drm_crypt_info;

        // Block access
        BlockData           m_block_data;       // Sent from the user of the block access API
        INT                 m_current_block;    // To track the current block
#endif
        DrmMimeType m_drm_mime_type ;

        const BinData*      m_drm_message ;
        DrmLocalId m_local_id ;
        UINT8* m_decoded_buf;   // Pointer to decoded media object data - deleted when object expires
};

#ifdef APOXI_INCLUDE_DRM_V2

struct DrmMultipartDcfMessage {
    
    DrmDcfMessageType       m_type;             // Message type
    DrmMessage          m_dcf_message;      // DrmMessage
};

class DrmMessageContainer {
    public:
        DrmMessageContainer();
        
        INT GetCount() const;           // Content count

        INT GetAllCount() const;        // Inclusive of preview and icons

        DrmMessage& GetDrmMessage(INT i) ;

        void AddDrmMessage(DrmMessage& drm_message,DrmDcfMessageType dcf_type);

        INT GetInstantPreviewMessageCount() const ;
        DrmMessage& GetInstantPreviewMessage(INT i=0);
        INT GetIconMessageCount() const ;
        DrmMessage& GetIconMessage(INT i=0);

        DrmStatus GetLastError();


    private:
        Vector<DrmMultipartDcfMessage> m_drm_multipart_msg;
        INT     m_count;
        INT     m_icon_count;
        INT     m_preview_count;
        INT     m_content_count;
        DrmStatus   m_last_error;
};

class DrmMessageFactory {
    public:
        static DrmMessageContainer* GetDrmMessageContainer(const CHAR* headers, BinData* raw_drm_message, INT offset=0);

        static DrmMessageContainer* GetDrmMessageContainer(const CHAR* headers, FilePtr file, INT offset=0);
};
#endif  
        

#endif //Apoxi_Drm_Message_hpp

