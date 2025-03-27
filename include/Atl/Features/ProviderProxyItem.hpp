//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(ProviderProxyItem_hpp)
#define ProviderProxyItem_hpp

#include <Gui/Item.hpp>
#include <Auxiliary/Observer.hpp>
#include <Auxiliary/Provider.hpp>

class DataItem;
class ProviderProxyItem : public Item, public Observer
{
    typedef Item Base;
    
    public:
    enum {
        ID = 106
    };
        
    ProviderProxyItem();

    ProviderProxyItem(Provider* provider, 
                    INT row = c_no_row, 
                    INT text_id = c_invalid_colid, 
                    INT icon_id = c_invalid_colid, 
                    BOOLEAN obs_prov = TRUE);

    ProviderProxyItem(Dispatcher* disp, 
                    Provider* m_provider, 
                    INT row = c_no_row, 
                    INT text_id = c_invalid_colid, 
                    INT icon_id = c_invalid_colid, 
                    BOOLEAN obs_prov = TRUE);

    ProviderProxyItem(const ProviderProxyItem &ppi);

    virtual ~ProviderProxyItem();

    void Init(Provider* provider, 
            INT row = c_no_row, 
            INT text_id = c_invalid_colid, 
            INT icon_id = c_invalid_colid, 
            BOOLEAN obs_prov = TRUE);

    void Init(Dispatcher* disp, 
            Provider* m_container, 
            INT row = c_no_row, 
            INT text_id = c_invalid_colid, 
            INT icon_id = c_invalid_colid, 
            BOOLEAN obs_prov = TRUE);

    virtual const WString& GetText() const;

    virtual const ImageObtainer& GetIcon(const IconState& icon_state) const;

    BOOLEAN GetData(INT data_id, DataItem& data_item) const;

    void SetData(INT data_id, DataItem& data_item);

    BOOLEAN IsInvalid() const { return m_invalid; }

    void SetInvalid();

    void SetItemColumnIds(INT text_id, INT icon_id);
    
    INT GetItemColumnTextId() { return m_text_col_id; }

    INT GetItemColumnIconId(void) { return m_icon_col_id; }

    void SetProvider(Provider* provider) { m_provider = provider; }
    
    Provider* GetProvider() { return m_provider; }
    
    virtual void OnUpdate(ObservableObject *obs_obj);
    
    virtual BOOLEAN IsEqual(const Item& item) const;
    
    virtual BOOLEAN IsInstanceOf(INT id) const;
    
    void SetProviderRow(INT row);

    INT GetProviderRow() const { return m_row; }

    ProviderProxyItem& operator = (const ProviderProxyItem& ppi);

    void ObserveProvider(BOOLEAN flag);

    void InvalidateText();

    void InvalidateIcon();

private:

    Provider* m_provider;
    INT m_row;
    INT m_text_col_id;
    INT m_icon_col_id;

    BOOLEAN m_invalid;
    mutable BOOLEAN m_valid_text;
    mutable BOOLEAN m_valid_icon;
};

#endif /* ProviderProxyItem_hpp */

