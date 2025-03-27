/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DateCompoundItem_hpp)
#define Apoxi_DateCompoundItem_hpp

#include <Gui/CompoundItem.hpp>
#include <Auxiliary/Date.hpp>

class DateCompoundItem : public CompoundItem {
    typedef CompoundItem Base;

    public:
        enum {
            ID = 8
        };

        static DateCompoundItem* CreateInstance(const Date& date = Date());

        virtual ~DateCompoundItem();

        virtual INT GetId() const;

        void SetDate(const Date& date) { m_date = date; }

        const Date& GetDate() const { return m_date; }

        void SetDateFormat(DateFormat date_format) { m_date_format = date_format; }

        DateFormat GetDateFormat() const { return m_date_format; }

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const;

        virtual INT WrapLine(INT index,
                             XYDIM width,
                             WrapPolicy wrap_policy = EditorDocument::WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT index, INT count) const;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const;

        virtual INT GetItemCount() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        DateCompoundItem(const Date& date = Date());

    private:
        Date            m_date;
        DateFormat      m_date_format;
};

#endif  // Apoxi_DateCompoundItem_hpp


