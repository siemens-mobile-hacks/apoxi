/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if !defined(Mmi_RegAppCommon_hpp)
#define Mmi_RegAppCommon_hpp

#include <Afs/Uri.hpp>
#include <Auxiliary/DataItem.hpp>

#include "RegEncoderDecoder.hpp"

class RegAppCommon
{
    public:

#if REGAPP_USE_NEW
        static Init();
        static Close();
#endif


        static RegEncoderDecoder::Mobile2PCMsg* GetInstanceMobile2PC();
        static RegEncoderDecoder::PC2MobileMsg* GetInstancePC2Mobile();
        static DataItem* GetInstanceDataItem();
        static RegEncoderDecoder::IteratorObjResult* GetInstanceIteratorObj();
        static Uri* GetInstanceUri();
        


    private:

#if REGAPP_USE_NEW
        static RegEncoderDecoder::Mobile2PCMsg      *m_mob2pcmsg;
        static RegEncoderDecoder::PC2MobileMsg      *m_pc2mobMsg;
        static DataItem                             *m_dataitem;
        static RegEncoderDecoder::IteratorObjResult *m_iterator_obj;
        static Uri                                  *m_uri;
#else
        static RegEncoderDecoder::Mobile2PCMsg      m_mob2pcmsg;
        static RegEncoderDecoder::PC2MobileMsg      m_pc2mobMsg;
        static DataItem                             m_dataitem;
        static RegEncoderDecoder::IteratorObjResult m_iterator_obj;
        static Uri                                  m_uri;

#endif
};


#endif
