/*  ------------------------------------------------------------------------
    Copyright (C) 2003 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GlassPane_hpp)
#define Apoxi_GlassPane_hpp

#include <Auxiliary/Vector.hpp>

class AbstractRenderer;
class DeviceContext;

class PaneObject {
    public:
        PaneObject();

        PaneObject(const Rect& bounding_rect, AbstractRenderer* renderer = 0);

        ~PaneObject();

        void Init(const Rect& bounding_rect, AbstractRenderer* renderer = 0);

        void SetPos(XYDIM x, XYDIM y);

        Point GetPos() const;

        void SetSize(XYDIM width, XYDIM height);

        Size GetSize() const;

        void SetBoundingRect(const Rect& bounding_rect);

        const Rect& GetBoundingRect() const { return m_bounding_rect; }

        virtual void Draw(DeviceContext* dc);

        void Invalidate();

    private:
        AbstractRenderer* m_renderer;
        Rect m_bounding_rect;
};

 class GlassPane {
    public:
        GlassPane();

        virtual ~GlassPane();
        
        void Add(PaneObject* pane_object);

        void Remove(PaneObject* pane_object);

        void RemoveAllPaneObjects();

        BOOLEAN Contains(const PaneObject* pane_object) const;

        virtual void Draw(DeviceContext* dc) const;

        void SetEnabled(BOOLEAN enabled) { m_enabled = enabled; }

        BOOLEAN IsEnabled() const { return m_enabled; }

    private:
        mutable Vector<PaneObject*> m_pane_objects;
        BOOLEAN m_enabled;
};


#endif // Apoxi_GlassPane_hpp


