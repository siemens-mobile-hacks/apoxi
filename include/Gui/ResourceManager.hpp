/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ResourceManager_hpp)
#define Apoxi_ResourceManager_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/Types.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Gui/ResourceReader.hpp>

class ResourceManager {
    
    public:     
        ~ResourceManager();

        static const WCHAR c_uri_separator;
        static const WCHAR c_nvp_separator;

        static ResourceManager& GetInstance();

        void* Construct(const WString& uri, 
                        UINT16* top_object_id = 0,
                        GuiObjectFactory::ClassType* top_object_classtype = 0);

        void* Construct(const WString& uri, 
                        BinData* data, 
                        ResourceReader::DataType data_type,
                        UINT16* top_object_id = 0,
                        GuiObjectFactory::ClassType* top_object_classtype = 0);

        void* GetFromObjectPool(ResourceParser& parser,
                                const GuiObjectDescr& descr,
                                GuiObjectDescr* returned_object_descr);

        BOOLEAN Destruct(const WString& uri,
                         void* object = 0);

        BOOLEAN Destruct(void* object);

        void DestructAll();

        void* GetObject(const WString& uri, 
                        INT id, 
                        void* object = 0,
                        GuiObjectFactory::ClassType* class_type = 0);

        ChildBinData* GetData (const WString& uri_in_ctd, 
                               const WString& resource_uri,
                               ResourceReader::DataType* data_type = 0);

        BOOLEAN GetDataType(const WString& uri, ResourceReader::DataType& type);

        INT GetFileEntryCount(const WString& uri);

        BOOLEAN GetDataInfoByIndex(const WString& uri, 
                                   UINT16 idx, 
                                   UINT16& id, 
                                   ResourceReader::DataType& type);

        INT GetFileVersion(const WString& uri);

        BOOLEAN IsResourceFile(const WString& uri, const WString& device_id = L"rfs");


        BOOLEAN AddObject(const WString& uri, 
                          const GuiObjectDescr& descriptor, 
                          void* instance = 0);

        BOOLEAN SetObjectUntreated(const WString& uri, 
                                   void* instance, 
                                   GuiObjectFactory::ClassType class_type, 
                                   GuiObjectFactory::PropertyId prop_id, 
                                   UINT16 comp_id);

// old ArmCC versions can't compile these private structs. If it's such an old version, 
// make the structs public. If it's a new version, or we're not using ArmCC at all, 
// make them private.
#ifdef __ARMCC_VERSION
    #if (__ARMCC_VERSION>=200000)                   
        private:
    #endif
#else
        private:
#endif

        struct GuiObject {
            INT m_id;
            GuiObjectFactory::ClassType m_class_type;
            void* m_instance;
        };

        struct UntreatedGuiObject {
            void* m_instance;
            GuiObjectFactory::ClassType m_class_type;
            GuiObjectFactory::PropertyId m_prop_id; // property that needs to be treated
            UINT16 m_comp_id; // id of component that needs to be set
        };

        struct Instance {
            Vector<GuiObject> m_objects;    // objects created from description
            Vector<UntreatedGuiObject> m_untreated_objects;
        };

        struct CtdResource {
            UINT16 m_resource_id;   // id in resource file
            Vector<Instance> m_instances;
        };                                 
                                   

    private:
        static BOOLEAN m_is_initialized;
        
        static Mutex m_mutex;

        static WString m_objectpool_uri;

        struct ResourceFile {
            WString m_uri;
            ResourceReader* m_reader;
            Vector<CtdResource> m_resources;
        };

        Vector<ResourceFile> m_files;

        INT m_cur_res_idx;
        INT m_cur_instance_idx;
        WString m_cur_construction_uri;
        
        ResourceManager();

        ResourceManager(const ResourceManager& obj);
        
        void Init();

        BOOLEAN Destruct(INT16 file_idx, 
                         INT16 res_idx, 
                         INT16 instance_idx = -1,
                         BOOLEAN force = FALSE);

        BOOLEAN CleanupFile(INT16 file_idx);

        BOOLEAN Finalize(const WString& uri,
                         INT16 file_idx,
                         INT16 res_idx,
                         INT16 instance_idx);

        void* GetFromObjectPoolI(const WString& uri,
                                 INT id, 
                                 GuiObjectDescr* returned_object_descr);
        
        INT16 GetFileIndex(const WString& uri);

        INT16 GetResourceIndex(const WString& uri,
                               INT16& instance_idx,
                               void* object = 0);
        
        UINT16 OpenFile(const WString& uri);
        
        WString GetAbsoluteUri(const WString& uri, 
                               const WString& resource_uri);

        WString RemoveIdFromUri(const WString& uri);

        BOOLEAN GetIdFromUri(const WString& uri, UINT16& id);

        BOOLEAN IsRelativeUri(const WString& uri);

        WString GetTypeCorrectedUri(const WString& uri);

        BufferedData* ReadFileFromHostFileSystem(const WString& uri);
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_ResourceManager_hpp

