/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_RegAppWin_hpp)
#define Mmi_RegAppWin_hpp


#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/RadioButtonListBoxModel.hpp>
#include <GuiExtensions/DrawableObjectListBox.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <Socket/SocketHandler.hpp>
#include <Socket/TcpSocket.hpp>

#include "RegEncoderDecoder.hpp"


class RegTcpSocket : public TcpSocket
{
    typedef TcpSocket Base;

    public:

        RegTcpSocket();

        ~RegTcpSocket();
        
    protected:

        virtual void OnAsyncEvent(Event event);
};


class RegAppWin : public MmiWindow
{
    typedef MmiWindow Base;

public:

    RegAppWin();

    ~RegAppWin();
    
    void Init();
    
    static RegAppWin* GetInstance();

    void InitSocket();

    void HandleByteStream(UINT8* ptr);
    
    void ConnectToPC(const IpAddr& ip_addr, UINT16 port_no);

    BOOLEAN SendSetUpMsgToPC();

    void SendRegisterNotification(const Uri& uri);

#if !defined(APOXI_RTOS_WIN32)

    DataConnProfileId m_profileId;

#endif

    void FindDataConnProfiles();

    static BOOLEAN m_socket_connected;
    static INT16   m_lock_id;


protected:

    virtual void OnOpen();
        

private:

    static RegAppWin m_RegAppWin;
    
    static RegEncoderDecoder *pRegCoder;

    RegEncoderDecoder::Mobile2PCMsg* m_Mob2PCMsg;

    RegEncoderDecoder::PC2MobileMsg* m_PC2MobMsg;
   
    DrawableObjectListBox mListBox;

    RadioButtonListBoxModel mRadioButtonListBoxModel;

    RadioButtonAction mRadioButtonAction[3];

    CloseWindowAction mCloseWinAction;

    BOOLEAN EncodeAndSendDataToPC(UINT8* buffer, RegEncoderDecoder::Mobile2PCMsg& m_Mob2PCMsg, UINT8 packet_number);
    
    BOOLEAN SendDataToPC(UINT8* buffer, UINT16 BytesToWrite);
    
    BOOLEAN HandleConnectionClose(UINT8* buffer, RegEncoderDecoder::Mobile2PCMsg& m_Mob2PCMsg);
    
    BOOLEAN HandleBigBlob(UINT8* buffer,RegEncoderDecoder::Mobile2PCMsg& m_Mob2PCMsg);
    
    static RegTcpSocket tcp_Sock;

    SocketHandler sock_handler_tcp;

}; // RegAppWin

#endif // Mmi_RegAppWin_hpp
