/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_RegApp_hpp)
#define Mmi_RegApp_hpp

#include <Common/MmiApplication.hpp>  
#include "RegAppFirstWin.hpp"

class RegApp : public MmiApplication
{
    typedef MmiApplication Base; 
    
public:

    RegApp();

    virtual ~RegApp();
    
    void Init();
    
    static RegApp* GetInstance();
    

protected:
    
    virtual void OnOpen(); 
    
    virtual void OnClose();
    
    virtual BOOLEAN OnMessage(const Message &msg);

    virtual void OnStartup();
    
    virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);


private:

    static RegApp m_reg_app;

    RegAppFirstWin  m_result_first_win;

    Feature m_feature;
        
};

#endif
