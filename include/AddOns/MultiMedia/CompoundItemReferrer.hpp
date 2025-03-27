/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CompoundItemReferrer_hpp)
#define Apoxi_CompoundItemReferrer_hpp

class CompoundItem;

class CompoundItemReferrer {
    public:
        explicit CompoundItemReferrer(INT start_index = 0, CompoundItem* compound_item = 0);

        void SetStartIndex(INT index) { m_start_index = index; }

        INT GetStartIndex() const { return m_start_index; }

        void SetCompoundItem(CompoundItem* compound_item) { m_compound_item = compound_item; }

        CompoundItem* GetCompoundItem() const { return m_compound_item; }

        INT GetCount() const { ASSERT_DEBUG(m_compound_item != 0); return m_compound_item->GetItemCount(); }

    private:
        INT m_start_index;
        CompoundItem* m_compound_item;
};

#endif  // Apoxi_CompoundItemReferrer_hpp


