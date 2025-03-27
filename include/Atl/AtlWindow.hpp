/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_AtlWindow_hpp)
#define Atl_AtlWindow_hpp

#include <Auxiliary/Observer.hpp>
#include <Gui/Window.hpp>

#include <Atl/Context/ContextID.hpp>
#include <Atl/Properties/SubstitutedText.hpp>

#if defined(APOXI_COMPAT_2_7_0)
    #include <Atl/Features/FeatureID.hpp>
#endif  // APOXI_COMPAT_2_7_0

class Feature;

class AtlWindow : public Window, public Observer {
    typedef Window Base;

    public:
         enum {
            ID = 39
         };

        AtlWindow();

        virtual ~AtlWindow();

        void Init(Dispatcher* dispatcher = 0);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        // @param id    context id which is set to the window
        void SetContextId(const ContextID& id);

        // @param id    context id which is set to the window
        void SetContextId(const CHAR * id);

        virtual const ContextID& GetContextId() const { return m_context_id; }

        void SetDispatcher(Dispatcher* dispatcher) { m_dispatcher = dispatcher; }

        Dispatcher* GetDispatcher() { return m_dispatcher; }

        virtual void SetTitle(const WCHAR* title);

        virtual void SetSoftkey(INT index, Action* action);

        virtual void SetDefaultSize();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);

        virtual void OnOpen();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnGetFocus();
        
        virtual void OnLoseFocus();

        virtual void OnActionExecuted(Action *action);

        virtual void OnLanguageChanged();

        virtual void OnThemeChanged();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();

        virtual void OnContextSwitched();


    private:
        BOOLEAN SoftkeyUpdateNeeded(Feature* feature, INT property_id) const;
        BOOLEAN TitleAffected(Feature* feature, INT property_id) const;
        BOOLEAN SoftkeysAffected(Feature* feature, INT property_id) const;

        ContextID m_context_id;
        Dispatcher* m_dispatcher;
        SubstitutedText m_substituted_title;
        
        void AdjustBoundaries();
};

#endif  // Atl_AtlWindow_hpp

