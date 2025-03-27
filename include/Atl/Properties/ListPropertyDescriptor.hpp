//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#ifndef Atl_ListPropertyDescriptor_hpp
#define Atl_ListPropertyDescriptor_hpp

#include "PropertyDescriptor.hpp"


class ListPropertyDescriptor : public PropertyDescriptor {
    typedef PropertyDescriptor Base;

    public:
        enum {
            ID = 2
        };

        ListPropertyDescriptor();

        virtual ~ListPropertyDescriptor();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(const INT id) const;

        virtual WString GetText(INT index) const = 0;

        virtual ImageObtainer GetIcon(INT index) const = 0;
        
        virtual DataItem GetValue(INT index) const;

        virtual INT GetItemCount() const;
};

#endif  // Atl_ListPropertyDescriptor_hpp

