/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_MessageIdentifier_hpp)
#define Apc_MessageIdentifier_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/BitField.hpp>

/*  ========================================================================
    Message Identifier - 3GPP TS 23.041 V4.1.0 [9.4.1.2.2]
    ========================================================================*/
class MessageIdentifier {
    public:
        enum Range {
            PlmnOperatorAssociationsMessageBegin = 0x0000,
            PlmnOperatorAssociationsMessageEnd = 0x03e7,

            LocationServicesRangeBegin = 0x03e8,
            LocationServicesRangeEnd = 0x03ec,

            UnsecureCellBroadcastDataDownloadRangeBegin = 0x1000,
            UnsecureCellBroadcastDataDownloadRangeEnd = 0x107f,

            SecureCellBroadcastDataDownloadRangeBegin = 0x1080,
            SecureCellBroadcastDataDownloadRangeEnd = 0x10ff,

            PlmnOperatorSpecificRangeBegin = 0xa000, 
            PlmnOperatorSpecificRangeEnd = 0xafff, 

            ForStandardizationInFutureVersionsRange1Begin = 0x03ec, 
            ForStandardizationInFutureVersionsRange1End = 0x0fff, 
            
            ForStandardizationInFutureVersionsRange2Begin = 0x1100, 
            ForStandardizationInFutureVersionsRange2End = 0x9fff, 

            ForPlmnOperatorSpecificInFutureVersionsRangeBegin = 0xb000, 
            ForPlmnOperatorSpecificInFutureVersionsRangeEnd = 0xfffe, 
        };

        enum Type {
            InPlmnOperatorAssociationsRange = 0x0000,

            LcsEOtdAssistanceDataMessage = 0x03e8,
            LcsDGpsCorrectionDataMessage = 0x03e9,
            LcsGpsEphemerisAndClockCorrectionDataMessage = 0x03ea,
            LcsGpsAlmanacAndOtherDataMessage = 0x03eb,

            InUnsecureCellBroadcastDataDownloadRange = 0x1000,

            InSecureCellBroadcastDataDownloadRange = 0x1080,

            InPlmnOperatorSpecificRange = 0xa000,

            InPlmnOperatorSpecificForFutureVersionsRange = 0x03ec,


            InReservedForFutureVersionsRange = 0xfffe,

            InvalidType = 0xffff
        };

        MessageIdentifier() : m_bit_field(0xffff) {};
        MessageIdentifier(UINT16 incoming_word) : m_bit_field(incoming_word) {};
        MessageIdentifier(const MessageIdentifier & mid) : m_bit_field(mid.m_bit_field) {};
        BOOLEAN operator == (const MessageIdentifier &mid) const {
                return (m_bit_field == mid.m_bit_field); 
        }

        UINT16 Get() const { return (m_bit_field.Get()); }

        Type GetType() const;
        void SetType(Type type);

        void Clear() { m_bit_field.Clear(); }

    private:
        BitField16 m_bit_field;     
};


/*  ========================================================================
    Message Identifier Range 
    ========================================================================*/
class MessageIdentifierRange : public Linkable<MessageIdentifierRange> {
    public:
        MessageIdentifierRange();
        MessageIdentifierRange(const MessageIdentifier &begin, const MessageIdentifier &end = MessageIdentifier());
        MessageIdentifierRange(const MessageIdentifierRange & midrange) 
            : m_begin(midrange.m_begin), m_end(midrange.m_end) {};
        BOOLEAN operator == (const MessageIdentifierRange &mid_range) const;

        const MessageIdentifier& Begin() const { return (m_begin); }
        void Begin(const MessageIdentifier &begin) { m_begin = begin; }
        const MessageIdentifier& End() const { return (m_end); }
        void End(const MessageIdentifier &end) { m_end = end; }
        BOOLEAN IsValid() { return (m_begin.Get() <= m_end.Get());}

    private:
        MessageIdentifier m_begin;
        MessageIdentifier m_end;
};

