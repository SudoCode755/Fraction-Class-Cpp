#ifndef FRACTIONS_H_
#define FRACTIONS_H_

 enum Sign
{
   negative = -1, positive = 1
};

class Fraction
{
private:
   typedef long long int inputInt;
   typedef unsigned long long int internalInt;

   internalInt numerator;
   internalInt denominator;

   Sign sign;

   internalInt gcd() const;

   internalInt lcm(inputInt num1, inputInt num2) const;

   Fraction dividedBy(const Fraction&value) const;
   Fraction addTo(const Fraction& value) const;
public:

   Fraction();

   Fraction(const Fraction& f);

   Fraction(const inputInt num, const inputInt denom);

   Fraction(const int num, const int denom);

   Fraction(const internalInt num, const internalInt denom, const Sign sign);

   Fraction(const unsigned num, const unsigned denom, const Sign sign);

   Fraction(const inputInt num);

   Fraction(const int num);

   Fraction(const internalInt num);

   Fraction(const unsigned num);

   void fracAbs();

   int getSign() const;

   internalInt getNumerator() const;

   internalInt getDenominator() const;

   void flipSign();

   void setNumerator(inputInt num);

   void setDenominator(inputInt denom);

   void fromDecimal(double decimal, internalInt maxDenom);

   double decimalValue() const;

   void reduce();
   ~Fraction();

   /*assignment operator*/

   Fraction& operator=(const Fraction & value);

   Fraction& operator=(const inputInt value);

   Fraction& operator=(const internalInt value);

   /*Begin Arithmetic operators*/

   /* Addition Operators */

   Fraction operator+(const Fraction&rhs) const;

   Fraction operator+(const inputInt value) const;

   Fraction operator+(const internalInt value) const;

   friend Fraction operator+(const inputInt value, const Fraction&rhs);

   friend Fraction operator+(const internalInt value, const Fraction&rhs);


   /* Divide Operators */

   Fraction operator/(const Fraction&rhs) const;

   Fraction operator/(const inputInt value) const;

   Fraction operator/(const internalInt value) const;

   friend Fraction operator/(const inputInt value, const Fraction&rhs);

   friend Fraction operator/(const internalInt value, const Fraction&rhs);

   /* Multiply operators */

   Fraction operator*(const Fraction&rhs) const;

   Fraction operator*(const inputInt value) const;

   Fraction operator*(const internalInt value) const;

   friend Fraction operator*(const inputInt value, const Fraction&rhs);

   friend Fraction operator*(const internalInt value, const Fraction&rhs);

   /*Subtraction operators */

   Fraction operator-(const Fraction&rhs) const;

   Fraction operator-(const inputInt value) const;

   Fraction operator-(const internalInt value) const;

   friend Fraction operator-(const inputInt value, const Fraction&rhs);

   friend Fraction operator-(const internalInt value, const Fraction&rhs);

   /*End Arithmetic operators*/

   /*Begin Comparison operators/relational operators*/

   /*Equal-to operators*/

   bool operator==(const Fraction&rhs) const;

   bool operator==(const inputInt value) const;

   bool operator==(const internalInt value) const;

   friend bool operator==(const inputInt value, const Fraction&rhs);

   friend bool operator==(const internalInt value, const Fraction&rhs);

   /*Not-Equal-to Operators*/

   bool operator!=(const Fraction&rhs) const;

   bool operator!=(const inputInt value) const;

   bool operator!=(const internalInt value) const;

   friend bool operator!=(const inputInt value, const Fraction&rhs);

   friend bool operator!=(const internalInt value, const Fraction&rhs);

   /*Greater-than Operators*/

   bool operator>(const Fraction&rhs) const;

   bool operator>(const inputInt value) const;

   bool operator>(const internalInt value) const;

   friend bool operator>(const inputInt value, const Fraction&rhs);

   friend bool operator>(const internalInt value, const Fraction&rhs);

   /*Less-than Operators*/

   bool operator<(const Fraction&rhs) const;

   bool operator<(const inputInt value) const;

   bool operator<(const internalInt value) const;

   friend bool operator<(const inputInt value, const Fraction&rhs);

   friend bool operator<(const internalInt value, const Fraction&rhs);

   /*Greater-than-Or-Equal Operators*/

   bool operator>=(const Fraction&rhs) const;

   bool operator>=(const inputInt value) const;

   bool operator>=(const internalInt value) const;

   friend bool operator>=(const inputInt value, const Fraction&rhs);

   friend bool operator>=(const inputInt value, const Fraction&rhs);

   /*Less-than-Or-Equal Operators*/

   bool operator<=(const Fraction&rhs) const;

   bool operator<=(const inputInt value) const;

   bool operator<=(const internalInt value) const;

   friend bool operator<=(const inputInt value, const Fraction&rhs);

   friend bool operator<=(const internalInt value, const Fraction&rhs);


   /*End Comparison operators/relational operators*/

   /*Begin Compound Assignment operators*/

   /*Addition assignment operators*/

   Fraction& operator+=(const Fraction & value);

   Fraction& operator+=(const inputInt value);

   Fraction& operator+=(const internalInt value);

   /*Subtraction assignment operators*/

   Fraction& operator-=(const Fraction & value);

   Fraction& operator-=(const inputInt value);

   Fraction& operator-=(const internalInt value);

   /* Multiplication assignment operators*/

   Fraction& operator*=(const Fraction & value);

   Fraction& operator*=(const inputInt value);

   Fraction& operator*=(const internalInt value);

   /* Division  assignment operators*/

   Fraction& operator/=(const Fraction & value);

   Fraction& operator/=(const inputInt value);

   Fraction& operator/=(const internalInt value);

   /*End Compound Assignment operators*/

};

#endif
