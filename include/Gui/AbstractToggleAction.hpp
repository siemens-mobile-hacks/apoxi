/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractToggleAction_hpp)
#define Apoxi_AbstractToggleAction_hpp

#include <Gui/Action.hpp>
#include <Gui/Bitmap.hpp>

class AbstractToggleAction : public Action {
    typedef Action Base;

    public:
        enum {
            ID = 4
        };
        
        enum AbstractToogleActionPropertyId {
            SelectedPropertyId = 3,
            ValuePropertyId = 4
        };
        
        AbstractToggleAction();

        AbstractToggleAction(Dispatcher* dispatcher,
                             const WCHAR* text,
                             BOOLEAN enabled = TRUE,
                             BOOLEAN selected = FALSE,
                             INT value = 0);    //lint !e1931

        virtual ~AbstractToggleAction();

        void Init(Dispatcher* dispatcher,
                  const WCHAR* text,
                  BOOLEAN enabled = TRUE,
                  BOOLEAN selected = FALSE,
                  INT value = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual BOOLEAN Execute();

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual BOOLEAN IsEqual(const Item& item) const;
        
        virtual void SetSelected(BOOLEAN selected);

        virtual BOOLEAN IsSelected() const;

        virtual BOOLEAN Toggle(BOOLEAN old_state) = 0;

        void SetValue(INT value);

        INT GetValue() const { return m_value; }

        AbstractToggleAction(const WCHAR* text,
                             BOOLEAN enabled = TRUE,
                             BOOLEAN selected = FALSE,
                             INT value = 0);    //lint !e1931

        void Init(const WCHAR* text,
                  BOOLEAN enabled = TRUE,
                  BOOLEAN selected = FALSE,
                  INT value = 0);
        
        virtual const BitmapRes* GetSelectedIcon() const;

        virtual const BitmapRes* GetDeselectedIcon() const;

    private:
        BOOLEAN m_selected;
        INT m_value;
};

#endif // Apoxi_AbstractToggleAction_hpp


