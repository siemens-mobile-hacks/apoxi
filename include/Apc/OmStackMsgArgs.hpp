/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "auzinger_view_latest\lnz_apoxi\Apoxi\Apc\OmArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_OmStackMsgArgs_hpp)
#define Apc_OmStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/NetworkTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class OmMultiSlotIndArg
    ====================================================================== */

class OmMultiSlotIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmMultiSlotIndArg();
        
        static const OmMultiSlotIndArg& Cast(const StackMsgArgument& arg);
        void SetSuccess(BOOLEAN success) { m_success = success; }
        BOOLEAN IsSuccess() const { return m_success; }
        
        enum  {
            ID = 1600
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmMultiSlotIndArg*) arg); }
        
        BOOLEAN m_success;
        
    };

// Inline definitions
inline const OmMultiSlotIndArg& OmMultiSlotIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmMultiSlotIndArg!\n");
    return ((OmMultiSlotIndArg &) arg);
}



/*  ======================================================================
    Class OmBandStatusCnfArg
    ====================================================================== */

class OmBandStatusCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmBandStatusCnfArg();
        
        static const OmBandStatusCnfArg& Cast(const StackMsgArgument& arg);
        void SetSupportedBandList(const GsmBandList& supported_band_list) { m_supported_band_list = supported_band_list; }
        const GsmBandList& GetSupportedBandList() const { return m_supported_band_list; }
        void SetUsedBandList(const GsmBandList& used_band_list) { m_used_band_list = used_band_list; }
        const GsmBandList& GetUsedBandList() const { return m_used_band_list; }
        
        enum  {
            ID = 1601
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmBandStatusCnfArg*) arg); }
        
        GsmBandList m_supported_band_list;
        GsmBandList m_used_band_list;
        
    };

// Inline definitions
inline const OmBandStatusCnfArg& OmBandStatusCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmBandStatusCnfArg!\n");
    return ((OmBandStatusCnfArg &) arg);
}



/*  ======================================================================
    Class OmRatChangeCnfArg
    ====================================================================== */

class OmRatChangeCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmRatChangeCnfArg();
        
        static const OmRatChangeCnfArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 1602
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmRatChangeCnfArg*) arg); }
        
    };

// Inline definitions
inline const OmRatChangeCnfArg& OmRatChangeCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmRatChangeCnfArg!\n");
    return ((OmRatChangeCnfArg &) arg);
}



/*  ======================================================================
    Class OmRatChangeIndArg
    ====================================================================== */

class OmRatChangeIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmRatChangeIndArg();
        
        static const OmRatChangeIndArg& Cast(const StackMsgArgument& arg);
        void SetRatChangeMode(const RatChangeMode& rat_change_mode) { m_rat_change_mode = rat_change_mode; }
        const RatChangeMode& GetRatChangeMode() const { return m_rat_change_mode; }
        
        enum  {
            ID = 1603
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmRatChangeIndArg*) arg); }
        
        RatChangeMode m_rat_change_mode;
        
    };

// Inline definitions
inline const OmRatChangeIndArg& OmRatChangeIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmRatChangeIndArg!\n");
    return ((OmRatChangeIndArg &) arg);
}



/*  ======================================================================
    Class OmMultiSlotReqArg
    ====================================================================== */

class OmMultiSlotReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmMultiSlotReqArg(const MultiSlotMode& multi_slot_mode);
        OmMultiSlotReqArg();
        
        static const OmMultiSlotReqArg& Cast(const StackMsgArgument& arg);
        void SetMultiSlotMode(const MultiSlotMode& multi_slot_mode) { m_multi_slot_mode = multi_slot_mode; }
        const MultiSlotMode& GetMultiSlotMode() const { return m_multi_slot_mode; }
        
        enum  {
            ID = 2600
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmMultiSlotReqArg*) arg); }
        
        MultiSlotMode m_multi_slot_mode;
        
    };

// Inline definitions
inline const OmMultiSlotReqArg& OmMultiSlotReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmMultiSlotReqArg!\n");
    return ((OmMultiSlotReqArg &) arg);
}



/*  ======================================================================
    Class OmBandStatusReqArg
    ====================================================================== */

class OmBandStatusReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmBandStatusReqArg();
        
        static const OmBandStatusReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2601
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmBandStatusReqArg*) arg); }
        
    };

// Inline definitions
inline const OmBandStatusReqArg& OmBandStatusReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmBandStatusReqArg!\n");
    return ((OmBandStatusReqArg &) arg);
}



/*  ======================================================================
    Class OmRatChangeReqArg
    ====================================================================== */

class OmRatChangeReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        OmRatChangeReqArg(const RatChangeMode& rat_change_mode);
        OmRatChangeReqArg();
        
        static const OmRatChangeReqArg& Cast(const StackMsgArgument& arg);
        const RatChangeMode& GetRatChangeMode() const { return m_rat_change_mode; }
        
        enum  {
            ID = 2602
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((OmRatChangeReqArg*) arg); }
        
        RatChangeMode m_rat_change_mode;
        
    };

// Inline definitions
inline const OmRatChangeReqArg& OmRatChangeReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to OmRatChangeReqArg!\n");
    return ((OmRatChangeReqArg &) arg);
}


#endif // Apc_OmStackMsgArgs_hpp

