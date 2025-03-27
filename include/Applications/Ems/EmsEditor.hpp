/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_EmsEditor_hpp)
#define Ems_EmsEditor_hpp

#include <Gui/TextFormat.hpp>
#include <Ems/EmsEditorListener.hpp>
#include <AddOns/MultiMedia/MultiMediaEditor.hpp>
#include <AddOns/MultiMedia/AudioContext.hpp>

class CompoundItem;
class ParagraphCompoundItem;

class EmsEditor : public MultiMediaEditor {
    typedef MultiMediaEditor Base;

    public:

        EmsEditor();

        virtual ~EmsEditor();

        void Init(Control *parent, InputMapper::Id input_mapper_id);
        
        void SetObtainedDocument(EditorDocumentObtainer obtainer);
        
        EditorDocumentObtainer GetObtainedDocument() const;

        virtual BOOLEAN InsertItem(const AtomItem &item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN InsertCompoundItem(CompoundItem *compound_item, INT index = -1);

        virtual BOOLEAN RemoveCompoundItem(INT index = -1);

        virtual BOOLEAN Backspace();
        
        virtual void StartTextFormatting(const TextFormat& format, const Color& text_color, const Color& bg_color);
        
        virtual void OnItemMarked(const AbstractEditorItem *item);

        void SetEditorListener(EmsEditorListener* lstn) { m_editor_listener = lstn; }

    protected:
        virtual Model* CreateModel() const;

        virtual BOOLEAN DestroyModel(Model *model);

    private:
        CompoundItem*           m_text_item;
        ParagraphCompoundItem*  m_pg_item;
        EmsEditorListener*      m_editor_listener;
        EditorDocumentObtainer  m_obtainer;

        static AudioContext     m_audio_context;    // ToDo: Move to Kernel/System to make it common available
};

#endif  // Ems_EmsEditor_hpp
