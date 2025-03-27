//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_PropertyEditorFactory_hpp)
#define Atl_PropertyEditorFactory_hpp

class PropertyItem;
class PropertyEditorFactory {
    public:
        
        static PropertyEditorFactory* GetInstance() { return &m_instance; }
        
        virtual ~PropertyEditorFactory();
        
        BOOLEAN Edit(PropertyItem* property);

    private:
        PropertyEditorFactory() {};
        
        static PropertyEditorFactory m_instance;
};

#endif // Atl_PropertyEditorFactory_hpp 

