/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexFtpServer_hpp)
#define Apoxi_ObexFtpServer_hpp

#include "ObexFtpDataServer.hpp"

class ObexFtpServer {

    public:
        typedef ObexFtpDataServer::FolderListingEntryProps
            FolderListingEntryProperties;

    public:
        ObexFtpServer();

        ObexFtpServer(ExecutionContext* ctx_ptr);

        virtual ~ObexFtpServer();

        virtual void Init(ExecutionContext* ctx_ptr);


        inline ObexResult Open();

        inline ObexResult Open(const String& obex_addr_url,
            UINT8 open_flags = 0);

        virtual void OnBind(const ObexAddrPtr& addr_ptr, ObexResult result) {};

        inline ObexResult Close();

        virtual void OnClose(ObexResult result) {};


        virtual void OnConnect(const ObexHeaderList& headers, UINT8 flags) = 0;

        inline ObexResult AcceptConnectRequest();

        inline ObexResult RejectConnectRequest(
            ObexObject::ResponseCode resp_code = ObexObject::RespForbidden);


        virtual void OnDisconnected(ObexResult result) = 0;


        virtual void OnGetFolderListing(const WString& current_folder) = 0;

        inline ObexResult AcceptFolderListingRequest();

        inline ObexResult RejectFolderListingRequest(
            ObexObject::ResponseCode resp_code = ObexObject::RespForbidden);

        virtual void OnProvideFolderListingEntries(
            const WString& current_folder) = 0;

        inline ObexResult ProvideFolderListingEntry(
            BOOLEAN isFolder, const String& name,
            const FolderListingEntryProperties& properties);

        inline ObexResult ProvideFolderListingEntriesFinished();


        virtual void OnSetCurrentFolder(const WString& current_folder,
            const WString& new_current_folder, BOOLEAN create) = 0;

        inline ObexResult AcceptSetCurrentFolderRequest();

        inline ObexResult RejectSetCurrentFolderRequest(
            ObexObject::ResponseCode resp_code = ObexObject::RespForbidden);


        virtual void OnFilePull(const WString& current_folder,
            const WString& filename) = 0;

        inline ObexResult AcceptFilePullRequest(DataSourcePtr data_src_ptr);

        inline ObexResult RejectFilePullRequest(
            ObexObject::ResponseCode resp_code = ObexObject::RespForbidden);

        virtual void OnFilePullRequestCompleted(ObexResult result) = 0;


        virtual void OnFilePush(const WString& current_folder,
            const WString& filename, UINT32 size) = 0;

        inline ObexResult AcceptFilePushRequest(DataSinkPtr data_sink_ptr,
            UINT32 max_size = 0xFFFFFFFFul);

        inline ObexResult RejectFilePushRequest(
            ObexObject::ResponseCode resp_code = ObexObject::RespForbidden);

        virtual void OnFilePushRequestCompleted(ObexResult result) = 0;


        virtual void OnDeleteObject(const WString& current_folder,
            const WString& object) = 0;

        inline ObexResult AcceptDeleteObjectRequest();

        inline ObexResult RejectDeleteObjectRequest(
            ObexObject::ResponseCode resp_code = ObexObject::RespForbidden);


        inline const WString& GetCurrentFolder() const;

    private:
        ObexFtpDataServer m_server;
};

