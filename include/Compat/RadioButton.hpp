/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_RadioButton_hpp)
#define Apoxi_RadioButton_hpp

#include <Gui/Control.hpp>
#include <Gui/Model.hpp>
#include <Gui/View.hpp>


class RadioButtonView;

class RadioButtonModel : public Model {
    public:
        typedef Model Base;

        // Constructor of the radiobutton-model.
        RadioButtonModel(const WCHAR *caption = 0, BOOLEAN state = 0) : 
            m_caption(caption), m_state(state)  {};

        //
        void SetCaption(const WCHAR *caption) { m_caption = caption; };

        //
        const WCHAR* GetCaption() const { return m_caption; };

        //
        void SetState(BOOLEAN state) { m_state = state; };

        //      
        BOOLEAN GetState() const { return m_state; };

    private:
        const WCHAR     *m_caption;
        BOOLEAN         m_state;
};

class RadioButtonView : public View {
    typedef View Base;

    public:
        RadioButtonView();
        // Constructor of the radiobutton-view.
        RadioButtonView(XYDIM item_height,
                               XYDIM left_gap,
                               XYDIM middle_gap) :
                    Base(-1, item_height),
                    m_item_height(item_height),
                    m_left_gap(left_gap),
                    m_middle_gap(middle_gap) {};

        virtual ~RadioButtonView() {}

        //
        void SetItemHeight(XYDIM item_height) { m_item_height = item_height; };

        //
        XYDIM GetItemHeight() { return m_item_height; };

        //
        void SetLeftGap(XYDIM left_gap) { m_left_gap = left_gap; };

        //
        XYDIM GetLeftGap() const { return m_left_gap; };

        //
        void SetMiddleGap(XYDIM middle_gap) { m_middle_gap = middle_gap; };

        //
        XYDIM GetMiddleGap() const { return m_middle_gap; };

        virtual void Draw(const Component &component, DeviceContext *dc, const Rect &repaint_rect) const;

        virtual void DrawShifted(const Rect &shift_rect, const Model &abstract_model, DeviceContext *dc,  const Rect &repaint_rect) const;

    protected:
        virtual void DrawRadioButton(const RadioButtonModel &model, DeviceContext *dc, const Rect &repaint_rect) const = 0;

        virtual void DrawShiftedRadioButton(const Rect &shift_rect, const RadioButtonModel &abstract_model, DeviceContext *dc,  const Rect &repaint_rect) const = 0;

    private:
        XYDIM m_item_height;
        XYDIM m_left_gap;
        XYDIM m_middle_gap;
};


#endif  // Apoxi_RadioButton_hpp


