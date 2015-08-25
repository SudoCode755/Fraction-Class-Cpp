#ifndef FRACTIONS_H_
#define FRACTIONS_H_

enum Sign
{
   negative = -1, positive = 1
};

class Fraction
{
private:
   typedef long long int LLInt_64;
   typedef unsigned long long int ULLInt_64;

   typedef unsigned int uInt_32;

   ULLInt_64 numerator;
   ULLInt_64 denominator;

   Sign sign;

   ULLInt_64 gcd() const;

   ULLInt_64 lcm(LLInt_64 num1, LLInt_64 num2) const;

   Fraction dividedBy(const Fraction&value) const;
   Fraction addTo(const Fraction& value) const;
public:

   Fraction();

   Fraction(const Fraction& f);

   Fraction(const LLInt_64 num, const LLInt_64 denom);

   Fraction(const int num, const int denom);

   Fraction(const ULLInt_64 num, const ULLInt_64 denom, const Sign sign);

   Fraction(const unsigned num, const unsigned denom, const Sign sign);

   Fraction(const LLInt_64 num);

   Fraction(const int num);

   Fraction(const ULLInt_64 num);

   Fraction(const unsigned num);

   void fracAbs();

   int getSign() const;

   ULLInt_64 getNumerator() const;

   ULLInt_64 getDenominator() const;

   void flipSign();

   void setNumerator(LLInt_64 num);

   void setDenominator(LLInt_64 denom);

   void fromDecimal(double decimal, ULLInt_64 maxDenom);

   double decimalValue() const;

   void reduce();
   ~Fraction();

   /*assignment operator*/

   Fraction& operator=(const Fraction & value);

   Fraction& operator=(const LLInt_64 value);

   Fraction& operator=(const ULLInt_64 value);

   Fraction& operator=(const int value);

   Fraction& operator=(const uInt_32 value);

   /*Begin Arithmetic operators*/

   /* Addition Operators */

   Fraction operator+(const Fraction&rhs) const;

   Fraction operator+(const LLInt_64 value) const;

   Fraction operator+(const ULLInt_64 value) const;

   Fraction operator+(const int value) const;

   Fraction operator+(const uInt_32 value) const;

   friend Fraction operator+(const LLInt_64 value, const Fraction&rhs);

   friend Fraction operator+(const ULLInt_64 value, const Fraction&rhs);

   friend Fraction operator+(const int value, const Fraction&rhs);

   friend Fraction operator+(const uInt_32 value, const Fraction&rhs);

   /* Divide Operators */

   Fraction operator/(const Fraction&rhs) const;

   Fraction operator/(const LLInt_64 value) const;

   Fraction operator/(const ULLInt_64 value) const;

   Fraction operator/(const int value) const;

   Fraction operator/(const uInt_32 value) const;

   friend Fraction operator/(const LLInt_64 value, const Fraction&rhs);

   friend Fraction operator/(const ULLInt_64 value, const Fraction&rhs);

   friend Fraction operator/(const int value, const Fraction&rhs);

   friend Fraction operator/(const uInt_32 value, const Fraction&rhs);

   /* Multiply operators */

   Fraction operator*(const Fraction&rhs) const;

   Fraction operator*(const LLInt_64 value) const;

   Fraction operator*(const ULLInt_64 value) const;

   Fraction operator*(const int value) const;

   Fraction operator*(const uInt_32 value) const;

   friend Fraction operator*(const LLInt_64 value, const Fraction&rhs);

   friend Fraction operator*(const ULLInt_64 value, const Fraction&rhs);

   friend Fraction operator*(const int value, const Fraction&rhs);

   friend Fraction operator*(const uInt_32 value, const Fraction&rhs);

   /*Subtraction operators */

   Fraction operator-(const Fraction&rhs) const;

   Fraction operator-(const LLInt_64 value) const;

   Fraction operator-(const ULLInt_64 value) const;

   Fraction operator-(const int value) const;

   Fraction operator-(const uInt_32 value) const;

   friend Fraction operator-(const LLInt_64 value, const Fraction&rhs);

   friend Fraction operator-(const ULLInt_64 value, const Fraction&rhs);

   friend Fraction operator-(const int value, const Fraction&rhs);

   friend Fraction operator-(const uInt_32 value, const Fraction&rhs);

   /*End Arithmetic operators*/

   /*Begin Comparison operators/relational operators*/

   /*Equal-to operators*/

   bool operator==(const Fraction&rhs) const;

   bool operator==(const LLInt_64 value) const;

   bool operator==(const ULLInt_64 value) const;

   bool operator==(const int value) const;

