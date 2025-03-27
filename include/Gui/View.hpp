/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_View_hpp)
#define Apoxi_View_hpp

class Model;
class DeviceContext;
class Rect;
class Component;
class Theme;

class View {
    public:
        View(XYDIM default_width = -1, XYDIM default_height = -1);

        virtual ~View();

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const = 0;
        
        XYDIM GetDefaultWidth() const { return m_default_width; }

        XYDIM GetDefaultHeight() const { return m_default_height; }

        virtual void Update(const Theme& theme);

    protected:
        void SetDefaultWidth(XYDIM width) { m_default_width = width; }

        void SetDefaultHeight(XYDIM height) { m_default_height = height; }

    private:
        XYDIM m_default_width;
        XYDIM m_default_height;
};

#endif  // Apoxi_View_hpp


