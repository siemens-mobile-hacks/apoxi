/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RfsConfig_hpp)
#define Apoxi_RfsConfig_hpp


#if !defined(APOXI_MAX_NET_FILENAME_LENGTH)
    #define APOXI_MAX_NET_FILENAME_LENGTH 255
#endif

#if !defined(APOXI_MAX_NET_STORAGE_DEVICE_ID_LENGTH)
    #define APOXI_MAX_NET_STORAGE_DEVICE_ID_LENGTH 3
#endif

/* The pathname must be big enough to hold the longest filename. If the virtual
   root storage device is part of the system then the pathname must be big
   enough to also hold the starting storage device Id string with its
   surrounding separators, otherwise it must only also hold the leading
   separator. */
#if defined(APOXI_LIB_ADDON_AFSRFS)

    #define APOXI_MAX_PATHNAME_LENGTH (                                       \
        1 /* The starting separator. */ +                                     \
        APOXI_MAX_NET_STORAGE_DEVICE_ID_LENGTH /* The storage device Id. */ + \
        1 /* The following separator. */ +                                    \
        APOXI_MAX_NET_FILENAME_LENGTH + /* The filename itself. */            \
        1 /* The terminating \c 0 character. */                               \
        )
#else

    #define APOXI_MAX_PATHNAME_LENGTH (                             \
        1 /* The starting separator. */ +                           \
        APOXI_MAX_NET_FILENAME_LENGTH + /* The filename itself. */  \
        1 /* The terminating \c 0 character. */                     \
        )
#endif  // APOXI_LIB_ADDON_AFSRFS

#endif  // Apoxi_RfsConfig_hpp

