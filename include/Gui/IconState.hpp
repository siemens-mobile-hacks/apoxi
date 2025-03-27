/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IconState_hpp)
#define Apoxi_IconState_hpp


class IconState {
    public:
        enum Size {
            DefaultSize = 1,
            SmallSize = 2,
            LargeSize = 4
        };

        enum Mode {
            NormalMode = 8,
            DisabledMode = 16,
            ActiveMode = 32
        };

        IconState(Size size = DefaultSize, Mode mode = NormalMode);

        void SetSize(Size size);

        Size GetSize() const;

        void SetMode(Mode mode);

        Mode GetMode() const; 

        BOOLEAN operator==(const IconState& state) const { return m_state == state.m_state; }

        BOOLEAN operator!=(const IconState& state) const { return m_state != state.m_state; }

    private:
        UINT8 m_state;
};

#endif // Apoxi_IconState_hpp


