/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsReqProcessor_hpp)
#define AddOns_Lcs_Common_LcsReqProcessor_hpp

struct MolrInfo;
struct MtlrInfo;
struct MolrRepeatInfo;
class Application;
class LcsProviderImplBase;

enum MolrStatus
{
    NonExistent,
    Ongoing,
    Pending
};

class LcsReqProcessor
{
    public:
        
        ~LcsReqProcessor();

        static LcsReqProcessor* GetInstance();

        static void ReleaseInstance();

        void StoreMolr(MolrInfo* molr_info);

        MolrInfo* GetMolr() const;

        void RemoveMolr(Application* app);

        MolrStatus GetMolrStatus(Application* app);

        void MolrProcessed(BOOLEAN remove_molr = FALSE);

        void OnRepMolrTimeOut(UINT16 invoke_id);

        void StoreMtlr(const MtlrInfo* mtlr_info);

        MtlrInfo* GetMtlr();

        MtlrInfo* RetrieveMtlr(UINT16 invoke_id);

        BOOLEAN RequestExists(const LcsProviderImplBase* prov_impl) const;


    private:

        LcsReqProcessor();

        MolrInfo* FindMolr(const Application* app);

        
    private:

        static LcsReqProcessor* m_self;

        LinkedList<MolrInfo> m_molr_list;

        LinkedList<MolrRepeatInfo> m_rep_molr_list;

        LinkedList<MtlrInfo> m_mtlr_list;

        BOOLEAN m_molr_ongoing;

}; // LcsReqProcessor

#endif // AddOns_Lcs_Common_LcsReqProcessor_hpp

