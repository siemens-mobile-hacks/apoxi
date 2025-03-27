/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_AdvPbAction_hpp)
#define Mmi_AdvPbAction_hpp

#include <AdvPhonebook/PbAction.hpp>

class AdvPbApp;
class AdvPbAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        AdvPbAction();
        virtual ~AdvPbAction();

        void Init(AdvPbApp *pb_app, const WCHAR *text);
        
        AdvPbApp* GetPbApplication() { return (AdvPbApp*) Base::GetPbApplication(); }
};

class PbAdvDetails;
class PbAdvDetailAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        PbAdvDetailAction();
        PbAdvDetailAction(PbAdvDetails *detail_win, const WCHAR *text);
        virtual ~PbAdvDetailAction();

        void Init(PbAdvDetails *detail_win, const WCHAR *text);
    
        PbAdvDetails* GetDetailWin() { return m_detail_win; };

    private:
        PbAdvDetails    *m_detail_win;
};

class PbAddPhoneNoAction : public PbAdvDetailAction {
    typedef PbAdvDetailAction Base;

    public:
        virtual BOOLEAN Execute();

};

class PbConfirmAddNoAction : public PbAdvDetailAction {
    typedef PbAdvDetailAction Base;

    public:
        virtual BOOLEAN Execute();
};

class PbCancelAddNoAction : public PbAdvDetailAction {
    typedef PbAdvDetailAction Base;

    public:
        virtual BOOLEAN Execute();
};

class PbDelPhonenoAction : public AdvPbAction {
    typedef AdvPbAction Base;

    public:
        virtual BOOLEAN Execute();
};

class PbChangeNoTypeAction : public AdvPbAction {
    typedef AdvPbAction Base;

    public:
        virtual BOOLEAN Execute();
    
};

class PbSelectGroupAction : public AdvPbAction {
    typedef AdvPbAction Base;

    public:
        virtual BOOLEAN Execute();
};

class SyncSimAllAction : public AdvPbAction {
    typedef AdvPbAction Base;

    public:
        virtual BOOLEAN Execute();
    
};

class SyncPhoneAllAction : public AdvPbAction {
    typedef AdvPbAction Base;

    public:
        virtual BOOLEAN Execute();  
};

class SyncSimAction : public AdvPbAction {
    typedef AdvPbAction Base;

    public:
        virtual BOOLEAN Execute();
    
};

class SyncPhoneAction : public AdvPbAction {
    typedef AdvPbAction Base;

    public:
        virtual BOOLEAN Execute();  
};

#endif  // Mmi_AdvPbAction_hpp
