/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MultiMedia_Melody_hpp)
#define MultiMedia_Melody_hpp

#include <Devices/Device.hpp>
#include <AddOns/MultiMedia/Sound.hpp>

class Melody : public Sound
{
    typedef Sound Base;
    public:
        Melody(BOOLEAN copyrighted = FALSE);        

        virtual ~Melody();

        void Init(BOOLEAN copyrighted = FALSE);

        virtual const WCHAR* GetName() const;

        virtual BOOLEAN Play(AudioContext* context);

        virtual Audio::ToneData* GetToneData();
    
        virtual void SetCopyright(BOOLEAN state);

        virtual BOOLEAN IsCopyrighted() const;

    protected:
        void SetName(const WCHAR* name) { m_name = name; }
        
    private:
        BOOLEAN m_copyrighted;
        WString m_name;
};

#endif // MultiMedia_Melody_hpp


