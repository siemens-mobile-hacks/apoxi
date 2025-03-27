/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class Fota {
#endif
    public:
        virtual ~Fota();

        virtual const WCHAR* GetName() const;

        static ControlArg Control(INT command, ControlArg arg);

        static INT InitiateFirmwareUpdate(BOOLEAN force = TRUE);

        static INT ReadMetaData(UINT32 offset, void* buffer, UINT32 size);

        static INT WriteMetaData(UINT32 offset, const void* buffer, UINT32 size);

        static UINT32 GetMetaDataCapacity();

    private:
        friend class ShutDown;
        
        static Fota m_fota;

        Fota();
        static void RebootSystem();

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

