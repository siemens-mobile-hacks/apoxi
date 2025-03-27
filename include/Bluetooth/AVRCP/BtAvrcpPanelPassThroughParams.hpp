/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpPanelPassThroughParams_hpp)
#define BtAvrcpPanelPassThroughParams_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>

class BtAvrcpPanelPassThroughParams 
{

    public:
        BtAvrcpPanelPassThroughParams();
        
        BtAvrcpPanelPassThroughParams(BtAvrcpOperation operation, BtAvrcpStateFlag state);

        virtual ~BtAvrcpPanelPassThroughParams();

        /**********************************************************************/
        /* Avrcp Panel Pass Through Parameters                            */
        /**********************************************************************/

        const BtAvrcpOperation GetOperation() const { return (BtAvrcpOperation)m_operation; };

        void SetOperation(BtAvrcpOperation operation) { m_operation = operation; };

        const BtAvrcpStateFlag GetState() const { return m_state_flag; };

        void SetState(BtAvrcpStateFlag state) { m_state_flag = state; };

        const UINT8 GetOperationDataLength() const { return m_operation_data_length; };


        void SetOperationDataLength(UINT8 data_length) { m_operation_data_length = data_length; };

        const UINT8* GetOperationData() const { return m_operation_data; };

        BOOLEAN SetOperationData(UINT8* operation_data);

        BOOLEAN ReleaseOperationData();

    private:
        BtAvrcpOperation    m_operation;
        BtAvrcpStateFlag    m_state_flag;
        UINT8               m_operation_data_length;
        UINT8*              m_operation_data;

};

#endif  // BtAvrcpPanelPassThroughParams

