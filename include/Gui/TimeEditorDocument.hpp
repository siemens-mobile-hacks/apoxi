/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TimeEditorDocument_hpp)
#define Apoxi_TimeEditorDocument_hpp

#include <Gui/EditorDocument.hpp>
#include <Gui/TimeCompoundItem.hpp>
#include <Gui/CharItem.hpp>
#include <Auxiliary/Time.hpp>
#include <Auxiliary/WString.hpp>

class TimeEditorDocument : public EditorDocument {
    typedef EditorDocument Base;

    public:
        TimeEditorDocument(const Time& time = Time());

        virtual ~TimeEditorDocument();

        void Init(const Time& time);

        virtual INT GetItemCount() const;

        virtual INT GetMaxItemCount() const;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT item_index);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT item_index);

        virtual BOOLEAN RemoveItem(INT item_index);

        virtual const CompoundItem& GetCompoundItem(INT item_index, INT* start_item_index = 0) const;

        void SetTime(const Time& time);

        const Time& GetTime() const;
        
        virtual void Draw(DeviceContext* dc, XYDIM x, XYDIM y,
                          INT item_index, INT count) const;

        virtual INT WrapLine(INT item_index, XYDIM width, WrapPolicy wrap_policy = WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT item_index, INT count) const;

        virtual XYDIM GetLineHeight(INT item_index, INT count, XYDIM* baseline = 0) const;

        BOOLEAN IsSeparator(INT item_index) const;

    private:
        TimeCompoundItem* m_compound_item;
};

#endif  // Apoxi_TimeEditorDocument_hpp


