/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBppClientService_hpp)
#define BtBppClientService_hpp

#include <Auxiliary/DataSink.hpp>
#include <Auxiliary/DataSource.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BPP/BtBppSndFilePushReqRequest.hpp>
#include <Bluetooth/BPP/BtBppSndAbortReqRequest.hpp>
#include <Bluetooth/BPP/BtBppTypes.hpp>


class BtBppClientService: public BtBppService
{
    private:
        typedef BtBppService Base;

    public:
        BtBppClientService();

        virtual ~BtBppClientService();


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        virtual BOOLEAN IsServerService() const;



        BOOLEAN IsConnected() const;


        BtRequestState BppSndFilePush( //const BtDeviceAddress& device, 
            BppObjectTypeEnum bpp_object_type_enum,  const DataSourcePtr& pagetoprint );

        //Not necessary 2 different functions:
//      BtRequestState BppSndFilePushFromRam( const BtDeviceAddress& device, 
//          BppObjectTypeEnum bpp_object_type_enum,  const DataSourcePtr& pagetoprint );
        
//      BtRequestState BppSndFilePushFromFlash ( const BtDeviceAddress& device, 
//          BppObjectTypeEnum bpp_object_type_enum,  const Pathname& pathname);

        
        



        BtRequestState BppSndAbortReq();

        



        BtResultCode GetResult();
        BtBppSndFilePushReqRequest::BppSubstate GetSubState() { return  m_file_push_req.GetBppSubState();}
        UINT8 GetProgressInPercent() {return (UINT8)((100 * (m_bytes_read_so_far+1)) / (m_data_source_size+1)); }
        UINT32  GetProgressInBytes() {return m_bytes_read_so_far; }
        UINT32  GetProgressTotalBytes() {return m_data_source_size;}

        
        //      virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);

    private:

        void BppSndConnectIndCb(BtResultCode result);
        void BppSndFilePushCfmCb(BtResultCode result);
        void BppSndDisconnectIndCb(BtResultCode result);
        void BppSndAbortCfmCb(BtResultCode result);
//      void BppSndAuthenticationRequestIndCb(BtAuthenticationReq auth_req);

        BtBppSndFilePushReqRequest      m_file_push_req;
        BOOLEAN                         m_is_final_buffer;
        DataSourcePtr                   m_pagetoprint;
        UINT32                          m_data_source_size;
        UINT32                          m_bytes_read_so_far;
        BtBppSndAbortReqRequest         m_abort_req;

#ifdef _DEBUG
        static SystemTimer m_clienttimer;
        static void OnClientTimer(void* arg);
        static INT delay_ms_to_abort ;
        static BOOLEAN start_abort_from_connect_indication ;
#endif

        friend class BtBppSndFilePushReqRequest;
        friend class BtBppSndAbortReqRequest;
};

#if defined(APOXI_RTOS_WIN32)



#endif //#if defined(APOXI_RTOS_WIN32)

#endif  // BtBppClientService_hpp


