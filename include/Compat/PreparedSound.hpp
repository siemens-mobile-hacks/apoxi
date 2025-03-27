/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MultiMedia_PreparedSound_hpp)
#define MultiMedia_PreparedSound_hpp

#include <Devices/Device.hpp>
#include <AddOns/MultiMedia/Sound.hpp>

class PreparedSound : public Sound {
    typedef Sound Base;
    public:
        enum {
            ID = 1
        };

        PreparedSound();    

        PreparedSound(const WCHAR* name);
        
        virtual ~PreparedSound();

        void Init(const WCHAR* name);

        void SetToneId(Audio::AudioToneId tone_id) { m_tone_id = tone_id; }

        Audio::AudioToneId GetToneId() const { return m_tone_id; }

        void SetRepeatCount(INT times) { m_times = times; }

        INT GetRepeatCount() const { return m_times; }

        virtual INT GetId() const;

        void SetName(const WCHAR* name) { m_name = name; }

        virtual const WCHAR* GetName() const;

        virtual BOOLEAN Play(AudioContext* context);

    private:
        Audio::AudioToneId  m_tone_id;
        INT                 m_times;
        const WCHAR         *m_name;
};

#endif // MultiMedia_PreparedSound_hpp


