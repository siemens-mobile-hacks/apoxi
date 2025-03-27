/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileVisitor_hpp)
#define Apoxi_FileVisitor_hpp

#include <Auxiliary/NiSharedPtr.hpp>

class Path;
class FileFilter;

typedef NiSharedPtr<FileFilter> FileFilterPtr;

class FileVisitor
{
    public:
        virtual ~FileVisitor();

        virtual BOOLEAN Visit(const Path &file) = 0;

        inline FileFilterPtr GetIteratorFilter() const 
            { return m_filter; }

        inline BOOLEAN VisitDirectories() const 
            { return m_visit_directories; }

    protected:
        FileVisitor(const FileFilterPtr &filter, 
            BOOLEAN visit_directories = FALSE);

    protected:
        FileFilterPtr m_filter;

    private:
        BOOLEAN m_visit_directories;
};

#endif  // Apoxi_FileVisitor_hpp


