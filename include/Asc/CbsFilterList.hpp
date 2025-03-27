/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CbsFilterList_hpp)
#define Asc_CbsFilterList_hpp

#include <Kernel/Types.hpp>

#include <Apc/Cbs.hpp>

/*  ========================================================================
    CbsFilterList
    ======================================================================== */

class CbsFilterList  {
    public:
        enum {
            c_max_cbs_applications = 10
        };

        struct CbsFilterListEntry {
            Application * m_app;
            Cbs::Filter * m_filter;

            void Init() {
                m_app = 0;
                m_filter = 0;
            }
            void Clear() {
                m_app = 0;
                delete m_filter;
                m_filter = 0;
            }
        };

        CbsFilterList();
        virtual ~CbsFilterList();

        BOOLEAN IsEmpty() const;
        BOOLEAN PutFilter(Application * app, const Cbs::Filter & filter);
        BOOLEAN RemoveFilter(Application * app);
        const Cbs::Filter * GetFilter(Application * app) const;
        BOOLEAN MergeFilters();
        const Cbs::Filter & GetMergedFilter() const { return m_merge_filter; }
        BOOLEAN IsOfInterest(Application * app, const CbsNewDataIndArg & arg) const;
        
    private:
        BOOLEAN MergeDcsFilter();
        BOOLEAN MergeMidFilter();


        CbsFilterListEntry m_entries[c_max_cbs_applications];
        Cbs::Filter        m_merge_filter;
        

};


#endif // Asc_CbsFilterList_hpp


