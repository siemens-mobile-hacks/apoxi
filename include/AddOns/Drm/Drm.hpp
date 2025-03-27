/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_Drm_hpp)
#define Apoxi_Drm_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/Vector.hpp>
#include <Auxiliary/DateTime.hpp>
#include <Auxiliary/BinData.hpp>
#include <Auxiliary/String.hpp>

#include <Auxiliary/DrmCore.hpp>
#include <AddOns/Drm/DrmRights.hpp>
#include <AddOns/Drm/DrmRightsStore.hpp>

struct DrmMediaObject {
    
        UINT8 *m_content;

        String m_content_type ;

        INT m_content_len;
};

struct BlockData {
    INT m_start_block_num ;         // Starting block number of data to parse.
    INT m_end_block_num ;           // End block number of data to parse.
    INT m_block_size ;              // Block size to use for each block to be parsed.
} ;


#endif

