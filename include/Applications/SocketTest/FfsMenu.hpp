/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsMenu_hpp)
#define ApoxiApp_FfsMenu_hpp

#include <GuiExtensions/AbstractMmiMenuAccessor.hpp>
#include <SocketTest/FfsTestMenu.hpp>
#include <SocketTest/FfsTestDispWin.hpp>
#include <SocketTest/FfsTestResultsMenu.hpp>

class FfsMenu : public AbstractMmiMenuAccessor
{
    typedef AbstractMmiMenuAccessor Base;

    public:
        FfsMenu(); 
        virtual ~FfsMenu(); 

        void Init(); 

        BOOLEAN First(); 
        BOOLEAN Next(); 

        virtual const WCHAR* GetItemText(BOOLEAN highlighted); 
        virtual const BitmapRes* GetItemIcon(BOOLEAN highlighted); 
 
    protected:
        virtual void OnTrigger(INT selected_idx); 

    private:
        enum State {
            ChooseTests,
            StartStop,
            Results,
            DisableAll,
            Default,
            ItemCnt     
        };

    protected:
        INT GetIndex() const { return m_idx; } 

    private:
        INT             m_idx; 
        
        MmiMenuWindow           m_ffs_settings_win; 
        FfsTestMenu             m_ffs_settings_menu; 
 
        FfsTestResultsMenu      m_ffs_results_menu; 
        MmiMenuWindow           m_ffs_results_win;

        FfsTestDispWin      m_ffs_display_win; 
};
#endif  // ApoxiApp_FfsMenu_hpp
