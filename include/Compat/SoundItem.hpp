/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoundItem_hpp)
#define Apoxi_SoundItem_hpp

#include <AddOns/MultiMedia/Sound.hpp>
#include <AddOns/MultiMedia/BoundedItem.hpp>

class SoundItem : public BoundedItem {
    typedef BoundedItem Base;

    public:
        enum {
            ID = 5
        };

        explicit SoundItem(const SoundObtainer& obtainer);

        virtual ~SoundItem();

        virtual INT GetId() const;

        virtual XYDIM GetWidth() const;

        virtual XYDIM GetHeight() const;

        const SoundObtainer& GetSoundObtainer() const { return m_obtainer; }

        const Sound* GetSound() const { return m_obtainer.GetSound(); }

        virtual void Draw(DeviceContext* dc, const Rect& bounds) const;

        virtual void Play(AudioContext* ac) const;

        virtual AtomItem* Clone() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
    private:
        SoundObtainer m_obtainer;
};

#endif  // Apoxi_SoundItem_hpp