/*  ========================================================================
    Message Identifier Container 
    ========================================================================*/
class MessageIdentifierContainer {
    public:
        enum {
            // defines the no of mid-ranges per allocation
            c_inrease_step = 32,
            // defines the maximum number of ranges per container
            c_max_apoxi_no_of_message_identifiers = 128
        };

        // this class hold a pair of ids, as MessageIdentifierRange uses more memory
        class MessageIdentifierPair {
            public:
                MessageIdentifierPair() : m_begin(0xFFFF), m_end(0xFFFF) {};
                MessageIdentifierPair(MessageIdentifier begin, MessageIdentifier end) :
                    m_begin(begin.Get()), m_end(end.Get()) {};
                MessageIdentifierPair(UINT16 begin, UINT16 end) :
                    m_begin(begin), m_end(end) {};

                MessageIdentifierPair(const MessageIdentifierPair & midpair) :
                    m_begin(midpair.m_begin), m_end(midpair.m_end) {};
                MessageIdentifierPair(const MessageIdentifierRange & range) :
                    m_begin(range.Begin().Get()), m_end(range.End().Get()) {};
                
                BOOLEAN operator == (const MessageIdentifierPair &midpair) const {
                    return midpair.m_begin==m_begin && midpair.m_end==m_end;
                }
                BOOLEAN operator == (const MessageIdentifierRange &midrange) const {
                    return midrange.Begin()==m_begin && midrange.End()==m_end;
                }

                UINT16 m_begin;
                UINT16 m_end;
        };

        MessageIdentifierContainer();

        MessageIdentifierContainer(INT preallocsize);

        MessageIdentifierContainer(const MessageIdentifierContainer &midcont);

        ~MessageIdentifierContainer();

        MessageIdentifierContainer& operator =(const MessageIdentifierContainer &midcont);

        // appends a ranges distinct means, only a lookup if it exists is done, before appending
        BOOLEAN AppendDistinct(const MessageIdentifierRange & range);
        // returns if the range exactly exists, means the given range is inside the container
        BOOLEAN Exists(const MessageIdentifierRange & range) const;
        // clears the range, without deleting the container, means reusing memory
        BOOLEAN Clear() {
            m_no_of_pairs = 0;
            return TRUE;
        }
        // removes the range if it is existing as the given range
        BOOLEAN Remove(const MessageIdentifierRange & range);
        // operator []
        const MessageIdentifierRange operator [] (INT idx) const { 
            return MessageIdentifierRange(m_pair[idx].m_begin,m_pair[idx].m_end);
        }
        // returns the number of MessageIdentifierRanges 
        INT GetSize() const { return m_no_of_pairs; }

        // merges a complete container with AppendMerged
        BOOLEAN Merge(const MessageIdentifierContainer &midcont) ;
        // optimize the complete container iterative, means that all overlapping ranges are merged
        BOOLEAN Optimize();
        // merges the container to a given maximum number of ranges 
        BOOLEAN Limit(INT limit);
        // appends a pair at correct position with inserting
        BOOLEAN AppendSorted(const MessageIdentifierPair & pair);

#if defined(_DEBUG) && defined(APOXI_RTOS_WIN32)
        void DbgOut() const;
        void SelfTest() const;
        void FitTest(const MessageIdentifierContainer & cont) const;
#endif

    private:
        // allocates the array
        void Allocate(INT size);
        // assigns the buffer from cont to the object and clears buffer of cont
        void Assign(MessageIdentifierContainer & cont);

        // appends a range merged, means that overlapping areas are taken into account
        BOOLEAN AppendMerged(const MessageIdentifierPair & pair);
        // appends a pair without check and merging
        BOOLEAN Append(const MessageIdentifierPair & pair);


        MessageIdentifierPair * m_pair;
        INT m_no_of_pairs;
        INT m_preallocsize;
};




#endif  // Apc_MessageIdentifier_hpp