   bool operator==(const uInt_32 value) const;

   friend bool operator==(const LLInt_64 value, const Fraction&rhs);

   friend bool operator==(const ULLInt_64 value, const Fraction&rhs);

   friend bool operator==(const int value, const Fraction&rhs);

   friend bool operator==(const uInt_32 value, const Fraction&rhs);

   /*Not-Equal-to Operators*/

   bool operator!=(const Fraction&rhs) const;

   bool operator!=(const LLInt_64 value) const;

   bool operator!=(const ULLInt_64 value) const;

   bool operator!=(const int value) const;

   bool operator!=(const uInt_32 value) const;

   friend bool operator!=(const LLInt_64 value, const Fraction&rhs);

   friend bool operator!=(const ULLInt_64 value, const Fraction&rhs);

   friend bool operator!=(const int value, const Fraction&rhs);

   friend bool operator!=(const uInt_32 value, const Fraction&rhs);

   /*Greater-than Operators*/

   bool operator>(const Fraction&rhs) const;

   bool operator>(const LLInt_64 value) const;

   bool operator>(const ULLInt_64 value) const;

   bool operator>(const int value) const;

   bool operator>(const uInt_32 value) const;

   friend bool operator>(const LLInt_64 value, const Fraction&rhs);

   friend bool operator>(const ULLInt_64 value, const Fraction&rhs);

   friend bool operator>(const int value, const Fraction&rhs);

   friend bool operator>(const uInt_32 value, const Fraction&rhs);

   /*Less-than Operators*/

   bool operator<(const Fraction&rhs) const;

   bool operator<(const LLInt_64 value) const;

   bool operator<(const ULLInt_64 value) const;

   bool operator<(const int value) const;

   bool operator<(const uInt_32 value) const;

   friend bool operator<(const LLInt_64 value, const Fraction&rhs);

   friend bool operator<(const ULLInt_64 value, const Fraction&rhs);

   friend bool operator<(const int value, const Fraction&rhs);

   friend bool operator<(const uInt_32 value, const Fraction&rhs);

   /*Greater-than-Or-Equal Operators*/

   bool operator>=(const Fraction&rhs) const;

   bool operator>=(const LLInt_64 value) const;

   bool operator>=(const ULLInt_64 value) const;

   bool operator>=(const int value) const;

   bool operator>=(const uInt_32 value) const;

   friend bool operator>=(const LLInt_64 value, const Fraction&rhs);

   friend bool operator>=(const LLInt_64 value, const Fraction&rhs);

   friend bool operator>=(const int value, const Fraction&rhs);

   friend bool operator>=(const uInt_32 value, const Fraction&rhs);

   /*Less-than-Or-Equal Operators*/

   bool operator<=(const Fraction&rhs) const;

   bool operator<=(const LLInt_64 value) const;

   bool operator<=(const ULLInt_64 value) const;

   bool operator<=(const int value) const;

   bool operator<=(const uInt_32 value) const;

   friend bool operator<=(const LLInt_64 value, const Fraction&rhs);

   friend bool operator<=(const ULLInt_64 value, const Fraction&rhs);

   friend bool operator<=(const int value, const Fraction&rhs);

   friend bool operator<=(const uInt_32 value, const Fraction&rhs);

   /*End Comparison operators/relational operators*/

   /*Begin Compound Assignment operators*/

   /*Addition assignment operators*/

   Fraction& operator+=(const Fraction & value);

   Fraction& operator+=(const LLInt_64 value);

   Fraction& operator+=(const ULLInt_64 value);

   Fraction& operator+=(const int value);

   Fraction& operator+=(const uInt_32 value);

   /*Subtraction assignment operators*/

   Fraction& operator-=(const Fraction & value);

   Fraction& operator-=(const LLInt_64 value);

   Fraction& operator-=(const ULLInt_64 value);

   Fraction& operator-=(const int value);

   Fraction& operator-=(const uInt_32 value);

   /* Multiplication assignment operators*/

   Fraction& operator*=(const Fraction & value);

   Fraction& operator*=(const LLInt_64 value);

   Fraction& operator*=(const ULLInt_64 value);

   Fraction& operator*=(const int value);

   Fraction& operator*=(const uInt_32 value);


   /* Division  assignment operators*/

   Fraction& operator/=(const Fraction & value);

   Fraction& operator/=(const LLInt_64 value);

   Fraction& operator/=(const ULLInt_64 value);

   Fraction& operator/=(const int value);

   Fraction& operator/=(const uInt_32 value);

   /*End Compound Assignment operators*/

};

#endif
