/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbAdvDetails_hpp)
#define Mmi_PbAdvDetails_hpp

#include <AdvPhonebook/AdvPbAction.hpp>
#include <AdvPhonebook/PbDetails.hpp>
 
class AdvPbApp;
class AdvPbWin;
class PbAdvDetails : public PbDetails {
    typedef PbDetails Base;

    public:

        PbAdvDetails();
        virtual ~PbAdvDetails();
        
        void Init(AdvPbApp* pb_app, AdvPbWin *parent, const INT* detail_columns);

        virtual void AddNumber();
        virtual void CancelAddNumber();

        virtual INT GetSelectedRow();
        
    protected:
        virtual PbDetailProvider * GetDetailProvider();
        virtual void GetUpdatedItem(INT colid, DataItem &item);
        virtual const WString   GetSavedText(INT colid);

    private:
        virtual void UpdateWin();
        virtual void UpdateEnabledActions();
    
        AdvPbApp*               m_pb_app;

        PbAddPhoneNoAction      m_add_phoneno_action;
        PbCancelAddNoAction     m_cancel_add_no_action;
        PbChangeNoTypeAction    m_no_type_action;
//      static const INT        m_more_detail_columns[5];

        PbNumberFilterProvider  m_no_filter;
        INT                     m_phoneno_cnt;
};

#endif  // Mmi_PbAdvDetails_hpp
