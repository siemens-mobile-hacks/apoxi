/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(DrmCore_hpp)
#define DrmCore_hpp


#include <limits.h>
#include <Auxiliary/MimeTypeTable.hpp>
#include <Config/DrmConfig.hpp>

#include <Auxiliary/String.hpp>

#define DRM_KEY_SIZE 16
typedef UINT8 DrmKey[DRM_KEY_SIZE];

typedef String DrmUid;

typedef INT16 DrmLocalId;

const DrmLocalId DefaultLocalId = APOXI_DRM_RIGHTS_OBJECT_MAX + 1 ;

const DrmLocalId c_drm_invalid_local_id = 0;

#define MAX_COUNT    INT_MAX    // Some defines for REL Parser and DrmAsset
#define MIN_DATE     0
#define MAX_DATE     UINT_MAX
#define MAX_INTERVAL UINT_MAX

#define DRM_RO_DEBUG

enum DrmStatus {
    DrmSuccess = 0,
    DrmDefaultConstraints,  // to indicate that constraint is not found in XML rights.
    DrmInvalidOperation = -101 ,
    DrmInvalidLocalId,
    DrmInvalidAsset,
    DrmCorruptMessage,
    DrmInvalidXmlFormat,
    DrmInvalidContainer,
    DrmAesDecryptionFail,
    DrmNoRightsAvailable,
    DrmInvalidParams,
    DrmUnknown
};

enum DrmMimeType {
    DrmNone = 0,
    DrmForwardLock = 1,
    DrmCombinedDelivery = 2,
    DrmDcf = 3,
    DrmRoXml = 4,
    DrmRoWbxml = 5,
    DrmForwardLockDcf = 6,
#ifdef APOXI_INCLUDE_DRM_V2
    DrmDcfv2 = 7,                   
    // DRM2.0 DCF
    DrmForwardLockDcfv2 = 8,            
    // DRM2.0 Forward Locked DCF
    DrmPdcf = 9,                        
    // DRM2.0 PDCF
    DrmRov2Xml = 10,                    
    // DRM2.0 Rights Object XML
    DrmForwardLockBinary = 11,          
    // DRM1.0 Forward Lock (Binary format)
    DrmCombinedDeliveryBinary = 12,     
    // DRM1.0 Combined Delivery (Binary format)
    DrmDcfBinary = 13,                  
    // DRM1.0 DCF (Binary format)
    DrmForwardLockDcfBinary = 14,       
    // DRM1.0 Forward Locked DCF (Binary format)
    DrmForwardLockDcfObject = 15,       
    // DRM1.0 intermediate data from FL DCF
    DrmDcfv2Binary = 16,                
    // DRM2.0 DCF (Binary format)
    DrmForwardLockDcfv2Binary = 17,     
    // DRM2.0 Forward Locked DCF (Binary format)
    DrmForwardLockDcfv2Object = 18,     
    // DRM2.0 intermediate data from FL DCFv2
    DrmPdcfBinary = 19,                 
    // DRM2.0 PDCF (Binary format)
    DrmOtherForwardLock = 20,           
    // other Forward-Lock content e.g. SMAF
 #endif
};

enum DrmConstraintDefValues {
    DrmAllDefault = 0,
    DrmDatetimeDefault,
    DrmStartDefault,
    DrmEndDefault,
    // to indicate atleast one or all constraints present in rights XML
    DrmNoDefault // must be last
};

enum DrmOperation {
    DrmOpPlay = 0,
    DrmOpDisplay = 1,
    DrmOpExecute = 2,
    DrmOpPrint = 3,
    DrmOpRewind = 4,

    DrmOpCount  // must be last
};

#ifdef APOXI_INCLUDE_DRM_V2

enum DrmDcfMessageType {
    DrmDcfIcon,
    DrmDcfPreview,
    DrmDcfContent,
};

enum DrmEncMethod   {
    DrmAES128CBC = 0,
    DrmAES128CTR = 1,
    DrmEncNull              // must be last
};

enum DrmPaddingScheme {
    DrmRfc2630 = 0,
    DrmNoPadding        // must be last
};
#endif


#endif // DrmCore_hpp

