/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\bt_avrcp_multiconnection\lnz_apoxi\Apoxi\Bluetooth\AVRCP\BtAvrcpOperationServiceMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Bluetooth_AVRCP_BtAvrcpOperationServiceMessageArgument_hpp)
#define Bluetooth_AVRCP_BtAvrcpOperationServiceMessageArgument_hpp
#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpPanelPassThroughParams.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRawFrameParams.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class BtAvrcpNmaPanelPassThrough
    ====================================================================== */
class BtAvrcpNmaPanelPassThrough : public StackMsgArgument {
    friend class BtAvrcpMessageArgumentsDestroyTableNode;
    public:
        BtAvrcpNmaPanelPassThrough(const BtAvrcpPanelPassThroughParams& panel_passthrough_params);
        BtAvrcpNmaPanelPassThrough();
        ~BtAvrcpNmaPanelPassThrough();
        
        static const BtAvrcpNmaPanelPassThrough& Cast(const StackMsgArgument& arg);
        const BtAvrcpPanelPassThroughParams& GetPanelPassthroughParams() const { return m_panel_passthrough_params; }
        
        enum  {
            ID = 12
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtAvrcpNmaPanelPassThrough*) arg); }
        
        BtAvrcpPanelPassThroughParams m_panel_passthrough_params;
        
    };
// Inline definitions
inline const BtAvrcpNmaPanelPassThrough& BtAvrcpNmaPanelPassThrough::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtAvrcpNmaPanelPassThrough!\n");
    return ((BtAvrcpNmaPanelPassThrough &) arg);
}
/*  ======================================================================
    Class BtAvrcpNmaRawFrame
    ====================================================================== */
class BtAvrcpNmaRawFrame : public StackMsgArgument {
    friend class BtAvrcpMessageArgumentsDestroyTableNode;
    public:
        BtAvrcpNmaRawFrame(const BtAvrcpRawFrameParams& raw_frame_params);
        BtAvrcpNmaRawFrame();
        ~BtAvrcpNmaRawFrame();
        
        static const BtAvrcpNmaRawFrame& Cast(const StackMsgArgument& arg);
        const BtAvrcpRawFrameParams& GetRawFrameParams() const { return m_raw_frame_params; }
        
        enum  {
            ID = 13
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtAvrcpNmaRawFrame*) arg); }
        
        BtAvrcpRawFrameParams m_raw_frame_params;
        
    };
// Inline definitions
inline const BtAvrcpNmaRawFrame& BtAvrcpNmaRawFrame::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtAvrcpNmaRawFrame!\n");
    return ((BtAvrcpNmaRawFrame &) arg);
}
#endif // Bluetooth_AVRCP_BtAvrcpOperationServiceMessageArgument_hpp

