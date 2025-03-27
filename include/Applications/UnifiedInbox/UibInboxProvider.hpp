/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(UnifiedInbox_UibInboxProvider_hpp)
#define UnifiedInbox_UibInboxProvider_hpp


#include <AddOns/AuxExtensions/AppendProvider.hpp>


class UibInboxProvider: public AppendProvider {
            typedef AppendProvider Base;
    public:

    UibInboxProvider();

    ~UibInboxProvider();

    virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem& item);
    protected:
        virtual void OnUpdate(ObservableObject *obs_obj){};

};

#endif  // Mmi_UnifiedInboxProvider_hpp
