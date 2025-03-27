/*  ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Zi8AlphabetBox_hpp)
#define Apoxi_Zi8AlphabetBox_hpp

#include <Gui/DrawableObject.hpp>

class Zi8AlphabetBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        Zi8AlphabetBoxView();

        virtual ~Zi8AlphabetBoxView();

        void Init();

        virtual void Draw(const Component &component, 
                          DeviceContext *dc, 
                          const Rect &repaint_rect) const;      
};

class Zi8AlphabetBox : public DrawableObject {
    public:
        typedef DrawableObject Base;
        
        Zi8AlphabetBox();

        Zi8AlphabetBox(Control *control);

        virtual ~Zi8AlphabetBox();
        
        virtual XYDIM GetDefaultHeight() const;

        void    Init(Control *control);
        
        void    SetText(const WCHAR *text, INT selected_idx = -1, const INT caps_status = 0);

        const   WCHAR* GetText(INT *selected_idx = 0, INT *caps_status = 0) const;

        void    SetPageFlag(BOOLEAN prev_page, BOOLEAN next_page);

        void    GetPageFlag(BOOLEAN *prev_page, BOOLEAN *next_page) const;

        void    SetEleCount(INT ele_count);

        INT     GetEleCount() const;

        INT     GetShowCount(const WCHAR *text, INT font_id);

        INT GetCenterXpos() const;

    private:
        const WCHAR         *m_text;            //point to the english candidates
        INT                 m_selected_idx;     //the index of the selected word
        INT                 m_candidate_count;
        INT                 m_canddidate_offset;
        INT                 m_ele_count;
        INT                 m_center_xpos;
        BOOLEAN             m_caps_status;
        BOOLEAN             m_prev_page, m_next_page;

        static Zi8AlphabetBoxView   m_view;
};

#endif  // Apoxi_Zi8AlphabetBox_hpp


