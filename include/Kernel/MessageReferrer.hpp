/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageReferrer_hpp)
#define Apoxi_MessageReferrer_hpp

class Message;

class MessageReferrer {
    public:
        MessageReferrer(Message* msg = 0);

        MessageReferrer(const MessageReferrer& mr);

        virtual ~MessageReferrer();

        virtual MessageReferrer& operator=(const MessageReferrer& mr);

        Message* GetMessage() const { return m_msg; }

    private:
        Message* m_msg;
};

#endif  // Apoxi_MessageReferrer_hpp


