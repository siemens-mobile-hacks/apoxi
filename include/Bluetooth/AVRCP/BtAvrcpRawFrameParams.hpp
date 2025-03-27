/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpRawFrameParams_hpp)
#define BtAvrcpRawFrameParams_hpp

#include <Bluetooth/BtTypes.hpp>
#include "BtTypes.hpp"

class BtAvrcpRawFrameParams 
{

    public:
        BtAvrcpRawFrameParams();

        virtual ~BtAvrcpRawFrameParams();

        /**********************************************************************/
        /* Avrcp Raw Frame Parameters                             */
        /**********************************************************************/

        const BtAvrcpControlType GetControlType() const { return m_ctype; };

        void SetControlType(BtAvrcpControlType ctype) { m_ctype = ctype; };

        const BtAvrcpSubunitType GetSubunitType() const { return m_subunit_type; };

        void SetSubunitType(BtAvrcpSubunitType subunit_type) { m_subunit_type = subunit_type; };

        const UINT8 GetSubunitId() const { return m_subunit_id; };

        void SetSubunitId(UINT8 subunit_id) { m_subunit_id = subunit_id; };

        const BtAvrcpOpcode GetOpCode() const { return m_opcode; };

        const UINT8 GetOperandsLength() const { return m_operands_length; };

        void SetOperandsLength(UINT8 operands_length) { m_operands_length = operands_length; };

        const UINT8* GetOperands() const { return m_operands; };

        BOOLEAN SetOperands(UINT8* operands);

        BOOLEAN ReleaseOperands();

    private:

        BtAvrcpControlType  m_ctype;
        BtAvrcpStateFlag    m_state_flag;
        BtAvrcpSubunitType  m_subunit_type;
        UINT8               m_subunit_id;
        BtAvrcpOpcode       m_opcode;
        UINT8               m_operands_length;
        UINT8*              m_operands;
};

#endif  // BtAvrcpRawFrameParams_hpp

