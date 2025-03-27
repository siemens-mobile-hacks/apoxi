/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MultiMedia_IMelody_hpp)
#define MultiMedia_IMelody_hpp

#include <Auxiliary/BinData.hpp>
#include <AddOns/MultiMedia/Melody.hpp>

struct IMelodyData {
    WString m_version;
    WString m_format;
    WString m_name;
    WString m_composer;
    Audio::ToneData m_tone_data;
    
    struct {
        UINT16 beat     : 10;
        UINT8  style    : 2;
        UINT8  volume   : 4;
    } m_properties;
};
    
class AbstractIMelodyParser;

class IMelody : public Melody {
    typedef Melody Base;

    public:
        enum {
            ID = 0
        };

        IMelody();

        explicit IMelody(BinData* bin_data, BOOLEAN copyrighted = FALSE);

        virtual ~IMelody();

        void Init(BinData* bin_data, BOOLEAN copyrighted = FALSE);
        
        virtual INT GetId() const;

        virtual Audio::ToneData* GetToneData();
        
        static void RegisterParser(AbstractIMelodyParser* parser);

        virtual const BinData* GetBinData() const;

        BinData* GetPlainData() { return m_bin_data; }

    private:
        BinData* m_bin_data;
        IMelodyData m_parsed_data;
        static AbstractIMelodyParser* m_parser;
};

#endif // MultiMedia_IMelody_hpp


