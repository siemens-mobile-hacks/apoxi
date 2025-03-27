/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FlowLayout_hpp)
#define Apoxi_FlowLayout_hpp

#include <Gui/Control.hpp>
#include <Auxiliary/Vector.hpp>

class FlowLayout : public Control {
    typedef Control Base;

    public:
        enum {
            ID = 38
        };

        enum Alignment {
            Start = 0,
            Middle = 1,
            End = 2,
        };

        FlowLayout();

        FlowLayout(Control* parent, BOOLEAN horizontal = TRUE);
        
        virtual ~FlowLayout();

        void Init(Control* parent, BOOLEAN horizontal = TRUE);
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        void AddAlignInfo(Component& comp, Alignment align);

        BOOLEAN RemoveAlignInfo(const Component& comp);

        BOOLEAN GetAlignInfo(const Component& comp, Alignment& align) const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        virtual void OnLayoutClient();

        virtual void OnThemeChanged();

        virtual void OnFocusPreviousControl();
        
        virtual void OnFocusNextControl();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

    private:
        struct AlignInfo {
            Component* comp;
            Alignment align;
        };

        BOOLEAN m_horizontal;
        Vector<AlignInfo> m_align_info;

        BOOLEAN IsComponentEmbedded(const Component& comp) const;
        void UpdateNavigationGuidance();
        BOOLEAN TreatKeyCode(KeyCode key_code);
};

#endif  //Apoxi_FlowLayout_hpp