/*  ----------------------------------------------------------------------
    Open
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::Open()
{
    return Open("*://{target=H'F9EC7BC4-953C-11D2-984E-525400DC9E09'}",
        ObexServerDispatcher::SdbAutoRegister);
}   // Open

/*  ----------------------------------------------------------------------
    Open
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::Open(const String& obex_addr_url, UINT8 open_flags)
{
    return m_server.Open(obex_addr_url, open_flags);
}   // Open

/*  ----------------------------------------------------------------------
    Close
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::Close()
{
    return m_server.Close();
}   // Close

/*  ----------------------------------------------------------------------
    AcceptConnection
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::AcceptConnectRequest()
{
    return m_server.HandleConnectionRequest(ObexObject::RespOk);
}   // AcceptConnection

/*  ----------------------------------------------------------------------
    RejectConnection
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::RejectConnectRequest(
    ObexObject::ResponseCode resp_code)
{
    // To reject a connection an error response code must be passed!
    ASSERT_DEBUG(resp_code != ObexObject::RespOk);

    return m_server.HandleConnectionRequest(resp_code);
}   // RejectConnection

/*  ----------------------------------------------------------------------
    AcceptFolderListingRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::AcceptFolderListingRequest()
{
    return m_server.HandleFolderListingRequest(ObexObject::RespOk);
}   // AcceptConnection

/*  ----------------------------------------------------------------------
    RejectFolderListingRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::RejectFolderListingRequest(
    ObexObject::ResponseCode resp_code)
{
    // To reject a folder listing request an error response code must be passed!
    ASSERT_DEBUG(resp_code != ObexObject::RespOk);

    return m_server.HandleFolderListingRequest(resp_code);
}   // RejectConnection

/*  ----------------------------------------------------------------------
    ProvideFolderListingEntry
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::ProvideFolderListingEntry(
    BOOLEAN isFolder, const String& name,
    const FolderListingEntryProperties& properties)
{
    return m_server.HandleProvideFolderListingEntry(isFolder, name, properties);
}   // ProvideFolderListingEntry

/*  ----------------------------------------------------------------------
    ProvideFolderListingEntriesFinished
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::ProvideFolderListingEntriesFinished()
{
    return m_server.HandleProvideFolderListingEntriesFinished();
}   // ProvideFolderListingEntriesFinished

/*  ----------------------------------------------------------------------
    AcceptSetCurrentFolderRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::AcceptSetCurrentFolderRequest()
{
    return m_server.HandleSetCurrentFolderRequest(ObexObject::RespOk);
}   // AcceptSetCurrentFolderRequest

/*  ----------------------------------------------------------------------
    RejectSetCurrentFolderRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::RejectSetCurrentFolderRequest(
    ObexObject::ResponseCode resp_code)
{
    // To reject a current folder set request an error response code must be
    // passed!
    ASSERT_DEBUG(resp_code != ObexObject::RespOk);

    return m_server.HandleSetCurrentFolderRequest(resp_code);
}   // RejectSetCurrentFolderRequest

/*  ----------------------------------------------------------------------
    AcceptDeleteObjectRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::AcceptDeleteObjectRequest()
{
    return m_server.HandleDeleteObjectRequest(ObexObject::RespOk);
}   // AcceptDeleteObjectRequest

/*  ----------------------------------------------------------------------
    RejectDeleteObjectRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::RejectDeleteObjectRequest(
    ObexObject::ResponseCode resp_code)
{
    // To reject a delete object request an error response code must be passed!
    ASSERT_DEBUG(resp_code != ObexObject::RespOk);

    return m_server.HandleDeleteObjectRequest(resp_code);
}   // RejectDeleteObjectRequest

/*  ----------------------------------------------------------------------
    AcceptFilePushRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::AcceptFilePushRequest(DataSinkPtr data_sink_ptr,
    UINT32 max_size)
{
    return m_server.HandleFilePushRequest(ObexObject::RespOk, data_sink_ptr,
        max_size);
}   // AcceptFilePushRequest

/*  ----------------------------------------------------------------------
    RejectFilePushRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::RejectFilePushRequest(
    ObexObject::ResponseCode resp_code)
{
    // To reject a file push request an error response code must be passed!
    ASSERT_DEBUG(resp_code != ObexObject::RespOk);

    return m_server.HandleFilePushRequest(resp_code, DataSinkPtr(0));
}   // RejectFilePushRequest

/*  ----------------------------------------------------------------------
    AcceptFilePullRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::AcceptFilePullRequest(DataSourcePtr data_src_ptr)
{
    return m_server.HandleFilePullRequest(ObexObject::RespOk, data_src_ptr);
}   // AcceptFilePullRequest

/*  ----------------------------------------------------------------------
    RejectFilePullRequest
    ---------------------------------------------------------------------- */
ObexResult ObexFtpServer::RejectFilePullRequest(
    ObexObject::ResponseCode resp_code)
{
    // To reject a file pull request an error response code must be passed!
    ASSERT_DEBUG(resp_code != ObexObject::RespOk);

    return m_server.HandleFilePullRequest(resp_code, DataSourcePtr(0));
}   // RejectFilePullRequest

/*  ----------------------------------------------------------------------
    GetCurrentFolder
    ---------------------------------------------------------------------- */
const WString& ObexFtpServer::GetCurrentFolder() const
{
    return m_server.GetCurrentFolder();
}   // GetCurrentFolder

#endif  // Apoxi_ObexFtpServer_hpp

