#include "Fraction.h"
#include <cassert>
#include <limits>
#include <cmath>
#include <iostream>

typedef long long int inputInt;
typedef unsigned long long int internalInt;

Fraction::Fraction() :
      numerator(0), denominator(1), sign(positive)
{
}

Fraction::Fraction(const Fraction& f) :
      numerator(f.numerator), denominator(f.denominator), sign(f.sign)
{
   reduce();
}

Fraction::Fraction(const inputInt num, const inputInt denom)
{
   assert(denom != (0));

   if (num < 0 && denom < 0)
   {
      numerator = abs(num);
      denominator = abs(denom);
      sign = positive;
   }
   else if (num > 0 && denom > 0)
   {
      numerator = (num);
      denominator = (denom);
      sign = positive;
   }
   else
   {
      numerator = abs(num);
      denominator = abs(denom);
      sign = negative;
   }

   reduce();
}

Fraction::Fraction(const int num, const int denom)
{
   assert(denom != (0));

   if (num < 0 && denom < 0)
   {
      numerator = abs(num);
      denominator = abs(denom);
      sign = positive;
   }
   else if (num > 0 && denom > 0)
   {
      numerator = (num);
      denominator = (denom);
      sign = positive;
   }
   else
   {
      numerator = abs(num);
      denominator = abs(denom);
      sign = negative;
   }

   reduce();
}

Fraction::Fraction(const inputInt num) :
      numerator(abs(num)), denominator(1), sign(num > 0 ? positive : negative)
{

}

Fraction::Fraction(const int num) :
      numerator(abs(num)), denominator(1), sign(num > 0 ? positive : negative)
{

}

Fraction::Fraction(const internalInt num, const internalInt denom, const Sign _sign) :
      numerator(num), denominator(denom), sign(_sign)
{
   assert(denom != (0));
   reduce();
}

Fraction::Fraction(const unsigned num, const unsigned denom, const Sign _sign) :
      numerator(num), denominator(denom), sign(_sign)
{
   assert(denom != (0));
   reduce();
}

Fraction::Fraction(const internalInt num) :
      numerator(num), denominator(1), sign(positive)
{

}

Fraction::Fraction(const unsigned num) :
      numerator(num), denominator(1), sign(positive)
{

}

int Fraction::getSign() const
{
   return sign;
}

internalInt Fraction::getNumerator() const
{
   return numerator;
}

internalInt Fraction::getDenominator() const
{
   return denominator;
}

void Fraction::setNumerator(inputInt num)
{
   numerator = abs(num);
   if (num < 0)
   {
      sign = negative;
   }
}

void Fraction::setDenominator(inputInt denom)
{
   denominator = abs(denom);
   if (denom < 0)
   {
      sign = negative;
   }
}

void Fraction::flipSign()
{
   if (sign == negative)
   {
      sign = positive;
   }
   else
   {
      sign = negative;
   }
}

Fraction::~Fraction()
{
}

Fraction Fraction::addTo(const Fraction& rhs) const
{
   internalInt val = lcm(this->denominator, rhs.denominator);
   Fraction result;

   if (sign == rhs.sign)
   {
      result = Fraction(this->numerator * (val / this->denominator) + rhs.numerator * (val / rhs.denominator), val, sign);
   }
   else
   {
      Sign maxSign = (*this) > rhs ? this->sign : rhs.sign;
      Fraction maxFrac = (*this) > rhs ? *this : rhs;
      Fraction minFrac = (!((*this) > rhs)) ? *this : rhs;
      result = Fraction(maxFrac.numerator * (val / maxFrac.denominator) - minFrac.numerator * (val / minFrac.denominator), val, maxSign);
   }
   return result;
}

Fraction Fraction::dividedBy(const Fraction&value) const
{
   if (value.numerator == 0)
   {
      std::cerr << "division by zero!";
      throw "division by zero!";
   }
   Fraction result;
   result.numerator = numerator * value.denominator;
   result.denominator = denominator * value.numerator;
   result.reduce();
   return result;
}

internalInt Fraction::gcd() const
{
   internalInt u = numerator, v = denominator;

   while (v != inputInt(0))
   {
      internalInt r = u % v;
      u = v;
      v = r;
   }
   return u;
}

internalInt Fraction::lcm(inputInt num1, inputInt num2) const
{

   internalInt max = (num1 > num2) ? num1 : num2; /* maximum value is stored in variable max */
   while (1) /* Always true. */
   {
      if (max % num1 == 0 && max % num2 == 0)
      {
         break; /* while loop terminates. */
      }
      ++max;
   }
   return max;
}

void Fraction::reduce()
{
   internalInt temp = (this->gcd());
   numerator = numerator / temp;
   denominator = denominator / temp;
}

