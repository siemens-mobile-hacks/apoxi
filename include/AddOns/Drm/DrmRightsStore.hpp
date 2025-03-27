/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DrmRightsStore_hpp)
#define Apoxi_DrmRightsStore_hpp


#include <Auxiliary/DrmCore.hpp>
#include <AddOns/Drm/DrmRights.hpp>
#include <AddOns/Drm/DrmSubsystem.hpp>

//************************* DEBUG
//#define       DRM_FFS_BYPASS

#define     DRM_FL_LOCAL_ID         APOXI_DRM_RIGHTS_OBJECT_MAX+1
#define     DRM_RO_FILE_PREFIX      "adrm"

class FlsFile;

class DrmRightsObjectContainer {
    public:
        INT GetCount() const;

        DrmRightsObject& GetRightsObject(INT i);

        void AddRightsObject(const DrmRightsObject& rights_obj);

        BOOLEAN IsAllowed(DrmOperation op);

        BOOLEAN OnContentConsumedStart(DrmOperation op);

        BOOLEAN OnContentConsumedEnd(DrmOperation op);

        BOOLEAN OnRollback(DrmOperation op);

        BOOLEAN IsDrmOpValid(DrmOperation op, MimeType mo_type) const;

    private:
        Vector<DrmRightsObject> m_rights;

        static DrmSubsystem drm_subsys;
};

class DrmRightsObjectFile {
    public:
        static BOOLEAN Create(const CHAR* ro_file_path, DrmRightsObject& rights_obj);

        static BOOLEAN Update(const CHAR* ro_file_path, DrmRightsObject& rights_obj);

        static BOOLEAN GetRightsObject(const CHAR* ro_file_path, DrmRightsObject& rights_obj);

        static BOOLEAN Delete(const CHAR* ro_file_path);

        static BOOLEAN WriteRightsObject(FlsFile& fp, DrmRightsObject& rights_obj);

        static UINT32 ReadROHeaderInfo(FlsFile& ro_file, DrmLocalId& id, DrmUid& uid);

        static BOOLEAN ReadRightsObject(FlsFile& fp, DrmRightsObject& rights_obj);

#ifdef DRM_FFS_BYPASS

        static BOOLEAN WriteRightsObject_debug(FILE* fp, DrmRightsObject& rights_obj);
        static BOOLEAN ReadRightsObject_debug(FILE* fp, DrmRightsObject& rights_obj);
#endif
    private:
        static INT DrmGetRightsObjectSize(DrmRightsObject &rights_obj);
};

struct DrmRightsMapTableEntry {
    BOOLEAN         m_is_valid;         // Validity flag
    DrmLocalId      m_local_id;         // Local ID
    String          m_uid;              // UID : Note : We could store a hash instead
    Vector<String>  m_ro_file_paths;    // Rights Object File Path(s)
};

class DrmRightsObjectStore {
    public:
        DrmRightsObjectStore();
        void InitRightsObjectMapTable( void );

        DrmLocalId GetNextLocalId(void);

        BOOLEAN IsLocalIdValid(DrmLocalId local_id);

        DrmLocalId MapUidToLocalId(const DrmUid &uid);

        DrmUid MapLocalIdToUid(DrmLocalId id);

        BOOLEAN GetDrmRights(const DrmLocalId &id, DrmRightsObjectContainer& ro_container);

        DrmLocalId AddRightsObject(DrmRightsObject &ro);

        BOOLEAN UpdateRightsObject(DrmRightsObject &ro, INT r_index);

        BOOLEAN DeleteRightsObject(DrmLocalId id);

#ifdef DRM_RO_DEBUG
        void DebugDump(String& debug_info);
#endif

    private:
        BOOLEAN FillMapFromFile(const CHAR* ro_file_path);

        BOOLEAN GenerateFileName(DrmLocalId id, String& file_name);

        // Rights object table map -- for easy access of information
        // Element 0 corresponds to invalid rights
        // Element APOXI_DRM_RIGHTS_OBJECT_MAX+1 corresponds to FL
        // Hence we need to declare the array as APOXI_DRM_RIGHTS_OBJECT_MAX+2
        DrmRightsMapTableEntry  m_ro_map_table[APOXI_DRM_RIGHTS_OBJECT_MAX+2];
        static const UINT       m_max_map;
        BOOLEAN                 bInitDone;
};

class DrmROStoreSingleton
{
public:
    static DrmRightsObjectStore* Instance()
    {
        if (m_instance == NULL) m_instance = new DrmRightsObjectStore;

        ASSERT(m_instance != NULL);

        return m_instance;
    }

    static void DestroyInstance()
    {
        delete m_instance;
        m_instance = NULL;
    }

protected:
    DrmROStoreSingleton()
    {
    }

    virtual ~DrmROStoreSingleton()
    {
    }

private:
    // Copy constructor.
    DrmROStoreSingleton(const DrmROStoreSingleton& source)
    {
    }

    static DrmRightsObjectStore* m_instance; 
};

typedef DrmROStoreSingleton DrmROStore;


#endif // Apoxi_DrmRightsStore_hpp

