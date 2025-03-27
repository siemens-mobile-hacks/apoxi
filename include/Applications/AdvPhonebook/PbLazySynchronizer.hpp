/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbLazySynchronizer_hpp)
#define Mmi_PbLazySynchronizer_hpp

#include <AdvPhonebook/PbSynchronizer.hpp>

class PbLazySynchronizer : public PbSynchronizer {
    typedef PbSynchronizer Base;

    public:

        PbLazySynchronizer();
        virtual ~PbLazySynchronizer();
    
        virtual BOOLEAN AutoSyncSim(INT phone_row);
        virtual BOOLEAN AutoSyncPhone(INT sim_row);

        virtual BOOLEAN AutoDeleteSim(INT phone_row);
        virtual BOOLEAN AutoDeletePhone(INT sim_row);

    protected:
        virtual BOOLEAN SyncSim(INT );
        virtual BOOLEAN SyncPhone(INT );
};

#endif  // Mmi_PbLazySynchronizer_hpp
