/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Adc_SimTkCommands_hpp)
#define Adc_SimTkCommands_hpp

#include <Adc/DataHandler.hpp>

#if defined(APOXI_ADC_SIMTK_PROACTIVE_CODE)


const INT c_sim_response = 159;
const INT c_sim_toolkit_busy = 147;
const INT c_sim_removed = 9;
const INT c_sim_normal_ending = 144;

enum SimTkTestEventListCode {
    c_useractivity = 0x04,
    c_idlescreenactivity = 0x05,
    c_langselection = 0x07
};

class SimTkCommands 
{
    public:

// sends a proactive sim reset cmd to the sim prozess which leads to a reset of the sim
// for simulation on host, stack debugging and changing values is necessary
        static BOOLEAN SendSimReset();

// triggers a Simtk event notification of type SimTkTestEventListCode
        static BOOLEAN SendSetupEventList(SimTkTestEventListCode code);

// triggers a Simtk language notification 
        static BOOLEAN SendLanguageNotification(ExtLanguage language);

// triggers a Simtk request to ask for the active language
        static BOOLEAN SendProvideLocalLanguage();

// triggers a simtk file refresh notification for a single file please refer to GSM 11.11
        static BOOLEAN SendSimRefresh(UINT16 df, UINT16 ef);

// triggers a refresh of all sim files 
        static BOOLEAN SendSimAllRefresh();

// sends a Simtk 8-bit display text 
        static BOOLEAN SendDisplayText(const WString & text,
                                       BOOLEAN highpriority = FALSE, 
                                       BOOLEAN waitforuser = FALSE);
// sends a Simtk getinkey request
        static BOOLEAN SendGetInkey(const WString & text, 
                                    BOOLEAN digitsonly = FALSE, 
                                    BOOLEAN smsdefaultalphabet = TRUE,
                                    BOOLEAN yesnorequest = FALSE, 
                                    BOOLEAN helpavailable = FALSE);
// sends a Simtk getinput request
        static BOOLEAN SendGetInput(const WString & text, INT min, INT max,
                                    BOOLEAN digitsonly = FALSE, 
                                    BOOLEAN smsdefaultalphabet = TRUE,
                                    BOOLEAN userecho = TRUE, 
                                    BOOLEAN smspacked = FALSE, 
                                    BOOLEAN helpavailable = FALSE);
// send a SimTk playtone request
        static BOOLEAN SendPlayTone(const WString & text = L"",
                                    BOOLEAN tonetag = FALSE, 
                                    UINT8 tone = 0, 
                                    BOOLEAN durationtag = FALSE, 
                                    UINT8 timeunit = 0, 
                                    UINT8 timeinterval = 0);
// send a Simtk setupidletext request
        static BOOLEAN SendSetupIdleModeText(const WString & text);

// send a Simtk menu request
        static BOOLEAN SendSetupMenu(const WString & menutext, 
                                     const WString & item1,
                                     const WString & item2,
                                     BOOLEAN softkeyprefered = FALSE,
                                     BOOLEAN helpavailable = FALSE);



    private:
        static SimApduData m_apdu;
};
#endif

#endif


