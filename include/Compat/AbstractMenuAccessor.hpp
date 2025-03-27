/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractMenuAccessor_hpp)
#define Apoxi_AbstractMenuAccessor_hpp

#include <Kernel/Dispatcher.hpp>

class Menu;
class DeviceContext;
class Rect;

class AbstractMenuAccessor : public Dispatcher {
    public:
        AbstractMenuAccessor();

        void Init();

        virtual ~AbstractMenuAccessor();

        virtual BOOLEAN First() = 0;

        virtual BOOLEAN Next() = 0;

        virtual XYDIM GetItemHeight() const = 0;

        virtual XYDIM GetItemWidth() const;
        
        virtual INT GetColumnCount() const;

        virtual BOOLEAN IsEnabled();

        virtual void Draw(DeviceContext* dc, const Rect& draw_rect, BOOLEAN highlighted) = 0;

        virtual void Trigger(Menu* menu) = 0;

        virtual void Back(Menu* menu) = 0;

        virtual BOOLEAN IsRoot();

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnLanguageChanged();

        virtual void OnActivate(Menu* menu, AbstractMenuAccessor* parent_accessor);

        virtual void OnDeactivate(Menu* menu);

        virtual void OnSelectionChanged(INT selected_idx);

    private:
        INT m_act_lang;

    friend class Menu;
};

#endif  // Apoxi_AbstractMenuAccessor_hpp


