/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MultiMediaEditor_hpp)
#define Apoxi_MultiMediaEditor_hpp

class ParagraphCompoundItem;
class MultiMediaEditorDocument;
class BoundedEditorItem;
class ImageItem;

#include <Gui/AbstractMultiLineEditor.hpp>
#include <Gui/ImageBox.hpp>

class MultiMediaEditor : public AbstractMultiLineEditor {
    typedef AbstractMultiLineEditor Base;

    public:
        enum {
            ID = 36
        };

        MultiMediaEditor();

        MultiMediaEditor(Control* parent,
                         INT input_mapper_id);

        virtual ~MultiMediaEditor();

        void Init(Control* parent,
                  INT input_mapper_id);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual void SetReadOnly(BOOLEAN read_only);

        virtual void OnItemMarked(const AbstractEditorItem* item);

        virtual void Update();

        void SetFont(const Font& font);

        const Font& GetFont() const { ASSERT_DEBUG(m_font != 0); return* m_font; }

        void SetTextAttr(TextAttr text_attr);

        TextAttr GetTextAttr() const { return m_text_attr; }

        void SetForegroundColor(const Color& color);

        const Color& GetForegroundColor() const { return m_foregr_color; }

        void SetBackgroundColor(const Color& color);

        const Color& GetBackgroundColor() const { return m_backgr_color; }

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Backspace();

        virtual BOOLEAN GetCharItem(INT index, WCHAR& chr) const;

        void SetTopLineGap(UINT8 gap);

        UINT8 GetTopLineGap() const;

        void SetBottomLineGap(UINT8 gap);

        UINT8 GetBottomLineGap() const;

        virtual void SetFirstVisibleLineIndex(INT line_idx);

    protected:
        virtual Model* CreateModel() const;

        virtual BOOLEAN DestroyModel(Model* model);

        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();

        virtual void OnPaint(const Rect& repaint_rect);

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnLayoutClient();

        virtual void DrawMarkedItemSelection(DeviceContext* dc,
                                             const Rect& item_rect,
                                             INT item_index);

        // Debugging-code (enabled only for HOST-environment)
        #if defined(_MSC)
            #if defined(_DEBUG)
                INT DumpCompoundItem(const CompoundItem& comp_item, INT level = 0) const;
            #endif
        #endif

    private:
        enum RefreshHint {
            UpdatedDocument,
            InsertedItem,
            ReplacedItem,
            RemovedItem
        };

        BOOLEAN     m_use_rt_format;
        INT         m_sel_action_elem_idx;
        const Font* m_font;
        TextAttr    m_text_attr;
        Color       m_foregr_color;
        Color       m_backgr_color;
        Vector<INT> m_action_elem_idx;
        Vector<ImageBox*> m_img_box_vec;

        MultiMediaEditorDocument* GetMyDocument() { return (MultiMediaEditorDocument*)GetModel(); } //lint !e1762
        const MultiMediaEditorDocument* GetMyDocument() const { return (MultiMediaEditorDocument*)GetModel(); }

        void CreateActionElemIndices();
        INT AdjustSelectedActionElem(BOOLEAN& old_visible, BOOLEAN& new_visible, INT delta = 0);
        const AbstractEditorItem* GetItem(INT index) const;

        void RefreshImageCache(RefreshHint hint);
        void CleanupImageCache();
        void UpdateImagePositions();
        ImageBox* InsertImageBox(const ImageItem& img_item);
        void DeleteImageBox(INT index);
        BOOLEAN GetCharItemForParagraph(const ParagraphCompoundItem& paragraph, INT index, WCHAR& chr) const;
};

#endif  // Apoxi_MultiMediaEditor_hpp

