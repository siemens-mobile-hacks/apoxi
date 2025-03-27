/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BitmapDc_hpp)
#define Apoxi_BitmapDc_hpp

#include <Gui/DeviceContext.hpp>

class Bitmap;
class VirtualDisplay;

class BitmapDc : public DeviceContext {
    typedef DeviceContext Base;

    public:
        BitmapDc();

        BitmapDc(Bitmap* bitmap);

        virtual ~BitmapDc();

        void Init(Bitmap* bitmap);

        virtual void AdjustBoundingRect();

    private:
        Bitmap* m_bitmap;
        VirtualDisplay* m_display;
};  // BitmapDc

#endif  // Apoxi_BitmapDc_hpp

