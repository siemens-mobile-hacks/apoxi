/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(_Asc_InputAction_hpp)
#define _Asc_InputAction_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Apc/SignalTypes.hpp>

#include <Asc/InputParser.hpp>


void InputAnalyzerTest();


const INT c_invalid_parsed_number = -1;


enum InputActionType {
    PbEntryShowActionType = 10,
    ImeiShowActionType = 20,
    UnlockActionType = 25,
    EngModeActionType = 30,
    ApoxiCommandActionType = 35,
    LanguageResetActionType = 37,
    CallSsActionType = 40,
    PinActionType = 50,
    ClirActionType = 60,
    ClipActionType = 70,
    CnapActionType = 75,
    EmlppActionType = 77,
    BarringSsActionType = 80,
    PasswordChangeSsActionType = 85,
    ColpActionType = 90,
    ColrActionType = 100,
    ForwardingSsActionType = 110,
    WaitSsActionType = 120,
    UserDefinedActionType = 130,
    UssdActionType = 140,
    UndefinedSsActionType = 150,
    MoCallActionType = 160,
    InvalidActionType = 1000
};


class InputContext;

class InputAction
{
    public:
        InputAction();
        virtual ~InputAction(); 
        virtual BOOLEAN IsExecutionPossible();
        virtual BOOLEAN HasWrongSyntax();
        virtual BOOLEAN ShallExecuteImmediatly();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & , const InputContext * );
        virtual BOOLEAN Execute();
        const WString & GetSourceString() const { return m_sourcestring; }

        INT GetParsePriority() const { return (INT)GetActionType(); }

    protected:
        static  INT ParseNumber(const WCHAR * str, INT maxdigits = 255);
        void    Clear() { m_sourcestring.Clear(); m_syntaxerror = FALSE; }

        WString m_sourcestring;
        BOOLEAN m_syntaxerror;
   
};


class PbEntryShowAction : public InputAction
{
    public:
        PbEntryShowAction();
        explicit PbEntryShowAction(INT entrynr);
        virtual ~PbEntryShowAction(); 
        virtual BOOLEAN IsExecutionPossible();
        virtual BOOLEAN ShallExecuteImmediatly();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);
        INT GetEntryNr() const { return m_entrynr; }

    private:
        INT m_entrynr;

};


class UnlockAction : public InputAction
{
    public:
        UnlockAction();
        virtual ~UnlockAction(); 
        virtual BOOLEAN IsExecutionPossible() = 0;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context) = 0;
        virtual BOOLEAN Execute() = 0;

        virtual InputActionType GetActionType() const;

};


class MoCallAction : public InputAction
{
    public:
        enum Type {
            Default,
            DisplayPhoneNumber,
            SurpressPhoneNumber
        };

        MoCallAction();
        explicit MoCallAction(const PhoneNumber & phnr);
        virtual ~MoCallAction(); 
        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        const PhoneNumber & GetPhoneNumber() const { return m_phonenr; }

        MoCallAction::Type GetMocType() const { return m_moc_type; }

    private:
        PhoneNumber m_phonenr;
        Type        m_moc_type;

};


class ImeiShowAction : public InputAction
{
    public:
        ImeiShowAction();
        virtual ~ImeiShowAction(); 
        virtual BOOLEAN ShallExecuteImmediatly();
        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

};


class EngModeAction : public InputAction
{
    public:
        EngModeAction();
        virtual ~EngModeAction(); 

        virtual BOOLEAN ShallExecuteImmediatly();
        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

};


class CallSsAction : public InputAction
{
    public:
        enum CallSsActionId {
            ReleaseAllHeldOrSetUdub,
            ReleaseAllActiveAndAcceptOther,
            ReleaseSpecificCall,
            PlaceAllActiveOnHold,
            PlaceAllActiveOnHoldExceptSpecificCall,
            AddHeldCall,
            ConnectTwoCallsAndDisconnectSubscriber,
            RedirectCall,
            ActivateCompletionOfCalls,
            Invalid
        };
        CallSsAction();
        virtual ~CallSsAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        CallSsActionId GetCallSsActionId() const { return m_type; }
        INT GetCallIdx() const { return m_callidx; }
        const PhoneNumber & GetPhoneNumber() const { return m_phonenr; }

    private:
        CallSsActionId   m_type;
        INT              m_callidx;
        PhoneNumber      m_phonenr;
};


class PinAction : public InputAction
{
    public:
        enum Type {
            ChangePin,
            UnblockPin,
            Invalid
        };

        PinAction();
        virtual ~PinAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual BOOLEAN ShallExecuteImmediatly();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        ChvNo           GetChvNo() const { return m_chvno; }
        PinAction::Type GetType() const { return m_type; }
        const WString & GetOldPin() const { ASSERT(m_type==ChangePin); return m_pin; }
        const WString & GetUnblockPin() const { ASSERT(m_type==UnblockPin); return m_pin; }
        const WString & GetNewPin() const { ASSERT(m_type!=Invalid); return m_newpin1; }
        const WString & GetNewPin2() const { ASSERT(m_type!=Invalid); return m_newpin2; }

    private:
        ChvNo   m_chvno;
        Type    m_type;
        WString m_pin;
        WString m_newpin1;
        WString m_newpin2;
};


class ClirAction : public InputAction
{
    public:
        ClirAction();
        virtual ~ClirAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        InputParser::SsProcedure GetSsProcedure() const { return m_procedure; }
        const PhoneNumber & GetClirPhoneNumber() const { return m_phonenr; }

