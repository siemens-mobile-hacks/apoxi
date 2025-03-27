/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MultiMedia_MidiSound_hpp)
#define MultiMedia_MidiSound_hpp

#include <Auxiliary/BinData.hpp>
#include <AddOns/MultiMedia/Melody.hpp>

class MidiSound : public Melody {
    typedef Melody Base;

    public:
        enum {
            ID = 3
        };

        MidiSound();

        explicit MidiSound(BinData* bin_data);

        virtual ~MidiSound();

        void Init(BinData* bin_data);
        
        virtual INT GetId() const;

        virtual const BinData* GetBinData() const;

    private:
        BinData* m_bin_data;
};

#endif // MultiMedia_MidiSound_hpp


