/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TimeFeatureObject_hpp)
#define Apoxi_TimeFeatureObject_hpp

#include <Auxiliary/GenericObject.hpp>

class TimeFeatureObject// : public GenericObject
{
    public:
        TimeFeatureObject();

        TimeFeatureObject(const TimeFeatureObject &obj);

        static const GenericTypeId  c_time_feature_object_id;

        virtual ~TimeFeatureObject();

        virtual TimeFeatureObject * Copy() const;
        virtual BOOLEAN         IsEqual(TimeFeatureObject * object);
        virtual GenericTypeId   GetTypeId();

        UINT32 GetTimeStamp() const;

        INT32 GetChannelId() const;
        
        void SetTimeStamp(UINT32 time);
        
        void SetChannelId(INT32 channel);

    protected:
        UINT32 m_time;
        
        INT32 m_channel;
};
#endif // Apoxi_TimeFeatureObject_hpp

