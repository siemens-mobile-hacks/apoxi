/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------

    The implementation of the class BidiManager has been taken from the
    sample implementation of the Unicode Bidirectional Algorithm and
    has been adapted to work within APOXI. See
    http://www.unicode.org/unicode/reports/tr9 for the sample
    implementation.

    Original quote: 
    "Disclaimer and legal rights: This file contains bugs.
    All representations to the contrary are void.

    Source code in this file and the accompanying headers and included files
    may be distributed free of charge by anyone, as long as full credit is 
    given and any and all liabilities are assumed by the recipient.

    Written by: Asmus Freytag
    Command line interface by: Rick McGowan
    Verification and Test Harness: Doug Felt

    Copyright (C) 1999, ASMUS, Inc. All Rights Reserved" 
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BidiManager_hpp)
#define Apoxi_BidiManager_hpp

#include <Kernel/Types.hpp>

class BidiManager {
    public:
        enum CharType {
            NeutralType,
            LeftToRightType,
            RightToLeftType
        };

        struct ParagraphContext {
            WCHAR* dest_text;
            INT* dest_pos;
            INT* types;
            INT* levels;
            INT base_level;
            INT from;
            INT count;
        };

        static BidiManager* GetInstance();

        void SetActive(BOOLEAN flag) { m_is_active = flag; }

        BOOLEAN IsActive() const { return m_is_active; }

        ParagraphContext* BeginProcessing(const WCHAR* text, INT from = 0, INT count = -1);

        void EndProcessing(ParagraphContext* context);

        const WCHAR* GetConvertedText(ParagraphContext* context,
                                      INT from = 0,
                                      INT count = -1,
                                      INT* cursor_pos = 0);

        const INT* GetConvertedPositions(ParagraphContext* context,
                                         INT from = 0) const
        {
            if (!m_alloc_ok)
                return 0;
            else
                return &context->dest_pos[from];
        }

        INT RemoveFormattingCodes(WCHAR* text, INT char_count);

        CharType GetCharType(WCHAR chr) const;

    private:
        enum BidiType {
            ON = 0,  // Other Neutral  
            L,       // Left Letter 
            R,       // Right Letter 
            AN,      // Arabic Number
            EN,      // European Number
            AL,      // Arabic Letter (Right-to-left)
            NSM,     // Non-spacing Mark
            CS,      // Common Separator
            ES,      // European Separator
            ET,      // European Terminator (post/prefix e.g. $ and %)
    
            // resolved types
            BN,      // Boundary neutral (type of RLE etc after explicit levels)
    
            // input types, 
            S,       // Segment Separator (TAB) - used only in L1
            WS,      // White space - used only in L1
            B,       // Paragraph Separator (aka as PS)
    
            // types for explicit controls
            RLO,     // these are used only in X1-X9
            RLE,
            LRO,
            LRE,
            PDF,

            // resolved types, also resolved directions
            N = ON,  // alias, where ON, WS and S are treated the same
        };

        enum State {
            xa,     //  arabic letter            
            xr,     //  right leter           
            xl,     //  left letter           
                                                   
            ao,     //  arabic lett. foll by ON  
            ro,     //  right lett. foll by ON    
            lo,     //  left lett. foll by ON     
                                                   
            rt,     //  ET following R          
            lt,     //  ET following L        
                                                   
            cn,     //  EN, AN following AL      
            ra,     //  arabic number foll R    
            re,     //  european number foll R  
            la,     //  arabic number foll L    
            le,     //  european number foll L  
                                                   
            ac,     //  CS following cn          
            rc,     //  CS following ra       
            rs,     //  CS,ES following re       
            lc,     //  CS following la       
            ls,     //  CS,ES following le        

            ret,    //  ET following re
            let,    //  ET following le
        };

        enum Action {
            // primitives
            IX = 0x100,                 // increment
            XX = 0xF,                   // no-op

