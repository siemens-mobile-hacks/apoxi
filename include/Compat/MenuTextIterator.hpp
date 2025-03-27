/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MenuTextIterator_hpp)
#define Apoxi_MenuTextIterator_hpp


class MenuTextIterator {
    public:
        virtual INT ItemCount() const = 0;

        virtual const WCHAR* operator()(INT idx) const = 0;
};

#endif  // Apoxi_MenuTextIterator_hpp


