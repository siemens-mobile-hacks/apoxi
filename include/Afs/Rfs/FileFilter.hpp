/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileFilter_hpp)
#define Apoxi_FileFilter_hpp

#include <Auxiliary/MimeTypeTable.hpp>
#include <Auxiliary/WString.hpp>

class Path;

class FileFilter
{
    public:
        virtual ~FileFilter();

        virtual BOOLEAN Complies(const Path &path) = 0;

    protected:
        FileFilter();
};

class NamePatternFileFilter : public FileFilter
{
    public:
        NamePatternFileFilter(const WString &name_pattern,
            BOOLEAN case_sensitive = TRUE, BOOLEAN filter_dirs = FALSE);

        virtual BOOLEAN Complies(const Path &path);

        inline const WString& GetNamePattern() const
            { return m_name_pattern; }

    protected:
        virtual ~NamePatternFileFilter();

    protected:
        WString m_name_pattern;
        BOOLEAN m_case_sensitive;
        BOOLEAN m_filter_dirs;
};

class ImageFileFilter : public FileFilter
{
    public:
        ImageFileFilter(BOOLEAN filter_dirs = FALSE);

        virtual BOOLEAN Complies(const Path &path);

    protected:
        virtual ~ImageFileFilter();

        BOOLEAN m_filter_dirs;
};

class SoundFileFilter : public FileFilter
{
    public:
        SoundFileFilter(BOOLEAN filter_dirs = FALSE);

        virtual BOOLEAN Complies(const Path &path);

    protected:
        virtual ~SoundFileFilter();

        BOOLEAN m_filter_dirs;
};

#endif  // Apoxi_FileFilter_hpp

