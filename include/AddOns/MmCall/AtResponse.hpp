/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AtResponse_hpp)
#define Apoxi_AtResponse_hpp

const INT c_max_at_resp_params = 16;

class SerialTerminal;
class AtResponseIterator;
struct AtResponseMetaInfo;

struct AtResponseParameter 
{
    public: 
 
        enum  ParamType {
            PtNumeric,
            PtString,
            PtNoValue
        };

        AtResponseParameter();

        AtResponseParameter(const AtResponseParameter& parameter);

        ~AtResponseParameter();

        AtResponseParameter& operator = (const AtResponseParameter& parameter);
        INT32 GetIntegerValue() const { return m_int_val; };
    
        const String &GetStringValue() const { return m_str_val; };

        ParamType GetParameterType() const { return m_param_type; };
    
        friend AtResponseIterator;

    private:
    
        INT32       m_int_val;
        String      m_str_val;
    
        ParamType   m_param_type;
};

class AtResponse 
{
    public:
        enum ResponseType {
            Ok,
            Connect,
            Ring,
            NoCarrier,
            Error,
            NoDialtone,
            Busy,
            NoAnswer,
            Calv,
            Ccwa,
            Ccwv,
            Cdev,
            Cdip,
            Ciev,
            Ckev,
            Clav,
            Clip,
            CmeError,
            Colp,
            Cr,
            Creg,
            Cring,
            Cssi,
            Cssu,
            Ctzv,
            Cusd,
            Clcc,
            Cuus1i,
            Cuus1u,
            Dr,
            Ilrr,
            Xcallstat,
            Xcallinfo,
            Xceer,
            Xcallrefuse,
            Xprogress,
            Cgact,
            Xcaoc,
            Xcharge,
            Xcccm,
            Xccharge,
            XaocService,

            UnknownResponse,
            FatalError
        };

        AtResponse();
        
        AtResponse(const AtResponse& response);
        
        ~AtResponse();
        
        AtResponse& operator= (const AtResponse& response);

        ResponseType GetResponseType() const { return m_response_type; };
        
        void SetResponseType(ResponseType type) { m_response_type = type; };
        
        
        const AtResponseParameter& GetParameterAt(const UINT8 index) const {return m_parameter_list[index];};
        
        INT GetNrOfParameters() const { return m_nr_of_parameters; };

        static const String GetResponseString(AtResponse::ResponseType type);

        friend AtResponseIterator;

    private:
        ResponseType        m_response_type;
        AtResponseParameter m_parameter_list[c_max_at_resp_params];
        INT                 m_nr_of_parameters;
};


struct AtResponseMetaInfo {
    AtResponse::ResponseType    m_response_type;
    CHAR *                      m_str_presentation;
};

struct AtResponseInfoTable {
    public:

        static INT GetNumberOfEntries() { return c_response_info_size; };
        
        static const AtResponseMetaInfo *GetElementAt(INT index) { return &c_response_info_table[index]; };

    private:
        static const AtResponseMetaInfo c_response_info_table[];
        
        static UINT c_response_info_size;
};

#endif /* Apoxi_AtResponseIterator_hpp */

