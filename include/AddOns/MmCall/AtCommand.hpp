/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AtCommand_hpp)
#define Apoxi_AtCommand_hpp

#include <AddOns/MmCall/AtResponse.hpp>

const INT c_max_at_cmd_params = 16;
const INT c_max_specific_at_resp_params = 5;

struct AtCommandMetaInfo;

class AtCommand 
{
    public: 
        enum Type {
            At = 1,
            Atd,
            Ata,
            Ath,
            AtCops,
            AtCbst, 
            AtCrc,
            AtChld,
            AtColp,
            AtClip,
            AtClir,
            AtCmee,
            AtCeer,
            AtClcc,
            AtXcallstat,
            AtXservice,
            AtXceer,
            AtXcallrefuse,
            AtXprogress,
            AtCgactQuery,
            AtCgact,
            AtXcaoc,
            AtTypeInvalid
        };

        AtCommand(Type type, const String parameters[], UINT8 param_cnt);

        
        ~AtCommand();
        
        Type GetType() const { return m_type; };

        const String ToString() const;
    
        static BOOLEAN IsTerminatingResponse(AtCommand::Type cmd, AtResponse::ResponseType resp);

    private:
        AtCommand();
        
        Type m_type;

        String m_parameters[c_max_at_cmd_params];
        
        UINT8 m_param_cnt;

        static const AtCommandMetaInfo m_command_info_table[];
};

struct AtCommandMetaInfo {
    AtCommand::Type             m_command_type;
    CHAR *                      m_str_presentation;
    INT                         m_specific_resp_cnt;
    AtResponse::ResponseType    m_specific_responses[c_max_specific_at_resp_params];
};

struct AtCommandData {
    AtCommand::Type m_command_type;
    CHAR * m_parameters[c_max_at_cmd_params];
    INT m_number_of_params;
    
};

struct AtCommandInfoTable {
    public:

        static INT GetNumberOfEntries() { return c_command_info_size; };
        
        static const AtCommandMetaInfo *GetElementAt(INT index) { return &c_command_info_table[index]; };

    private:
        static const AtCommandMetaInfo c_command_info_table[];

        static UINT c_command_info_size;
};

#endif /* Apoxi_AtResponseIterator_hpp */

