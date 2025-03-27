/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexOppBinDataPushClient_hpp)
#define Apoxi_ObexOppBinDataPushClient_hpp

#include <Auxiliary/MimeTypeTable.hpp>

#include <Obex/ObexOppClient.hpp>

// Forward declarations of classes
class ExecutionContext;
class BinData;

class ObexOppBinDataPushClient : private ObexOppClient {

    typedef ObexOppClient   Base;

    public:
        enum {
            DefFragSize = 4096  
        };
        ObexOppBinDataPushClient();

        ObexOppBinDataPushClient(ExecutionContext *     ctx_ptr);

        virtual ~ObexOppBinDataPushClient();

        using   Base::Init;
        using   Base::GetProgressInBytes;

        ObexResult      Abort(const WString &   desc,
                              BOOLEAN           force_sync = FALSE);

        ObexResult      Push(const String &     obex_url,
                             BinData *          obj_src_ptr,
                             MimeType           obj_type,
                             const WString &    obj_name,
                             const WString &    obj_desc = L"");

    protected:
        virtual void    OnPushComplete(ObexResult               result,
                                       ObexObject::ResponseCode resp_code,
                                       const WString &          push_desc);

    private:
        BinData *       m_data_src_ptr;
        UINT32          m_data_offset;

        virtual void    OnPushConfirmed();
        virtual void    OnDataProcessed(ObexBuffer &    app_data);

        void            SendData(ObexBuffer &   buffer);
        void            CleanUp();
};

#endif  // Apoxi_ObexOppBinDataPushClient_hpp

