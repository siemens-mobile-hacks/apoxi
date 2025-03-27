/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_IsrDataContainer_hpp)
#define Apoxi_IsrDataContainer_hpp


/*  -------------------------------------------------------------------------
                                    Types
    ------------------------------------------------------------------------- */

template<class Data, INT c_queue_size = 5> class IsrDataContainer {
    public:
        IsrDataContainer();

        BOOLEAN IsrPushData(const Data& data);
        BOOLEAN ThrPopData(Data& data);

    private:
        struct QueueEntry {
            BOOLEAN m_used;
            Data m_data;
        };

        INT m_isr_idx;
        INT m_thr_idx;
        QueueEntry m_queue[c_queue_size];

        void IncIdx(INT& idx) {
            if (idx == (c_queue_size - 1))
                idx = 0;
            else
                idx++;
        }

};



/*  -------------------------------------------------------------------------
    IsrDataContainer
    ------------------------------------------------------------------------- */
template<class Data, INT c_queue_size> 
IsrDataContainer<Data,c_queue_size>::IsrDataContainer() : 
    m_isr_idx(0),
    m_thr_idx(0)
{
    for (INT i = 0; i < c_queue_size; i++) {
        m_queue[i].m_used = FALSE;
    }
}   // IsrDataContainer


/*  -------------------------------------------------------------------------
    IsrPushData
    ------------------------------------------------------------------------- */
template<class Data, INT c_queue_size> 
BOOLEAN IsrDataContainer<Data,c_queue_size>::IsrPushData(const Data& data)
{
    if (m_queue[m_isr_idx].m_used)
        return FALSE;

    m_queue[m_isr_idx].m_data = data;
    m_queue[m_isr_idx].m_used = TRUE;
    IncIdx(m_isr_idx);

    IsrDataManager::SetPendingDataFlag();

    ASSERT_DEBUG(System::GetFirstAppContainer() != 0);
    System::GetFirstAppContainer()->TriggerIsrDataProcessing();

    return TRUE;
}   // IsrPushData


/*  -------------------------------------------------------------------------
    ThrPopData
    ------------------------------------------------------------------------- */
template<class Data, INT c_queue_size> 
BOOLEAN IsrDataContainer<Data,c_queue_size>::ThrPopData(Data& data)
{
    if (! m_queue[m_thr_idx].m_used)
        return FALSE;

    data = m_queue[m_thr_idx].m_data;
    m_queue[m_thr_idx].m_used = FALSE;

    IncIdx(m_thr_idx);

    return TRUE;
}   // ThrPopData



#endif  // Apoxi_IsrDataContainer_hpp


