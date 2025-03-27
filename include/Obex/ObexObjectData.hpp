/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexObjectData_hpp)
#define Apoxi_ObexObjectData_hpp

#include <Kernel/Os/Semaphore.hpp>
#include <Auxiliary/ObjectReferrer.hpp>

#include <Obex/ObexBuffer.hpp>
#include <Obex/ObexObject.hpp>

class ObexObjectData : public ReferableObject {

    friend class ObexObject;

    public:
        typedef ReferableObject Base;

    private:
        class LockObtainer : public NonCloneable {
            public:
                LockObtainer();

            private:
                // Place to hold a mutex - or semobtainer
                static Semaphore        s_sem;
                SemObtainer             m_lock_obtainer;

                static  Semaphore *     GetLock();
        };

        BOOLEAN                     m_end_of_data;  
        UINT8                       m_req_flags;    
        ObexObject::ResponseCode    m_resp_code;    
        ObexHeaderList              m_header_list;  
        ObexBuffer                  m_buffer;       

        ObexObjectData(ObexObject::ResponseCode     response_code);

        ObexObjectData(ObexObject::ResponseCode     response_code,
                       ObexBuffer &                 source_buffer);

        static ObexObjectData * Init(ObexObjectData *           obj_data_ptr,
                                     ObexObject::ResponseCode   response_code);

        static ObexObjectData * Init(ObexObjectData *           obj_data_ptr,
                                     ObexObject::ResponseCode   response_code,
                                     ObexBuffer &               source_buffer);
        virtual void    AddRef() const;
        virtual void    Release() const;

        UINT32          GetDataFractionSize() const;

        void            SetBuffer(ObexBuffer &  source_buffer);
        BOOLEAN         GetBuffer(ObexBuffer &  target_buffer);

        void    SetResponseCode(ObexObject::ResponseCode    response_code);
        void    SetRequestFlags(UINT8                       request_flags);
        void    SetEndOfData(BOOLEAN                        end_of_data);

        inline  BOOLEAN                     HasSingleReferrer() const;

        inline  const ObexHeaderList &      GetHeaderList() const;
        inline  ObexHeaderList &            GetHeaderList();

        inline  ObexObject::ResponseCode    GetResponseCode() const;
        inline  UINT8                       GetRequestFlags() const;
        inline  BOOLEAN                     IsEndOfData() const;
};

/*  ----------------------------------------------------------------------
    HasMultipleReferrers
    ---------------------------------------------------------------------- */
BOOLEAN     ObexObjectData::HasSingleReferrer()
const
{
    return ( RefCount() == 1 );
}

/*  ----------------------------------------------------------------------
    GetHeaderList
    ---------------------------------------------------------------------- */
ObexHeaderList const &  ObexObjectData::GetHeaderList()
const
{
    return  m_header_list;
}


/*  ----------------------------------------------------------------------
    GetHeaderList
    ---------------------------------------------------------------------- */
ObexHeaderList &    ObexObjectData::GetHeaderList()
{
    return  m_header_list;
}

/*  ----------------------------------------------------------------------
    GetResponseCode
    ---------------------------------------------------------------------- */
ObexObject::ResponseCode    ObexObjectData::GetResponseCode()
const
{
    return  m_resp_code;
}

/*  ----------------------------------------------------------------------
    GetRequestFlags
    ---------------------------------------------------------------------- */
UINT8       ObexObjectData::GetRequestFlags()
const
{
    return  m_req_flags;
}

/*  ----------------------------------------------------------------------
    IsEndOfData
    ---------------------------------------------------------------------- */
BOOLEAN     ObexObjectData::IsEndOfData()
const
{
    return  m_end_of_data;
}

#endif  // Apoxi_ObexObjectData_hpp

