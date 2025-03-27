/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(RfsObexFtpServer_hpp)
#define RfsObexFtpServer_hpp

#include <Afs/Rfs/Path.hpp>
#include <Obex/ObexFtpServer.hpp>

class RfsObexFtpServer : public ObexFtpServer {

    typedef ObexFtpServer Base;

    public:
        RfsObexFtpServer();

        RfsObexFtpServer(ExecutionContext* ctx_ptr, const Path& root_path);

        virtual ~RfsObexFtpServer();

        virtual void Init(ExecutionContext* ctx_ptr, const Path& root_path);

        // Implementation of abstract base class methods.
        // See base class for details.

        virtual void OnBind(const ObexAddrPtr& addr_ptr, ObexResult result);
        virtual void OnConnect(const ObexHeaderList& headers, UINT8 flags);
        virtual void OnDisconnected(ObexResult result);
        virtual void OnGetFolderListing(const WString& current_folder);
        virtual void OnProvideFolderListingEntries(
            const WString& current_folder);
        virtual void OnSetCurrentFolder(const WString& current_folder,
            const WString& new_current_folder, BOOLEAN create);
        virtual void OnDeleteObject(const WString& current_folder,
            const WString& object);
        virtual void OnFilePush(const WString& current_folder,
            const WString& filename, UINT32 size);
        virtual void OnFilePushRequestCompleted(ObexResult result);
        virtual void OnFilePull(const WString& current_folder,
            const WString& filename);
        virtual void OnFilePullRequestCompleted(ObexResult result);

    protected:
        Path GetAbsolutePath(const WString& path, const WString& object = L"");

        // Root path of the server.
        Path m_root_path;

        // Directory iterator shared pointer, necessary for retrieving folder
        // listings.
        DirectoryIteratorPtr m_dir_itor_ptr;
};

#endif  // RfsObexFtpServer_hpp

