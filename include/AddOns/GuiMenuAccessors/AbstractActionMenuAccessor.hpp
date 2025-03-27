/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractActionMenuAccessor_hpp)
#define Apoxi_AbstractActionMenuAccessor_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/Vector.hpp>
#include <Gui/MenuAccessor.hpp>

class Action;

class AbstractActionMenuAccessor : public MenuAccessor {
    typedef MenuAccessor Base;

    public:
        AbstractActionMenuAccessor();

        AbstractActionMenuAccessor(const WCHAR* title);

        ~AbstractActionMenuAccessor();

        void Init(const WCHAR* title);

        virtual Action* GetAction() = 0;

        virtual const WCHAR* GetItemText(BOOLEAN highlighted);

        virtual const BitmapRes* GetItemIcon(BOOLEAN highlighted);

        virtual BOOLEAN IsEnabled();

        virtual void Trigger(Menu* menu);

    protected:
        virtual AbstractMenuAccessor* GetChild();
            
        virtual void OnTrigger(INT selected_idx);

        virtual void OnLanguageChanged();
};

#endif  // Apoxi_AbstractActionMenuAccessor_hpp

