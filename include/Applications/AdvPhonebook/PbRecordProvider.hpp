/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(Mmi_PbRecordProvider_hpp)
#define Mmi_PbRecordProvider_hpp

#include <Auxiliary/Provider.hpp>
#include <AdvPhonebook/PbRecord.hpp>

class ProviderListener;
class PbRecordHandler;
class PbRecordProvider : public ThreadSafeProvider {

    public:
        typedef ThreadSafeProvider Base;

        enum LastChange {
            Append,
            Commit,
            Delete,
            DeleteAll, 
            None
        };

        PbRecordProvider();
        PbRecordProvider(Protector *protector, PbRecordHandler *m_handler);
        virtual ~PbRecordProvider();

        void Init(Protector *protector, PbRecordHandler *m_handler);

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

        virtual INT RowCount();

        virtual INT MaxRowCount();
        
        virtual BOOLEAN GetDataItem(IN INT columnid, 
                                    IN INT row, 
                                    OUT DataItem & item) = 0;

        virtual BOOLEAN SetDataItem(IN const DataItem & item, 
                                    IN INT columnid) = 0;

        
        virtual BOOLEAN SelectRow(INT row);

        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN AppendRow();
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);
        virtual BOOLEAN Update(ProviderListener * listener = 0);
        INT GetKeyId() const { return m_key_id; };

    protected:
        virtual Record* GetDataRecord() = 0;
        PbRecordHandler* GetHandler() { ASSERT(m_handler != 0); return m_handler; }
        virtual void InitRecord() = 0;

        const IndexTable<INT>* GetRowTable() { return &m_row_table; }
        INT GetFirstFreeRecNo();

    private:    
        void InitRowTable(INT start = 0);
        void UpdateRowTable();

        INT                 m_key_id;
        PbRecordHandler *   m_handler;

        IndexTable<INT>     m_row_table;

        INT                 m_new_recno;
        LastChange          m_last_change;

};

#endif  
