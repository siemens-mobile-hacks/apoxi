/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MultiMedia_SmafSound_hpp)
#define MultiMedia_SmafSound_hpp

#include <Auxiliary/BinData.hpp>
#include <AddOns/MultiMedia/Melody.hpp>

class SmafSound : public Melody {
    typedef Melody Base;

    public:
        enum {
            ID = 2
        };

        SmafSound();

        explicit SmafSound(BinData* bin_data);

        virtual ~SmafSound();

        void Init(BinData* bin_data);
        
        virtual INT GetId() const;

        virtual const BinData* GetBinData() const;

    private:
        BinData* m_bin_data;
};

#endif // MultiMedia_SmafSound_hpp


