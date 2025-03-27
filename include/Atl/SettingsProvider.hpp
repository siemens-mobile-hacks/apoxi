/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_SettingsProvider_hpp)
#define Mmi_SettingsProvider_hpp

#include <Auxiliary/Provider.hpp>

class SettingsProvider : public Provider , public Linkable<SettingsProvider> {
        typedef Provider Base;
    public:
        virtual Provider::Status GetStatus() const { return Provider::updated; }

        virtual INT RowCount();

        virtual void RestoreFactorySettings() = 0 ;

        virtual BOOLEAN Update(ProviderListener * listener = 0);

};
#endif  // Mmi_SettingsProvider_hpp


