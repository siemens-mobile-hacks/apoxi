/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Mmi_FmRadioStationsRecord_hpp)
#define Mmi_FmRadioStationsRecord_hpp

#include <AddOns/AdcExtensions/Record.hpp>

class FmRadioStationsRecord : public Record {
    typedef Record Base;

    public:
        FmRadioStationsRecord( UINT32 radio_freq = 0L );
 
        struct Persist {
            UINT32 radio_freq;
        } m_data;

        virtual const UINT8* GetData();
        virtual void SetData(const UINT8* data);
        virtual INT GetPersistentSize();

        void SetRadioFreq(UINT32 radio_freq) { m_data.radio_freq = radio_freq; }
        UINT32 GetRadioFreq() { return m_data.radio_freq; }
};

#endif  // Mmi_FmRadioStationsRecord_hpp
