/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Stream_hpp)
#define Apoxi_Stream_hpp

class StreamWriter;
class StreamReader;

#include <Auxiliary/StreamingInfo.hpp>

class Stream {
    public:

        // StreamCaps enum ------------------------------------------------------------------------

        enum Caps {

            StreamCanBeRead = 1,

            StreamCanBeWritten,

            StreamCanBeReadWritten

        };

        // StreamOrigin enum ----------------------------------------------------------------------

        enum Origin {

            StreamBegin = 1,

            StreamEnd,

            StreamCurrent

        };

        // construction  --------------------------------------------------------------------------

        Stream();

        virtual ~Stream();

        // capabilites ----------------------------------------------------------------------------

        virtual Caps GetCapabilities() = 0; 
        
        // reader and writer ----------------------------------------------------------------------
        
        virtual StreamReader* GetReader() = 0;  

        virtual StreamWriter* GetWriter() = 0;  

        // opening, closing ----------------------------------------------------------------------

        virtual void Open(StreamingInfo& info) = 0; 

        virtual void Close(StreamingInfo& info) = 0; 
};

#endif  // Apoxi_Stream_hpp


