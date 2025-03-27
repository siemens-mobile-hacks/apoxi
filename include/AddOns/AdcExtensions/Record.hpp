/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AdcExtensions_Record_hpp)
#define Apoxi_AdcExtensions_Record_hpp

class Record {

    public:
        Record() {};

        virtual const UINT8* GetData() = 0;

        virtual void SetData(const UINT8* data) = 0;

        virtual INT GetPersistentSize() = 0;

        virtual void MarkDeleted() {};

        virtual BOOLEAN IsRecordDeleted() { return FALSE; }

};

#endif  // Apoxi_AdcExtensions_Record_hpp

