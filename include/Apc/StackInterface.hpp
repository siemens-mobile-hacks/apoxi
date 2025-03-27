/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_StackInterface_hpp)
#define Apc_StackInterface_hpp

/*  ========================================================================
    StackInterface
    ======================================================================== */
class StackInterface {
    public:
        static void Init();
        static BOOLEAN IsFastSmsLoadingSupported();
        static BOOLEAN IsGroupDeletionNotificationSupported();

};


#endif // Apc_StackInterface_hpp


