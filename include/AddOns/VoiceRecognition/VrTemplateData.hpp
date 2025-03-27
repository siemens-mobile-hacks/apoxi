/*-----------------------------------------------------------------------
  Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
  -----------------------------------------------------------------------
  This document contains proprietary information belonging to COMNEON.
  Passing on and copying of this document, use and communication of its
  contents is not permitted without prior written authorisation.
  ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(AddOns_VoiceRecognition_VrTemplateData_hpp)
#define AddOns_VoiceRecognition_VrTemplateData_hpp

#include <Kernel/Types.hpp>

/* ========================================================================
   VrTemplateData
   ======================================================================== */
class VrTemplate : public Linkable<VrTemplate>
{

public:
    enum VrFileIoRc {
        Success,
        FileNotExists,
        WrongFileSize,
        ReadTooLess,
        FileExists,
        FileNotCreated,
        WriteError,
        MemoryProblem,
        DeleteError
    };

    VrTemplate(UINT16 template_id, const WString& device_id = L"ffs");


    VrTemplate(UINT16 template_id, const UINT16* template_data, UINT32 size, const WString& device_id = L"ffs");

    virtual ~VrTemplate();


    const UINT16* GetTemplatePtr();

    VrFileIoRc GetInitResult() { return m_init_result; }
    
    virtual VrFileIoRc StoreTemplate();

    UINT16 GetTemplateId() { return m_template_id;  }

    const WString& GetDeviceId() { return m_device_id; }

protected:

    VrTemplate(const UINT16* template_data);
    
    void SetInitResult(VrFileIoRc init_result) { m_init_result = init_result; }
    

    VrTemplate::VrFileIoRc SetData(UINT32 size, const UINT16* template_data);

    VrFileIoRc LoadFromFile(const WString& filename, UINT16*& data, UINT32& size);

    VrFileIoRc SaveToFile(const WString& filename, const UINT16* data, UINT32 size);

private:

    VrFileIoRc LoadTemplate(const WString& device_id, UINT16 template_id);
    
    UINT16      m_template_id;
    UINT32      m_size;
    UINT16*     m_data;
    WString     m_device_id;

    VrFileIoRc  m_init_result;
};

/* ========================================================================
   VrTrainedTemplateData
   ======================================================================== */
class VrTrainedTemplate : public VrTemplate
{

    typedef VrTemplate Base;
public:


    VrTrainedTemplate(UINT16 template_id, const UINT16* template_data, UINT32 template_size, const UINT8* sample_buffer, UINT32 sample_size, const WString& device_id = L"ffs");

    VrTrainedTemplate(UINT16 template_id, const WString& device_id = L"ffs");

    virtual ~VrTrainedTemplate();

//  VrFileIoRc PlayTemplate();


    VrFileIoRc GetAudioFileName(WString& file_name);

protected:


    VrTemplate::VrFileIoRc SetSampleData(UINT16 template_id, const WString& device_id, UINT32 sample_size, const UINT8* sample_data);

private:
//  VrTemplate::VrFileIoRc LoadSamples(const WString& device_id, UINT16 template_id);

    UINT32      m_sample_size;
};
#endif  // AddOns_VoiceRecognition_VrTemplateData_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS

