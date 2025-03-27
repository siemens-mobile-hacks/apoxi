/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "swap\views\hartmanw_mpeu-host-bsy_sv\lnz_apoxi\Apoxi\AddOns\MmCall\SerialTerminalArg.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(AddOns_MmCall_SerialTerminalArg_hpp)
#define AddOns_MmCall_SerialTerminalArg_hpp
#include <Apc/StackMsgArgument.hpp>
#include <Apc/SignalTypes.hpp>
#include <SerialTerminal.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class SerialTerminalArg
    ====================================================================== */
class SerialTerminalArg : public StackMsgArgument {
    friend class SerialTerminalMsgArgsDestroyTableNode;
    public:
        SerialTerminalArg();
        
        static const SerialTerminalArg& Cast(const StackMsgArgument& arg);
        void SetEvent(const SerialTerminal::Event& event) { m_event = event; }
        const SerialTerminal::Event& GetEvent() const { return m_event; }
        void SetTerminal(SerialTerminal* terminal) { m_terminal = terminal; }
        SerialTerminal* GetTerminal() const { return m_terminal; }
        
        enum  {
            ID = 9100
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SerialTerminalArg*) arg); }
        
        SerialTerminal::Event m_event;
        SerialTerminal* m_terminal;
        
    };
// Inline definitions
inline const SerialTerminalArg& SerialTerminalArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SerialTerminalArg!\n");
    return ((SerialTerminalArg &) arg);
}
#endif // AddOns_MmCall_SerialTerminalArg_hpp

