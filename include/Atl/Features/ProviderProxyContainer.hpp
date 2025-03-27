//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(ProviderProxyContainer_hpp)
#define ProviderProxyContainer_hpp

#include <Gui/ItemContainer.hpp>
#include <Auxiliary/Provider.hpp>

#if defined(APOXI_COMPAT_2_7_0)
    #include <Atl/Features/ProviderProxyItem.hpp>
#endif  // APOXI_COMPAT_2_7_0

class Provider;
class ProviderProxyItem;

class ProviderProxyContainer : public ItemContainer, public Observer
{
    typedef ItemContainer Base;

    public:
        enum {
            ID = 105
        };

        ProviderProxyContainer();

        ProviderProxyContainer(Dispatcher* disp,
                               Provider* provider,
                               INT text_col_id,
                               INT icon_col_id = c_invalid_colid);

        virtual ~ProviderProxyContainer();

        void Init(Dispatcher* disp,
                  Provider* provider,
                  INT text_col_id,
                  INT icon_col_id = c_invalid_colid);

        void Init(Dispatcher* disp,
                  Provider* provider,
                  const WString& text,
                  INT text_col_id,
                  INT icon_col_id = c_invalid_colid);

        void Init(Dispatcher* disp,
                  Provider* provider,
                  const WString& text,
                  const ImageObtainer& img_obt,
                  INT text_col_id,
                  INT icon_col_id = c_invalid_colid);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        BOOLEAN SetProvider(Provider* provider);

        Provider* GetProvider() { return m_provider; }

        INT GetTextColumnId() const { return m_text_col_id; }

        void SetTextColumnId(INT text_col_id) { m_text_col_id = text_col_id; }

        INT GetIconColumnId() const { return m_icon_col_id; }

        void SetIconColumnId(INT icon_col_id) { m_icon_col_id = icon_col_id; }

        virtual BOOLEAN AddItem(Item* item);

        virtual BOOLEAN InsertItem(INT index, Item* item);

        virtual BOOLEAN RemoveItem(INT index);

        virtual BOOLEAN RemoveAllItems();

        virtual BOOLEAN SetParentContainer(AbstractItemContainer* container);

        virtual AbstractItemContainer* GetParentContainer();

        virtual void OnUpdate(ObservableObject* obs_obj);

    private:
        void UpdateItems();
        void DeleteItems();
        void InvalidateItem(ProviderProxyItem* item) const;

        Provider* m_provider;

        INT m_text_col_id;
        INT m_icon_col_id;
};

#endif /* ProviderProxyContainer_hpp */

