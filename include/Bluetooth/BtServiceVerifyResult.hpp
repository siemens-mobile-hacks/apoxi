/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtServiceVerifyResult_hpp)
#define BtServiceVerifyResult_hpp

#include <Bluetooth/BtSvrServiceRecord.hpp>

/*  ------------------------------------------------------------------------
    forward declartion
    ------------------------------------------------------------------------ */
class BtServiceVerifyRequest;
class BtOperationSelectDeviceAndPerformServiceVerify;

class BtServiceVerifyResult
{
    public:
        virtual ~BtServiceVerifyResult();

    public:

        BOOLEAN IsValid() const;


        UINT16 GetNumberOfServiceRecords() const;


        BOOLEAN GetServiceRecordAtIndex(UINT16 index, BtSvrServiceRecord& svr_service_record) const;

    private:
        BtServiceVerifyResult();

        BtServiceVerifyResult(const void* data, UINT16 data_size);


        UINT32 GetDataSize() const;


        const void* GetData() const;


        void SetData(const void* data, UINT16 data_size) const;


        BtServiceVerifyResult& operator=(const BtServiceVerifyResult& service_verify_result);

    private:
        BOOLEAN m_is_valid;

        UINT8* m_data;

        UINT32 m_data_size;

        UINT16 m_number_of_service_records;

    private:
        friend class BtServiceVerifyRequest;
        friend class BtOperationSelectDeviceAndPerformServiceVerify;
};

#endif  // BtServiceVerifyResult_hpp

