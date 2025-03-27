//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_MenuProperties_hpp)
#define Atl_Context_MenuProperties_hpp

#include <Config/GuiObjectFactory.hpp>
#include <Gui/Point.hpp>

class ResourceParser;

class MenuProperties {
    public:
        enum Corner {
            TopLeft,
            TopRight,
            BottomLeft,
            BottomRight
        };

        enum MenuType 
        {
            FullSize,
            PopUp
        };

        enum TitleTextType
        { 
             NoTitle, 
             ItemContainerText, 
             ItemText, 
             ParentItemText, 
             ContextDependantTitle, 
             UndefinedTitleText 
        }; 

        MenuProperties(MenuType = FullSize, 
                       BOOLEAN close_after_trigger = FALSE,
                       TitleTextType = UndefinedTitleText);

        virtual ~MenuProperties();

        BOOLEAN SetProperty(ResourceParser& parser, 
                            const GuiObjectFactory::PropertyId prop_id);

        MenuType GetMenuType() const { return m_menu_type; }

        void SetMenuType(MenuType menu_type) { m_menu_type = menu_type; }

        Corner GetCorner() const { return m_corner; }

        void SetCorner(Corner corner) { m_corner = corner; }

        const Point& GetPos() const { return m_pos; }

        void SetPos(const Point& pos) { m_pos = pos; }

        void SetCloseAfterTrigger(BOOLEAN flag) { m_close_after_trigger = flag; }

        BOOLEAN CloseAfterTrigger() const { return m_close_after_trigger; }

        void SetTitleTextType (TitleTextType title_text) { m_title_type = title_text; } 

        TitleTextType GetTitleTextType () const { return m_title_type; }

    private:
        MenuType m_menu_type;
        Corner m_corner;
        Point m_pos;
        BOOLEAN m_close_after_trigger;
        TitleTextType m_title_type;
};

#endif /* Atl_Context_MenuProperties_hpp */


