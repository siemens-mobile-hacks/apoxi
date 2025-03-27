// ****************************************************************************
// Copyright (C) 2001 COMNEON GmbH & Co. OHG. All rights reserved.
// ****************************************************************************
//
// ****************************************************************************
//
// This document contains proprietary information belonging to COMNEON.
// Passing on and copying of this document, use and communication of its
// contents is not permitted without prior written authorisation.
//
// ****************************************************************************
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_TchInterface_hpp)
#define Asc_TchInterface_hpp


extern void OpenDownlink(); 

extern void OpenUplink();

extern void CloseDownlink();

extern void CloseUplink();

extern void OpenTch();

extern void CloseTch();

extern BOOLEAN IsUplinkConnected();

extern BOOLEAN IsDownlinkConnected();

extern BOOLEAN IsTchConnected();

#endif  // _ASC_TchInterface_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS


