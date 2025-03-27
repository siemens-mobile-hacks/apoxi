/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_MachType_hpp)
#define Apoxi_MachType_hpp

#include <Kernel/Types.hpp>

#if !defined(APOXI_LITTLE_ENDIAN) && ! defined(APOXI_BIG_ENDIAN)
#   if defined(APOXI_RTOS_WIN32)
#       define APOXI_LITTLE_ENDIAN
#   elif defined(APOXI_RTOS_NUC16S) || defined(APOXI_RTOS_NUC16U) 
#       define APOXI_LITTLE_ENDIAN
#   elif defined(APOXI_RTOS_OSE166)
#       define APOXI_LITTLE_ENDIAN
#   else
#       error APOXI_LITTLE_ENDIAN or APOXI_BIG_ENDIAN must be specified
#   endif
#endif



/*  -------------------------------------------------------------------------
                                    Types
    ------------------------------------------------------------------------- */

class BigEndian16Bit;
class BigEndian32Bit;
class LittleEndian16Bit;
class LittleEndian32Bit;


class BigEndian16Bit {
    public:
        BigEndian16Bit(UINT16 v = 0)  { m_val.m_uint16 = v; }

        inline BigEndian16Bit(const LittleEndian16Bit& v);

        inline BigEndian16Bit& operator=(const LittleEndian16Bit& v);

        union {
            UINT8 m_uint8_ar[2];
            UINT16 m_uint16;

            struct {
                UINT8 m_a;
                UINT8 m_b;
            } m_uint8;
        } m_val;

};


class BigEndian32Bit {
    public:
        BigEndian32Bit(UINT32 v = 0) { m_val.m_uint32 = v; }

        inline BigEndian32Bit(const LittleEndian32Bit& v);

        inline BigEndian32Bit& operator=(const LittleEndian32Bit& v);

        union {
            UINT8 m_uint8_ar[4];
            UINT16 m_uint16_ar[2];
            UINT32 m_uint32;

            struct {
                UINT8 m_a;
                UINT8 m_b;
                UINT8 m_c;
                UINT8 m_d;
            } m_uint8;

            struct {
                UINT16 m_a;
                UINT16 m_b;
            } m_uint16;
        } m_val;
};


class LittleEndian16Bit {
    public:
        LittleEndian16Bit(UINT16 v = 0) { m_val.m_uint16 = v; }

        inline LittleEndian16Bit(const BigEndian16Bit& v);

        inline LittleEndian16Bit& operator=(const BigEndian16Bit& v);

        union {
            UINT8 m_uint8_ar[2];
            UINT16 m_uint16;

            struct {
                UINT8 m_b;
                UINT8 m_a;
            } m_uint8;
        } m_val;
};


class LittleEndian32Bit {
    public:
        LittleEndian32Bit(UINT32 v = 0) { m_val.m_uint32 = v; }

        LittleEndian32Bit(const BigEndian32Bit& v);

        LittleEndian32Bit& operator=(const BigEndian32Bit& v);

        union {
            UINT8 m_uint8_ar[4];
            UINT16 m_uint16_ar[2];
            UINT32 m_uint32;

            struct {
                UINT8 m_d;
                UINT8 m_c;
                UINT8 m_b;
                UINT8 m_a;
            } m_uint8;

            struct {
                UINT16 m_b;
                UINT16 m_a;
            } m_uint16;
        } m_val;
};


#if defined(APOXI_BIG_ENDIAN)
    typedef BigEndian16Bit Native16BitBase;
    typedef BigEndian32Bit Native32BitBase;
#else
    typedef LittleEndian16Bit Native16BitBase;
    typedef LittleEndian32Bit Native32BitBase;
#endif


class Native16Bit : public Native16BitBase {
    typedef Native16BitBase Base;

    public:
        Native16Bit(UINT16 v = 0) : Base(v) { }

        Native16Bit(const BigEndian16Bit& v) {* this = v; }

        Native16Bit(const LittleEndian16Bit& v) {* this = v; }

        inline Native16Bit& operator=(const BigEndian16Bit& v);

        inline Native16Bit& operator=(const LittleEndian16Bit& v);
};


class Native32Bit : public Native32BitBase {
    typedef Native32BitBase Base;

    public:
        Native32Bit(UINT32 v = 0) : Base(v) { }

        Native32Bit(const BigEndian32Bit& v) {* this = v; }

        Native32Bit(const LittleEndian32Bit& v) {* this = v; }

        inline Native32Bit& operator=(const BigEndian32Bit& v);

        inline Native32Bit& operator=(const LittleEndian32Bit& v);
};


inline Native16Bit& Native16Bit::operator=(const BigEndian16Bit& v)
{
    Base::operator=(v);
    return* this;
}


inline Native16Bit& Native16Bit::operator=(const LittleEndian16Bit& v)
{
    Base::operator=(v);
    return* this;
}


inline Native32Bit& Native32Bit::operator=(const BigEndian32Bit& v)
{
    Base::operator=(v);
    return* this;
}


inline Native32Bit& Native32Bit::operator=(const LittleEndian32Bit& v)
{
    Base::operator=(v);
    return* this;
}


inline BigEndian16Bit::BigEndian16Bit(const LittleEndian16Bit& v) 
{
    *this = v;
}

inline BigEndian16Bit& BigEndian16Bit::operator=(const LittleEndian16Bit& v) 
{
    m_val.m_uint8.m_a = v.m_val.m_uint8.m_a;
    m_val.m_uint8.m_b = v.m_val.m_uint8.m_b;
    return* this;
}   // operator=


inline BigEndian32Bit::BigEndian32Bit(const LittleEndian32Bit& v) 
{
    *this = v;
}

inline BigEndian32Bit& BigEndian32Bit::operator=(const LittleEndian32Bit& v) 
{
    m_val.m_uint8.m_a = v.m_val.m_uint8.m_a;
    m_val.m_uint8.m_b = v.m_val.m_uint8.m_b;
    m_val.m_uint8.m_c = v.m_val.m_uint8.m_c;
    m_val.m_uint8.m_d = v.m_val.m_uint8.m_d;
    return* this;
}   // operator=


inline LittleEndian16Bit::LittleEndian16Bit(const BigEndian16Bit& v) 
{
    *this = v;
}

inline LittleEndian16Bit& LittleEndian16Bit::operator=(const BigEndian16Bit& v) 
{
    m_val.m_uint8.m_a = v.m_val.m_uint8.m_a;
    m_val.m_uint8.m_b = v.m_val.m_uint8.m_b;
    return* this;
}   // operator=


inline LittleEndian32Bit::LittleEndian32Bit(const BigEndian32Bit& v) 
{
    *this = v;
}

inline LittleEndian32Bit& LittleEndian32Bit::operator=(const BigEndian32Bit& v) 
{
    m_val.m_uint8.m_a = v.m_val.m_uint8.m_a;
    m_val.m_uint8.m_b = v.m_val.m_uint8.m_b;
    m_val.m_uint8.m_c = v.m_val.m_uint8.m_c;
    m_val.m_uint8.m_d = v.m_val.m_uint8.m_d;
    return* this;
}   // operator=



/*  -------------------------------------------------------------------------
                                    Macros
    ------------------------------------------------------------------------- */

#define ApoxiSwap16Bit(x)   ((UINT16) ((((UINT16) (x)) << 8U) | (((UINT16) (x)) >> 8U)))
#define ApoxiSwap32Bit(x)   ((UINT32) (((UINT32) ApoxiSwap16Bit((UINT16) x)) << 16U) |      \
                                      (((UINT32) ApoxiSwap16Bit((UINT16) (x >> 16U)))))


// use these macros to define 16/32 bit big / little endian constants
#if defined(APOXI_BIG_ENDIAN)
#   define ApoxiLittleEndian16BitConstant(x) ApoxiSwap16Bit(x)
#   define ApoxiLittleEndian32BitConstant(x) ApoxiSwap32Bit(x)

#   define ApoxiBigEndian16BitConstant(x) ((UINT16) (x))
#   define ApoxiBigEndian32BitConstant(x) ((UINT32) (x))
#else
#   define ApoxiLittleEndian16BitConstant(x) ((UINT16) (x))
#   define ApoxiLIttleEndian32BitConstant(x) ((UINT32) (x))

#   define ApoxiBigEndian16BitConstant(x) ApoxiSwap16Bit(x)
#   define ApoxiBigEndian32BitConstant(x) ApoxiSwap32Bit(x)
#endif

#endif  // Apoxi_MachType_hpp


