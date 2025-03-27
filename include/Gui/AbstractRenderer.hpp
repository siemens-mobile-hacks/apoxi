/*  ------------------------------------------------------------------------
    Copyright (C) 2003 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractRenderer_hpp)
#define Apoxi_AbstractRenderer_hpp

class DeviceContext;

class AbstractRenderer {
    public:
        AbstractRenderer();

        virtual ~AbstractRenderer();

        virtual void Draw(DeviceContext* dc) const = 0;
};

#endif // Apoxi_AbstractRenderer_hpp


