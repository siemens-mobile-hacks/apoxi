/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Types_hpp)
#define Apoxi_Types_hpp

#include <Kernel/Types.h>

/*----------------------------------------------------------------
                                Constants
  ----------------------------------------------------------------*/

const BOOLEAN TRUE = 1;
const BOOLEAN FALSE = 0;

/*----------------------------------------------------------------
                                Templates
  ----------------------------------------------------------------*/

template <typename T> inline
T Sign(const T& a)
{
    return (a < 0 ? -1 : 1);
}

template <typename T> inline
T Absolute(const T& a)
{
    return (a < 0 ? -a : a);
}

template <typename T1, typename T2> inline
T1 Maximum(const T1& a, const T2& b)
{
    return (a > b ? a : b);
}

template <typename T1, typename T2> inline
T1 Minimum(const T1& a, const T2& b)
{
    return (a < b ? a : b);
}

template <typename T1, typename T2> inline
BOOLEAN Between(const T1& a, const T2& low, const T2& high)
{
    return (a >= low && a <= high);
}

template <typename T> inline
BOOLEAN TestBit(const T& b, const INT& i)
{
    return ((b & (1 << i)) != 0);
}

/*----------------------------------------------------------------
                                Casts
  ----------------------------------------------------------------*/

#if defined(APOXI_DISABLE_CPP_CASTS)
    #define static_cast apoxi_static_cast
    #define const_cast apoxi_const_cast
    #define reinterpret_cast apoxi_reinterpret_cast

    template <typename ToType, typename FromType> inline
    ToType apoxi_static_cast(FromType val)
    {
        return (ToType)val;
    }

    template <typename ToType, typename FromType> inline
    ToType apoxi_const_cast(FromType val)
    {
        return (ToType)val;
    }

    template <typename ToType, typename FromType> inline
    ToType apoxi_reinterpret_cast(FromType val)
    {
        return (ToType)val;
    }
#endif

#endif  // Apoxi_Types_hpp

