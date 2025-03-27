/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(UnifiedInbox_UibActionAccessor_hpp)
#define UnifiedInbox_UibActionAccessor_hpp

#include <GuiExtensions/ActionAccessor.hpp>

class UibActionAccessor : public ActionAccessor {
    typedef ActionAccessor Base;

    public:
        UibActionAccessor();

        ~UibActionAccessor();
        
        virtual Action* GetAction();
        
        virtual INT GetActionCount() const;
        
        virtual void InsertAction(INT index, Action *action);

        virtual void RemoveAction(INT index);

        virtual void RemoveAllActions();

        virtual Action* GetAction(INT index) const;

        virtual INT GetActionIndex(const Action &action) const;

        void SetAccessor(AbstractActionAccessor* accessor) { m_accessor = accessor; }

        void RemoveAccessor() { m_accessor = 0; }

    private:
        INT AccActionCnt() const;
        Action* GetAccAction(INT index) const;
        
        AbstractActionAccessor*         m_accessor;         
};

#endif  // Mmi_ActionAccessor_hpp
