/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(_APOXI_WCAttr_h)
#define _APOXI_WCAttr_h

#include <Kernel/Types.hpp>

 

// Unicode General Category
typedef enum {
    WCTypeLu, // Letter, Uppercase
    WCTypeLl, // Letter, Lowercase
    WCTypeLt, // Letter, Titlecase
    WCTypeLm, // Letter, Modifier
    WCTypeLo, // Letter, Other
    WCTypeMn, // Mark, Non-Spacing
    WCTypeMc, // Mark, Spacing Combining
    WCTypeMe, // Mark, Enclosing
    WCTypeNd, // Number, Decimal Digit
    WCTypeNl, // Number, Letter
    WCTypeNo, // Number, Other
    WCTypePc, // Punctuation, Connector
    WCTypePd, // Punctuation, Dash
    WCTypePs, // Punctuation, Open
    WCTypePe, // Punctuation, Close
    WCTypePi, // Punctuation, Initial quote 
    WCTypePf, // Punctuation, Final quote
    WCTypePo, // Punctuation, Other
    WCTypeSm, // Symbol, Math
    WCTypeSc, // Symbol, Currency
    WCTypeSk, // Symbol, Modifier
    WCTypeSo, // Symbol, Other
    WCTypeZs, // Separator, Space
    WCTypeZl, // Separator, Line
    WCTypeZp, // Separator, Paragraph
    WCTypeCc, // Other, Control
    WCTypeCf, // Other, Format
    WCTypeCs, // Other, Surrogate
    WCTypeCo, // Other, Private Use
    WCTypeCn  // Other, Not Assigned
} WCType;

// Unicode Bidirectional Category
typedef enum {
    WCBTypeL,   // Left-to-Right
    WCBTypeLRE, // Left-to-Right Embedding
    WCBTypeLRO, // Left-to-Right Override
    WCBTypeR,   // Right-to-Left
    WCBTypeAL,  // Right-to-Left Arabic
    WCBTypeRLE, // Right-to-Left Embedding
    WCBTypeRLO, // Right-to-Left Override
    WCBTypePDF, // Pop Directional Format
    WCBTypeEN,  // European Number
    WCBTypeES,  // European Number Separator
    WCBTypeET,  // European Number Terminator
    WCBTypeAN,  // Arabic Number
    WCBTypeCS,  // Common Number Separator
    WCBTypeNSM, // Non-Spacing Mark
    WCBTypeBN,  // Boundary Neutral
    WCBTypeB,   // Paragraph Separator
    WCBTypeS,   // Segment Separator
    WCBTypeWS,  // Whitespace
    WCBTypeON   // Other Neutrals
} WCBType;

WCType  WType(WCHAR wc);
BOOLEAN WIsComposed(WCHAR wc);
WCHAR   WDecompose(WCHAR wc);
BOOLEAN WIsUnicode(void);

 
#endif // _APOXI_WCAttr_h

