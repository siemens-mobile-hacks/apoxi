/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_IsrDataMarshaller_hpp)
#define Apoxi_IsrDataMarshaller_hpp


/*  -------------------------------------------------------------------------
                                    Types
    ------------------------------------------------------------------------- */

class IsrDataMarshaller {
    public:
        IsrDataMarshaller();
        virtual ~IsrDataMarshaller();

        virtual void Marshall() = 0;

    private:
        IsrDataMarshaller* m_next;

        friend class IsrDataManager;
};



#endif  // Apoxi_IsrDataMarshaller_hpp


