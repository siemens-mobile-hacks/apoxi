/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_BtHfRecord_hpp)
#define Mmi_BtHfRecord_hpp

#include <AddOns/AdcExtensions/Record.hpp>
#include <Devices/Device.hpp>


class BtHfRecord : public Record {
    typedef Record Base;
    public:
        BtHfRecord(
            BOOLEAN phone_audio_path = FALSE);
        
        ~BtHfRecord() { };

        virtual const UINT8* GetData();
        virtual void SetData(const UINT8* data);
        virtual INT GetPersistentSize();
#if 0

        void SetAudioPath(BOOLEAN phone_path) { m_data.audio_at_phone = phone_path; }
        BOOLEAN GetAudioPath() { return (BOOLEAN)m_data.audio_at_phone; }
        private:
#endif

        struct Persist {
            BOOLEAN audio_at_phone;
        } m_data;

};

#endif  // Mmi_BtHfRecord_hpp
