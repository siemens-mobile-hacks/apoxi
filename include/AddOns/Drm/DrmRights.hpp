/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DrmRights_hpp)
#define Apoxi_DrmRights_hpp


#include <Auxiliary/DrmCore.hpp>

#define DRM_RIGHTS_UPDATE_REQUIRED  2
#define DRM_RIGHTS_OP_NOT_FOUND     3

class DrmConstraint : public Linkable<DrmConstraint> {
    public:
        enum Type {
            None,
            TypeCount,
            TypeDateTime,
            TypeInterval
        };

        DrmConstraint();
        DrmConstraint(Type type, INT32 max_count);
        DrmConstraint(Type type, UINT32 sec_start, UINT32 sec_end);
        DrmConstraint(Type type, UINT32 sec_interval);
        virtual ~DrmConstraint();

        Type GetType() const;

        void GetCount(INT32 *consume_count, INT32 *max_count) const;

        void GetCount(INT32 *consume_count, INT32 *max_count, INT32 *prev_count) const;

        void GetDateTime(UINT32 *sec_start, UINT32 *sec_end) const;

        void GetIntervall(UINT32 *sec_interval, UINT32 *first_consume) const ;

        void GetIntervall(UINT32 *sec_interval, UINT32 *first_consume, UINT32 *prev_consume) const ;

        void SetType(Type type);

        void SetCount(INT32 max_count);

        void SetConsumedCount(INT32 consume_count);

        void SetPrevConsumedCount(INT32 prev_consume_count);

        void SetStartDate(UINT32 sec_start);
        void SetEndDate(UINT32 sec_end);

        void SetInterval(UINT32 sec_interval);

        //
        void SetFirstConsumedInterval(UINT32 first_consume_interval);

        //
        void SetPrevFirstConsumedInterval(UINT32 prev_consume_interval);

        BOOLEAN DoesApply() const;

        INT OnContentConsumedStart();

        INT OnContentConsumedEnd();

        INT OnRollback();

    private:
        union Data {
            struct {
                INT32 m_consume_count;
                INT32 m_max_count;
                INT32 m_prev_consume_count;
            } m_count_constraint;

            struct {
                UINT32 m_sec_start;
                UINT32 m_sec_end;
                // place holder for nothing
                UINT32 m_prev_placeholder;
            } m_datetime_constraint;

            struct {
                UINT32 m_sec_intervall;
                UINT32 m_first_consume;
                UINT32 m_prev_first_consume;
            } m_intervall_constraint;
        };

        Type m_type;
        Data m_data;

        INT OnContentConsumed();
};

class DrmPermission : public Linkable<DrmPermission> {
    public:

        DrmPermission();
        virtual ~DrmPermission();

        DrmOperation GetOpType() const;

        INT GetConstraintsCount() const;

        const DrmConstraint& GetConstraint(INT index) const;

        BOOLEAN SetOpType(DrmOperation op);

        BOOLEAN AddConstraint(const DrmConstraint &constraint);

        BOOLEAN IsAllowed() const;

        INT OnContentConsumedStart();

        INT OnContentConsumedEnd();

        INT OnRollback();

        BOOLEAN GetDateConstraint(UINT32 &start_date, UINT32 &end_date);
        BOOLEAN GetIntervalConstraint(UINT32 &start_consume, UINT32 &max_consume);
        BOOLEAN GetCountConstraint(INT32 &consume_count, INT32 &max_count);

        void SetConstraintDefaultValue(DrmConstraintDefValues def_constraints) { m_def_constraints = def_constraints; }

        DrmConstraintDefValues GetConstraintDefaultValue() const { return m_def_constraints;}

    private:
        DrmOperation m_op;
        DrmConstraintDefValues m_def_constraints;
        //BOOLEAN m_no_constraints;
        // Collection of constraints on a permission
        Vector<DrmConstraint> m_constraint;
};

class DrmRightsObject {
    public:

        DrmRightsObject();
        ~DrmRightsObject();

        DrmLocalId GetLocalId() const;

        DrmMimeType GetDrmMimeType() const;

        // Return the media object MIME type
        MimeType GetMoMimeType() const;

        const DrmUid& GetUid() const;

        BOOLEAN GetKey(UINT8* key) const;

        INT GetPermissionsCount() const;

        DrmPermission& GetPermission(INT index);

        DrmPermission* GetPermission(DrmOperation op) ;

        void SetLocalId(DrmLocalId local_id);

        void SetMimeType(DrmMimeType mime_type);

        void SetMoMimeType(MimeType mime_type);

        void SetUid(const DrmUid &uid);

        void SetKey(const DrmKey &key);

        UINT8 GetRefCount()
        {
            return m_ref_count ;
        }

        void SetRefCount(UINT8 count)
        {
            m_ref_count = count ;
        }

        BOOLEAN AddPermission(const DrmPermission &perm);

        BOOLEAN IsAllowed(DrmOperation op) const;

        INT OnContentConsumedStart(DrmOperation op);

        INT OnContentConsumedEnd(DrmOperation op);

        INT OnRollback(DrmOperation op);

        INT IsConstraintAvailable(DrmOperation op);
        BOOLEAN GetDateConstraint(DrmOperation op, UINT32 &start_date, UINT32 &endDate);
        BOOLEAN GetIntervalConstraint(DrmOperation op, UINT32 &start_consume, UINT32 &max_consume);
        BOOLEAN GetCountConstraint(DrmOperation op, INT32 &consume_count, INT32 &max_count);

    private:
        DrmLocalId m_local_id;
        DrmMimeType m_mime_type;
        MimeType m_mo_mime_type;
        DrmUid m_uid;
        DrmKey m_key;
        UINT8 m_ref_count;

        // Collection of permissions for this rights object
        Vector<DrmPermission> m_perm;   
};

#endif // Apoxi_DrmRights_hpp

