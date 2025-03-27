/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_development\src\Apoxi\ObEx\ObexVCardMsg.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Obex_ObexVCardMsg_hpp)
#define Obex_ObexVCardMsg_hpp

#include <Kernel/Message.hpp>
#include <Obex/VCard.hpp>
#include <Kernel/InputStream.hpp>
#include <Kernel/OutputStream.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class ObexVCardMsg
    ====================================================================== */

class ObexVCardMsg : public Message {
    public:
        ObexVCardMsg(const VCard& vCard);
        virtual ~ObexVCardMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const VCard& GetVCard() const { return m_vCard; }
        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const ObexVCardMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, ObexVCardMsg& cls);
#endif // APOXI_NOSTREAMING
        
        enum {
            ID = 22001
            };
        
    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        VCard m_vCard;
        
    };

#endif // Obex_ObexVCardMsg_hpp

