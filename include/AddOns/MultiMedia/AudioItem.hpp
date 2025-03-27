/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioItem_hpp)
#define Apoxi_AudioItem_hpp

#include <Auxiliary/SharedPtr.hpp>
#include <AddOns/MultiMedia/BoundedItem.hpp>
#include <Audio/AudioReference.hpp>

class AudioItem : public BoundedItem {
    typedef BoundedItem Base;

    public:
        enum {
            ID = 15
        };

        explicit AudioItem(SharedPtr<AudioReference> audio_ref);
        virtual ~AudioItem();

        virtual INT GetId() const;

        virtual XYDIM GetWidth() const;

        virtual XYDIM GetHeight() const;

        virtual void Draw(DeviceContext* dc, const Rect& bounds) const;

        SharedPtr<AudioReference> GetAudioReference() const { return m_audio_ref; }

        virtual AtomItem* Clone() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;
    
    private:
        SharedPtr<AudioReference> m_audio_ref;
};

#endif  // Apoxi_AudioItem_hpp

