/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Component_hpp)
#define Apoxi_Component_hpp

#include <Kernel/Dispatcher.hpp>
#include <Gui/Point.hpp>
#include <Gui/Rect.hpp>
#include <Gui/Size.hpp>
#include <Config/GuiObjectFactory.hpp>

class Model;
class View;
class Control;
class ResourceParser;

class Component : public Dispatcher {
    typedef Dispatcher Base;

    public:
        enum {
            ID = 7
        };

        Component();        

        Component(const View* view, Control* parent = 0);
        
        virtual ~Component();

        void Init(const View* view, Control* parent = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);
        
        virtual void SetParent(Control* parent) = 0;

        Control* GetParent() const { return m_parent; }
        
        /* Internal comment: the following IDs are currently used inside APOXI
            -  0: AbstractButton
            -  1: AbstractGrid
            -  2: AbstractItemGrid
            -  3: AbstractTextObject
            -  4: Alert
            -  5: AnimatedTextLine
            -  6: CheckBoxControl
            -  7: Component
            -  8: ContextMenu
            -  9: Control
            - 10: DrawableObject
            - 11: ImageBox
            - 12: ItemGrid
            - 13: ItemMenu
            - 14: ItemTree
            - 15: GridLayout
            - 16: MessageBox
            - 17: Panel
            - 18: PositionIndicator
            - 19: ProgressBar
            - 20: PushButton
            - 21: RadioButtonControl
            - 22: TabButton
            - 23: TabControl
            - 24: TextBox
            - 25: TextLine
            - 26: Window
            - 27: AbstractEditor
            - 28: AbstractLineEditor
            - 29: AbstractMultiLineEditor
            - 30: DateEditor
            - 31: IpAddrEditor
            - 32: LineEditor
            - 33: MultiLineEditor
            - 34: PasswordEditor
            - 35: TimeEditor
            - 36: MultiMediaEditor
            - 37: ItemBox
            - 38: FlowLayout
            - 39: AtlWindow
            - 40: AtlItemMenuWindow
            - 41: AtlItemListWindow
            - 42: AtlItemGridWindow
        */
        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetXPos(XYDIM x_pos);

        void SetYPos(XYDIM y_pos);

        XYDIM GetXPos() const { return m_bounds.GetLeft(); }

        XYDIM GetYPos() const { return m_bounds.GetTop(); }

        void SetWidth(XYDIM width);

        XYDIM GetWidth() const { return m_bounds.GetWidth(); }

        void SetHeight(XYDIM height);

        XYDIM GetHeight() const { return m_bounds.GetHeight(); }

        void SetPos(const Point& pos);

        void SetPos(XYDIM x, XYDIM y);

        Point GetPos() const { return m_bounds.GetPos(); }

        void SetSize(const Size& size);

        void SetSize(XYDIM width, XYDIM height);

        Size GetSize() const { return m_bounds.GetSize(); }

        void SetBoundingRect(const Rect& bounds);

        void SetBoundingRect(XYDIM left, XYDIM top, XYDIM right, XYDIM bottom);

        const Rect& GetBoundingRect() const { return m_bounds; }

        virtual XYDIM GetDefaultWidth() const;

        virtual XYDIM GetDefaultHeight() const;

        Model* GetModel() const;

        const View* GetView() const { return m_abstract_view; }
        
        void DeleteLater();

        void AdjustParent(Control* parent) { m_parent = parent; }
        
        INT GetId() const { return m_id; }

        void SetId(INT id) { m_id = id; }

    protected:
        const View* m_abstract_view;

        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();
        
        virtual Model* CreateModel() const;

        void SetModel(Model* model) { m_model = model; }

        void SetView(const View* view) { m_abstract_view = view; }

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnMove(XYDIM dx, XYDIM dy);

        virtual void OnResize(XYDIM dx, XYDIM dy);

        virtual void OnThemeChanged() = 0;

        virtual void OnLanguageChanged() = 0;

#if defined(APOXI_COMPAT_1_8_0)     

        virtual BOOLEAN DestroyModel(Model* model);
#endif // APOXI_COMPAT_1_8_0

    private:
        INT m_id;
        Control* m_parent;
        mutable Model* m_model;
        Rect m_bounds;
};

#endif

