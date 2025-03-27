#ifndef emcpp_apoxi_OBEXAdapter_HPP_FIRST
#define emcpp_apoxi_OBEXAdapter_HPP_FIRST

class StreamObexImpl;
class ObexChannel;

class emcpp_apoxi_OBEXAdapterPrivate;

class emcpp_apoxi_OBEXAdapter {
  typedef emcpp_apoxi_OBEXAdapterPrivate Private;
public:
  emcpp_apoxi_OBEXAdapter(StreamObexImpl& obex_implementation,
                          const ObexChannel& obex_channel);

  ~emcpp_apoxi_OBEXAdapter();

  Private& private_implementation()
  { return *_private; }

  const Private& private_implementation() const
  { return *_private; }

  StreamObexImpl& obex_implementation()
  { return _obex_implementation; }

  const ObexChannel& obex_channel() const
  { return _obex_channel; }

private:
  StreamObexImpl&    _obex_implementation;
  const ObexChannel& _obex_channel;
  Private*           _private;
};


#endif

