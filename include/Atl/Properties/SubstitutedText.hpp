//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------


#ifndef Atl_SubstitutedText_hpp
#define Atl_SubstitutedText_hpp


class FeatureItem;
class Property;

class SubstitutedText{
    public:
        SubstitutedText();
        
        void Init(const WString& pattern, 
                  const FeatureItem* item);

        void SetText(const WString& pattern);
          
        const WString& GetText() const;

        WString GetSubstitutedText() const;

        static BOOLEAN IsSubstitutionNeeded(const WString& pattern_text);
        BOOLEAN ContainsProperty(Property* property) const;

    private:
        void Update(WString& subst_text) const;
        WString GetValue(const WString& identifier) const;

        WString     m_original_text;
        const FeatureItem*  m_feature_item;

};

#endif  // Atl_SubstitutedText_hpp


