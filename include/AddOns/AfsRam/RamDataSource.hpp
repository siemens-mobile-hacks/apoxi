/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RamDataSource_hpp)
#define Apoxi_RamDataSource_hpp

#include <Afs/Rfs/FileDataSource.hpp>

class RamDataSink;
class RamDataSource;

typedef NiSharedPtr<RamDataSink> RamDataSinkPtr;
typedef NiSharedPtr<RamDataSource> RamDataSourcePtr;

class RamDataSource : public FileDataSource
{
    typedef FileDataSource Base;

    public:
        RamDataSource(const RamDataSinkPtr &sink);

        virtual ~RamDataSource();

    protected:
        RamDataSinkPtr m_sink;
};

#endif  // Apoxi_RamDataSource_hpp


