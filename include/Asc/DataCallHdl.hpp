/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_DataCall_DataCallHdl_hpp)
#define Asc_DataCall_DataCallHdl_hpp

#include <Asc/Types.hpp>
#include <Asc/DataCallContext.hpp>

class DataCallControl;

class DataCallHdl { 
    friend class DataCallSignalProcessor;
    public:
        static void Init(const DataCallContext &context);

        static CallApiRc Setup(const PhoneNumber &phone_no, 
                               BOOLEAN isdn,
                               UINT data_rate, 
                               DataCallControl *dcc_p);

        static CallApiRc Release();

    private:
        static DataCallContext m_context;
        static DataCallControl *m_dcc_p;    // connection to virtual routines
        static Tipd m_tipd;                 // tipd of csdata call

        static void DataCallTerminated();
};

#endif // Asc_DataCall_DataCallHdl_hpp







