/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Main_Desktop_hpp)
#define Main_Desktop_hpp

#include <Gui/Desktop.hpp>


class MainDesktop : public Desktop {
    typedef Desktop Base;
    
    public:
        static Desktop* CreateInstance(PanelAlignment panel_align = PanelOnBottom,
                                       SectionAlignment section_align = HorizBorderAlign);

    protected:
        virtual Component* CreateSection(SectionType section_type);
        
        MainDesktop(PanelAlignment panel_align,
                    SectionAlignment section_align);
};

#endif  // Main_Desktop_hpp

