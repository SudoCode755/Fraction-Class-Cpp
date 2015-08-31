#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Fraction.h"

using namespace std;

void printFraction(Fraction f)
{
   cout << f.getNumerator() << "/" << f.getDenominator() << "=" << f.decimalValue() << endl;
}

int main()
{
   srand(time(0));

   int x, y;
   Fraction f;
   bool success = true;
   for (int i = 0; i < 10000; i++)
   {
      x = rand();
      y = rand() + 1;
      f = Fraction(x, y);
      Fraction f2 = Fraction(2 * f);
      f2.reduce();
      if (f + f != f2)
      {
         cout << "FAIL ADD-MUL WITH" << endl;
         printFraction(f + f);
         printFraction(Fraction(2 * f));
         success = false;
      }
      if ((2ULL * f) / Fraction(2) != f)
      {
         cout << "FAIL MUL-DIV WITH" << endl;
         printFraction(f);
         printFraction((2ULL * f) / Fraction(2));
         success = false;
      }

      x = rand();
      y = rand() + 1;
      f.fromDecimal(static_cast<double>(x) / static_cast<double>(y), 0);
      if (f!=Fraction(x,y))
      {
         cout << "FAIL DECIMAL EXTARCTION WITH" << endl;
         printFraction(f);
         cout << x << "/" << y << "=" << (x * 1.0) / (y * 1.0) << endl;
         success = false;
      }
   }

   if (success)
   {
      cout << "!!!SUCCESS!!!" << endl;
   }
   return 0;
}
