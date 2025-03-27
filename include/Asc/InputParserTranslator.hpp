/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_InputParserTranslator_hpp)
#define Asc_InputParserTranslator_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Asc/InputParser.hpp>

class InputParserTranslator {
 public:
  static SsCode Ss2Ss(InputParser::SsCode ip_ss);

  static InputParser::SsCode Ss2Ss(SsCode std_ss);
  
  static const SsGroup& Bs2SsGroup(InputParser::BasicServiceMmiCode bs);

  static InputParser::BasicServiceMmiCode SsGroup2Bs(SsGroup &sg);


  static ServiceGroup Bs2Sg(InputParser::BasicServiceMmiCode bs);

 static InputParser::BasicServiceMmiCode Sg2Bs(ServiceGroup sg);

  static void Sg2SsGroup(ServiceGroup sg, SsGroup& ss_group);
  static InputParser::SsProcedure SsOpcode2MmiProc(SsOperationCode op_code);
  static SsOperationCode MmiProc2SsOpcode(InputParser::SsProcedure mmi_proc);

};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Asc_InputParserTranslator_hpp

