/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTestResultsMenu_hpp)
#define ApoxiApp_FfsTestResultsMenu_hpp

#include <GuiExtensions/AbstractMmiMenuAccessor.hpp>
#include <GuiExtensions/MmiPrompt.hpp>
#include <SocketTest/FfsTestBase.hpp>

class FfsTestResultsSubMenu : public AbstractMmiMenuAccessor
{
    typedef AbstractMmiMenuAccessor Base;

    public:
        FfsTestResultsSubMenu(); 
        virtual ~FfsTestResultsSubMenu(); 

        void Init(INT test = -1); 

        BOOLEAN First(); 
        BOOLEAN Next(); 

        virtual const WCHAR* GetItemText(BOOLEAN highlighted); 

    protected:
        virtual void OnTrigger(INT selected_idx); 

    protected:
        INT GetIndex() const { return m_idx; } 

    private:
        INT             m_idx; 
        INT             m_test_number; 

        FfsTestBase *m_tests; 

        enum State {
            Total,
            Successfull,
            Failed,
            ErrorCode,
            ItemCnt     
        };
};

class FfsTestResultsMenu : public AbstractMmiMenuAccessor
{
    typedef AbstractMmiMenuAccessor Base;

    public:
        FfsTestResultsMenu(); 
        virtual ~FfsTestResultsMenu(); 

        void Init(); 

        BOOLEAN First();
        BOOLEAN Next();

        virtual const WCHAR* GetItemText(BOOLEAN highlighted);
        virtual const BitmapRes* GetItemIcon(BOOLEAN highlighted);

    protected:
        virtual void OnTrigger(INT selected_idx);

    private:
        enum State {
            ItemCnt  = FfsTestBase::m_nTotalNumberOfTests       
        };

        FfsTestBase *m_tests; 

        FfsTestResultsSubMenu m_submenu_menu;
        MmiMenuWindow            m_submenu_win; 

    protected:
        INT GetIndex() const { return m_idx; }

    private:
        INT             m_idx;  
};

#endif  // ApoxiApp_FfsTestResultsMenu_hpp
