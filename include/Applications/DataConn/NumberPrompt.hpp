/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_NumberPrompt_hpp)
#define Apoxi_NumberPrompt_hpp

#include <GuiExtensions/MmiPrompt.hpp>

class NumberPrompt : public MmiPrompt {
    public:
        typedef MmiPrompt Base;

        NumberPrompt();
        virtual ~NumberPrompt();

        void Init(const WCHAR* title = 0);

        void SetUInt(UINT ui);
        UINT GetUInt() const;
        
        void SetInt(INT i);
        INT GetInt() const;
};

#endif  // Apoxi_DataConnWin_hpp
