/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Pathname_hpp)
#define Apoxi_Pathname_hpp

#include <Afs/Rfs/RfsConfig.hpp>
#include <Auxiliary/MimeTypeTable.hpp>
#include <Auxiliary/WString.hpp>

class Pathname
{
    public:
        static const WCHAR s_separator;
        static const WCHAR s_extension_separator;
        static const WCHAR s_root_pathname;

        enum {
            MAX_PATHNAME_LENGTH = APOXI_MAX_PATHNAME_LENGTH
        };

        class Iterator
        {
            public:
                Iterator();

                WString operator*() const;

                Iterator& operator++();

                Iterator operator++(INT);

                BOOLEAN operator==(const Iterator &itor) const;

                BOOLEAN operator!=(const Iterator &itor) const;

                BOOLEAN operator<(const Iterator &itor) const;

                BOOLEAN operator>(const Iterator &itor) const;

            protected:
                Iterator(const WString *str, UINT pos);

                friend class Pathname;

            private:
                const WString *m_str_pathname;
                UINT m_pos;
        };

        class ReverseIterator
        {
            public:
                ReverseIterator();

                WString operator*() const;

                ReverseIterator& operator++();

                ReverseIterator operator++(INT);

                BOOLEAN operator==(const ReverseIterator &itor) const;

                BOOLEAN operator!=(const ReverseIterator &itor) const;

                BOOLEAN operator<(const ReverseIterator &itor) const;

                BOOLEAN operator>(const ReverseIterator &itor) const;

            protected:
                ReverseIterator(const WString *str, UINT pos);

                friend class Pathname;

            private:
                const WString *m_str_pathname;
                UINT m_pos;
        };

        Pathname();

        Pathname(const WString &str);

        Pathname(const Pathname &pathname);

        ~Pathname();

        void Init(const WString &str);

        void Reset();

        BOOLEAN Add(const WString &str);

        BOOLEAN Add(const Pathname &pathname);

        BOOLEAN RemoveHead();

        BOOLEAN RemoveLeaf();

        WString GetHead() const;

        WString GetLeaf() const;

        BOOLEAN AddFileExtension(const WString &file_extension);

        BOOLEAN AddFileExtension(MimeType type);

        BOOLEAN SetFileExtension(const WString &file_extension);

        BOOLEAN SetFileExtension(MimeType type);

        BOOLEAN RemoveFileExtension();

        WString GetFileExtension() const;

        WString GetStrippedFileName() const;

        MimeType GetMimeType() const;

        UINT GetSegmentCount() const;

        WString GetSegmentAt(UINT segment_idx) const;

        BOOLEAN IsValid() const;

        BOOLEAN IsRoot() const;

        BOOLEAN HasLeaf() const;

        BOOLEAN HasExtension() const;

        const WString& ToWString() const;

        BOOLEAN operator==(const Pathname &rhs) const;

        BOOLEAN operator!=(const Pathname &rhs) const {
            return !operator==(rhs);
        }

        static WString GetSeparator();

        static WString GetExtensionSeparator();

        // Iterator methods

        Iterator Begin() const;

        Iterator End() const;

        ReverseIterator ReverseBegin() const;

        ReverseIterator ReverseEnd() const;

    protected:
        void RemoveTrailingSeparators();

    private:
        WString m_str_pathname;
};

#endif  // Apoxi_Pathname_hpp

