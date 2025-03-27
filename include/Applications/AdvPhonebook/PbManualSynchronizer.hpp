/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbManualSynchronizer_hpp)
#define Mmi_PbManualSynchronizer_hpp

#include <AdvPhonebook/PbLazySynchronizer.hpp>

class PhonebookApp;

class PbManualSynchronizer : public PbLazySynchronizer {
    typedef PbLazySynchronizer Base;

    public:

        PbManualSynchronizer();
        virtual ~PbManualSynchronizer();
    
        void Init(PhonebookApp *app, Provider *pb_prov, Provider *sim_prov);

        virtual void Update();

    protected:

        virtual BOOLEAN SyncSim(INT no_row);
        virtual BOOLEAN SyncPhone(INT no_row);

        BOOLEAN AddPbEntry(const DataItem &name, const DataItem &phoneno, const DataItem &sim_pos);
        BOOLEAN AddSimEntry(const DataItem &name, const DataItem &phoneno);
        BOOLEAN AddNumber(INT name_row, const DataItem &phoneno, const DataItem &simpos);
        BOOLEAN UpdateItem(Provider *prov, INT row, const DataItem &item, INT column_id);

        BOOLEAN EqualName(INT pb_no_row, INT sim_row);
        BOOLEAN EqualNumber(INT sim_row, INT pb_row);

        INT GetProvRow(Provider *prov, const DataItem &item, INT column_id) const;
        INT FindRow(Provider *prov, const DataItem &name, const DataItem &phoneno) const;

        BOOLEAN DoAddNumber(INT name_row);

        BOOLEAN AlphaTagSizeError(const WString &str);
        void ShrinkString(WString &str);
        void GetUniqueString(WString &str);
    
//      IndexTable<INT>* GetSimPosTable() { return &m_simpos_table; }

    private:
        BOOLEAN ExistName(const WString &name_str);
        void IncreaseSimposTable(INT row);

        PhonebookApp* m_app;
        QuickSortProvider m_sort_simpos_prov;
        IndexTable<INT>  m_simpos_table;
};

#endif  // Mmi_PbManualSynchronizer_hpp
