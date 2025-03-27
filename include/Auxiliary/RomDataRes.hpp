#if !defined(RomDataRes_hpp)
#define RomDataRes_hpp

#include <Auxiliary/MimeTypeTable.hpp>

struct RomDataRes {
    MimeType mimetype;
    UINT32 size;
    const UINT8 HUGE* data;
};

#endif //RomDataRes_hpp

