/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Fraction_hpp)
#define Apoxi_Fraction_hpp


class Fraction {
    public:
        Fraction();
        Fraction(const Fraction &frac);
        Fraction(INT32 num, INT32 denom = 1);

        virtual ~Fraction();

        void Set(INT32 num, INT32 denom = 1);
        void SetNumerator(INT32 num) { m_numerator = num; };
        void SetDenominator (INT32 denom) { m_denominator = denom; };

        INT32 GetNumerator() const { return m_numerator; }
        INT32 GetDenominator() const { return m_denominator; }
        
        BOOLEAN SetDecimalString(const WCHAR *str);
        WString GetDecimalString(INT digits = 0) const;
        BOOLEAN SetFractionString(const WCHAR *str);
        WString GetFractionString() const;

        BOOLEAN IsValid() const;
        void Simplify();
        Fraction Reciprocal();
        
        Fraction& operator += (const Fraction &frac);
        Fraction& operator -= (const Fraction &frac);
        Fraction& operator *= (const Fraction &frac);
        Fraction& operator /= (const Fraction &frac);

        Fraction operator + (const Fraction &fraction) const;
        Fraction operator - (const Fraction &fraction) const;
        Fraction operator * (const Fraction &fraction) const;
        Fraction operator / (const Fraction &fraction) const;

    private:
    
        BOOLEAN TestMultiplyOverflow(const INT32& i, const INT32& j) const;
        BOOLEAN TestDivideOverflow(const INT32& i, const INT32& j)   const;
        BOOLEAN TestAdditionOverflow(const INT32& i, const INT32& j) const;
        BOOLEAN TestSubtractOverflow(const INT32& i, const INT32& j) const;
    
        INT32   m_numerator;
        INT32   m_denominator;
};

#endif  // Apoxi_Fraction_hpp



