/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(AddOns_VoiceRecognition_VrData_hpp)
#define AddOns_VoiceRecognition_VrData_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Kernel/Types.hpp>
#include <Kernel/Os/Semaphore.hpp>

#include <stack/extensions.h>

#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/Vector.hpp>

#include "VrHandler.hpp"

#define INVALID_COMMAND_ID 65535
class VrTemplate;


class VrData 
{
    
 public:

//  typedef SimpleMap<WString, Vector<UINT16> > TemplateMap;
    enum VrState {
        Undefined,
        Idle,
        Recognition,
        Training,
        Playback
    };

    static VrData* GetInstance();

    virtual ~VrData();

    static VrState GetVrState();

    static void SetVrState(VrState vr_state);


    static BOOLEAN ChangeVrState(VrState from, VrState to);
    
    static BOOLEAN IsRepeatedMode() { return FALSE; // repated mode not supported for now return m_repeated_mode; 
    }
    
    static void SetRepeatedMode(BOOLEAN repeated_mode) { m_repeated_mode = repeated_mode; }

//  static const ParamData& GetVrEngineParams() { return m_vr_engine_params; }
    
    static VrHandler::VrApiRc GetNextTemplateId(UINT16& template_id);

    static VrHandler::VrApiRc GetLastTemplateId(UINT16& template_id);

    void Reset();

    VrHandler::VrCommand GetCommand(UINT16 template_id);
    
    // Add a template to template list  
    void AddTemplate(VrTemplate* templ) { m_template_store.PushFront(templ); }    

    const UINT16* GetTemplateIdsPtr() { return m_template_ids; }

    void SetTemplateIds(const Vector<UINT16>& id_set);

//  void SetAudResource(UINT8 handle) { m_aud_resource = handle; }
    void SetPlaybackActiveRef(SharedPtr<AudioActiveReference> ref, UINT32 template_id);
    
//  UINT8 GetAudResource() { return m_aud_resource; }
    SharedPtr<AudioActiveReference> GetPlaybackActiveRef() { return m_playback_active_ref; }
    UINT32 GetPlaybackTemplateId() { return m_playback_id; }

    VrTemplate::VrFileIoRc StoreAppTemplateId(const WString& app_name, UINT16 template_id);

    VrTemplate::VrFileIoRc RemoveAppTemplateId(const WString& app_name, UINT16 template_id);
    
    VrTemplate::VrFileIoRc RemoveAllAppTemplateIds(const WString& app_name);

    void SetPendingAppName(const WString& app_name) { m_pending_app_name = app_name; };

    const WString& GetPendingAppName() { return m_pending_app_name; }

    const Vector<UINT16>& GetAppTemplateIds(const WString& app_name);

    void EmptyEngineProperties();

    const Vector<VrProperty>& GetEngineProperties() { return m_engine_properties; }
    
    void AddEngineProperty(VrProperty property) { m_engine_properties.PushBack(property); }
        
 private:

    VrData();
     
    void CleanUpTemplateList();

    VrTemplate::VrFileIoRc WriteAppTemplateData();

    VrTemplate::VrFileIoRc LoadAppTemplateData();

    void AddAppTemplateId(const WString& app_name, UINT16 template_id);
    
    VrTemplate::VrFileIoRc EraseTemplateFiles(UINT16 template_id);

    VrTemplate::VrFileIoRc EraseTemplateFile(const WString& file_name);
    
//  VrTemplate::VrFileIoRc LoadVrParameters();
    
//  VrTemplate::VrFileIoRc WriteVrParameters();

    static VrData* m_instance;
    
    static VrState m_vr_state;
    
    static BOOLEAN m_repeated_mode;

    static VrHandler::VrCommand m_fixed_commands[29];
    
    static UINT16 m_next_template_id;
    
    UINT16* m_template_ids;

//  UINT8       m_aud_resource;
    SharedPtr<AudioActiveReference> m_playback_active_ref;
    UINT32  m_playback_id;

    LinkedList<VrTemplate> m_template_store;

    SimpleMap<WString, Vector<UINT16> > m_app_templates;
//  TemplateMap m_app_templates;

    WString m_pending_app_name;
    
    Vector<VrProperty> m_engine_properties;
    
    Semaphore m_semaphore;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // AddOns_VoiceRecognition_VrData_hpp


