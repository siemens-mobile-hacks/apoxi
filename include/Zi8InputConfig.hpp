/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Zi8InputConfig_hpp)
#define Apoxi_Zi8InputConfig_hpp

/*  Do not change this header file. Each class in the configuration-lib must
    stay binary-compatible with Apoxi.  */

#include <Kernel/Types.hpp>
#include <AddOns/GuiInputExtensions/AbstractPredictiveInputBox.hpp>

class Font;

class Zi8InputConfig {
    public:
        static const Font& GetFont(AbstractPredictiveInputBox::PredFontId pred_font_id);
        static const BitmapRes* GetBitmap(AbstractPredictiveInputBox::PredBitmapId pred_bitmap_id);
        static const WCHAR GetStroke(const INT stroke);
        static const WCHAR* GetSymbolCandidates();
        static const UINT8 GetSymbolCandidatesLength();
        static CHAR* LoadZi8Udb(UINT16& data_size);
        static void SaveZi8Udb();
};

#endif  // Apoxi_Zi8InputConfig_hpp

