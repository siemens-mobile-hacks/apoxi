/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_T9InputConfig_hpp)
#define Apoxi_T9InputConfig_hpp

#include <Kernel/Types.hpp>
#include <AddOns/T9/T9Wrapper.hpp>
#include <AddOns/GuiInputExtensions/AbstractPredictiveInputBox.hpp>

class Font;

class T9InputConfig {
    public:
        enum T9FunctionCode {
            MenuFunction,
            NextFunction,
            PreviousFunction,
            ShiftFunction,
            SpaceFunction,
            SymbolEntryRequestFunction, // used with longpress to open a window where symbols can be picked
            ToggleNumericModeFunction // used with longpress to switch to numeric mode
        };

        static const Font& GetFont(AbstractPredictiveInputBox::PredFontId pred_font_id);

        static const BitmapRes* GetBitmap(AbstractPredictiveInputBox::PredBitmapId pred_bitmap_id);

        static KeyCode GetKeyForFunction(T9FunctionCode function_code);

        static WCHAR GetObjectReplacementCharacter () { return 0x0FFFC; }

        static WCHAR GetStroke(INT stroke);

        static WCHAR GetSymbol(UINT8 row, UINT8 page);
        
        static UINT8 GetSymbolRows();

        static UINT8 GetSymbolPages();

        static CHAR* LoadT9Udb(UINT16& data_size);

        static void SaveT9Udb();
        
        static INT GetT9BufferSize();

        static INT GetT9UdbSize();

#if defined(APOXI_COMPAT_2_7_0)

        static KeyCode GetT9NextKey();
#endif
        static const UINT8 c_t9_symbol_rows;
        static const UINT8 c_t9_symbol_pages;
};

#endif  // Apoxi_T9InputConfig_hpp

