/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_SimChvHandler_hpp)
#define Adc_SimChvHandler_hpp

#include <Adc/BaseDataHandler.hpp>

class SimAccessor;

const INT c_attempts_left_undefined = 0xff;

class SimChvHandler : public BaseDataHandler
{
    typedef BaseDataHandler Base;

    public:
        SimChvHandler();
        virtual ~SimChvHandler();

        void Reset();

// chv handler
        INT GetMaxNumbersStored() const;

        void InitChvData(const SimInfo & simInfo);
        void RefreshChvData(const ChvData& chv_data);
        const ChvData & GetChvData(INT idx) const;

        ChvStatus VerifyChv (ChvNo chv_no, const WString &chv_str);
        ChvStatus ChangeChv (ChvNo chv_no, const WString &old_chv_str, const WString &new_chv_str);
        ChvStatus UnblockChv(ChvNo chv_no, const WString &unblocking_str, const WString &new_chv_str);
        ChvStatus EnableChv (ChvNo chv_no, const WString &chv_str);
        ChvStatus DisableChv(ChvNo chv_no, const WString &chv_str);

// lock states
        void SetSecLockStates(const SecLockStates & lockstates);
        const SecLockStates & GetSecLockStates() const { return m_lockstates; }
// imsi plmn, set by the SimMccMncIndArg signal, used to determine the language
        void SetImsiPlmn(const Plmn & plmn) { m_imsiplmn = plmn; }
        const Plmn & GetImsiPlmn() const { return m_imsiplmn; }

        BOOLEAN IsUnlockingAllowedOnStartup();
        BOOLEAN IsUnlockingAllowedPerMenu();
        BOOLEAN IsUnlockingAllowedKeyBased();

        BOOLEAN ModifyLock(const SecLockAction lockaction, const SecLockType locktype,
                           const WString & oldpwd, const WString & newpwd);

        BOOLEAN UpdateChvData(ChvNo no,
                              ChvStatus status,
                              ChvAttempts attempts_left = c_attempts_left_undefined,
                              ChvAttempts unblocking_attempts_left = c_attempts_left_undefined);

    private:
        void SortSecLockStates();

        INT      m_numbers_stored;
        ChvData  m_chv_data[c_max_chvs];
        BOOLEAN  m_chv_data_initialized;

        SecLockStates m_lockstates; // lock structure
        Plmn          m_imsiplmn;   // imsi plmn used for unlocking for correct language

};

#endif


