/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BrowserViewContainer_hpp)
#define Apoxi_BrowserViewContainer_hpp

#include "BrowserView.hpp"

class BrowserViewContainer : public DrawableObject
{
    typedef DrawableObject Base;

    public:
        BrowserViewContainer();
        BrowserViewContainer(Control *parent, BrowserView &browser_view);
        virtual ~BrowserViewContainer();

        void Init(Control *parent, BrowserView &browser_view);

        virtual void AddView(BrowserView &browser_view);

        virtual BOOLEAN RemoveView(BrowserView &browser_view);
        
        virtual void SetActiveView(INT index);

        virtual void ToggleView();

        virtual INT GetViewCount();

        virtual BrowserView *GetActiveView() const;

        virtual void Update(INT item_count);

        virtual void NotifyDelete();

    private:
        BrowserView *m_views[5];
        INT m_view_cnt;
        INT m_active_view;
};

#endif  // Apoxi_BrowserViewContainer_hpp
