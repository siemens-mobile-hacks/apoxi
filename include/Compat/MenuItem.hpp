/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MenuItem_hpp)
#define Apoxi_MenuItem_hpp

#include <Gui/Action.hpp>
#include <Auxiliary/Linkable.hpp>

class MenuItem : public Linkable<MenuItem> {
    public:
        MenuItem();

        MenuItem(Action *action);

        void Init(Action *action);

        void SetAction(Action *action) { m_action = action; }

        Action* GetAction() const { return m_action; }

    private:
        Action *m_action;
};


#endif  // Apoxi_MenuItem_hpp


