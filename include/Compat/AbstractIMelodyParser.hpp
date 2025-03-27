/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(MultiMedia_AbstractIMelodyParser_hpp)
#define MultiMedia_AbstractIMelodyParser_hpp

#include <Auxiliary/BinData.hpp>
#include <AddOns/MultiMedia/IMelody.hpp>

class AbstractIMelodyParser
{
    public:
        AbstractIMelodyParser();
        virtual ~AbstractIMelodyParser();
            
        virtual INT GetToneCount(BinData* data) = 0;
        
        virtual void Parse(BinData* data, IMelodyData& parsed_data) = 0;
};
    
#endif // MultiMedia_AbstractIMelodyParser_hpp


