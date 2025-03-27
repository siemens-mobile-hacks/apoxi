/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(_Asc_InputAnalyzer_hpp)
#define _Asc_InputAnalyzer_hpp

#include <Kernel/Types.hpp>

#include <Asc/InputAction.hpp>
#include <Auxiliary/ElementList.hpp>



class InputActionPtr : public Linkable<InputActionPtr> 
{
    public:
        InputActionPtr() : m_action(0) {}
        explicit InputActionPtr(InputAction * action) : m_action(action) { ASSERT(action!=0); }

        BOOLEAN operator == (const InputActionPtr &ptr) const { return (m_action == ptr.m_action); }

        InputAction * GetInputAction() { ASSERT(m_action!=0); return m_action; }

        BOOLEAN operator < (const InputActionPtr &ptr) const { 
            ASSERT(m_action!=0 && ptr.m_action!=0); 
            return (m_action->GetParsePriority() < ptr.m_action->GetParsePriority()); 
        }


    private:
        InputAction * m_action;

};


class InputActionList : public SortedElementList<InputActionPtr>
{
    public:
        InputActionList() {} 

        void RegisterInputAction(InputAction * action);      
};


class InputContext 
{
    public:
        InputContext();
        explicit InputContext(Application * application);
        // only for test purposes
        InputContext(Application * application, BOOLEAN msp, BOOLEAN ace, 
                     BOOLEAN hce, BOOLEAN cse = FALSE);
        ~InputContext(); 

        BOOLEAN IsMocSetupPermitted() const { return m_mocsetuppermitted; } 
        BOOLEAN ActiveCallExists() const { return m_activecallexists; }
        BOOLEAN HeldCallExists() const { return m_heldcallexists; }
        BOOLEAN CallInSetupExists() const { return m_callinsetupexists; }
        BOOLEAN IsCingularActive() const { return m_cingularactive; }

        void SetCingularActive(BOOLEAN active = TRUE) { m_cingularactive = active; }


        BOOLEAN Update();
    
    private:
        BOOLEAN  m_mocsetuppermitted;
        BOOLEAN  m_activecallexists;
        BOOLEAN  m_heldcallexists;
        BOOLEAN  m_callinsetupexists;
        BOOLEAN  m_cingularactive;
};


class InputAnalyzer 
{
    public:
        InputAnalyzer() : m_actionlist(0) {}

        explicit InputAnalyzer(const InputActionList * actionlist);
        ~InputAnalyzer(); 

        void Init(const InputActionList * actionlist);

        InputAction * GetFirstInputAction(const WString & actionstring, const InputContext * context = 0);
    
        static BOOLEAN IsStorableMocPhoneNumber(const PhoneNumber & phno);

    private:
        const InputActionList * m_actionlist;
};

 
#endif


