#ifndef emcpp_apoxi_emcpp_OBEXAdapter_HPP_FIRST
#define emcpp_apoxi_emcpp_OBEXAdapter_HPP_FIRST

#ifndef EMCPP_OBEX_SERVER
#define EMCPP_OBEX_SERVER 1
#endif

#ifndef EMCPP_OBEX_CLIENT
#define EMCPP_OBEX_CLIENT 0
#endif

class ObexObject;

class emcpp_apoxi_OBEXAdapter;
class apoxi_emcpp_OBEXAdapterPrivate;

class apoxi_emcpp_OBEXAdapter {
  typedef apoxi_emcpp_OBEXAdapterPrivate Private;
public:
  apoxi_emcpp_OBEXAdapter(emcpp_apoxi_OBEXAdapter& back);

  ~apoxi_emcpp_OBEXAdapter();

#if EMCPP_OBEX_SERVER
  int handle_response(unsigned char response_code,
                      const ObexObject& response);
#endif

#if EMCPP_OBEX_CLIENT
  int handle_request(unsigned char request_code,
                     const ObexObject& request);
#endif
  Private& private_implementation()
  { return *_private; }

  const Private& private_implementation() const
  { return *_private; }

private:
  Private*           _private;
};


#endif

