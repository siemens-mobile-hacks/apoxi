/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestAutoRepository_hpp)
#define Apoxi_UnitTestAutoRepository_hpp

#include "UnitTestRepository.hpp"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST
#ifndef APOXI_UNITTEST_STATIC_REPOSITORY

/*  ------------------------------------------------------------------------
    DEFINES TO FORCE LINKER TO KEEP TESTCLASS CODE
    ------------------------------------------------------------------------ */
#ifdef APOXI_TARGETSYSTEM_HOST
    #define SYMBOL_DECORATOR_START() /include:?c_test_data_
    #define APPEND_TO_SYMBOL_NAME(className) className
    #ifdef REGISTER_UNITTESTSUITE   
        #define SYMBOL_DECORATOR_END @@3VUnitTestSuiteData@@B
    #else
        #define SYMBOL_DECORATOR_END @@3VUnitTestData@@B
    #endif
    #define ASSEMBLE_DECORATOR(decorator) QUOTE_DECORATOR(decorator)
    #define QUOTE_DECORATOR(decorator) #decorator
    #define INCLUDE_SYMBOL(className) comment (linker, ASSEMBLE_DECORATOR(SYMBOL_DECORATOR_START()APPEND_TO_SYMBOL_NAME(className)SYMBOL_DECORATOR_END))
    #define END_INCLUDE_SYMBOL comment( user, "")
#else
    #ifdef APOXI_COMPILER_C166 
        // Using the pragmas no_global_dead_store_elim and global_dead_store_elim. Tasking Compiler doesnot perform preprocessor macro substituions for pragmas.
        // Thus, pragmas are directly added to UnitTestRegistrar.hpp
        #define INCLUDE_SYMBOL(className) 
    #endif 
    #ifdef APOXI_COMPILER_RVCT
        // Use the -keep linker command line option to prevent linker from optimizing out (wrongly detected) unused code
        #define INCLUDE_SYMBOL(className) 
    #endif
    #ifdef APOXI_COMPILER_ADS
        // Use the -keep linker command line option to prevent linker from optimizing out (wrongly detected) unused code
        #define INCLUDE_SYMBOL(className)
    #endif
#endif // APOXI_TARGETSYSTEM_HOST
// DEFINES TO FORCE LINKER TO KEEP TESTCLASS CODE



/*  ------------------------------------------------------------------------
    DEFINES FOR THE DYNAMIC REPOSITORY
    ------------------------------------------------------------------------ */

#ifdef APOXI_TARGETSYSTEM_HOST
    #undef DECLARATION_START_EXP
    #ifdef REGISTER_UNITTESTSUITE
        #define DECLARATION_START_EXP(ClassName) extern const UnitTestSuiteData c_test_data_##ClassName     
    #else 
        #define DECLARATION_START_EXP(ClassName) extern const UnitTestData c_test_data_##ClassName      
    #endif 
    #define DECLARATION_START(ClassName) DECLARATION_START_EXP(ClassName)
    #undef REGISTER_UNITTEST
    #ifdef APOXI_UNITTEST_NO_TESTNAMES      
        #ifdef REGISTER_UNITTESTSUITE
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, UnitTestData::m_instance_counter, UnitTestData::m_latest_instance, ClassName::GetTestAtStatic);
        #else 
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, UnitTestData::m_instance_counter, UnitTestData::m_latest_instance);        
        #endif
    #else
        #define STRINGIZE_NAME_EXP(ClassName) L###ClassName
        #define STRINGIZE_NAME(ClassName) STRINGIZE_NAME_EXP(ClassName)
        #undef REGISTER_UNITTEST
        #ifdef REGISTER_UNITTESTSUITE
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, STRINGIZE_NAME(ClassName), UnitTestData::m_instance_counter, UnitTestData::m_latest_instance, ClassName::GetTestAtStatic);         
        #else
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, STRINGIZE_NAME(ClassName), UnitTestData::m_instance_counter, UnitTestData::m_latest_instance);                     
        #endif      
    #endif
#else
    #undef DECLARATION_START_EXP
    #ifdef REGISTER_UNITTESTSUITE
        #define DECLARATION_START_EXP(ClassName) extern const UnitTestSuiteData c_test_data_##ClassName     
    #else 
        #define DECLARATION_START_EXP(ClassName) extern const UnitTestData c_test_data_##ClassName      
    #endif  
    #define DECLARATION_START(ClassName) DECLARATION_START_EXP(ClassName)
    #undef REGISTER_UNITTEST
    #ifdef APOXI_UNITTEST_NO_TESTNAMES
        #ifdef REGISTER_UNITTESTSUITE
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, UnitTestData::m_instance_counter, UnitTestData::m_latest_instance, ClassName::GetTestAtStatic);
        #else 
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, UnitTestData::m_instance_counter, UnitTestData::m_latest_instance);        
        #endif      
    #else
        #define STRINGIZE_NAME_EXP(ClassName) L###ClassName
        #define STRINGIZE_NAME(ClassName) STRINGIZE_NAME_EXP(ClassName)
        #ifdef REGISTER_UNITTESTSUITE
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, STRINGIZE_NAME(ClassName), UnitTestData::m_instance_counter, UnitTestData::m_latest_instance, ClassName::GetTestAtStatic);         
        #else
            #define REGISTER_UNITTEST(ClassName) DECLARATION_START(ClassName)(ClassName::CreateInstance, STRINGIZE_NAME(ClassName), UnitTestData::m_instance_counter, UnitTestData::m_latest_instance);
        #endif      
    #endif
#endif

// DEFINES FOR THE DYNAMIC REPOSITORY

class UnitTestAutoRepository: public UnitTestRepository{
    friend UnitTestRepository;
    public:
        virtual ~UnitTestAutoRepository();

        UINT16 GetTestCount() const { return m_count; }

        const UnitTestData* GetTestAt(UINT16 index) const;
        const UnitTestData* GetTestAt(void* address) const;

        BOOLEAN CopyHandleToBuffer(void* buffer, UINT16 index) const;
    
    protected:
        UnitTestAutoRepository();
    private:
                
        static UnitTestAutoRepository* m_instance;

        static const UnitTestData*  m_unit_test_data_anchor;
        static UINT16 m_count;


};


#endif //APOXI_UNITTEST_STATIC_REPOSITORY
#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS
#endif  // Apoxi_UnitTestAutoRepository_hpp

