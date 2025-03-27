/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBppTypes_hpp)
#define BtBppTypes_hpp

        //corresponds to \3p_bt_mec\inc\bpp_snd.h Predefined Mime Media-Type strings.
typedef enum   {
                e_bpp_snd_media_xhtml_print,
                e_bpp_snd_media_basic_text,
                e_bpp_snd_media_vcard,
                e_bpp_snd_media_vcalendar,
                e_bpp_snd_media_icalendar,
                e_bpp_snd_media_vmessage,
                e_bpp_snd_media_post_script,
                e_bpp_snd_media_pcl,
                e_bpp_snd_media_pdf,
                e_bpp_snd_media_jpeg,
                e_bpp_snd_media_gif,
} BppObjectTypeEnum;

//corresponds to \3p_bt_mec\inc\bpp_snd.h Predefined Mime Media-Type strings.
static char * bpp_object_type_tab[] ={
        "application/vnd.pwg-xhtml-print+xml\0",
        "text/plain\0",
        "text/x-vcard\0",
        "text/x-vcalendar\0",
        "text/calendar\0",
        "text/x-vmessage\0",
        "application/PostScript\0",
        "application/vnd.hp-PCL\0",
        "application/PDF\0",
        "image/jpeg\0",
        "image/gif\0"
};

static WCHAR * bpp_object_name_tab[] ={
        L"comneon.xml\0\0",
        L"comneon.txt\0\0",
        L"comneon.vcf\0\0",
        L"comneon.vcl\0\0",
        L"comneon.icl\0\0",
        L"comneon.msg\0\0",
        L"comneon.ps\0\0",
        L"comneon.pcl\0\0",
        L"comneon.pdf\0\0",
        L"comneon.jpg\0\0",
        L"comneon.gif\0\0",
};

static WCHAR * bpp_object_description_tab[] ={ // formatiing commands possible here, according to Mecel BPP reference Manual
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
        L"\0\0",
};


enum BppBuffSize {e_bpp_buff_size = 2048};



// Result of BPP operation
enum BtBppResult {
        BppOk,
        BppContinue,
        BppObexFailed,
        BppSdapFailed,
        BppPadaptFailed,
        BppObexHeaderFailed,
        BppCallError,
        BppUnauthenticated,

};


/*
typedef enum
{
        BTAPI_BPP_RESULT_OK,
        BTAPI_BPP_RESULT_OBEX_FAILED,
        BTAPI_BPP_RESULT_SAP_FAILED,
        BTAPI_BPP_RESULT_PADAPT_FAILED
} btapi_bpp_snd_result_t; */


enum BtBppObexResult {
        BppObexOk,
        BppObexContinue,
        BppObexPartialContent,
        BppObexBadRequest,
        BppObexNotImplemented,
        BppObexForbidden,
        BppObexUnauthorised,
        BppObexPreconditionFailed,
        BppObexNotFound,
        BppObexNotAcceptable,
        BppObexServiceUnavailable,
        BppObexUndefined
};

#if defined(_DEBUG)
static const char * BtResultCode_tab[] ={
        "BtRcOk\0",
        "",
        "BtRcAccepted\0",
        "BtRcPending\0",
        "",
        "",
        "",
        "",
        "",
        "",
        "",//10

        "","","","","","","","","","",//11-20
        "","","","","","","","","","",//21-30
        "","","","","","","","","","",//31-40
        "","","","","","","","","","",//41-50
        "","","","","","","","","","",//51-60
        "","","","","","","","","","",//61-70
        "","","","","","","","","","",//71-80
        "","","","","","","","","","",//81-90
        "","","","","","","","","","",//91-100

        "","","","","","","","","","",//101-110
        "","","","","","","","","","",//111-120
        "","","","","","","","BtRcUnknown","","",//121-130
        "","","","","","","","","","",//131-140
        "","","","","","","","","","",//141-150
        "","","","","","","","","","",//151-160
        "","","","","","","","","","",//161-170
        "","","","","","","","","","",//171-180
        "","","","","","","","","","",//181-190
        "","","","","","","","","","",//191-200

        "","","","","","","","","","",//201-210
        "","","","","","","","","","",//211-220
        "","","","","","","","","","",//221-230
        "","","","","","","","","","",//231-240
        "","","","","","","","","","",//241-250
        "","","BtRcError","BtRcIgnored","BtRcRejected"                  //251-255
};


static const char * bt_request_state_tab[] ={ // from enum BtRequestState: \lnz_apoxi\Apoxi\Bluetooth\BtTypes.hpp
        "BtRqsUnknown\0",
        "BtRqsInitialized\0",
        "BtRqsAccepted\0",
        "BtRqsRejected\0",
        "BtRqsAcceptedCancelation\0",
        "BtRqsExecuting\0",
        "BtRqsIgnored\0",
        "BtRqsExecutingCancelation\0",
        "BtRqsFinishedOk\0",
        "BtRqsFinishedFailure\0",

};

static const char * bt_bpp_substate_tab[] ={ // from enum BppSubstate
        "bpp_state1_initial\0",
        "bpp_state2_pushsent\0",
        "bpp_state3_connect_ind_received_ok\0",
        "bpp_state3_connect_ind_received_failed\0",
        "bpp_state4_push_cfm_received_ok_send_more\0",
        "bpp_state4_push_cfm_received_ok_final\0",
        "bpp_state4_push_cfm_received_failed\0",
        "bpp_state5_abort_cfm_received\0",
        "bpp_state6_disconnect_ind_received\0",

};

#endif // _DEBUG


#endif // BtBppTypes_hpp

