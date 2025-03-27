/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractItemGrid_hpp)
#define Apoxi_AbstractItemGrid_hpp

class PaintDc;
class AbstractItemContainer;
class AbstractItemRenderer;
class ImageBox;
class ItemRendererProperties;
class Item;
class TextLine;
#include <Gui/AbstractGrid.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Auxiliary/TriggerTimer.hpp>
#include <Auxiliary/Vector.hpp>
#if defined(APOXI_ENABLE_POSITION_PREVIEW)
    #include <Gui/IconState.hpp>
    #include <Auxiliary/WString.hpp>
#endif

class AbstractItemGrid : public AbstractGrid {
    typedef AbstractGrid Base;
    
    public:
        enum {
            ID = 2
        };

        AbstractItemGrid();

        AbstractItemGrid(Control* parent, AbstractItemContainer* item_cont = 0);

        virtual ~AbstractItemGrid();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void Init(Control* parent, AbstractItemContainer* item_cont = 0);

        void SetRenderer(const ItemRendererProperties* properties = 0);

        const AbstractItemRenderer* GetRenderer() const { return m_renderer; }

        void SetItemContainer(AbstractItemContainer* item_cont);
        
        virtual AbstractItemContainer* GetItemContainer() const;

        virtual INT GetCellCount() const;

        virtual XYDIM GetCellHeight() const;

        virtual BOOLEAN HasHeader() const;

        virtual XYDIM GetHeaderHeight() const;

        virtual XYDIM GetSelectionHeight() const;

        void SetHeaderItem(INT column, Item* item);

        Item* GetHeaderItem(INT column) const;

        BOOLEAN AddItem(Item* item);
        
        Item* GetSelectedItem() const;

        virtual void SetSelectedIndex(INT idx);

        virtual void MoveSelectedIndex(MoveDirection move_dir);

#if defined(APOXI_ENABLE_POSITION_PREVIEW)

        void SetParentShortcutInfo(const WString& parent_info);

        const WString& GetParentShortcutInfo() const { return m_parent_shortcut_info; }

        virtual WString GetShortcutInfo() const;
#endif
        
    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnSelectionChanged();

        virtual void OnPaint(const Rect& repaint_rect);

        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();

        virtual void OnGetFocus();

        virtual void OnLoseFocus();
        
        virtual void OnResize(XYDIM dx, XYDIM dy);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual BOOLEAN OnTimeout(const Timer& timer);

        virtual Rect GetItemRect(INT item_index) const;

        virtual void DrawItemBorder(DeviceContext* dc,
                                    const Rect& cell_rect,
                                    const Rect& item_rect,
                                    INT item_index) const;

        void RefreshImageCache();

        void CleanupImageCache();

        void SwitchItemContainer(AbstractItemContainer* item_cont);
        
    private:
        friend class TriggerTimer<AbstractItemGrid>;

        BOOLEAN m_allocated_item_cont;
        AbstractItemRenderer* m_renderer;
        AbstractItemContainer* m_item_cont;
        Vector<Item*> m_header_vec;
        Vector<ImageBox*> m_img_box_vec;
        TriggerTimer<AbstractItemGrid> m_timer;

#if defined(APOXI_ENABLE_POSITION_PREVIEW)

        class TitleIconView : public View {
            public:
                TitleIconView();
                virtual ~TitleIconView();
                virtual void Draw(const Component& component,
                                  DeviceContext* dc,
                                  const Rect& repaint_rect) const;
        };
            
        class TitleIcon : public DrawableObject {
            typedef DrawableObject Base;
            
            public:
                TitleIcon(Control* parent, const ImageObtainer& img_obt);
                virtual ~TitleIcon();
                void SetImageObtainer(const ImageObtainer& img_obt);
                const ImageObtainer& GetImageObtainer() const { return m_img_obt; }
                
            private:
                ImageObtainer m_img_obt;
        };

        TitleIcon* m_title_icon;
        TextLine* m_title_pos;
        WString m_parent_shortcut_info;
#endif

        void InitProperties();
        void OnTimer();
        void StartTextScrolling();
        BOOLEAN IsValidIndex(INT index) const;
        void RefreshContent();
        Rect GetIconRect(const Item& item, INT index) const;

        void ReTranslateItemContainer(AbstractItemContainer& item_cont) const;

        void ResetDispatchers(AbstractItemContainer& item_cont) const;

        void DeleteImageBoxes(INT start_index = 0);

        BOOLEAN MoveImageBox(INT item_idx, const ImageObtainer& icon);

        BOOLEAN HasImage() const;

        void IncreaseImageVectorSize(INT size);
        
        BOOLEAN IsItemSelectable(const Item* item) const;

        void UpdateImageBoxBounds();

        void DrawItem(DeviceContext& dc,
                      INT idx,
                      INT& item_idx,
                      INT last_visible_idx,
                      const Rect& repaint_rect,
                      BOOLEAN draw_background,
                      BOOLEAN draw_mirrored = FALSE);

        void DrawHeaders(PaintDc& pdc);

        Rect GetScaledImageBounds(const Rect& icon_rect, XYDIM width, XYDIM height) const;

        void CreateDefaultItemContainer();

#if defined(APOXI_ENABLE_POSITION_PREVIEW)

        void UpdatePositionPreview();

        void DeletePreviewObject(DrawableObject* obj);

        void AdjustTitleIconSize();

        IconState::Size GetTitleIconSize(Size* pixel_size = 0) const;

        void UpdateTitlePosColor();
#endif
};

#endif  // Apoxi_AbstractItemGrid_hpp

