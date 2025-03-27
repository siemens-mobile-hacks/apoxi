/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_StackWrapper_hpp)
#define Apc_StackWrapper_hpp

#include <Kernel/Types.hpp>

#include <Apc/NetworkTypes.hpp>


class Tpdu;
class StackWrapper 
{
    public:
        // access methods to the built-in stack plmn table
        static INT GetCountryListLength();
        static Mcc GetCountryListMcc(INT idx);
        static INT GetCountryListCc(INT idx);
        static const CHAR * GetCountryListName(INT idx);
        static INT GetPlmnListLength();
        static Mnc GetPlmnListMnc(INT idx);
        static Mcc GetPlmnListMcc(INT idx);
        static INT GetPlmnListCc(INT idx);
        static const CHAR * GetPlmnListCountryName(INT idx);
        static const CHAR * GetPlmnListName(INT idx);
        static const CHAR * GetPlmnListShortName(INT idx);
        static INT GetPlmnListNetType(INT idx);

        // returns -1 if no match was found, otherwise the index into the plmn-list
        static INT LookupPlmnEntryIndex(Mcc mcc, Mnc mnc);

        // transformation methods
        static Plmn     TransformBcdPlmnToPlmn(const BcdPlmn & bcd_plmn);
        static BcdPlmn  TransformPlmnToBcdPlmn(const Plmn &plmn);

        static BOOLEAN  IsBcdPlmnMatching(const BcdPlmn &plmn, UINT16 mcc, UINT8 mnc);


        /*  RETURN VALUES:
                negative number         It was not possible to store the short message.
                non negative number     The NVRAM position where the PDU has been stored. */
        static INT FlashWritePdu(const Tpdu &tpdu);
        
        /*  RETURN VALUES:
                negative number         error or no message to read
                0 or positive number    NVRAM position to which the entry has been saved. */
        static INT FlashReadPdu(INT position, Tpdu &tpdu);

        /*  RETURN VALUES:
                negative number:        error or no message to remove
                0 or positive number    NVRAM position from which the entry has been removed. */
        static INT FlashDeletePdu(INT position);

};


#endif

