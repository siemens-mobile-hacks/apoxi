/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextList_hpp)
#define Apoxi_TextList_hpp

#include <Kernel/Types.hpp>
#include <Gui/AbstractListBox.hpp>
#include <Auxiliary/Vector.hpp>

class TextListLine {
    public:
        TextListLine() :
                    m_start_index(0),
                    m_length(0) {};

        void SetStartIndex(INT start_index) { m_start_index = start_index; };
        INT GetStartIndex() const { return m_start_index; };

        void SetLength(INT length) { m_length = length; };
        INT GetLength() const { return m_length; };


    private:
        INT m_start_index;
        INT m_length;
};

typedef Vector<TextListLine> TLLVector;


class TextListModel : public AbstractListBoxModel {
    typedef AbstractListBoxModel Base;

    public:
        TLLVector m_lines;

        TextListModel();
        TextListModel(const WCHAR* text);
    
        void SetText(const WCHAR* text) { m_text = text; };

        const WCHAR* GetText() const { return m_text; };

    private:
        const WCHAR *m_text;
};

class TextList : public AbstractListBox {
    typedef AbstractListBox Base;

    public:
        TextList();

        TextList(Control* parent, const WCHAR* text);

        virtual ~TextList();

        void Init(Control* parent, const WCHAR* text);

        void SetText(const WCHAR* text);

        const WCHAR* GetText() const;
        
    protected:
        virtual Model* CreateModel() const;

        virtual void OnLayoutClient();

        virtual void Refresh(const Rect& rect);

        void Layout(XYDIM width);

        virtual void OnPreviousItem();

        virtual void OnNextItem();

        virtual void OnThemeChanged();
        
        void UpdateNavigationGuidance();

    private:
        TextListModel* GetMyModel() const { return (TextListModel* )GetModel(); }
};

class TextListView : public AbstractListBoxView {
    typedef AbstractListBoxView Base;

    public:
        TextListView();
        TextListView(XYDIM item_height) :
                    AbstractListBoxView(item_height) {};

        virtual ~TextListView();

        virtual void DrawItem(const AbstractListBox& listbox, DeviceContext* dc, INT index, const Rect& item_rect) const;

    protected:
        virtual void DrawTextListItem(const TextList& text_list, DeviceContext* dc, INT index, const Rect& item_rect) const = 0;
};

#endif // Apoxi_TextList_hpp


