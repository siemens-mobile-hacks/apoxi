/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Item_hpp)
#define Apoxi_Item_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/WString.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Gui/IconState.hpp>
#include <Gui/IconSet.hpp>

#include <Config/GuiObjectFactory.hpp>

class Dispatcher;
class ResourceParser;

class Item {
    public:
        enum {
            ID = 0
        };
        
        enum ItemPropertyId {
            UnspecifiedPropertyId   = -1,
            TextPropertyId          = 0,
            IconPropertyId          = 1,
            EnabledPropertyId       = 2,
            SeparatorPropertyId     = 3,
            ValuePropertyId         = 4,
            MarkedPropertyId        = 5,
            CustomPropertyId        = 999
        };

        Item();

        Item(Dispatcher* dispatcher,
             const WCHAR* text,
             const BitmapRes* icon = 0,
             BOOLEAN enabled = TRUE);

        Item(Dispatcher* dispatcher,
             const WString& text,
             const BitmapRes* icon = 0,
             BOOLEAN enabled = TRUE);

        Item(Dispatcher* dispatcher,
             const WString& text,
             const ImageObtainer& icon,
             BOOLEAN enabled = TRUE);


        Item(Dispatcher* dispatcher,
             const WString& text,
             const IconSet& icon_set,
             BOOLEAN enabled = TRUE);

        virtual ~Item();

        void Init(Dispatcher* dispatcher,
                  const WCHAR* text,
                  const BitmapRes* icon = 0,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const BitmapRes* icon = 0,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const ImageObtainer& icon,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const IconSet& icon_set,
                  BOOLEAN enabled = TRUE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual void SetText(const WString& text);

        void SetText(const WCHAR* text);

        virtual const WString& GetText() const;

        virtual void SetIcon(const ImageObtainer& icon);

        void SetIcon(const BitmapRes* icon);

        void SetIcon(const IconSet& icon_set);

        const ImageObtainer& GetIcon() const;

        virtual const ImageObtainer& GetIcon(const IconState& icon_state) const;
        
        BOOLEAN HasIcon() const;

        virtual void SetEnabled(BOOLEAN enabled);

        virtual BOOLEAN IsEnabled() const;

        void SetSeparator(BOOLEAN is_separator);

        BOOLEAN IsSeparator() const { return (BOOLEAN)m_bits.is_separator; }

        void SetMarked(BOOLEAN marked);

        BOOLEAN IsMarked() const { return (BOOLEAN)m_bits.marked; }

        virtual void SetDispatcher(Dispatcher* dispatcher) { m_dispatcher = dispatcher; }

        Dispatcher* GetDispatcher() const { return m_dispatcher; }

        void SetSyncModeEnabled(BOOLEAN enabled) { m_bits.sync_mode_enabled = enabled; }

        BOOLEAN IsSyncModeEnabled() const { return (BOOLEAN)m_bits.sync_mode_enabled; }

        void BlockNotification(BOOLEAN block) { m_bits.block_notification = block; }

        BOOLEAN IsNotificationBlocked() const { return (BOOLEAN)m_bits.block_notification; }

        void SetRetranslateEnabled(BOOLEAN enabled) { m_bits.retranslate_enabled = enabled; }

        BOOLEAN IsRetranslateEnabled() const { return (BOOLEAN)m_bits.retranslate_enabled; }

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual BOOLEAN IsEqual(const Item& item) const;
        
        virtual void OnLanguageChanged();

        BOOLEAN UsesIconSet(BOOLEAN* contains_only_bmps = 0) const;

        INT GetLanguageId() const { return (INT) m_bits.language_id; }

    protected:
        void NotifyPropertyChange(INT property_id = UnspecifiedPropertyId); 

        void SetTextProperty(const WString& text) const  { m_text = text; }

        void SetIconProperty(const ImageObtainer& icon) const;

        void SetEnabledProperty(BOOLEAN enabled) const { m_bits.enabled = enabled; }
        
        void SetLanguageId(INT lang_id) { m_bits.language_id = lang_id; }

    private:
        mutable struct {
            UINT enabled                : 1;
            UINT is_separator           : 1;
            UINT sync_mode_enabled      : 1;
            UINT block_notification     : 1;
            UINT retranslate_enabled    : 1;
            UINT language_id            : 8;
            UINT marked                 : 1;
        } m_bits;
        Dispatcher* m_dispatcher;
        mutable WString m_text;
        mutable IconSet m_icon_set;
        
        void InitBitset();
};
 
#endif  // Apoxi_Item_hpp

