/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ResourceManager_hpp)
#define Apoxi_ResourceManager_hpp

#include <Kernel/InputMap.hpp>

class Font;
struct PagingMap;
struct ColorTable;

class ResourceManager {
    public:
        const ColorTable& GetColorTable() const;

        const InputMap& GetInputMap(MapItemType type) const;

        const Font& GetFont(INT id) const;

        const PagingMap& GetPagingMap(INT lang_id = -1) const;
};

#endif  // Apoxi_ResourceManager_hpp


