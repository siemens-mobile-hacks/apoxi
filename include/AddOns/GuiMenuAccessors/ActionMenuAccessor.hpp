/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ActionMenuAccessor_hpp)
#define Apoxi_ActionMenuAccessor_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/Vector.hpp>
#include <AddOns/GuiMenuAccessors/AbstractActionMenuAccessor.hpp>

class ActionMenuAccessor : public AbstractActionMenuAccessor {
    typedef AbstractActionMenuAccessor Base;

    public:
        ActionMenuAccessor();

        ActionMenuAccessor(const WCHAR* title, INT action_count = 4);

        ~ActionMenuAccessor();
        
        void Init(const WCHAR* title, INT action_count = 4);

        virtual BOOLEAN First();

        virtual BOOLEAN Next();

        virtual Action* GetAction();
        
        void AddAction(Action* action);

        void InsertAction(INT index, Action* action);

        void RemoveAction(INT index);

        void RemoveAllActions();

        BOOLEAN ContainsAction(const Action& action) const;

        void SetAction(INT index, Action* action);

        Action* GetAction(INT index) const;

        INT GetActionIndex(const Action& action) const;

        INT GetActionCount() const;

    protected:
        virtual void OnTrigger(INT selected_idx);

    private:
        INT                         m_index;
        Vector<Action*>             m_action_vec;

        void AssureValidIndex(INT& index) const;
};

#endif  // Apoxi_ActionMenuAccessor_hpp

