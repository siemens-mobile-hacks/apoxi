#if !defined(Apoxi_BtObexClientServiceImpl_hpp)
#define Apoxi_BtObexClientServiceImpl_hpp


#include <Bluetooth/OBEX/BtObexClientService.hpp>

class BtObexClientServiceImpl : public BtObexClientService
{
    private:
        typedef BtObexClientService Base;

    public:
        BtObexClientServiceImpl();
        virtual ~BtObexClientServiceImpl();

    protected:
        virtual void OnRequestStateChange( BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state);
};

#endif

