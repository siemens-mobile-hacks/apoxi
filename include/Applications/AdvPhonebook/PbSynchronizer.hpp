/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbSynchronizer_hpp)
#define Mmi_PbSynchronizer_hpp

#include <GuiExtensions/MmiAdvancedProgressBox.hpp>
#include <AdvPhonebook/PbSimProvider.hpp>

class PbSynchronizer {

    public:

        PbSynchronizer();
        virtual ~PbSynchronizer();

        void Init(Application *app, Provider *pb_prov, Provider *sim_prov);

        virtual BOOLEAN Synchronize(MmiAdvancedProgressBox *sync_progress_box = 0);

        virtual BOOLEAN SyncSimAll(MmiAdvancedProgressBox *sync_progress_box = 0);
        virtual BOOLEAN SyncPhoneAll(MmiAdvancedProgressBox *sync_progress_box = 0);

        virtual BOOLEAN SyncSimOne(INT phone_row);
        virtual BOOLEAN SyncPhoneOne(INT sim_row);

        virtual BOOLEAN AutoSyncSim(INT phone_row) = 0;
        virtual BOOLEAN AutoSyncPhone(INT sim_row) = 0;

        virtual BOOLEAN AutoDeleteSim(INT phone_row) = 0;
        virtual BOOLEAN AutoDeletePhone(INT sim_row) = 0;

        BOOLEAN IsSynchronizing() const { return m_is_synchronizing; };
        BOOLEAN IsSynchronized() const { return m_is_synchronized; };

        INT GetProgress() { return m_progress; }

        Provider* GetSimProvider() { return m_sim_prov; }
        Provider* GetPbProvider() { return m_pb_prov; }

        virtual void Update();

        void SetCanceled(BOOLEAN cancel) { m_is_canceled = cancel; }
        BOOLEAN IsCanceled() { return m_is_canceled; }
        void SetPbHasGrown(BOOLEAN grown) { m_pb_entries_added = grown; }
        BOOLEAN HasPbGrown() { return m_pb_entries_added; }

    protected:
        
        virtual BOOLEAN SyncSim(INT no_row) = 0;
        virtual BOOLEAN SyncPhone(INT no_row) = 0;

        void SetSynchronizing(BOOLEAN sync) { m_is_synchronizing = sync; }
        void SetSynchronized(BOOLEAN sync) { m_is_synchronized = sync; }

        Application* GetApplication() const { return m_app; }

    private:
        Application *           m_app;
        Provider *              m_sim_prov;
        Provider *              m_pb_prov;

        INT                     m_progress;

        BOOLEAN                 m_is_synchronizing;
        BOOLEAN                 m_is_synchronized;

        Semaphore               m_sem;

        BOOLEAN                 m_is_canceled;
        BOOLEAN                 m_pb_entries_added;
};

#endif  // Mmi_PbSynchronizer_hpp
