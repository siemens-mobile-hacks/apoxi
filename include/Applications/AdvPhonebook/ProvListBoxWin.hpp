/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_ProvListBoxWin_hpp)
#define Mmi_ProvListBoxWin_hpp

#include <GuiExtensions/DrawableObjectListBox.hpp>
#include <AdvPhonebook/PbProvListBox.hpp>
#include <AdvPhonebook/PbDetailListBox.hpp>
#include <AdvPhonebook/PbAbstractWin.hpp>
#include <GuiExtensions/MmiWindow.hpp>
#include <AdvPhonebook/PbDetailFilterProvider.hpp>

class ProvListBoxWin : public PbAbstractWin {
    typedef PbAbstractWin Base;

    public:
        ProvListBoxWin();
        virtual ~ProvListBoxWin();
        
        virtual void SetSelectedRow(INT row);

        virtual INT GetSelectedRow();

        virtual void SetProvider(Provider *provider);

        virtual Provider* GetProvider();

        virtual void UpdateWin(BOOLEAN win_only = FALSE);

        virtual void GetSelectedItem(INT colid, DataItem &item);
    protected:
        virtual PbProvListBox * GetListBox() = 0;
        virtual INT GetListBoxRow(INT row);

        virtual void Refresh(const Rect &rect);
        virtual void OnGetFocus();
        virtual BOOLEAN OnMessage(const Message& msg);


    private:
        INT m_selected_row;
        BOOLEAN m_prov_updating;
};

class ProvColListBoxWin : public ProvListBoxWin {
    typedef ProvListBoxWin Base;

    public:
        ProvColListBoxWin();
        ProvColListBoxWin(INT column_id);
        virtual ~ProvColListBoxWin();

        void Init(INT column_id, INT sort_colid = c_invalid_colid);
        virtual Provider* GetMyPbProvider();
        
    protected:
        virtual PbProvListBox * GetListBox();

    private:
        PbProvColListBox        m_prov_listbox;
};

class ProvDetailListBoxWin : public ProvListBoxWin {
    typedef ProvListBoxWin Base;

    public:
        ProvDetailListBoxWin();
        ProvDetailListBoxWin(ProvListBoxWin *parent, const INT *detail_columns, INT filt_colid);
        virtual ~ProvDetailListBoxWin();

        void Init(ProvListBoxWin *parent, const INT *detail_columns, INT filt_colid);

        virtual Provider* GetMyPbProvider();

        virtual INT GetSelectedRow();

        virtual void SetProvider(Provider *provider);

        void SetRow(int row);
        void SetDetailColumns(const INT *detail_columns) { m_detail_listbox.SetDetailColumns(detail_columns); }
        
        virtual void UpdateEnabledActions();

        virtual void UpdateWin(BOOLEAN win_only = FALSE);

    protected:
        virtual void Refresh(const Rect &rect);
        virtual void UpdateTitle();

        virtual PbProvListBox * GetListBox();
        virtual PbDetailProvider * GetDetailProvider() = 0;
        virtual ProvListBoxWin * GetParent();

    private:
        ProvListBoxWin *        m_parent;
        const INT *             m_detail_columns;
        PbDetailListBox         m_detail_listbox;
        Provider *              m_provider;
        INT                     m_filt_colid;
};

#endif  // Mmi_ProvListBoxWin_hpp
