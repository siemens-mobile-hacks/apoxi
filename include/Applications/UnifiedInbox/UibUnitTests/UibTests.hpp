// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_UIBTEST1_3FC1F1BC023A_INCLUDED
#define _INC_UIBTEST1_3FC1F1BC023A_INCLUDED

#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>

class UibTest1 : public MmiUnitTest {
    typedef MmiUnitTest Base;
    public:
        UibTest1() {};

        virtual ~UibTest1();

        void Init(WCHAR* name, MmiUnitTestSuite* suite);
        
        virtual TestResult Run();

};

class UibTest2 : public MmiUnitTest {
    typedef MmiUnitTest Base;
    public:
        UibTest2() {};

        virtual ~UibTest2();

        void Init(WCHAR* name, MmiUnitTestSuite* suite);
        
        virtual TestResult Run();

};


#endif /* _INC_UIBTEST1_3FC1F1BC023A_INCLUDED */
