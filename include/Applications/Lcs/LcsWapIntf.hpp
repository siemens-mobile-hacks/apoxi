/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsWapIntf_hpp)
#define Mmi_LcsWapIntf_hpp

class LcsWapIntf
{
    public:

        ~LcsWapIntf();

        static LcsWapIntf* GetInstance();

        static void ReleaseInstance();

        BOOLEAN DisplayMap(BOOLEAN feature_wai);

        BOOLEAN IsDispMapAllowed() { return m_is_disp_allowed; }

        BOOLEAN IsBrowserOpen() { return m_is_open; }

        void SetBrowserOpen(BOOLEAN is_open) { m_is_open = is_open; }

        void SetDispMapAllowed(BOOLEAN is_disp_allowed) { m_is_disp_allowed = is_disp_allowed; }

    private:

        LcsWapIntf();

    private:

        static LcsWapIntf* m_self;

        BOOLEAN m_is_disp_allowed;

        BOOLEAN m_is_open;

}; // LcsWapIntf

#endif // Mmi_LcsWapIntf_hpp
