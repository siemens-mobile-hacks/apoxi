/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IsrDataManager_hpp)
#define Apoxi_IsrDataManager_hpp

#include <Kernel/Os/Os.hpp>

class IsrDataMarshaller;

class IsrDataManager {
    public:
        static void ProcessIsrData();

        static BOOLEAN Init();

        static BOOLEAN HasPendingData() { return m_data_flag; }
        static void SetPendingDataFlag(BOOLEAN set = TRUE) { m_data_flag = set; }

    private:
        static BOOLEAN m_data_flag;
        static IsrDataMarshaller* m_first_idm;
        static Semaphore m_sem;
        
        static void Attach(IsrDataMarshaller* idm);
        static void Detach(IsrDataMarshaller* idm);

        friend class IsrDataMarshaller;
};

#endif  // Apoxi_IsrDataManager_hpp