void Fraction::fromDecimal(double decimal, internalInt maxDenom)
{
   if (maxDenom == 0)
   {
      maxDenom = ULONG_MAX;
   }
   /*  a: continued fraction coefficients. */
   internalInt a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 }, x, d, n = 1, i;

   if (maxDenom <= 1)
   {
      denominator = 1;
      numerator = static_cast<internalInt>(decimal);
      return;
   }
   sign = positive;
   if (decimal < 0)
   {
      sign = negative;
      decimal = -decimal;
   }

   while (decimal != floor(decimal))
   {
      n <<= 1;
      decimal *= 2;
   }
   d = decimal;

   /* continued fraction and check denominator each step */
   for (i = 0; i < 128; i++)
   {
      a = n ? d / n : 0;
      if (i && !a)
      {
         break;
      }

      x = d;
      d = n;
      n = x % n;
      x = a;

      if (k[1]* a + k[0] >= maxDenom)
      {
         x = (maxDenom - k[0]) / k[1];
         if (x * 2 >= a || k[1] >= maxDenom)
         {
            i = 129;
         }
         else
         {
            break;
         }
      }

      h[2] = x * h[1] + h[0];
      h[0] = h[1];
      h[1] = h[2];
      k[2] = x * k[1] + k[0];
      k[0] = k[1];
      k[1] = k[2];
   }
   denominator = k[1];
   numerator = h[1];
}

double Fraction::decimalValue() const
{
   return sign * static_cast<double>(numerator) / static_cast<double>(denominator);
}

Fraction& Fraction::operator=(const Fraction& value)
{
   this->numerator = value.numerator;
   this->denominator = value.denominator;
   this->sign = value.sign;
   return *this;
}

Fraction& Fraction::operator=(const inputInt value)
{

   this->numerator = value;
   this->denominator = 1;
   sign = value > 0 ? positive : negative;
   return *this;
}

Fraction& Fraction::operator=(const internalInt value)
{
   this->numerator = value;
   this->denominator = 1;
   sign = positive;
   return *this;
}

/* Addition Operators */
Fraction Fraction::operator+(const Fraction&rhs) const
{
   return this->addTo(rhs);
}

Fraction Fraction::operator+(const inputInt value) const
{
   return Fraction(value) + *this;
}

Fraction Fraction::operator+(const internalInt value) const
{
   return Fraction(value) + *this;
}

Fraction operator+(const inputInt value, const Fraction&rhs)
{
   return Fraction(value) + rhs;
}

Fraction operator+(const internalInt value, const Fraction&rhs)
{
   return Fraction(value) + rhs;
}
/* Divide Operators */

Fraction Fraction::operator/(const Fraction&rhs) const
{
   return this->dividedBy(rhs);
}

Fraction Fraction::operator/(const inputInt value) const
{
   return this->dividedBy(Fraction(value));
}

Fraction Fraction::operator/(const internalInt value) const
{
   return this->dividedBy(Fraction(value));
}

Fraction operator/(const internalInt value, const Fraction&rhs)
{
   return Fraction(value).dividedBy(rhs);
}

/* Multiply operators */

Fraction Fraction::operator*(const Fraction&rhs) const
{
   return Fraction(this->numerator * rhs.numerator, rhs.denominator * this->denominator, sign == rhs.sign ? positive : negative);
}

Fraction Fraction::operator*(const inputInt value) const
{
   Fraction result;
   result.numerator *= abs(value);
   if (value < 0)
   {
      result.flipSign();
   }
   return result;

}

Fraction Fraction::operator*(const internalInt value) const
{
   Fraction result;
   result.numerator *= value;
   return result;
}

Fraction operator*(const inputInt value, const Fraction&rhs)
{
   return rhs * value;
}

Fraction operator*(const internalInt value, const Fraction&rhs)
{
   return rhs * value;
}

/*Subtraction operators */

Fraction Fraction::operator-(const Fraction&rhs) const
{
   Fraction newRhs = rhs;
   newRhs.flipSign();
   return *this + newRhs;
}

Fraction Fraction::operator-(const inputInt value) const
{
   return *this - Fraction(value);
}

Fraction Fraction::operator-(const internalInt value) const
{
   return *this - Fraction(value);
}

Fraction operator-(const inputInt value, const Fraction&rhs)
{
   return Fraction(value) - rhs;
}

Fraction operator-(const internalInt value, const Fraction&rhs)
{
   return Fraction(value) - rhs;
}
/*End Arithmetic operators*/

/*Begin Comparison operators/relational operators*/

/*Equal-to operators*/

bool Fraction::operator==(const Fraction&rhs) const
{
   return ((this->numerator == rhs.numerator) && (this->denominator == rhs.denominator) && (this->sign == rhs.sign));
}

bool Fraction::operator==(const inputInt value) const
{
   return *this == value;
}

bool Fraction::operator==(const internalInt value) const
{
   return *this == value;
}

bool operator==(const inputInt value, const Fraction&rhs)
{
   return Fraction(value) == rhs;
}

bool operator==(const internalInt value, const Fraction&rhs)
{
   return Fraction(value) == rhs;
}

/*Not-Equal-to Operators*/

