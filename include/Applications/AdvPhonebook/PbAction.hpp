/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbAction_hpp)
#define Mmi_PbAction_hpp

#include <Gui/CheckBoxAction.hpp>

class PhonebookApp;
class PbAbstractWin;

class PbAction : public Action {
    typedef Action Base;

    public:
        PbAction();
        virtual ~PbAction();

        void Init(PhonebookApp *pb_app, const WCHAR *text, const BitmapRes* bitmap = 0);
        
        virtual BOOLEAN Execute();

        PhonebookApp* GetPbApplication() { return m_pb_app; }

    private:
        static PhonebookApp *m_pb_app;
};

class PbToggleAction : public CheckBoxAction {
    typedef CheckBoxAction Base;

    public:
        PbToggleAction();
        virtual ~PbToggleAction();

        void Init(PhonebookApp *pb_app, const WCHAR *text);
        
        PhonebookApp* GetPbApplication() { return m_pb_app; }

    private:
        static PhonebookApp *m_pb_app;
};

class PbSecuredAction : public PbAction {
    typedef PbAction Base;

    public:
        PbSecuredAction();  
        virtual ~PbSecuredAction();
        virtual BOOLEAN Execute();
        BOOLEAN IsExecuting() { return m_is_executing; }

    private:
        BOOLEAN m_is_executing;
};

class PbDetails;
class PbDetailAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        PbDetailAction();
        PbDetailAction(PbDetails *detail_win, const WCHAR *text);
        virtual ~PbDetailAction();

        void Init(PbDetails *detail_win, const WCHAR *text);
    
        PbDetails* GetDetailWin() { return m_detail_win; };

    private:
        PbDetails   *m_detail_win;
};

class PbAddAction : public PbSecuredAction {
    typedef PbSecuredAction Base;
        
    public:
        virtual BOOLEAN Execute();
};

class PbEditDetailAction : public PbDetailAction {
    typedef PbDetailAction Base;        

    public:
        virtual BOOLEAN Execute();
        
};

class PbConfirmEditAction : public PbDetailAction {
    typedef PbDetailAction Base;

    public:
        virtual BOOLEAN Execute();
};

class PbCancelEditAction : public PbDetailAction {
    typedef PbDetailAction Base;

    public:
        virtual BOOLEAN Execute();
};

class PbCallAction : public PbAction {
    public:
        typedef PbAction Base;

        virtual BOOLEAN Execute();
};

class PbDeleteAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        virtual BOOLEAN Execute();
};

class PbDelAllAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        virtual BOOLEAN Execute();
};

class SyncAction : public PbAction {
    typedef PbAction Base;

    public:
        virtual BOOLEAN Execute();  
};

class DisplayMemoryAction : public PbAction {
    typedef PbAction Base;

    public:
        virtual BOOLEAN Execute();  
};

class AddAllToFdnAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        virtual BOOLEAN Execute();  
};

class AddEntryToFdnAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        virtual BOOLEAN Execute();  
};

class AddNumberToFdnAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        virtual BOOLEAN Execute();  
};

class CopyToPbAction : public PbSecuredAction {
    typedef PbSecuredAction Base;

    public:
        virtual BOOLEAN Execute();  
};

#endif  // Mmi_PbAction_hpp
