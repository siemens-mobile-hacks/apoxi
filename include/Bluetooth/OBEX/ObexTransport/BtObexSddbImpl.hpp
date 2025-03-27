#if !defined(Apoxi_BtObexSddbImpl_hpp)
#define Apoxi_BtObexSddbImpl_hpp


#include <Bluetooth/BtSddbService.hpp>

class BtObexSddbImpl : public BtSddbService
{
    typedef BtSddbService Base;

    public:
        BtObexSddbImpl();

        virtual ~BtObexSddbImpl();

        BtRequestState UnregisterServiceRecordRequest();

    protected:
        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);
};


#endif

