/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpDeRegisterRequest_hpp)
#define BtAvrcpDeRegisterRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpRegistrationService;
class BtAvrcpRegistrationController;


class BtAvrcpDeRegisterRequest : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpDeRegisterRequest(BtAvrcpRegistrationService& avrcp_service);

        virtual ~BtAvrcpDeRegisterRequest();

        void SetRole(BtAvrcpRole role) { m_role = role; };

        BtAvrcpRole GetRole() const { return m_role; };


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


    private:
        BtAvrcpRole     m_role;
        
    private:
        friend class BtAvrcpRegistrationService;
        friend class BtAvrcpRegistrationController;

};

#endif  // BtAvrcpDeRegisterRequest

