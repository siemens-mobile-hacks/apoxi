/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StreamingInfo_hpp)
#define Apoxi_StreamingInfo_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/String.hpp>

class StreamingInfo {
    public:
        // OperationState enum --------------------------------------------------------------------

        enum OperationState {
            OperationCompletedSynchroneously,

            OperationCompleted,

            OperationNotCompleted,

            OperationErroneous,

            OperationFailed,

            // Operation is not supported
            OperationNotSupported, 

            // Other state 
            OperationOtherState
        };

        // Constructors, destructor ---------------------------------------------------------------

        StreamingInfo();

        ~StreamingInfo();

        // Getters --------------------------------------------------------------------------------

        OperationState GetOperationState() const { return m_op_state; }

        BOOLEAN IsOperationCompletedSynchroneously() const;

        BOOLEAN IsOperationCompleted() const;

        BOOLEAN IsOperationErroneous() const;

        BOOLEAN IsOperationFailed() const;

        String GetErrorMessage() const { return m_error_msg; }

        UINT32 GetDeviceErrorCode() const { return m_device_error_code; }

        // Setters --------------------------------------------------------------------------------

        void SetOperationState(OperationState op_state) { m_op_state = op_state; }

        void SetErrorMessage(const String& error_msg) { m_error_msg = error_msg; }

        void SetDeviceErrorCode(INT32 error_code) { m_device_error_code = error_code; }

        // Private part ---------------------------------------------------------------------------

    private:
        OperationState m_op_state;

        String m_error_msg;

        INT32 m_device_error_code;
};

#endif  // Apoxi_StreamingInfo_hpp

