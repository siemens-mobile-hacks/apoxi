// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if ! defined(UnifiedInbox_UibListBoxModel_hpp)
#define UnifiedInbox_UibListBoxModel_hpp

#include <GuiExtensions/LabelListBoxModel.hpp>
#include <Auxiliary/Provider.hpp>

#include <Config/Config.hpp>

class UibInboxWin;

class UibListBoxModel : public LabelListBoxModel {

    typedef LabelListBoxModel Base;

    public:

        UibListBoxModel();

        virtual ~UibListBoxModel();

        void Init(DrawableObjectListBox* list_box, Provider* provider);

        virtual const BitmapRes* GetCellIcon(INT index, BOOLEAN highlighted);

        virtual const WCHAR* GetCellText(INT index, BOOLEAN highlighted);

        virtual void Update(INT item_count = -1);

        void SetProvider(Provider* provider) { m_provider = provider; }

        Provider* GetProvider() { return m_provider; }

    private:
        Provider* m_provider;
        WString m_text;
};

#endif // UnifiedInbox_UibListBoxModel_hpp
