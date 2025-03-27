/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SavingProgressWin_hpp)
#define Mmi_SavingProgressWin_hpp

class SavingProgressWin : public Window {
    typedef Window Base;

    public:
        SavingProgressWin();
        ~SavingProgressWin();
        void Init();
        
    protected:
        virtual void OnLayoutClient();
        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnOpen();
        virtual void OnClose();
    
    private:
        TextLine m_text_line;
        ProgressBar m_progress_bar;
};

#endif  // Mmi_SavingProgressWin_hpp
