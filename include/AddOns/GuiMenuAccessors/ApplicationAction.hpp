/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ApplicationAction_hpp)
#define Apoxi_ApplicationAction_hpp

#include <Gui/Action.hpp>

class ApplicationAction : public Action {
    typedef Action Base;

    public:
        ApplicationAction();

        ApplicationAction(Dispatcher* dispatcher,
                          Application* app,
                          const WCHAR* text,
                          const BitmapRes* bitmap = 0,
                          BOOLEAN enabled = TRUE);

        virtual ~ApplicationAction();

        void Init(Dispatcher* dispatcher,
                  Application* app,
                  const WCHAR* text,
                  const BitmapRes* bitmap = 0,
                  BOOLEAN enabled = TRUE);

        Application* GetApplication() { return m_app; }

        virtual BOOLEAN Execute();

    private:
        Application* m_app;
};

#endif // Apoxi_ApplicationAction_hpp

