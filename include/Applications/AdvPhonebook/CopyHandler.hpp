/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Mmi_CopyHandler_hpp)
#define Mmi_CopyHandler_hpp

class MmiAdvancedProgressBox;
class CopyHandler {

    public:
        CopyHandler();
        CopyHandler(Provider *src_prov, Provider *dst_prov);
        virtual ~CopyHandler();
        
        void Init(Provider *src_prov, Provider *dst_prov);

        BOOLEAN CopyAll(MmiAdvancedProgressBox *listener = 0);

        BOOLEAN CopyRow(INT row);

    private:
        Provider *  m_src_prov;
        Provider *  m_dst_prov;
};

class PbProvider;
class PbCopyHandler : public CopyHandler {
    typedef CopyHandler Base;

    public:
        PbCopyHandler();
        virtual ~PbCopyHandler();

        void Init(Provider *src_prov, Provider *dst_prov);

        BOOLEAN CopyPbRow(INT row);

    private:
        Provider *m_src_prov;

};

#endif  // Mmi_PbCopyHandler_hpp

