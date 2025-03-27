/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexFtpDataServer_hpp)
#define Apoxi_ObexFtpDataServer_hpp

#include <Auxiliary/String.hpp>
#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/DataSource.hpp>
#include <Auxiliary/HeapDataSink.hpp>

#include <Obex/ObexHeaderList.hpp>
#include <Obex/ObexAddrPtr.hpp>
#include <Obex/ObexResult.hpp>
#include <Obex/ObexDataServer.hpp>

//  Forward declarations of classes
class DataSourceBinData;
class ObexFtpServer;

class ObexFtpDataServer : public ObexDataServer {

    typedef ObexDataServer Base;

    public:
        typedef SimpleMap<String, String> FolderListingEntryProps;

        ObexFtpDataServer();

        ObexFtpDataServer(ObexFtpServer* frontend, ExecutionContext* ctx_ptr);

        virtual ~ObexFtpDataServer();

        virtual void Init(ObexFtpServer* frontend, ExecutionContext* ctx_ptr);

        const WString& GetCurrentFolder() const;


        ObexResult HandleConnectionRequest(ObexObject::ResponseCode resp_code);

        ObexResult HandleFolderListingRequest(ObexObject::ResponseCode resp_code);

        ObexResult HandleProvideFolderListingEntry(BOOLEAN isFolder,
            const String& name, const FolderListingEntryProps& props);

        ObexResult HandleProvideFolderListingEntriesFinished();

        ObexResult HandleSetCurrentFolderRequest(
            ObexObject::ResponseCode resp_code);

        ObexResult HandleFilePullRequest(ObexObject::ResponseCode resp_code,
            DataSourcePtr data_src_ptr);

        ObexResult HandleFilePushRequest(ObexObject::ResponseCode resp_code,
            DataSinkPtr data_sink_ptr, UINT32 max_size = 0);

        ObexResult HandleDeleteObjectRequest(ObexObject::ResponseCode resp_code);

    protected:

        // Misc OBEX operations
        virtual void OnBind(const ObexAddrPtr& addr_ptr, ObexResult result);
        virtual void OnConnect(const ObexHeaderList& headers, UINT8 flags);
        virtual void OnDisconnect(const ObexHeaderList& headers);
        virtual void OnDisconnected(ObexResult result);
        virtual void OnSetPath(const ObexHeaderList& headers, UINT8 flags);

        // OBEX GET operation
        virtual void OnGetIncoming();
        virtual void OnGetHeaders(const ObexHeaderList& headers);
        virtual void OnDataRequested();
        virtual void OnGetComplete(ObexResult result);

        // OBEX PUT operation
        virtual void OnPutIncoming();
        virtual void OnPutHeaders(const ObexHeaderList& headers);
        virtual void OnDataAvailable();
        virtual void OnDelete();
        virtual void OnPutComplete(ObexResult result);

        // Submits an OBEX response code to the client.
        ObexResult SubmitResponse(ObexObject::ResponseCode resp_code);

        // Extracts all useful header fields out of the given header.
        void ExtractHeaderFields(const ObexHeaderList& headers);

        // Clears all header field members.
        void ClearHeaderFields();

    private:

        enum Operation {
            OperationNone,
            OperationFolderListing,
            OperationPullObject,
            OperationPushObject,
            OperationDeleteObject
        };

        enum FrontendEvent {
            FrontendEventOnConnect,
            FrontendEventOnGetFolderListing,
            FrontendEventOnProvideFolderListingEntries,
            FrontendEventOnSetCurrentFolder,
            FrontendEventOnFilePull,
            FrontendEventOnFilePush,
            FrontendEventOnDeleteObject,
            FrontendEventNone
        };

        // Used for checking correct invocation of public HandleXYZ methods.
        ObexResult IsInvocationAllowed(FrontendEvent expected_event);
        void SetFrontendEvent(FrontendEvent event);

    private:
        // Pointer to frontend
        ObexFtpServer* m_frontend;

        // Initialization state flag.
        BOOLEAN m_initialized;

        // Current operation
        Operation m_operation;

        // Last fired frontend event.
        FrontendEvent m_frontend_event;

        // Current & requested path
        WString m_cur_path;
        WString m_req_path;

        // Necessary header fields from PUT/GET operation
        BOOLEAN m_header_name_set;
        WString m_header_name;
        BOOLEAN m_header_length_set;
        UINT32 m_header_length;
        BOOLEAN m_header_type_set;
        String m_header_type;

        // Members for object pull/push
        DataSinkPtr m_data_sink_ptr;
        DataSourceBinData* m_bin_data_src_ptr;

        // DataSink for constructing XML folder listing
        HeapDataSinkPtr m_folder_listing_ptr;

        // Several static string constants, used for building XML folder listing
        static const CHAR* const xml_header;
        static const CHAR* const xml_parent_folder_entry;
        static const CHAR* const xml_folder_entry;
        static const CHAR* const xml_file_entry;
        static const CHAR* const xml_attribute_assignment;
        static const CHAR* const xml_attribute_separator;
        static const CHAR* const xml_end_tag_newline;
        static const CHAR* const xml_footer;
        static const CHAR* const obex_header_folder_listing;

        // Root path and path separator
        static const WCHAR* const s_root_path;
        static const WCHAR* const s_path_separator;
};

#endif // Apoxi_ObexFtpDataServer_hpp

