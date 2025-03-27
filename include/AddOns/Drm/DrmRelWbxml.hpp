/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DrmRelWbxml_hpp)
#define Apoxi_DrmRelWbxml_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/BinarySearch.hpp>

#include <AddOns/Drm/Drm.hpp>
#include <AddOns/Drm/DrmRelparser.hpp>
#include <AddOns/Wbxml/WbxmlHandlerBase.h>
#include <AddOns/Wbxml/HandlerBase.h>

// Wbxml Parser
class WbxmlRelHandler : public WBXMLHandlerBase {
    public:

        virtual void resolveTagName(Token token, CHAR* tagName, size_t tagNameLength) {         
        }

        virtual void resolveAttributeName(Token token,
            CHAR* attributeName, size_t attributeNameLength,
            CHAR* attributeValuePrefix, size_t attributeValuePrefixLength) {            
        }

        virtual void resolveAttributeValue(Token token,
            CHAR* attributeValue, size_t attributeValueLength) {            
        }
};



class WbxmlParserRel : public HandlerBase { 
    
    public:

        // Wbxml token values as defined by specification DRMREL v1.0
        enum RelWbxmlTag_v1_0 {
            RelWbxmlRights = 0x05,
            RelWbxmlContext,
            RelWbxmlVersion,
            RelWbxmlUid,
            RelWbxmlAgreement,
            RelWbxmlAsset,
            RelWbxmlKeyInfo,
            RelWbxmlKeyValue,
            RelWbxmlPermission,
            RelWbxmlPlay,
            RelWbxmlDisplay,
            RelWbxmlExecute,
            RelWbxmlPrint,
            RelWbxmlConstraint,
            RelWbxmlCount,
            RelWbxmlDatetime,
            RelWbxmlStart,
            RelWbxmlEnd,
            RelWbxmlInterval,
            RelWbxmlNone
        };

        // Wbxml attribute name token values as defined by specification DRMREL v1.0
        enum RelWbxmlAttName_v1_0 {
            RelWbxmlAttLang = 0x05,
            RelWbxmlAttDd,
            RelWbxmlAttSig,
            RelWbxmlAttNone
        };

        // Wbxml attribute token values as defined by specification DRMREL v1.0
        enum RelWbxmlAttValue_v1_0 {
            RelWbxmlAttLangVal = 0x05,
            RelWbxmlAttDdVal,
            RelWbxmlAttSigVal,
            RelWbxmlAttValNone
        };

        WbxmlParserRel(DrmRelParser& rh) : m_ro(rh.m_ro)
        {
            m_rel_parser = &rh;         
            m_perm = 0;
            m_constraint = 0;
            m_permission_depth = 0;
            m_constraint_depth = 0;
            m_data_depth = 0;
            m_unknowntag = 0;
            m_unknowntag_depth = 0;
            m_err_val = FALSE;
        }

        /* Cleans up on return */
        ~WbxmlParserRel();

        void AddDefaultConstraints(DrmPermission * perm);
        void AddDefaultPermissions();
        DrmStatus GetParseStatus();

        /* These are callbacks from open source code - Do not follow APOXI coding guidelines */
        virtual void setDocumentLocator(const Locator &locator);
        virtual void startDocument();
        virtual void endDocument();
        virtual void startElement(const SAXString& name, const AttributeList &atts,byte& tag, size_t depth);
        virtual void endElement(const SAXString& name,byte& tag,size_t depth);
        virtual void characters(const SAXString& chars,byte& tag);
        virtual void ignorableWhitespace(const SAXChar* ch, size_t length);
        virtual void processingInstruction(const SAXString& target, const SAXString& data);
        virtual void warning(const SAXParseException& e);
        virtual void error(const SAXParseException& e);
        virtual void fatalError(const SAXParseException& e);
        
    private:
        DrmRightsObject& m_ro;
        DrmRelParser * m_rel_parser;
        BOOLEAN m_err_val ;             // Error value

        DrmPermission*  m_perm;         // Pointer to permission
        DrmConstraint*  m_constraint;   // Pointer to constraint

        INT m_permission_depth;         // Depth of permission tag if any - default 0
        INT m_constraint_depth;         // Depth of constraint tag if any - default 0
        INT m_data_depth;
        INT m_unknowntag;
        byte m_unknowntag_val;
        INT m_unknowntag_depth;// Depth of count,datetime etc tag if any - default 0

        LinkedList<DrmConstraint> m_constraint_list;
        LinkedList<DrmPermission> m_perm_list;
};

#endif //Apoxi_DrmRelWbxml_hpp

