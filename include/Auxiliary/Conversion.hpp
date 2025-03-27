/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Common_Conversion_hpp)
#define Apc_Common_Conversion_hpp

/*  ========================================================================
    Conversion
    ======================================================================== */
class Conversion {
    public:
        // Converts APOXI_KEY_0 .. 9, STAR, HASH to the corresponding IA5 code.
        // Returns 0x00 if invoked with other KeyCode.
        static UINT8 KeyCode2IA5(const KeyCode key);
        
        // Converts IA5 code 0x30 - 9x39, 0x2a, 0x23 code to an corresponding 
        // APOXI KeyCode. Returns APOXI_KEY_NONE if invoked with other key value.
        static KeyCode IA52KeyCode(const UINT8 key);

}; // Conversion


#endif  // Apc_SignalTypes_hpp


