/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Mmi_FmRadioSettingsRecord_hpp)
#define Mmi_FmRadioSettingsRecord_hpp

#include <AddOns/AdcExtensions/Record.hpp>

class FmRadioSettingsRecord : public Record {
    typedef Record Base;

    public:
        FmRadioSettingsRecord( UINT8 radio_last_volume,
                                    UINT32 radio_last_freq );

        FmRatioSettingsRecord();    //added for restore factory settings
        void SetDefault();          //added for restore factory settings
         
        struct Persist {
            UINT8 radio_last_volume;
            UINT32 radio_last_freq;
        } m_data;

        virtual const UINT8* GetData();
        virtual void SetData(const UINT8* data);
        virtual INT GetPersistentSize();

        void SetRadioLastVolume(UINT8 radio_last_volume) { m_data.radio_last_volume = radio_last_volume; }
        UINT8 GetRadioLastVolume() { return m_data.radio_last_volume; }

        void SetRadioLastFreq(UINT32 radio_last_freq) { m_data.radio_last_freq = radio_last_freq; }
        UINT32 GetRadioLastFreq() { return m_data.radio_last_freq; }
};

#endif  // Mmi_FmRadioSettingsRecord_hpp