            // actions
            xxx = (XX << 4) + XX,       // no-op
            xIx = IX + xxx,             // increment run
            xxN = (XX << 4) + ON,       // set current to N
            xxE = (XX << 4) + EN,       // set current to EN
            xxA = (XX << 4) + AN,       // set current to AN
            xxR = (XX << 4) + R,        // set current to R
            xxL = (XX << 4) + L,        // set current to L
            Nxx = (ON << 4) + 0xF,      // set run to neutral
            Axx = (AN << 4) + 0xF,      // set run to AN
            ExE = (EN << 4) + EN,       // set run to EN, set current to EN
            NIx = (ON << 4) + 0xF + IX, // set run to N, increment
            NxN = (ON << 4) + ON,       // set run to N, set current to N
            NxR = (ON << 4) + R,        // set run to N, set current to R
            NxE = (ON << 4) + EN,       // set run to N, set current to EN

            AxA = (AN << 4) + AN,       // set run to AN, set current to AN
            NxL = (ON << 4) + L,        // set run to N, set current to L
            LxL = (L << 4) + L,         // set run to L, set current to L
        };

        enum ActionValue {
            // action to resolve previous input
            nL = L,         // resolve EN to L
            En = 3 << 4,    // resolve neutrals run to embedding level direction
            Rn = R << 4,    // resolve neutrals run to strong right
            Ln = L << 4,    // resolved neutrals run to strong left
            In = (1<<8),    // increment count of deferred neutrals
            LnL = (1<<4)+L, // set run and EN to L
        };

        enum StateValue {
            r,  // R and characters resolved to R
            l,  // L and characters resolved to L
            rn, // N preceded by right
            ln, // N preceded by left
            a,  // AN preceded by left (the abbrev 'la' is used up above)
            na, // N preceeded by a
        };

        BOOLEAN m_is_active;
        ParagraphContext m_context;
        
        static INT m_char_types[];
        static INT m_bidi_types[];
        static INT m_weak_state[][10];
        static INT m_weak_action[][10];                                       
        static INT m_action_neutrals[][5];
        static INT m_state_neutrals[][5];
        static INT m_add_level[][4];

        INT m_max_length;
        BOOLEAN m_alloc_ok;

        BidiManager();

        INT Classify(const WCHAR* dest_text,
                     INT* pcls,
                     INT char_count,
                     BOOLEAN whitespace = FALSE);

        INT ResolveParagraphs(INT* types, INT char_count);

        INT GetBaseLevel(const INT* pcls, INT char_count);

        INT ResolveExplicit(INT level,
                            INT dir,
                            INT* pcls,
                            INT* p_level,
                            INT char_count, 
                            INT depth = 0);
    
        void ResolveWeak(INT base_level, INT* pcls, INT* p_level, INT char_count);

        void ResolveNeutrals(INT base_level,
                             INT* pcls,
                             const INT* p_level,
                             INT char_count);

        void ResolveImplicit(const INT* pcls, INT* p_level, INT char_count);

        INT ResolveLines(const WCHAR* dest_text, BOOLEAN* pbrk, INT char_count);

        void ResolveWhitespace(INT base_level, const INT* pcls, INT* p_level, 
                               INT char_count);

        INT Reorder(INT base_level,
                    WCHAR* dest_text,
                    INT* dest_pos,
                    const INT* p_level,
                    INT char_count,
                    INT* cursor_pos);

        INT ReorderLevel(INT level,
                         WCHAR* dest_text,
                         INT* dest_pos,
                         const INT* p_level,
                         INT start_idx,
                         INT char_count,
                         INT* cursor_pos,
                         BOOLEAN reverse = FALSE);

        void MirrorText(WCHAR* dest_text, const INT * p_level, INT char_count);

        void WrapLine(INT base_level,
                      WCHAR* dest_text,
                      INT* dest_pos,
                      INT* pcls_line, 
                      INT* p_level_line,
                      INT char_count,
                      BOOLEAN mirror,
                      INT* cursor_pos,
                      BOOLEAN* pbrk = 0);

        INT ClassFromChN(WCHAR ch);
        INT ClassFromChWS(WCHAR ch);
        void SetDeferredRun(INT* pval, INT count, INT start, INT value);
        INT GreaterEven(INT i);
        INT GreaterOdd(INT i);
        INT EmbeddingDirection(INT level);
        INT GetDeferredType(INT action);
        INT GetResolvedType(INT action);
        INT GetDeferredNeutrals(INT action, INT level);
        INT GetResolvedNeutrals(INT action);

        static BidiManager m_bidi_manager;
};


#endif // Apoxi_BidiManager_hpp


