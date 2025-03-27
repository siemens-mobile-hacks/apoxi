/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#include "Adc/FlsFile.hpp"
#include <Afs/Registry.hpp>
#include <Afs/Uri.hpp>
#include <Afs/AfsMsgTypes.hpp>
#include <Auxiliary/RegBlobObject.hpp>

#include <Afs/RegIterator.hpp>

#include "RegEncoderDecoder.hpp"

class RegistryInterface
{
public:

    RegistryInterface();
    ~RegistryInterface();

    static RegIterator m_regiterator;

    //static Mobile2PCMsg& RegInterface(PC2MobileMsg& );
    static UINT8 RegInterface(RegEncoderDecoder::PC2MobileMsg&, RegEncoderDecoder::Mobile2PCMsg&);

private:

    static RegResult DataItemInterface(const RegEncoderDecoder::PC2MobileMsg&,RegEncoderDecoder::Mobile2PCMsg&);
    static RegResult RegIterator(const RegEncoderDecoder::PC2MobileMsg&,RegEncoderDecoder::Mobile2PCMsg&);
    static RegResult RegTransaction(const RegEncoderDecoder::PC2MobileMsg&,RegEncoderDecoder::Mobile2PCMsg&);
    static RegResult UnlockInterface(const RegEncoderDecoder::PC2MobileMsg&, RegEncoderDecoder::Mobile2PCMsg&);
    static RegResult RegIteratorGetUri(const RegEncoderDecoder::PC2MobileMsg&, RegEncoderDecoder::Mobile2PCMsg&);
};
