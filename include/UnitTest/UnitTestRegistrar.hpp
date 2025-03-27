/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    #ifdef APOXI_UNITTEST
        #ifndef APOXI_UNITTEST_STATIC_REPOSITORY
            #include <UnitTest/UnitTestAutoRepository.hpp>
            #ifdef TEST_NAME
                #ifdef APOXI_TARGETSYSTEM_HOST
                    #pragma INCLUDE_SYMBOL(TEST_NAME)
                #else
                    #ifdef APOXI_COMPILER_C166
                        #pragma no_global_dead_store_elim
                    #endif
                    #ifdef APOXI_COMPILER_RVCT
                        // Use the -keep linker command line option to prevent linker from optimizing out (wrongly detected) unused code
                    #endif
                    #ifdef APOXI_COMPILER_ADS
                        // Use the -keep linker command line option to prevent linker from optimizing out (wrongly detected) unused code
                    #endif
                    #ifndef APOXI_COMPILER_C166
                        #ifndef APOXI_COMPILER_RVCT
                            #ifndef APOXI_COMPILER_ADS
                                #error UnitTest automatic test registration does not work with this compiler
                            #endif
                        #endif
                    #endif
                #endif // APOXI_TARGETSYSTEM_HOST
                REGISTER_UNITTEST(TEST_NAME)
                #ifdef REGISTER_UNITTESTSUITE
                    //void TEST_NAME::dummy() {};
                    #undef REGISTER_UNITTESTSUITE
                #endif
                #ifdef APOXI_TARGETSYSTEM_HOST
                    #pragma END_INCLUDE_SYMBOL
                #else
                    #ifdef APOXI_COMPILER_C166
                        #pragma global_dead_store_elim
                    #endif
                    #ifdef APOXI_COMPILER_RVCT
                        // Use the -keep linker command line option to prevent linker from optimizing out (wrongly detected) unused code
                    #endif
                    #ifdef APOXI_COMPILER_ADS
                        // Use the -keep linker command line option to prevent linker from optimizing out (wrongly detected) unused code
                    #endif
                    #ifndef APOXI_COMPILER_C166
                        #ifndef APOXI_COMPILER_RVCT
                            #ifndef APOXI_COMPILER_ADS
                                #error UnitTest automatic test registration does not work with this compiler
                            #endif
                        #endif
                    #endif
                #endif // APOXI_TARGETSYSTEM_HOST
            #else
                #error Use TEST_NAME to define the name of yout test class. example: #define TEST_NAME StringTest
            #endif // TEST_NAME
        #endif // APOXI_UNITTEST_STATIC_REPOSITORY
    #endif // APOXI_UNITTEST
#endif // DOXYGEN_SHOULD_SKIP_THIS

