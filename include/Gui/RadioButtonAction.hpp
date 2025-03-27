/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RadioButtonAction_hpp)
#define Apoxi_RadioButtonAction_hpp

#include <Gui/AbstractToggleAction.hpp>

class RadioButtonGroup;

class RadioButtonAction : public AbstractToggleAction {
    typedef AbstractToggleAction Base;

    public:
        enum {
            ID = 6
        };
        
        RadioButtonAction();

        explicit RadioButtonAction(Dispatcher* dispatcher,
                                   RadioButtonGroup* rb_group,
                                   const WCHAR* text,
                                   BOOLEAN selected = FALSE,
                                   BOOLEAN enabled = TRUE,
                                   INT value = 0);

        virtual ~RadioButtonAction();

        void Init(Dispatcher* dispatcher,
                  RadioButtonGroup* rb_group,
                  const WCHAR* text,
                  BOOLEAN selected = FALSE,
                  BOOLEAN enabled = TRUE,
                  INT value = 0);
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual void SetSelected(BOOLEAN select);

        virtual BOOLEAN Toggle(BOOLEAN old_state);
        
        void SetGroup(RadioButtonGroup* rb_group);

        RadioButtonGroup* GetGroup() { return m_group; }

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        explicit RadioButtonAction(const WCHAR* text,
                                   BOOLEAN enabled = TRUE,
                                   BOOLEAN selected = FALSE,
                                   RadioButtonGroup* rb_group = 0,
                                   INT value = 0);
        
        explicit RadioButtonAction(Dispatcher* dispatcher,
                                   const WCHAR* text,
                                   BOOLEAN enabled = TRUE,
                                   BOOLEAN selected = FALSE,
                                   RadioButtonGroup* rb_group = 0,
                                   INT value = 0);

        void Init(const WCHAR* text,
                  BOOLEAN enabled = TRUE,
                  BOOLEAN selected = FALSE,
                  RadioButtonGroup* rb_group = 0,
                  INT value = 0);

        void Init(Dispatcher* dispatcher, 
                  const WCHAR* text,
                  BOOLEAN enabled = TRUE,
                  BOOLEAN selected = FALSE,
                  RadioButtonGroup* rb_group = 0,
                  INT value = 0);

        virtual const BitmapRes* GetSelectedIcon() const;

        virtual const BitmapRes* GetDeselectedIcon() const;

    private:
        RadioButtonGroup* m_group;

        void UpdateIcon();
};

#endif // Apoxi_RadioButtonAction_hpp

