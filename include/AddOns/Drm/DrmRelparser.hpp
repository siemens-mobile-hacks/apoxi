/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DrmRelParser_hpp)
#define Apoxi_DrmRelParser_hpp


#include <AddOns/Drm/Drm.hpp>

enum DrmXmlFormat {
    // Xml REL Data
    DrmRightsXml,
    // Wbxml REL Data
    DrmRightsWbxml,
    // None
    DrmRightsNone
};

// Basic Drm Rel parser
class DrmRelParser {

    friend class XmlParserRel;
    friend class WbxmlParserRel;

    public :

        enum DrmVersion {
            // Drm version 1.0
            Drm_v_1_0 ,
            Drm_v_None
        };

        DrmRelParser(DrmRightsObject& ro, const UINT8* rights_xml_buffer,DrmXmlFormat xml_format) : m_ro(ro) {          
            m_xml_format = xml_format;          
            m_rights_xml_data = rights_xml_buffer;
         }

        DrmRelParser(DrmRightsObject& ro, const BinData* wbxml_data,DrmXmlFormat wbxml_format) : m_ro(ro) {         
            m_xml_format = wbxml_format;            
            m_wbxml_data = wbxml_data;
         }

        INT32 Parse();

        DrmVersion GetDrmVersion();

        void SetDrmVersion(String& version){
            if(version.compare("1.0"))
                m_drm_version = Drm_v_1_0;
            else
                m_drm_version = Drm_v_None; // Should generate error and return according to spec
        }

    protected :
        INT32 ParseXmlRel();
        DrmStatus ParseWbxmlRel(); // Phase 3
        DrmRightsObject& GetRightsObject()
        {
            return m_ro;
        }
        

    private :   
        // Reference of rights object in container  
        DrmRightsObject& m_ro;

        const UINT8* m_rights_xml_data;

        // BinData interface for WBXML REL data.
        const BinData* m_wbxml_data;

        DrmXmlFormat m_xml_format;  // needs to be stored because parse can be called at any time, right now only XML and WBXML
                                     // change to UINT16 etc later when more formats are available

        DrmVersion m_drm_version;   // DrmVersion 1-v1.0, 2-v2.0 ...        
};// DrmRelParser

#endif

