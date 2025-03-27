/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "APOXI_1.10.0\src\Applications\LcsTransports\GLTP\GltpAppMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(LcsTransports_GLTP_GltpAppMsgTypes_hpp)
#define LcsTransports_GLTP_GltpAppMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Kernel/InputStream.hpp>
#include <Kernel/OutputStream.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class OnDataRcvdMsg
    ====================================================================== */

class OnDataRcvdMsg : public ApplicationMsg {
    public:
        OnDataRcvdMsg(Application* application, BYTE* buffer, INT size);
        virtual ~OnDataRcvdMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        BYTE* GetBuffer() const { return m_buffer; }
        INT GetSize() const { return m_size; }
        virtual Message* Clone() const;
#if !defined(APOXI_NOSTREAMING)
        friend OutputStream& operator << (OutputStream& ostr, const OnDataRcvdMsg& cls);
#endif // APOXI_NOSTREAMING
#if !defined(APOXI_NOSTREAMING)
        friend InputStream& operator >> (InputStream& istr, OnDataRcvdMsg& cls);
#endif // APOXI_NOSTREAMING
        
        enum {
            ID = 22235
            };
        
    protected:
        
#if !defined(APOXI_NOSTREAMING)
        virtual void Dump(OutputStream& ostr) const;
#endif // APOXI_NOSTREAMING
        
    private:
        static const MsgMetaData m_meta_data;
        BYTE* m_buffer;
        INT m_size;
        
    };

#endif // LcsTransports_GLTP_GltpAppMsgTypes_hpp

