/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestT6_hpp)
#define ApoxiApp_SocketTestT6_hpp

#include <SocketTest/SocketTestT4.hpp>

class SocketTestT6 : public SocketTestT4
{
public:
    SocketTestT6() { }

    virtual ~SocketTestT6() { }

    virtual internalStatus  TestA(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestB(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestC(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestD(internalStatus instatus, INT &ErrorCode); 
    virtual void FinishGroup();
};

#endif // ApoxiApp_SocketTestT6_hpp
