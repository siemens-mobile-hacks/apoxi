#ifndef __XML_Parser_h
#define __XML_Parser_h


extern "C" {
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
}
#include "xml.h"

#include <Auxiliary/WString.hpp>

class XMLParser { 
    
    public: 
        static char *strbuf;        
        static int prev_readpos ;
        XMLParser(char *str); 
        virtual ~XMLParser();
        s32 Parse();

        virtual s32 XML_Error_Handler(int ErrorCode, int ErrorLine) { return 0;}
        virtual s32 XML_Start_Handler(void *UserData) { return 0;}
        virtual s32 XML_End_Handler(void *UserData) { return 0;}
        virtual s32 XML_StartElement_Handler(void *UserData, char *uri, char *localname, char *qName, LPVECTOR atts) { return 0; }
        virtual s32 XML_EndElement_Handler(void *UserData, char *uri, char *localname, char *qName) { return 0;}
        virtual s32 XML_Characters_Handler(void *UserData, char *Chars, s32 cbsize) { return 0;}
        virtual s32 XML_PI_Handler(void *UserData, char *Target, char *Data) { return 0;}
        virtual s32 XML_StartCData_Handler(void *UserData) { return 0;}
        virtual s32 XML_EndCData_Handler(void *UserData) { return 0; }             

        static void ErrorHandler(LPXMLPARSER parser);
        static s32 StartDocument(LPXMLPARSER parser, void *UserData);
        static s32 EndDocument(LPXMLPARSER parser, void *UserData);
        static s32 StartElement(LPXMLPARSER parser, void *UserData, char *uri, char *localName, char *qName, LPVECTOR atts);
        static s32 EndElement(LPXMLPARSER parser, void *UserData, char *uri, char *localName, char *qName); 
        static s32 CharactersHandler(LPXMLPARSER parser, void *UserData, char *Chars, s32 cbSize);
        static s32 PIHandler(LPXMLPARSER parser, void *UserData, char *Target, char *Data);
        static s32 StartCDATAHandler(LPXMLPARSER parser, void *UserData);
        static s32 EndCDATAHandler(LPXMLPARSER parser, void *UserData);
        static s32 cstream(char *buf, s32 cBytes, s32 *cBytesActual, void *inputData);

    private:
        XMLPARSER parser;
        int depth ;
};

#endif


