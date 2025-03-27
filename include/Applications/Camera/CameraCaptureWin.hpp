#if !defined(Mmi_CameraCaptureWin_hpp)
#define Mmi_CameraCaptureWin_hpp

#include <Common/CommonMsgTypes.hpp>
#include <Camera/CameraApp.hpp>

#include <Auxiliary/RamData.hpp>
#include <AddOns/AfsRam/RamDataSink.hpp>
#include <Afs/Rfs/FileBinData.hpp>

#define MAX_INDEX_FILE_SINK_ARRAY (0)

class CameraCaptureWin : public MmiWindow
{
    typedef MmiWindow Base;

public:
    virtual void Init(CameraApp *pcamera_app);
    BOOLEAN CancelCamera(INT status); //HaJo 29.08.2005
            
        static void cb_image_captured(INT result, void* context, UINT16 frame);   //HaJo
        static void cb_image_encoded(INT result, void* context, UINT16 frame);    //HaJo
        static void cb_capture_finished(INT result, void* context, UINT16 frame); //HaJo

protected:
    virtual void OnOpen();
    virtual void OnClose();
    virtual void OnLoseFocus();
    virtual void OnGetFocus();
    virtual void OnPaint(const Rect& repaint_rect);
        virtual BOOLEAN OnMessage(const Message &msg);
        
        Path    GetNewPath(Pathname  &path_name_1, WString &deviceIdStr) const;
    
    StillCamera*            m_camera;   //HaJo
    UINT            m_current_camera_idx;
    
    BOOLEAN                 m_camera_capture_canceling; //HaJo 29.08.2005
    
    DataSink*           m_File_Sink_Array[MAX_INDEX_FILE_SINK_ARRAY+1]; 

    CameraApp*      m_pcamera_app;  
    JpegImage           m_jpeg_image;
};

#endif //Mmi_CameraCaptureWin_hpp
