/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CheckBoxAction_hpp)
#define Apoxi_CheckBoxAction_hpp

#include <Gui/AbstractToggleAction.hpp>

class CheckBoxAction : public AbstractToggleAction {
    typedef AbstractToggleAction Base;

    public:
        enum {
            ID = 5
        };
        
        CheckBoxAction();

        CheckBoxAction(Dispatcher* dispatcher,
                       const WCHAR* text,
                       BOOLEAN enabled = TRUE,
                       BOOLEAN selected = FALSE);   //lint !e1931

        virtual ~CheckBoxAction();

        void Init(Dispatcher* dispatcher, const WCHAR* text, BOOLEAN enabled = TRUE, BOOLEAN selected = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual void SetSelected(BOOLEAN select);

        virtual BOOLEAN Toggle(BOOLEAN old_state);
        
        virtual BOOLEAN IsInstanceOf(INT id) const;

        CheckBoxAction(const WCHAR* text,
                       BOOLEAN enabled = TRUE,
                       BOOLEAN selected = FALSE);   //lint !e1931

        void Init(const WCHAR* text, BOOLEAN enabled = TRUE, BOOLEAN selected = FALSE);

        virtual const BitmapRes* GetSelectedIcon() const;

        virtual const BitmapRes* GetDeselectedIcon() const;

    private:
        void UpdateIcon();
};

#endif // Apoxi_CheckBoxAction_hpp

