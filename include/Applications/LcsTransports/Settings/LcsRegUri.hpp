/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsRegUri_hpp)
#define Mmi_LcsRegUri_hpp


// Interior nodes for protocols
static const CHAR* c_lcs_root           = "./Lcs";
static const CHAR* c_gltp_root          = "./Gltp";
static const CHAR* c_3gpp_root          = "./Gpp";

// Chile nodes for LCS specific parameters
static const CHAR* c_active_protocol    = "./Lcs/ActiveProtocol";       // Stored in INT format

// Chile nodes for GLTP parameters
static const CHAR* c_gl_server_ip       = "./Gltp/GLServerAddress";     // Stored in String format
static const CHAR* c_wai_server_add     = "./Gltp/WAIServerAddress";    // Stored in String format
static const CHAR* c_ff_server_add      = "./Gltp/FFServerAddress";     // Stored in String format
static const CHAR* c_gltp_mode          = "./Gltp/GltpMode";            // Stored in INT format
static const CHAR* c_gltp_rep_interval  = "./Gltp/GltpRepeatInterval";  // Stored in INT format

// Chile nodes for 3GPP parameters
static const CHAR* c_horiz_acc          = "./Gpp/HorizontalAccuracy";   // Stored in INT format
static const CHAR* c_vert_acc           = "./Gpp/VerticalAccuracy";     // Stored in INT format
static const CHAR* c_resp_time_category = "./Gpp/RespTimeCategory";     // Stored in INT format
static const CHAR* c_lcs_cost_criteria  = "./Gpp/CostCriteria";         // Stored in INT format
static const CHAR* c_lcs_rep_interval   = "./Gpp/LcsRepeatInterval";    // Stored in INT format
static const CHAR* c_client_id          = "./Gpp/ClientId";             // Stored in String format
static const CHAR* c_mlc_number         = "./Gpp/MlcNumber";            // Stored in String format

#endif // Mmi_LcsRegUri_hpp
