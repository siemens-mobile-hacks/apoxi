/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractEditorItem_hpp)
#define Apoxi_AbstractEditorItem_hpp


class AbstractEditorItem {
    public:
        AbstractEditorItem();

        virtual ~AbstractEditorItem();

        virtual INT GetId() const = 0;

        virtual BOOLEAN IsInstanceOf(INT id) const = 0;
};

#endif  // Apoxi_AbstractEditorItem_hpp


