/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_EmsCreator_hpp)
#define Ems_EmsCreator_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/Provider.hpp>
#include <Auxiliary/BufferedData.hpp>
#include <Apc/Sms.hpp>
#include <Apc/BaseInformationElement.hpp>
#include <Apc/InformationElement.hpp>
#include <Adc/CompoundSmsItem.hpp>
#include <Asc/SmsContext.hpp>
#include <Asc/SmsFactory.hpp>

#include <Gui/EditorDocument.hpp>
#include <Gui/Color.hpp>
#include <Gui/Font.hpp>
#include <Gui/CharItem.hpp>
#include <Gui/IpAddrCompoundItem.hpp>
#include <Gui/DateCompoundItem.hpp>
#include <Gui/TimeCompoundItem.hpp>
#include <Gui/TextCompoundItem.hpp>
#include <AddOns/MultiMedia/GeneralCompoundItem.hpp>
#include <AddOns/MultiMedia/ParagraphCompoundItem.hpp>
#include <AddOns/MultiMedia/ParagraphMarker.hpp>
#include <AddOns/MultiMedia/RichTextCompoundItem.hpp>
#include <AddOns/MultiMedia/ImageItem.hpp>
#include <AddOns/MultiMedia/SoundItem.hpp>

#include <AddOns/MultiMedia/IMelody.hpp>
#include <Ems/EmsImage.hpp>
#include <Ems/PredefinedEmsSound.hpp>
#include <Ems/PredefinedEmsImage.hpp>

class EmsCreator {
    public:
        struct SpaceInfo {
            UINT8   m_pdu_count;
            UINT8   m_free_chars;
        };
        
        EmsCreator();
        ~EmsCreator();  // not virtual!
        
        SpaceInfo GetSpaceInfo(const EditorDocument& document, const SmsContext* context);
        BOOLEAN CreateMessages(const EditorDocument& document, const SmsContext* context, SmsFactory* factory);
        

    private:
        BOOLEAN ProcessDocument(const EditorDocument& document);
        BOOLEAN TraverseDocument(const EditorDocument& document);
        BOOLEAN TraverseDocument(const CompoundItem& parent);
        BOOLEAN AnalyseItem(const AbstractEditorItem& item);
        BOOLEAN ProcessImage(const Image* image);
        BOOLEAN ProcessSound(const Sound* sound);
        BOOLEAN ProcessFormattedText(const RichTextCompoundItem& item);
        BOOLEAN ProcessText(const WString& str, InformationElement* ie = 0);
        /* Calculates the remaining space if inserting of the give <em>InformationElement</em>
            is possible. In calc-mode (m_factory == 0) only the identifier of the given <em>ie</em>
            is needed and the additional size <em>add_size</em> is also included. If the
            inserting into the current PDU is not possible, <em>FALSE</em> is returned and
            no counter values are changed. */
        BOOLEAN ProcessAtomicIe(InformationElement& ie, UINT8 add_size);
        /* Calculates the remaining space if inserting of the give <em>InformationElement</em>
            and text is possible. <em>ie</em> may be <em>0</em> to indicate plain text.
            Retruns the number of processed characters or a value less than 0 if the
            text could not be inserted. */
        INT ProcessTextIe(InformationElement* ie, const WString& text, INT text_size);
        

        void ResetCounters();
        UINT8 CalcFreeChars() const;
        BOOLEAN TerminateSegment();

        UINT8 GetMaxPduSize() const { return SmsSubmit::c_max_guaranteed_user_data_size;}
        UINT8 CalcHeaderSize(UINT8 add_size) const { return m_header_size + add_size + (m_header_size == 0 && add_size > 0 ? 1 : 0); }

        static BOOLEAN          m_concatinated;
        static UINT8            m_header_size;  // size of user data header, always in bytes
        static UINT8            m_text_length;  // size of text, alphabet dependend (septets, octets, words)
        static UINT8            m_text_pos;     // size of text, number of characters
        static UINT8            m_concatinated_buffer[];
        static UINT8            m_buffer[];
        InformationElement::TextAlignment m_alignment;
        static WString          m_pdu_text;     // Text of a single pdu
        SmsFactory*             m_factory;
        const SmsContext*       m_context;
        SpaceInfo               m_space;
        InformationElement      m_concatinated_ie;
};

#endif // Ems_EmsCreator_hpp
