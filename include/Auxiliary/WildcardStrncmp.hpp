/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

// Copyright notice of the original code:

/* ***************************************************************************
 *
 *          Copyright 1992-2002 by Pete Wilson All Rights Reserved
 *           50 Staples Street : Lowell Massachusetts 01851 : USA
 *        http://www.pwilson.net/   pete@pwilson.net   +1 978-454-4547
 *
 * This item is free software: you can redistribute it and/or modify it as 
 * long as you preserve this copyright notice. Pete Wilson prepared this item 
 * hoping it might be useful, but it has NO WARRANTY WHATEVER, not even any 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 *
 *************************************************************************** */

// Modified the code to a template which can be used with char and wchar.

#if !defined(Apoxi_WildcardStrncmp_hpp)
#define Apoxi_WildcardStrncmp_hpp

#include <Kernel/Types.hpp>

template <typename T>
INT wc_strncmp(const T * pattern,      /* match this str (can contain *,?) */
               const T * candidate,    /*   against this one. */
               INT count,              /* require count chars in pattern */
               INT do_case,            /* 0 = no case, !0 = cased compare */ 
               INT do_wildcards);      /* 0 = no wc's, !0 = honor * and ? */

#define WC_QUES '?'
#define WC_STAR '*'

/* string and character match/no-match return codes */

enum {
  WC_MATCH = 0,     /* char/string-match succeed */
  WC_MISMATCH,      /* general char/string-match fail */
  WC_PAT_NULL_PTR,  /* (char *) pattern == NULL */
  WC_CAN_NULL_PTR,  /* (char *) candidate == NULL */
  WC_PAT_TOO_SHORT, /* too few pattern chars to satisfy count */
  WC_CAN_TOO_SHORT  /* too few candidate chars to satisfy '?' in pattern */
};

#endif  // Apoxi_WildcardStrncmp_hpp

