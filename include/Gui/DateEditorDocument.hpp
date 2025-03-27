/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DateEditorDocument_hpp)
#define Apoxi_DateEditorDocument_hpp

#include <Gui/EditorDocument.hpp>
#include <Gui/CharItem.hpp>
#include <Gui/DateCompoundItem.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/WString.hpp>

class DateEditorDocument : public EditorDocument {
    typedef EditorDocument Base;

    public:
        DateEditorDocument(const Date& date = Date());

        virtual ~DateEditorDocument();

        void Init(const Date& date);

        virtual INT GetItemCount() const;

        virtual INT GetMaxItemCount() const;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index);

        virtual BOOLEAN RemoveItem(INT index);

        virtual const CompoundItem& GetCompoundItem(INT index, INT* start_item_index = 0) const;

        void SetDate(const Date& date);

        const Date& GetDate() const;

        void SetDateFormat(DateFormat date_format);

        DateFormat GetDateFormat() const;

        virtual void Draw(DeviceContext* dc, XYDIM x, XYDIM y,
                          INT index, INT count) const;

        virtual INT WrapLine(INT index, XYDIM width, WrapPolicy wrap_policy = WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT index, INT count) const;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const;

        BOOLEAN IsSeparator(INT index) const;

    protected:
        BOOLEAN Reinterpret(INT index);
        
    private:
        // Supported pattern-types for editing.
        enum PatternType {
            Day,
            Month,
            ShortYear,
            LongYear
        };

        DateCompoundItem    *m_compound_item;
        WString             m_date_buffer;          // Buffer for increasing performance.

        /*  Returns the INTEGER-value of the date-buffer on the
            position given by <em>index</em>. Also the pattern-type is returned,
            hence checking and setting is possible for operations on the date-type.
            @param index    Pointer to the index (e. g. caret-position)
            @param value    Contains the INTEGER-value, if the return-value
                            is <em>TRUE</em>.
            @return         <em>TRUE</em>, if the operation was successful.*/
        BOOLEAN GetValue(INT index,
                         INT& value,
                         PatternType& pattern_type) const;
};

#endif  // Apoxi_DateEditorDocument_hpp


