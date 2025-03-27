/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractDevice_hpp)
#define Apoxi_AbstractDevice_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>

class AbstractDevice {
    public:
        enum Category {
            DisplayCategory = 0,
            StillCameraCategory = 1,
            VideoCameraCategory = 2,
            KeyboardCategory = 3,
            LedCategory = 4,
            ChargerCategory = 5,
            RealTimeClockCategory = 6,
            CodecCategory = 7,
            CustomCategory = 100
        };

        union ControlArg { 
            ControlArg() {};
            ControlArg(BOOLEAN val) {m_boolean = val;}
            ControlArg(UINT8 val) {m_uint8 = val;}
            ControlArg(INT8 val) {m_int8 = val;}
            ControlArg(UINT16 val) {m_uint16 = val;}
            ControlArg(INT16 val) {m_int16 = val;}
            ControlArg(UINT32 val) {m_uint32 = val;}
            ControlArg(INT32 val) {m_int32 = val;}
            ControlArg(CHAR* val) {m_char_ptr = val;}
            ControlArg(WCHAR* val) {m_wchar_ptr = val;}
            ControlArg(void* val) {m_void_ptr = val;}

            BOOLEAN m_boolean;
            UINT8 m_uint8;
            INT8 m_int8;
            UINT16 m_uint16;
            INT16 m_int16;
            UINT32 m_uint32;
            INT32 m_int32;
            CHAR* m_char_ptr;
            WCHAR* m_wchar_ptr;
            void* m_void_ptr;
        };

        explicit AbstractDevice(INT category = CustomCategory, INT index = 0);

        virtual ~AbstractDevice();

        virtual const WCHAR* GetName() const = 0;

        INT GetCategory() const { return (INT)m_category; }

        INT GetIndex() const { return (INT)m_index; }

        ControlArg Control(INT command, ControlArg arg);

    protected:
        virtual void OnStart();

        virtual void OnStop();

    private:
        UINT8 m_category;
        UINT8 m_index;
        AbstractDevice* m_next;

        AbstractDevice(const AbstractDevice& device);

        AbstractDevice& operator=(const AbstractDevice& device);

        friend class DeviceManager;             // reads and adjusts m_next property
};

#endif  // Apoxi_Device_hpp

