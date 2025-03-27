/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestResult_hpp)
#define Apoxi_UnitTestResult_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

#include "UnitTestMacros.hpp"
#include <Auxiliary/Vector.hpp>


class UnitTestError {
public:

    UnitTestError(const CHAR* file_name, INT line_number, BOOLEAN setup_error, BOOLEAN teardown_error);
    UnitTestError(BOOLEAN setup_error, BOOLEAN teardown_error);
    virtual ~UnitTestError();
    const CHAR* GetFileName() const { return m_file_name;};
    INT GetLineNumber() const { return m_line_number;};
    BOOLEAN IsSetupError() const { return m_setup_error;};
    BOOLEAN IsTeardownError() const { return m_teardown_error;};
private:
    CHAR* m_file_name;
    INT     m_line_number;
    BOOLEAN m_setup_error;
    BOOLEAN m_teardown_error;
};

class UnitTestResult {

    public:     
        virtual ~UnitTestResult();
        static UnitTestResult& GetInstance();
        void AddError(UnitTestError* test_error);
        void AddSuccess() { m_successes++; }
        void SetMaxErrorCount(INT max_error);
        void Clear();

        UINT16 GetFailureCount() const { return m_failures; }
        UINT16 GetSuccessCount() const { return m_successes; }
        UINT16 GetSetupErrorCount() const { return m_setup_errors; }
        UINT16 GetTeardownErrorCount() const { return m_teardown_errors; }

        UINT16 GetDetailedErrorCount() { return m_detailed_error_count; }
        UnitTestError* GetDetailedError(UINT16 index) { return m_error_list[index]; }

    private:

        UnitTestError* m_error_list[APOXI_UNIT_MAX_ERROR_HARD_LIMIT];
        UINT16 m_detailed_error_count;
        UINT16 m_successes;
        UINT16 m_max_error;
        UINT16 m_failures;
        UINT16 m_setup_errors;
        UINT16 m_teardown_errors;
        static UnitTestResult m_instance;
        static BOOLEAN m_initialized;
        UnitTestResult();
};

#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTestResult_hpp

