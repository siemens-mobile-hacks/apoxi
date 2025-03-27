/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_GLTP_AidDataRequests_hpp)
#define AddOns_Lcs_GLTP_AidDataRequests_hpp

class GltpRequest
{
    public:

        enum { HEADER_SIZE = 14 };

        virtual ~GltpRequest();
        
        virtual const BYTE* GetRequest() const = 0;

        virtual INT GetSize() const = 0;

        static UINT16 GetUnitId() { return m_unit_id; }


    protected:

        GltpRequest();

        BYTE* FillHeader(BYTE* buffer, UINT32 tag, UINT16 data_length);


    protected:

        static UINT16 m_unit_id;

}; // GltpRequest


class GltpHelloRequest : public GltpRequest
{
    typedef GltpRequest Base;

    public:

        GltpHelloRequest();
        
        virtual ~GltpHelloRequest();

        virtual const BYTE* GetRequest() const { return m_hello_req; }

        virtual INT GetSize() const { return HELLO_REQ_SIZE; }

        void FormRequest(UINT16 unit_id);


    private:

        enum
        {
            HELLO_DATA_SIZE = 18,
            HELLO_REQ_SIZE = Base::HEADER_SIZE + HELLO_DATA_SIZE
        };

        BYTE m_hello_req[HELLO_REQ_SIZE];

}; // GltpHelloRequest


class GltpAidingRequest : public GltpRequest
{
    typedef GltpRequest Base;

    public:
    
        GltpAidingRequest();

        virtual ~GltpAidingRequest();

        virtual const BYTE* GetRequest() const { return m_aid_req; }

        virtual INT GetSize() const { return AID_REQ_SIZE; }

        void FormRequest(INT32 init_lat, INT32 init_long, BOOLEAN ms_mode);


    private:

        enum
        {
            AIDING_REQ_LEN = 18,
            AID_REQ_SIZE = Base::HEADER_SIZE + AIDING_REQ_LEN
        };

        BYTE m_aid_req[AID_REQ_SIZE];

}; // GltpAidingRequest


class MeasurementData;
class GltpMsmtRequest : public GltpRequest
{
    typedef GltpRequest Base;

    public:

        GltpMsmtRequest();

        virtual ~GltpMsmtRequest();
        
        virtual const BYTE* GetRequest() const { return m_msr_req; }

        virtual INT GetSize() const { return m_size; }

        void FormRequest(const MeasurementData& msr_data);

        
    private:

        BYTE* m_msr_req;

        INT m_size;

}; // GltpMsmtRequest


class GltpPositionRequest : public GltpRequest
{
    typedef GltpRequest Base;

    public:

        GltpPositionRequest();

        virtual ~GltpPositionRequest();

        virtual const BYTE* GetRequest() const { return m_posn_req; }

        virtual INT GetSize() const { return POSN_REQ_SIZE; }

        void FormRequest(BYTE* posn_data);


    private:
    
        BYTE* EncodePositionValue(UINT32* posn_data, BYTE* posn_value);


    private:

        enum
        {
            POSN_DATA_SIZE = 84,
            POSN_REQ_SIZE = Base::HEADER_SIZE + POSN_DATA_SIZE
        };

        BYTE m_posn_req[POSN_REQ_SIZE];

}; // GltpPositionRequest


class GltpAidDataRequests
{
    public:

        GltpAidDataRequests();

        ~GltpAidDataRequests();

        // 'Hello' request to be sent to the GL server
        void SetUnitId(UINT16 unit_id);
            
        void FormAidingRequest(INT32 init_lat, INT32 init_long, BOOLEAN ms_mode);
        
        void FormPosnRequest(BYTE* posn_data);
        
        void FormMsmtRequest(const MeasurementData& msr_data);
        
        const GltpHelloRequest& GetHelloRequest() const { return m_hello_req; }

        const GltpAidingRequest& GetAidingRequest() const { return m_aid_req; }

        const GltpPositionRequest& GetPosnRequest() const { return m_posn_req; }

        const GltpMsmtRequest& GetMsmtRequest() const { return m_msmt_req; }


    private:

        GltpHelloRequest m_hello_req;

        GltpAidingRequest m_aid_req;

        GltpPositionRequest m_posn_req;

        GltpMsmtRequest m_msmt_req;

}; // GltpAidDataRequests

#endif // AddOns_Lcs_GLTP_AidDataRequests_hpp

