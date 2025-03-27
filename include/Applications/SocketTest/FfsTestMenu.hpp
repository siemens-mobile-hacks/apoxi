/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTestMenu_hpp)
#define ApoxiApp_FfsTestMenu_hpp

#include <GuiExtensions/AbstractMmiMenuAccessor.hpp>
#include <GuiExtensions/MmiPrompt.hpp>
#include <SocketTest/FfsTestBase.hpp>

class FfsTestSubMenu : public AbstractMmiMenuAccessor
{
    typedef AbstractMmiMenuAccessor Base;

    public:
        FfsTestSubMenu(); 
        virtual ~FfsTestSubMenu(); 

        void Init(INT test = -1); 

        BOOLEAN First(); 
        BOOLEAN Next(); 

        virtual const WCHAR* GetItemText(BOOLEAN highlighted); 
        virtual const BitmapRes* GetItemIcon(BOOLEAN highlighted); 

    protected:
        virtual void OnTrigger(INT selected_idx); 

    protected:
        INT GetIndex() const { return m_idx; } 

    private:
        INT             m_idx; 
        INT             m_test_number; 

        MmiPrompt       m_iterations_prompt; 

        FfsTestBase *m_tests; 

        enum State {
            Enabled,
            FirstSubtest,
            ItemCnt = 2     
        };
};

class FfsTestMenu : public AbstractMmiMenuAccessor
{
    typedef AbstractMmiMenuAccessor Base;

    public:
        FfsTestMenu(); 
        virtual ~FfsTestMenu(); 

        void Init(); 

        BOOLEAN First();
        BOOLEAN Next();

        virtual const WCHAR* GetItemText(BOOLEAN highlighted);
        virtual const BitmapRes* GetItemIcon(BOOLEAN highlighted);

    protected:
        virtual void OnTrigger(INT selected_idx);

    private:
        FfsTestSubMenu      m_submenu_menu; 
        MmiMenuWindow       m_submenu_win; 

        enum State {
            FirstSubTest,
            ItemCnt  = 4        
        };

        FfsTestBase *m_tests; 

    protected:
        INT GetIndex() const { return m_idx; }

    private:
        INT             m_idx;  
};

#endif  // ApoxiApp_FfsTestMenu_hpp
