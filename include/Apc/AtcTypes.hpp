/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_AtcTypes_hpp)
#define Apc_AtcTypes_hpp

#include <Apc/SignalTypes.hpp>

/*  ========================================================================
                                  MePhoneBookType
    ========================================================================*/
// T_MI_PHB_ID  

enum MePhoneBookType {
#if defined(APOXI_ENABLE_ME_PHONEBOOK_REQUEST)
    MePhoneBook         = MI_PHB_ME, 
    DcPhoneBook         = MI_PHB_DC,
    McPhoneBook         = MI_PHB_MC,
    RcPhoneBook         = MI_PHB_RC,
    MbPhoneBook         = MI_PHB_MB,
    MdPhoneBook         = MI_PHB_MD,
    MsPhoneBook         = MI_PHB_MS,
    RdPhoneBook         = MI_PHB_RD,
    SdPhoneBook         = MI_PHB_SD,
    BdPhoneBook         = MI_PHB_BD,
    CdPhoneBook         = MI_PHB_CD,
    CsPhoneBook         = MI_PHB_CS,
    InvalidPhoneBook
#else
    MePhoneBook, 
    DcPhoneBook,
    McPhoneBook,
    RcPhoneBook,
    MbPhoneBook,
    MdPhoneBook,
    MsPhoneBook,
    RdPhoneBook,
    SdPhoneBook,
    BdPhoneBook,
    CdPhoneBook,
    CsPhoneBook,
    InvalidPhoneBook
#endif
};

// T_MI_PB_STATUS  
enum MePhoneBookStatus {
#if defined(APOXI_ENABLE_ME_PHONEBOOK_REQUEST)
    MePbSuccessfull     = MI_SUCCESSFUL,
    MePbUnsuccessfull   = MI_UNSUCCESSFUL, 
    MePbNotPresent      = MI_PB_NOT_PRESENT,
    MePbInvalidIndex    = MI_INVALID_INDEX  
#else
    MePbSuccessfull,    
    MePbUnsuccessfull,
    MePbNotPresent,
    MePbInvalidIndex  
#endif
};

#if defined(APOXI_ENABLE_ME_PHONEBOOK_REQUEST)
const UINT c_max_phonebook_descriptors = MIAT_MAX_NOF_PB;
#else
const UINT c_max_phonebook_descriptors = 12;
#endif



class MePhonebookDescriptor {
    public:
        MePhonebookDescriptor(MePhoneBookType type, INT totalentries, INT maxalphalen) :
                    m_type(type), m_totalentries(totalentries), m_maxalphalen(maxalphalen) {}
        MePhonebookDescriptor() : m_type(InvalidPhoneBook), m_totalentries(0), m_maxalphalen(0) {}
        MePhonebookDescriptor(const MePhonebookDescriptor & desc) 
               : m_type(desc.m_type), 
                 m_totalentries(desc.m_totalentries), 
                 m_maxalphalen(desc.m_maxalphalen) {}
        MePhonebookDescriptor & operator = (const MePhonebookDescriptor & desc) {
            if(&desc!=this) {
                m_type = desc.m_type;
                m_totalentries = desc.m_totalentries;
                m_maxalphalen = desc.m_maxalphalen;
            }
            return *this;
        }
        MePhoneBookType GetMePhoneBookType() const { return m_type; }
        INT GetTotalEntries() const { return m_totalentries; }
        INT GetMaxAlphaLen() const { return m_maxalphalen; }

    private:
        MePhoneBookType m_type;
        INT             m_totalentries;
        INT             m_maxalphalen;


};

class MePhonebookDescription {
    public:
        MePhonebookDescription() : m_counter(0) { }

        MePhonebookDescription(const MePhonebookDescription & desc) : m_counter(desc.m_counter) 
        {
            for(UINT i=0; i<m_counter; i++) {
                m_desc[i] = desc.m_desc[i];
            }
        }
        MePhonebookDescription & operator = (const MePhonebookDescription & desc) {
            if(&desc!=this) {
                m_counter = desc.m_counter;
                for(UINT i=0; i<m_counter; i++) {
                    m_desc[i] = desc.m_desc[i];
                }
            }
            return *this;
        }

        BOOLEAN AppendMePhonebookDescriptor(const MePhonebookDescriptor & desc) {
            if(m_counter<c_max_phonebook_descriptors-1) {
                m_desc[m_counter] = desc;
                m_counter++;
                return TRUE;
            }
            return FALSE;
        }
        const MePhonebookDescriptor & Get(INT idx) const {
            ASSERT_DEBUG(idx<c_max_phonebook_descriptors);
            return m_desc[m_counter];
        }
        UINT GetCount() const { return m_counter; }

    private:
        MePhonebookDescriptor m_desc[c_max_phonebook_descriptors];
        UINT m_counter;
};


const INT c_max_at_req_alpha_id_size = c_max_phonebook_entry_len-c_max_bcd_number_size;


/*  ========================================================================
                             AT Generic Interface
    ========================================================================*/

// T_DATA 
class AtGenericCmdType {

    public:

        AtGenericCmdType() : m_length(0), m_data_ptr(0) { ; }

        AtGenericCmdType(const AtGenericCmdType & cmd) : m_length(0), m_data_ptr(0) { 
            if (cmd.m_length > 0) {
                m_data_ptr = new UINT8[cmd.m_length]; 
                if(m_data_ptr != 0) {
                    m_length = cmd.m_length; 
                    memcpy(m_data_ptr, cmd.m_data_ptr, m_length);
                }
            }
        }
        
        ~AtGenericCmdType() { 
            m_length = 0; 
            delete[] m_data_ptr;
            m_data_ptr = 0;
        }

        void Push(INT length, const UINT8 * data_ptr) {
            m_data_ptr = (length > 0) ? new UINT8[length] : 0;
            if (m_data_ptr != 0) {
                m_length = length;
                memcpy(m_data_ptr, data_ptr, length);
            }
        }

        INT     m_length;
        UINT8 * m_data_ptr;
};

// ATC_RESULT
enum AtStatusType {
#if defined(APOXI_ENABLE_GENERIC_AT_INTERFACE)
    AtStatusSuccess             = ATC_STATUS_SUCCESS,
    AtStatusSuccessNoOutput     = ATC_STATUS_SUCCESS_NO_OUTPUT,
    AtStatusError               = ATC_STATUS_ERROR,
    AtStatusNoCarrier           = ATC_STATUS_NO_CARRIER,
    AtStatusNoAnswer            = ATC_STATUS_NO_ANSWER,
    AtStatusBusy                = ATC_STATUS_BUSY,
    AtStatusCommitSignal        = ATC_STATUS_COMMIT_SIGNAL,
    AtStatusUnsolicitedResult   = ATC_STATUS_UNSOLICITED_RESULT,
    AtStatusSignalNotHandled    = ATC_STATUS_SIGNAL_NOT_HANDLED,
    AtStatusSignalNotExpected   = ATC_STATUS_SIGNAL_NOT_EXPECTED

#else
    AtStatusSuccess,
    AtStatusSuccessNoOutput,
    AtStatusError,
    AtStatusNoCarrier,
    AtStatusNoAnswer,
    AtStatusBusy,
    AtStatusCommitSignal,
    AtStatusUnsolicitedResult,
    AtStatusSignalNotHandled,
    AtStatusSignalNotExpected
#endif
};


#endif  // Apc_AtcTypes_hpp

