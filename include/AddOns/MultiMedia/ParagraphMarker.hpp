/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ParagraphMarker_hpp)
#define Apoxi_ParagraphMarker_hpp

#include <Auxiliary/WString.hpp>
#include <Gui/CompoundItem.hpp>

class Font;

class ParagraphMarker : public CompoundItem {
    typedef CompoundItem Base;

    public:
        enum {
            ID = 13
        };

        static ParagraphMarker* CreateInstance();

        virtual ~ParagraphMarker();

        virtual INT GetId() const;

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const;

        virtual INT WrapLine(INT index,
                             XYDIM width,
                             WrapPolicy wrap_policy = EditorDocument::WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT index, INT count) const;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const;

        virtual INT GetItemCount() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        ParagraphMarker();
};

#endif  // Apoxi_ParagraphMarker_hpp


