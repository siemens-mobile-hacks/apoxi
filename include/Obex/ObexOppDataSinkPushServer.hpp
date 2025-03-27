/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexOppDataSinkPushServer_hpp)
#define Apoxi_ObexOppDataSinkPushServer_hpp

#include <Auxiliary/MimeTypeTable.hpp>

#include <Obex/ObexOppServer.hpp>

// Forward declarations of classes
class ExecutionContext;
class DataSink;

class ObexOppDataSinkPushServer : private ObexOppServer {

    private:
        typedef ObexOppServer   Base;

    public:
        ObexOppDataSinkPushServer();

        ObexOppDataSinkPushServer(MimeType              mime_type,
                                  ExecutionContext *    ctx_ptr);

        virtual ~ObexOppDataSinkPushServer();

            virtual void    Init(ExecutionContext *     ctx_ptr,
                                 MimeType               mime_type);

        inline  ObexResult  BindToMimeType(MimeType     mime_type);

        inline  ObexResult  UnbindMimeType(MimeType     mime_type);

        inline  ObexResult  Open();

        inline  ObexResult  Close();

        inline  ObexResult  Accept(DataSink *   obj_sink_ptr,
                                   UINT32       max_obj_size = 0xFFFFFFFFul);

        inline  ObexResult  Cancel(ObexObject::ResponseCode     resp_code,
                                   const WString &              resp_desc = L"");

        inline  ObexResult  Confirm();

        inline  UINT32      GetProgressInBytes() const;

//  protected:
        virtual void    OnPushIncoming(const WString &  obj_name,
                                       MimeType         obj_type,
                                       const WString &  obj_desc,
                                       UINT32           obj_size) = 0;

        virtual void    OnDataComplete();

        virtual void    OnPushComplete(ObexResult       result,
                                       const WString &  description) = 0;

    private:
        class OppImpl : public ObexOppServer {

            public:
                OppImpl(ObexOppDataSinkPushServer &     frontend);

                ObexResult      Accept(DataSink *   obj_sink_ptr,
                                       UINT32       max_obj_size = 0xFFFFFFFFul);

                ObexResult      CloseOppServer();

//          protected:
                virtual void    OnPush(const WString &  obj_name,
                                       const String &   obj_type,
                                       const WString &  obj_desc,
                                       UINT32           obj_size);

                virtual void    OnDataAvailable(ObexBuffer &    app_data,
                                                BOOLEAN         end_data);

                virtual void    OnPushComplete(ObexResult       result,
                                               const WString &  description);

            private:
                ObexOppDataSinkPushServer &     m_frontend;
                DataSink *                      m_sink_ptr;
                UINT32                          m_sink_size;    // Max. object size
                BOOLEAN                         m_is_accepted;

                void                            CleanUp();
        };

        OppImpl                                 m_impl;
};

/*  ----------------------------------------------------------------------
    BindToMimeType
    ---------------------------------------------------------------------- */
ObexResult  ObexOppDataSinkPushServer::BindToMimeType(MimeType  mime_type)
{
    return  m_impl.BindToMimeType(mime_type);
}// BindToMimeType

/*  ----------------------------------------------------------------------
    UnbindMimeType
    ---------------------------------------------------------------------- */
ObexResult  ObexOppDataSinkPushServer::UnbindMimeType(MimeType  mime_type)
{
    return  m_impl.UnbindMimeType(mime_type);
}// UnbindMimeType

/*  ----------------------------------------------------------------------
    Open
    ---------------------------------------------------------------------- */
ObexResult  ObexOppDataSinkPushServer::Open()
{
    return  m_impl.Open();
}// Open

/*  ----------------------------------------------------------------------
    Close
    ---------------------------------------------------------------------- */
ObexResult  ObexOppDataSinkPushServer::Close()
{
    return  m_impl.CloseOppServer();
}// Close

/*  ----------------------------------------------------------------------
    Accept
    ---------------------------------------------------------------------- */
ObexResult  ObexOppDataSinkPushServer::Accept(DataSink *    obj_sink_ptr,
                                              UINT32        max_obj_size)
{
    return  m_impl.Accept(obj_sink_ptr, max_obj_size);
}// Accept

/*  ----------------------------------------------------------------------
    Cancel
    ---------------------------------------------------------------------- */
ObexResult  ObexOppDataSinkPushServer::Cancel(ObexObject::ResponseCode  resp_code,
                                              const WString &           resp_desc)
{
    return  m_impl.CancelOperation(resp_code, resp_desc);
}// Cancel

/*  ----------------------------------------------------------------------
    Confirm
    ---------------------------------------------------------------------- */
ObexResult  ObexOppDataSinkPushServer::Confirm()
{
    // Buffer still owned by ObexOppServer instance !
    return  m_impl.DataProcessed();
}// Confirm

/*  ----------------------------------------------------------------------
    GetProgressInBytes
    ---------------------------------------------------------------------- */
UINT32      ObexOppDataSinkPushServer::GetProgressInBytes()
const
{
    return  m_impl.GetProgressInBytes();
}// GetProgressInBytes

#endif  // Apoxi_ObexOppDataSinkPushServer_hpp

