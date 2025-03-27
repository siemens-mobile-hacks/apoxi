/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_CheckBox_hpp)
#define Apoxi_CheckBox_hpp

#include <Gui/Model.hpp>
#include <Gui/View.hpp>
#include <Gui/Control.hpp>


class CheckBoxModel : public Model {
    public:
        typedef Model Base;

        CheckBoxModel(const WCHAR *caption = 0, BOOLEAN selected = FALSE);

        void SetSelected(BOOLEAN selected) { m_selected = selected; };

        BOOLEAN IsSelected() const { return m_selected; };

        void SetCaption(const WCHAR *caption) { m_caption = caption; };

        const WCHAR* GetCaption() const { return m_caption; };

    private:
        BOOLEAN     m_selected;
        const WCHAR *m_caption;
};

class CheckBoxView : public View {
    typedef View Base;

    public:
        CheckBoxView();

        CheckBoxView(XYDIM default_height, XYDIM left_gap, XYDIM middle_gap);

        virtual ~CheckBoxView();

        void SetItemHeight(XYDIM item_height) { m_item_height = item_height; };

        XYDIM GetItemHeight() const { return m_item_height; };

        void SetLeftGap(XYDIM left_gap) { m_left_gap = left_gap; };

        XYDIM GetLeftGap() const { return m_left_gap; };

        void SetMiddleGap(XYDIM middle_gap) { m_middle_gap = middle_gap; };

        XYDIM GetMiddleGap() const { return m_middle_gap; };

        virtual void Draw(const Component &component, DeviceContext *dc, const Rect &repaint_rect) const;

        virtual void DrawShifted(const Rect &shift_rect, const Model &abstract_model, DeviceContext *dc,  const Rect &repaint_rect) const;

    protected:
        virtual void DrawCheckBox(const CheckBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const = 0;

        virtual void DrawShiftedCheckBox(const Rect &shift_rect, const CheckBoxModel &abstract_model, DeviceContext *dc,  const Rect &repaint_rect) const = 0;

    private:
        XYDIM m_item_height;
        XYDIM m_left_gap;
        XYDIM m_middle_gap;
};

class CheckBox : public Control {
    typedef Control Base;

    public:
        CheckBox();

        CheckBox(Control *parent, const WCHAR *caption = 0, BOOLEAN selected = FALSE);

        virtual ~CheckBox();

        void Init(Control *parent, const WCHAR *caption = 0, BOOLEAN selected = FALSE);

        void SetSelected(BOOLEAN selected);

        BOOLEAN IsSelected() const;

    protected:
        virtual Model* CreateModel() const;

        virtual void Refresh(const Rect &rect);

        virtual void OnGetFocus();

        virtual void OnLoseFocus();

        virtual BOOLEAN OnSoftkeyPressed(INT idx);

        virtual BOOLEAN OnInputMap(const InputMapItem &input_map_item);

        virtual void OnThemeChanged();

        virtual void OnLanguageChanged();

        virtual void OnChangeStatus();

    private:
        CheckBoxModel* GetMyModel() const { return (CheckBoxModel *)GetModel(); }
        void AdjustThemeDependencies();

};


#endif  // Apoxi_CheckBox_hpp