bool Fraction::operator!=(const Fraction&rhs) const
{
   return !(*this == rhs);
}

bool Fraction::operator!=(const inputInt value) const
{
   return !(*this == Fraction(value));
}

bool Fraction::operator!=(const internalInt value) const
{
   return !(*this == Fraction(value));
}

bool operator!=(const inputInt value, const Fraction&rhs)
{
   return !(Fraction(value) == rhs);
}

bool operator!=(const internalInt value, const Fraction&rhs)
{
   return !(Fraction(value) == rhs);
}

/*Greater-than Operators*/

bool Fraction::operator>(const Fraction&rhs) const
{
   internalInt val = lcm(this->denominator, rhs.denominator);
   return (this->numerator * (val / this->denominator) * this->sign) > (rhs.numerator * (val / rhs.denominator) * rhs.sign);
}

bool Fraction::operator>(const inputInt value) const
{
   return *this > Fraction(value);
}

bool Fraction::operator>(const internalInt value) const
{
   return *this > Fraction(value);
}

bool operator>(const inputInt value, const Fraction&rhs)
{
   return Fraction(value) > rhs;
}

bool operator>(const internalInt value, const Fraction&rhs)
{
   return Fraction(value) > rhs;
}

/*Less-than Operators*/

bool Fraction::operator<(const Fraction&rhs) const
{
   internalInt val = lcm(this->denominator, rhs.denominator);
   return (this->numerator * (val / this->denominator) * this->sign) < (rhs.numerator * (val / rhs.denominator) * rhs.sign);
}

bool Fraction::operator<(const inputInt value) const
{
   return (*this < Fraction(value));
}

bool Fraction::operator<(const internalInt value) const
{
   return (*this < Fraction(value));
}

bool operator<(const inputInt value, const Fraction&rhs)
{
   return (Fraction(value) < rhs);
}
bool operator<(const internalInt value, const Fraction&rhs)
{
   return (Fraction(value) < rhs);
}

/*Greater-than-Or-Equal Operators*/

bool Fraction::operator>=(const Fraction&rhs) const
{
   internalInt val = lcm(this->denominator, rhs.denominator);
   return (this->numerator * (val / this->denominator) * this->sign) >= (rhs.numerator * (val / rhs.denominator) * rhs.sign);
}

bool Fraction::operator>=(const inputInt value) const
{
   return (*this >= Fraction(value));
}

bool Fraction::operator>=(const internalInt value) const
{
   return (*this >= Fraction(value));
}

bool operator>=(const inputInt value, const Fraction&rhs)
{
   return (Fraction(value) >= rhs);
}

bool operator>=(const internalInt value, const Fraction&rhs)
{
   return (Fraction(value) >= rhs);
}

/*Less-than-Or-Equal Operators*/

bool Fraction::operator<=(const Fraction&rhs) const
{
   internalInt val = lcm(this->denominator, rhs.denominator);
   return (this->numerator * (val / this->denominator) * this->sign) <= (rhs.numerator * (val / rhs.denominator) * rhs.sign);
}

bool Fraction::operator<=(const inputInt value) const
{
   return (*this <= Fraction(value));
}

bool Fraction::operator<=(const internalInt value) const
{
   return (*this <= Fraction(value));
}

bool operator<=(const inputInt value, const Fraction&rhs)
{
   return (Fraction(value) <= rhs);
}

bool operator<=(const internalInt value, const Fraction&rhs)
{
   return (Fraction(value) <= rhs);
}

/*End Comparison operators/relational operators*/

/*Begin Compound Assignment operators*/

/*Addition assignment operators*/

Fraction& Fraction::operator +=(const Fraction& value)
{
   return (*this = *this + value);
}

Fraction& Fraction::operator +=(const inputInt value)
{
   return (*this = *this + value);
}

Fraction& Fraction::operator +=(const internalInt value)
{
   return (*this = *this + value);
}

/*Subtraction assignment operators*/

Fraction& Fraction::operator-=(const Fraction & value)
{
   return (*this = *this - value);
}

Fraction& Fraction::operator-=(const inputInt value)
{
   return (*this = *this - value);
}

Fraction& Fraction::operator-=(const internalInt value)
{
   return (*this = *this - value);
}

/* Multiplication assignment operators*/

Fraction& Fraction::operator *=(const Fraction& value)
{
   return (*this = *this * value);
}

/*End Compound Assignment operators*/

Fraction& Fraction::operator *=(const inputInt value)
{
   return (*this = *this * value);
}

Fraction& Fraction::operator *=(const internalInt value)
{
   return (*this = *this * value);
}

/* Division  assignment operators*/

Fraction& Fraction::operator /=(const Fraction& value)
{
   return (*this = *this / value);
}

Fraction& Fraction::operator /=(const inputInt value)
{
   return (*this = *this / value);
}

Fraction& Fraction::operator /=(const internalInt value)
{
   return (*this = *this / value);
}

void Fraction::fracAbs()
{
   sign = positive;
}