    private:
        InputParser::SsProcedure m_procedure;
        PhoneNumber              m_phonenr;
};



class NumberIdentificationAction : public InputAction
{
    public:
        NumberIdentificationAction();
        virtual ~NumberIdentificationAction(); 
        virtual BOOLEAN IsExecutionPossible();
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        InputParser::SsProcedure GetSsProcedure() const { return m_procedure; }

    protected:
        virtual InputParser::SsCode GetSsCode() const = 0;

    private:
        InputParser::SsProcedure m_procedure;
};


class ClipAction : public NumberIdentificationAction
{
    public:
        virtual InputActionType GetActionType() const;

    protected:
        virtual InputParser::SsCode GetSsCode() const;

};


class CnapAction : public NumberIdentificationAction
{
    public:
        virtual InputActionType GetActionType() const;

    protected:
        virtual InputParser::SsCode GetSsCode() const;

};


class ColpAction : public NumberIdentificationAction
{
    public:
        virtual InputActionType GetActionType() const;

    protected:
        virtual InputParser::SsCode GetSsCode() const;

};


class ColrAction : public NumberIdentificationAction
{
    public:
        virtual InputActionType GetActionType() const;

    protected:
        virtual InputParser::SsCode GetSsCode() const;

};



class BarringSsAction : public InputAction
{
    public:
        BarringSsAction();
        virtual ~BarringSsAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        InputParser::SsProcedure GetSsProcedure() const { return m_procedure; }
        InputParser::SsCode      GetSsCode() const { return m_code; }

        const WString & GetPassword() const { return m_pw; }
        InputParser::BasicServiceMmiCode GetBasicServiceMmiCode() const { return m_bsg; }

    private:
        InputParser::SsProcedure            m_procedure;
        InputParser::SsCode                 m_code;
        WString                             m_pw;
        InputParser::BasicServiceMmiCode    m_bsg;
};


class EmlppAction : public InputAction
{
    public:
        EmlppAction();
        virtual ~EmlppAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        InputParser::SsProcedure GetSsProcedure() const { return m_procedure; }
        InputParser::SsCode      GetSsCode() const { return m_code; }
        INT                      GetPriority() const { return m_priority; }

    private:
        InputParser::SsProcedure            m_procedure;
        InputParser::SsCode                 m_code;
        INT                                 m_priority;
};



class PasswordChangeSsAction : public InputAction
{
    public:
        PasswordChangeSsAction();
        virtual ~PasswordChangeSsAction(); 
        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        InputParser::SsProcedure GetSsProcedure() const { return m_procedure; }
        InputParser::SsCode      GetSsCode() const { return m_code; }

        const WString & GetOldPassword() const { return m_oldpw; }
        const WString & GetNewPassword() const { return m_newpw; }
        const WString & GetNewPassword2() const { return m_newpw2; }

    private:
        InputParser::SsProcedure            m_procedure;
        InputParser::SsCode                 m_code;
        WString                             m_oldpw;
        WString                             m_newpw;
        WString                             m_newpw2;
};


class ForwardingSsAction : public InputAction
{
    public:
        ForwardingSsAction();
        virtual ~ForwardingSsAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

        InputParser::SsProcedure GetSsProcedure() const { return m_procedure; }
        InputParser::SsCode      GetSsCode() const { return m_code; }

        const WString & GetPhoneNumber() const { return m_phonenr; }
        InputParser::BasicServiceMmiCode GetBasicServiceMmiCode() const { return m_bsg; }
        const WString & GetConditionTimer() const { return m_timer; }

    private:
        InputParser::SsProcedure            m_procedure;
        InputParser::SsCode                 m_code;
        InputParser::BasicServiceMmiCode    m_bsg;
        WString                             m_phonenr;
        WString                             m_timer;
};


class WaitSsAction : public InputAction
{
    public:
        WaitSsAction();
        virtual ~WaitSsAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);
        InputParser::SsProcedure GetSsProcedure() const { return m_procedure; }
        InputParser::BasicServiceMmiCode GetBasicServiceMmiCode() const { return m_bsg; }

    private:
        InputParser::SsProcedure            m_procedure;
        InputParser::BasicServiceMmiCode    m_bsg;

};



class UndefinedSsAction : public InputAction
{
    public:
        UndefinedSsAction();
        virtual ~UndefinedSsAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

    private:
        InputParser::SsProcedure m_procedure;
};


class UssdAction : public InputAction
{
    public:
        UssdAction();
        virtual ~UssdAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);

    private:
};


class ApoxiCommandAction : public InputAction
{
    public:
        ApoxiCommandAction();
        virtual ~ApoxiCommandAction(); 

        virtual BOOLEAN IsExecutionPossible();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);
        UINT GetCommandId() const { return m_command_id; }
        const WString & GetCommandString() const { return m_command_str; }      

    private:
        UINT    m_command_id;
        WString m_command_str;
};


class LanguageResetAction : public InputAction
{
    public:
        LanguageResetAction();
        virtual ~LanguageResetAction(); 
        virtual BOOLEAN IsExecutionPossible();
        virtual BOOLEAN ShallExecuteImmediatly();
        virtual InputActionType GetActionType() const;
        virtual InputAction * Analyze(const WString & actionstring, const InputContext * context);
        INT GetLanguageCode() const { return m_language_code; }

    private:
        INT m_language_code;
};


#endif


