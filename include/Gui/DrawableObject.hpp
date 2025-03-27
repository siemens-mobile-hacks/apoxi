/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DrawableObject_hpp)
#define Apoxi_DrawableObject_hpp

#include <Gui/Component.hpp>
#include <Gui/View.hpp>

class Control;

class DrawableObject : public Component {
    typedef Component Base;

    public:
        enum {
            ID = 10
        };

        enum ParentArea {
            ClientArea,
            FrameArea
        };

        DrawableObject();

        DrawableObject(Control* parent,
                       BOOLEAN add_to_parent = TRUE,
                       const View* view = 0);
    
        virtual ~DrawableObject() ;

        void Init(Control* parent,
                  BOOLEAN add_to_parent = TRUE,
                  const View* view = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void SetParent(Control* parent);
    
        void Draw(DeviceContext* dc, const Rect& repaint_rect) const;

        void Invalidate(BOOLEAN erase = TRUE);

        void SetParentArea(ParentArea parent_area) { m_parent_area = parent_area; }

        ParentArea GetParentArea() const { return m_parent_area; }

        void SetNext(DrawableObject* next) { m_next = next; }

        DrawableObject* GetNext() const { return m_next; }

        virtual void AdjustThemeDependencies();

        virtual void AdjustStrings();

        void SetVisible(BOOLEAN visible);

        BOOLEAN IsVisible() const;

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);
        
        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual void OnMove(XYDIM dx, XYDIM dy);

        virtual void OnResize(XYDIM dx, XYDIM dy);

    private:
        ParentArea m_parent_area;
        DrawableObject* m_next;
        
        friend class Control;   // a control must be able to invoke the methods Refresh and Cleanup from a drawable obj.
};

class DrawableObjectView : public View {
    typedef View Base;

    public:
        DrawableObjectView(XYDIM default_width = -1, XYDIM default_height = -1);

        virtual ~DrawableObjectView();
};

#endif  // Apoxi_DrawableObject_hpp

