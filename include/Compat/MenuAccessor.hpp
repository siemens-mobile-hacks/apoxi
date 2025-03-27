/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
    
#if !defined(Apoxi_MenuAccessor_hpp)
#define Apoxi_MenuAccessor_hpp

#include <Gui/AbstractMenuAccessor.hpp>

class TextLine;
class AnimatedTextLine;
class Menu;
struct BitmapRes;

class MenuAccessor : public AbstractMenuAccessor {
    typedef AbstractMenuAccessor Base;

    public:
        MenuAccessor();

        MenuAccessor(INT columns, INT selected_idx = 0);

        MenuAccessor(const WCHAR* title);

        virtual ~MenuAccessor();

        void Init(INT columns = 1, INT selected_idx = 0);

        void Init(const WCHAR* title);

        void SetColumnCount(INT columns) { m_columns = (INT8)columns; }

        virtual INT GetColumnCount() const;

        void SetItemHeight(XYDIM item_height) { m_item_height = (INT8)item_height; }

        virtual XYDIM GetItemHeight() const;

        virtual BOOLEAN IsRoot();

        void SetSelectedIndex(INT selected_idx);

        INT GetSelectedIndex() const { return m_selected_idx; }

        virtual const WCHAR* GetItemText(BOOLEAN highlighted);

        virtual const BitmapRes* GetItemIcon(BOOLEAN highlighted);

        void SetTitle(const WCHAR* title);

        const WCHAR* GetTitle() const { return m_title; }

        virtual void Draw(DeviceContext* dc, const Rect& draw_rect, BOOLEAN highlighted);

        virtual void Trigger(Menu* menu);

        virtual void Back(Menu* menu);

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnActivate(Menu* menu, AbstractMenuAccessor* parent_accessor);

        virtual void OnDeactivate(Menu* menu);

        virtual AbstractMenuAccessor* GetParent() const;
        
        virtual AbstractMenuAccessor* GetChild();
        
        virtual void OnTrigger(INT selected_idx);

        virtual void OnSelectionChanged(INT selected_idx);

        virtual void OnLanguageChanged();

    private:
        INT m_selected_idx;
        INT m_first_visible_idx;
        INT8 m_columns;
        INT8 m_item_height;
        AbstractMenuAccessor* m_parent_accessor;
        const WCHAR* m_title;
        TextLine* m_text_line;
        AnimatedTextLine* m_anim_text_line;
};

#endif  // Apoxi_MenuAccessor_hpp


