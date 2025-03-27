
#if !defined(Apoxi_BtObexServerServiceImpl_hpp)
#define Apoxi_BtObexServerServiceImpl_hpp

#include <Bluetooth/OBEX/BtObexServerService.hpp>


class BtObexServerServiceImpl : public BtObexServerService
{
    private:
        typedef BtObexServerService Base;

    public:
        BtObexServerServiceImpl();
        virtual ~BtObexServerServiceImpl();

    protected:
        virtual void OnRequestStateChange( BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);
};

#endif

