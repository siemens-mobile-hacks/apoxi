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

#if !defined(Adc_EccProvider_hpp)
#define Adc_EccProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>

/*------------------------------------------------------------------
                            EccProvider
 ------------------------------------------------------------------*/

#if defined(APOXI_ENABLE_ECC_CUSTOMIZATION)
    const INT c_max_customizable_codes = MAX_ECC_LIST_LEN;
#else
    const INT c_max_customizable_codes = 1;
#endif

class EccProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        EccProvider();
        virtual ~EccProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

        BOOLEAN IsEccCode(const WString & checkstr);

        EccCategory GetEccCategory(const WString & checkstr);

        void SetEccNetworkArray(const EccNetworkArray & eccarray);

    private:
        INT GetNoOfBuiltinEccCodes();
        BOOLEAN FillCustomizedEccs();

        void GetNetworkEcc(INT idx, WString & eccstr, UINT8 & ecccategory);
        INT GetNoOfNetworkEccs() { return m_networkarray.m_number; }

        SimAuxHandler * m_aux_handler;
        EccNetworkArray m_networkarray;

        WString         m_actual_cust_codes[c_max_customizable_codes];
        INT             m_noofcustomizedcodes;

};

/*------------------------------------------------------------------
                            EccCustomization
 ------------------------------------------------------------------*/

#if defined(APOXI_ENABLE_ECC_CUSTOMIZATION)


enum EccSimValidity {
    EccNotValid = 0x00,                                         // no bit set
    EccValidSimNotPresent = MSAP_ECC_SIM_NOT_PRES,              // bit 0 set
    EccValidSimPresent = MSAP_ECC_SIM_PRES,                     // bit 1 set
    EccValidAlways  = MSAP_ECC_SIM_PRES | MSAP_ECC_SIM_NOT_PRES // bit 0 and 1 set
};

class EccCustomization
{
    public:
        EccCustomization();
        ~EccCustomization();

        BOOLEAN AddEccCode(const WString & ecccode, EccSimValidity validity);

        BOOLEAN SetEccVector(INT bufferlen, const UINT8 * buffer);

        BOOLEAN Clear();

        BOOLEAN Commit(BOOLEAN dont_use_hardcoded_eccs);

    // Gets the ECC as WString
        BOOLEAN GetEcc(INT idx, WString & ecc);
    // Gets the EccSimValidity
        EccSimValidity GetEccSimValidity(INT idx);
    // Gets the overall number of set m_noofcodes
        INT GetNoOfCodes() { return m_codes.len; }
    // Shall be hardcoded eccs be used
        BOOLEAN AreHardcodedEccsUsed() { return ! m_dont_use_hardcoded_eccs; }
    
    private:
        T_ECC_CUST_LIST m_codes;
        BOOLEAN         m_dont_use_hardcoded_eccs;
};

#else

// dummy object for the case APOXI_ENABLE_ECC_CUSTOMIZATION is not set 
class EccCustomization
{
};

#endif


#endif

