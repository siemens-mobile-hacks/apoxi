/*  ------------------------------------------------------------------------
**  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
**  ------------------------------------------------------------------------
**  This document contains proprietary information belonging to COMNEON.
**  Passing on and copying of this document, use and communication of its
**  contents is not permitted without prior written authorisation.
**  ------------------------------------------------------------------------ 
*/
 
#if ! defined(Apoxi_AuxExtensions_AppendProvider_hpp)
#define Apoxi_AuxExtensions_AppendProvider_hpp

#include <Auxiliary/AbstractDelegationProvider.hpp>


class AppendProvider : public AbstractDelegationProvider {

    typedef AbstractDelegationProvider Base;

    public:

        AppendProvider();

        virtual ~AppendProvider();

        void Init();

        virtual INT GetProviderId() const;
        
        void SetProviderId(INT provider_id) {m_provider_id = provider_id;}

        virtual INT RowCount();

        virtual INT MaxRowCount();

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem &item);

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual BOOLEAN AppendRow();

        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);

        virtual BOOLEAN AddChildProvider(Provider* provider);
        
        virtual BOOLEAN RemoveChildProvider(Provider* provider);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();
        
        virtual INT GetSortedColumnId() const;

        virtual INT GetProgress();
        
        virtual BOOLEAN SetParameter(const DataItem &item);
        virtual void OnExecutingListener(Provider* provider = 0);

    protected:

        virtual BOOLEAN GetMappedRow(INT & mappedrow, INT row);

        virtual void OnChildProviderModification(Provider* provider, const Provider::Modification& modification);   


    private:
        Vector<Provider*>   m_provider_vec;

        INT                 m_provider_id;

};

#endif //Apoxi_AuxExtensions_AppendProvider_hpp


