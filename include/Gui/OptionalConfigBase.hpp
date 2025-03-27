/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (Apoxi_OptionalConfigBase_hpp)
#define Apoxi_OptionalConfigBase_hpp


class OptionalConfigBase {
    public:
        enum GroupIds {
            Display     = 0,
            Editor      = 1,
            Keyboard    = 2,
            Locale      = 3,
            Theme       = 4,
            GuiEngine   = 5,
            Custom      = 1000
        };

        enum SettingIds {
            // -----------------------------------------------------------------------------------
            // IDs for the group Display
            // -----------------------------------------------------------------------------------
            DimmedBacklightBrightness = 0,

            // -----------------------------------------------------------------------------------
            // IDs for the group GuiEngine
            // -----------------------------------------------------------------------------------

            ScrollbarAlignment       = 0,

            ScrollbarDisplayPolicy   = 1,

            MaxDecoderDelay          = 2,
            
            ScrollGap                = 3,

            HideClippedText          = 4,

            SmoothScrollSteps        = 5,

            MaxEncoderDelay          = 6,

            HorizontalScrollBehavior = 7,
            
            TabButtonDefaultHeight   = 8,

            TabButtonDefaultWidth    = 9,

            TabButtonMinimumWidth    = 10,

            TabButtonMaximumWidth    = 11,

            TabButtonClippedWidth    = 12,

            ShowParentPosition       = 13,

            PositionSeparator         = 14,

            SelectionStyle            = 15
        };
};

#endif  // Apoxi_OptionalConfigBase_hpp


