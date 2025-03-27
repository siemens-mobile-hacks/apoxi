/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_TaggedProblemCode_hpp)
#define Apc_TaggedProblemCode_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    Supplementary Service Problem Tag [GSM 04.80, 3.6.7, Table 3.13]
    (msap_msg_mn.pr: 1375)
    ========================================================================*/
class TaggedProblemCode {
    public:
        enum ProblemTag {
            General = 0x00,         // tag = 0x80
            Invoke = 0x01,          // tag = 0x81
            ReturnResult = 0x02,    // tag = 0x82
            ReturnError = 0x03,     // tag = 0x83
            InvalidTag = 0x0f
        };

        enum ProblemCode {

            UnrecognizedComponent       = 0x00, // tag = 0x80, code = 0x00 
            MistypedComponent           = 0x01, // tag = 0x80, code = 0x01
            BadlyStructuredComponent    = 0x02, // tag = 0x80, code = 0x02;

            DuplicateInvokeId           = 0x10, // tag = 0x81, code = 0x00
            UnrecognizedOperation       = 0x11, // tag = 0x81, code = 0x01
            MistypedProParameter        = 0x12, // tag = 0x81, code = 0x02
            ResourceLimitation          = 0x13, // tag = 0x81, code = 0x03;
            InitiatingRelease           = 0x14, // tag = 0x81, code = 0x04;
            UnrecognizedLinkedId        = 0x15, // tag = 0x81, code = 0x05;
            LinkedResponseUnexpected    = 0x16, // tag = 0x81, code = 0x06;
            UnexpectedLinkedOperation   = 0x17, // tag = 0x81, code = 0x07;

            UnrecognizedInvokeId        = 0x20, // tag = 0x82, code = 0x00;
            ReturnResultUnexpected      = 0x21, // tag = 0x82, code = 0x01;
            MistypedResParameter        = 0x22, // tag = 0x82, code = 0x02;

            UnrecognizedErrorInvokeId   = 0x30, // tag = 0x83, code = 0x00;
            ReturnErrorUnexpected       = 0x31, // tag = 0x83, code = 0x01;
            UnrecognizedError           = 0x32, // tag = 0x83, code = 0x02;
            UnexpectedError             = 0x33, // tag = 0x83, code = 0x03;
            MistypedErrorParameter      = 0x34, // tag = 0x83, code = 0x04;

            InvalidCode                 = 0x0f
        };

        explicit TaggedProblemCode(UINT8 incoming_tag = InvalidTag, UINT8 incoming_code = InvalidCode)
            // msb of incoming tag is shifted away (identification done by lsb of incoming tag)
            : m_tagged_problem_code((incoming_tag << 4) | incoming_code) {};

        TaggedProblemCode(const TaggedProblemCode & code) 
            : m_tagged_problem_code(code.GetProblemCode()) {}

        TaggedProblemCode(const ProblemCode code)
            : m_tagged_problem_code((UINT8)code) {}

        UINT8 GetTagAsByte() const { return (m_tagged_problem_code >> 4) | 0x80; }
        UINT8 GetCodeAsByte() const { return m_tagged_problem_code & 0x0f; }


        ProblemTag GetProblemTag() const { return (ProblemTag)(m_tagged_problem_code >> 4); } // 0xff->0x0f InvalidTag;


        ProblemCode GetProblemCode() const { return (ProblemCode)m_tagged_problem_code; }
        void SetProblemCode(ProblemCode code) { m_tagged_problem_code = code; } // tag is set implicitly

    private:
        UINT8 m_tagged_problem_code;
};


#endif  // Apc_TaggedProblemCode_hpp


