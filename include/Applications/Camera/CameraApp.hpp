#if !defined(Mmi_CameraApp_hpp)
#define Mmi_CameraApp_hpp

#include <Kernel/Lib.hpp>
#include <AddOns/MultiMedia/JpegImage.hpp>
#include <Common/MmiApplication.hpp>  
#include <Common/MmiServices.hpp>
#include <Camera/CameraViewFinderWin.hpp>


#define MAX_INDEX_FILE_SINK_ARRAY (0)

class CameraCaptureWin;

class CameraApp : public MmiApplication, public CameraService
{
    typedef MmiApplication Base;

    enum CameraPicAdjType 
    {
        DOWN = -1,
        UP = 1
    };

    enum FeatureIds {
        CamOpenViewfinder,  //open the viewfinder window "OpenViewfinder"
        CamZoomIn,
        CamZoomOut,
        CamNextSetting,
        CamPrevSetting,
        CamNextOption,
        CamPrevOption,
        CamIncrBrightness,
        CamDecrBrightness,
        CamClickPhoto,
        CamSelectOption,
        CamTimerToggle,
        CamFlashToggle,
        CamSettingsModeToggle,
        CamFeatureCnt
    };

    enum PropertyIds {
        CamMultishot,       //Select the number of multishot photos to be taken "Multishot"
        CamResolution,      //Set the camera resolution (set)   "Resolution"
        CamWhiteBalance,    //set the white balance (set)   "WhiteBalance"
        CamColourFilter,    //set the colour    (set?)  "ColourFilter"
        CamAntiFlicker,
        CamTransform,
        CamTimer,           //store the amount of time before the photo is taken "Timer"
        CamFlash,           //Store the Flash settings
        CamTwilight,        //Store the Twilight settings
        CamTimerEnable,     //checkbox to enable/disable the timer feature "TimerEnable"
        CamFlashEnable,     //checkbox to enable/diable the flash
        CamTwilightEnable,  //checkbox to enable/diable Twilight
        CamContrast,        //set the contrast  (progress) "Contrast"
        CamJPEGQuality,     //set the JPEG quality (set) "JPEGQuality"
        //CamShutterTone,   //select the sound to be played when the photo is taken "ShutterTone"
        CamPropertyCnt  
    };

    CameraViewFinderWin     m_cameraviewfinder_window;  //instance of the viewfinder window
    CameraSettings          m_camerasettings_object;

    static CameraApp        m_camera_app;   //static instance of the camera application
    UINT                    m_current_camera_idx;
    BOOLEAN                 m_settings_mode_enabled;

    StillCamera*            m_camera_ref;
    DataSink*               m_File_Sink_Array[MAX_INDEX_FILE_SINK_ARRAY+1]; 
    JpegImage               m_jpeg_image;

    UINT8                   m_current_selected_setting; //for properties 0 - 4
    UINT8                   m_current_selected_option;

    Feature m_items[CamFeatureCnt];
    Property m_property[CamPropertyCnt];

    public:
        static CameraApp* GetInstance();

        StillCamera* GetCameraReference();

        void LoadCameraSettings();

        virtual ~CameraApp();

        static void cb_image_captured(INT result, void* context, UINT16 frame);   
        static void cb_image_encoded(INT result, void* context, UINT16 frame);    
        static void cb_capture_finished(INT result, void* context, UINT16 frame); 

    protected:
        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification, 
                                               const Property* property, 
                                               const DataItem& value);

        virtual void OnOpen();
        
        virtual void OnClose();

        virtual BOOLEAN OnMessage(const Message &msg);

        virtual void OnStartup();

    private:
        CameraApp(const WCHAR* app_name);

        virtual ServiceResult CaptureImage(ImageObtainer &);

        BOOLEAN GetCurrentJpegImage(JpegImage *pjpeg_image);

        BOOLEAN SavePicture();

        //New capture related funcs
        void ResetFileSink();
        BOOLEAN FillDataSinkObjects();
        BOOLEAN OpenAllFiles();
        void SetPreCaptureImageSize();
        BOOLEAN FreezePicture();
        void FreeDataSinkMemory();

        //Viewfinder functions
        void SetViewfinderSettingModeText();

        PropertyIds MatchPropertyString(const FeatureID &id);

        BOOLEAN SetCameraDeviceProperty(PropertyIds id, DataItem value);
        BOOLEAN ToggleFlash(const DataItem& value);
        BOOLEAN ToggleTwilight(const DataItem& value);
};
#endif  // Mmi_CameraApp_hpp
