/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsAppUtils_hpp)
#define Mmi_LcsAppUtils_hpp

#include <Gui/MessageBox.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>

class WString;
struct LcsMmiQos;
struct ClientId;
struct MlcNumber;

class LcsAppUtils
{
    public:

        ~LcsAppUtils();

        static LcsAppUtils* GetInstance();

        static void ReleaseInstance();

        void DisplayMsg() const;

        void DisplayMsg(const WCHAR* err_str) const;

        BOOLEAN IsReqSent() { return m_is_req_sent; }

        void SetReqSent(BOOLEAN flag) { m_is_req_sent = flag; }

        BOOLEAN GetData(const CHAR* data_type, WString& data);

        BOOLEAN GetData(const CHAR* data_type, INT32& data);

        BOOLEAN StoreData(const CHAR* data_type, const WString& data) const;

        void ProcessSelfLocation();

        void ProcessTransferLocation(const ClientId& client_id, const MlcNumber& mlc_number);

        void SendAbortReq() const;

        void ProcessLocationError(LcsErrorCode err_code);

        void ProcessDispMapDecision(BOOLEAN feature_wai);

        BOOLEAN FormQos(LcsMmiQos& lcs_mmi_qos);


    private:

        LcsAppUtils();

    private:

        static LcsAppUtils* m_self;

        MessageBox m_err_msg_box;

        BOOLEAN m_is_req_sent;

}; // LcsAppUtils

#endif // Mmi_LcsAppUtils_hpp
