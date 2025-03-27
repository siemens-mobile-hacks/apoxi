/*  ------------------------------------------------------------------------
Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(Apoxi_TextIconPairArray_hpp)
#define Apoxi_TextIconPairArray_hpp

class ImageObtainer;

class TextIconPairArray {
    public:
        class TextIconPair {
            public:
                const WCHAR* GetText() const { return m_text; }
                ImageObtainer GetIcon() const;
                const WCHAR*        m_text;
                const BitmapRes*    m_icon;
        };

        TextIconPairArray();

        TextIconPairArray(const TextIconPair* pair, INT size);

        virtual ~TextIconPairArray();

        virtual void Init(const TextIconPair* pair, INT size);
        
        void SetTextIconPair(const TextIconPair* pair, INT size);
        
        const TextIconPair* operator[](INT index) const { 
            ASSERT_DEBUG(index >= 0 && index < GetSize());
            return (&m_pair[index]); 
        }

        INT GetSize() const { return m_size; }
        
        void PushBack(TextIconPair pair) {}
        
        void PopBack() {}

    private:
        const TextIconPair *m_pair;
        INT m_size;
};
#endif  // Apoxi_TextIconPairArray_hpp

