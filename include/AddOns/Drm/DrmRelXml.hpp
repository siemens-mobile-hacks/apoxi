/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DrmXmlRelParser_hpp)
#define Apoxi_DrmXmlRelParser_hpp


#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/BinarySearch.hpp>

#include <AddOns/Drm/Drm.hpp>
#include <AddOns/Drm/DrmRelparser.hpp>
#include <AddOns/XmlParser/xml_parser.hpp>


typedef enum date_type {
            dt_none,
            gyear,
            gmonth,
            gday,
            thour,
            tmin,
            tsec,
            tdiffhour,
            tdiffmin
        }date_type;
typedef enum correction_type {
            ct_none,
            ct_negative,
            ct_positive
}correction_type;


// XML parser 
class XmlParserRel : public XMLParser {
    public :
        // For readability of code 
        enum RelTag_v1_0 {
            RelTagKeyInfo = 0 ,
            RelTagKeyValue,
            RelTagCount,
            RelTagDatetime,
            RelTagDisplay,
            RelTagEnd,
            RelTagExecute,
            RelTagInterval,
            RelTagPlay,
            RelTagPrint,
            RelTagStart,
            RelTagUid,
            RelTagVersion,
            RelTagAgreement,
            RelTagAsset,
            RelTagConstraint,
            RelTagContext,
            RelTagPermission,
            RelTagRights,
            RelTagNone
        };

        XmlParserRel(CHAR *s,DrmRelParser& rh) : XMLParser(s), m_ro (rh.m_ro), m_rel_parser(&rh)
        {                       
            m_perm = 0;
            m_constraint = 0;
            m_permission_depth = 0;
            m_constraint_depth = 0;
            m_data_depth = 0;
            m_unknowntag = 0;
            m_unknowntag_depth = 0;
        }
        
        s32 Parse() { return XMLParser::Parse();}

        void AddDefaultConstraints(DrmPermission * perm);
        void AddDefaultPermissions();
        static UINT32 ParseDateString(String& date_data, INT &parse_err);
        static UINT32 ParseInterval(String& validity_data, INT &parse_err);

        virtual s32 XML_Error_Handler(INT ErrorCode, INT ErrorLine);
        virtual s32 XML_Start_Handler(void *UserData);
        virtual s32 XML_End_Handler(void *UserData);
        virtual s32 XML_StartElement_Handler(void *UserData, CHAR *uri, CHAR *localname, CHAR *qName, LPVECTOR atts);
        virtual s32 XML_EndElement_Handler(void *UserData, CHAR *uri, CHAR *localname, CHAR *qName);
        virtual s32 XML_Characters_Handler(void *UserData, CHAR *Chars, s32 cbsize);
        virtual s32 XML_PI_Handler(void *UserData, CHAR *Target, CHAR *Data);
        virtual s32 XML_StartCData_Handler(void *UserData);
        virtual s32 XML_EndCData_Handler(void *UserData);

        /* Cleans up on return */
    virtual ~XmlParserRel();

    private :
        DrmRightsObject& m_ro;
        DrmRelParser * m_rel_parser;
        
        INT m_tag_index;                    // Tag index in tag name strings - needs to be persisted in object
        DrmPermission*  m_perm;         // Pointer to permission
        DrmConstraint*  m_constraint;       // Pointer to constraint
        INT m_permission_depth;         // Depth of permission tag if any - default 0
        INT m_constraint_depth;         // Depth of constraint tag if any - default 0
        INT m_data_depth;                   // Depth of count,datetime etc tag if any - default 0
        INT m_unknowntag;
        String m_unknowntag_val;
        INT m_unknowntag_depth;

        LinkedList<DrmConstraint> m_constraint_list;
        LinkedList<DrmPermission> m_perm_list;
        static CHAR* trimSpaces (const CHAR *srcstr);
        static CHAR* parseDate(CHAR *srcstr, INT &year, INT &month, INT &day, date_type &count, INT &datetime_err);
        static INT parseTime(CHAR *srcstr, INT &hour, INT &min, INT &sec, correction_type  &corr_sign,INT &diffhour, INT &diffmin, INT &utc_time, date_type &count);

};

#endif //Apoxi_DrmXmlRelParser_hpp

