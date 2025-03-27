/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtTransport_hpp)
#define BtTransport_hpp

#include <Devices/AbstractTransport.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtTransport: public AbstractTransport
{
    private:
        typedef AbstractTransport Base;

    public:

        static BtTransport& GetInstance();

    public:
        virtual ~BtTransport();


        virtual void Enable();


        virtual AvState GetAvState() const;

    private:
        BtTransport(const WCHAR* mmi_name);

    private:
        static BtTransport m_transport;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtTransport_hpp


