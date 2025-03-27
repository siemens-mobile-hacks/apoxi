/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsTemplateProvider_hpp)
#define Mmi_SmsTemplateProvider_hpp

#include <Config/Config.hpp>

class SmsTemplateProvider : public Provider
{
    typedef Provider Base;

    public:
        SmsTemplateProvider();
        virtual ~SmsTemplateProvider();

        void Init();
        
        virtual INT GetProviderId() const;
        
        virtual INT RowCount();
        
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

};

#endif  // Mmi_SmsTemplateProvider_hpp
