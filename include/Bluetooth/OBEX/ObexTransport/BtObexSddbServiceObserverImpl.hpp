
#if !defined(Apoxi_BtSddbServiceObserverImpl_hpp)
#define Apoxi_BtSddbServiceObserverImpl_hpp

#include <Bluetooth/BtSddbServiceObserver.hpp>
#include <Obex/ObexObject.hpp>
#include <Obex/ObexBuffer.hpp>

class BtObexSddbServiceObserverImpl: public BtSddbServiceObserver
{
    private:
        typedef BtSddbServiceObserver Base;

    public:
        BtObexSddbServiceObserverImpl();

        virtual ~BtObexSddbServiceObserverImpl();


        inline void SetIndex( UINT8 id ) { m_id = id; };

    protected:


        virtual void OnRegisterService(BtResultCode code);


        virtual void OnUnregisterService(BtResultCode code);


        UINT8 m_id;

private:
        friend class BtSddbService;
};

#endif//BtSddbServiceObserverImpl





