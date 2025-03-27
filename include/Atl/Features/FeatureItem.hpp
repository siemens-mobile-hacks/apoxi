/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(FeatureItem_hpp)
#define FeatureItem_hpp

#include <Gui/Action.hpp>

#include <Atl/Features/FeatureID.hpp>
#include <Atl/Properties/SubstitutedText.hpp>
#include <Atl/Features/Feature.hpp>
#include <Atl/Context/ContextID.hpp>

class AtlApplication;
class Property;

class FeatureItem : public Action {
      typedef Action Base;
   public:

      enum {
         ID = 100
      };

      enum FeatureItemPropertyId {
          FeaturePropertyId = 5,
          ContextPropertyId = 6
      };

      FeatureItem();

      FeatureItem(Feature* feature);

      FeatureItem(Feature* feature, const WString& text);

      FeatureItem(Feature* feature, const WString& text, const ImageObtainer& icon);

      virtual ~FeatureItem();

      void Init(Feature* feature = 0);

      void Init(Feature* feature, const WString& text);

      void Init(Feature* feature, const WString& text, const ImageObtainer& icon);

      void SetContextId(const ContextID& id);

      void SetContextId(const CHAR * id);

      const ContextID& GetContextId() const { return m_context_id; }

      BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

      virtual INT GetID() const;

      virtual BOOLEAN IsInstanceOf(INT id) const;

      virtual BOOLEAN IsEqual(const Item& item) const;

      inline FeatureID GetFeatureId() const { return m_feature ? m_feature->GetFeatureId() : FeatureID();}

      virtual void SetText(const WString& text);
      
      virtual const WString& GetText() const;
      
      virtual BOOLEAN Execute();

      virtual void SetEnabled(BOOLEAN enabled);

      virtual BOOLEAN IsEnabled() const;

      Feature*          GetFeature() { return m_feature;}

      const Feature*    GetFeature() const { return m_feature;}

      void SetFeature(Feature* feature);

#if defined(APOXI_COMPAT_2_7_0)

      void      SetIconURI(const WString& icon_uri) {m_icon_uri = icon_uri;}

      WString   GetIconURI() const { return m_icon_uri;}

      virtual const ImageObtainer& GetIcon(const IconState& icon_state) const;

#endif

      virtual void OnLanguageChanged();

      virtual void Update();

      BOOLEAN IsAttachedToProperty(Property* property) const;

   protected:
      Feature*          m_feature;

      SubstitutedText   m_substituted_text;

#if defined(APOXI_COMPAT_2_7_0)

      WString           m_icon_uri;
#endif

   private:
      FeatureItem(const FeatureItem& orig);
      FeatureItem& operator = (const FeatureItem& rhs);

      ContextID m_context_id;
};

#endif /* FeatureItem_hpp */

