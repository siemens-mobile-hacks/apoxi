/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TimeCompoundItem_hpp)
#define Apoxi_TimeCompoundItem_hpp

#include <Gui/CompoundItem.hpp>
#include <Auxiliary/Time.hpp>

class TimeCompoundItem : public CompoundItem {
    typedef CompoundItem Base;

    public:
        enum {
            ID = 7
        };

        static TimeCompoundItem* CreateInstance(const Time& time = Time());

        virtual ~TimeCompoundItem();

        virtual INT GetId() const;

        void SetTime(const Time& time) { m_time = time; }

        const Time& GetTime() const { return m_time; }

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
        TimeCompoundItem(const Time& time = Time());

    private:
        Time m_time;
};

#endif  // Apoxi_TimeCompoundItem_hpp


