/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbBaseWin_hpp)
#define Mmi_PbBaseWin_hpp

#include <AdvPhonebook/PbConfig.hpp>
#include <AdvPhonebook/ProvListBoxWin.hpp>
#include <Gui/LineEditor.hpp>

class SearchBox : public LineEditor {
    typedef LineEditor Base;

    public:
        //
        SearchBox();
        virtual ~SearchBox();

        //
        void Init(Window *win);

        virtual void MoveCaret(INT steps);

    protected:
        //virtual void OnPagingTimer();
        //virtual BOOLEAN OnKeyDown(KeyCode key_code);
};

class PbBaseWin : public ProvColListBoxWin {
    public:
        typedef ProvColListBoxWin Base;

        PbBaseWin();
        virtual ~PbBaseWin();

        void Init(Provider* pb_provider = 0, INT sort_colid = c_name_id);

        virtual Provider* GetMyPbProvider();

        virtual INT GetSelectedRow();
        
    protected:
        virtual INT GetListBoxRow(INT prov_row);

        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnLayoutClient();
        virtual void OnGetFocus();
        virtual BOOLEAN OnKeyDown(KeyCode key_code);
        virtual BOOLEAN OnConfirm();
        virtual BOOLEAN OnCancel();

    private:
        INT SearchRow(const WString &string);

        INT                     m_sort_colid;
        QuickSortProvider       m_sorted_pb_provider;

        SearchBox               m_search_box;
        ImageBox                m_search_image;
        BOOLEAN                 m_searchbox_visible;
};

#endif  // Mmi_PbBaseWin_hpp
