#include <iostream>
using namespace std;

int lcmof2(int num1,int num2)
{
   int maxValue;
   
   maxValue = (num1 > num2) ? num1 :   num2;

   while(1)
   {
      if((maxValue % num1 == 0) && (maxValue % num2 == 0))
      {
         break;
      }
      maxValue++;
   }
   return maxValue;
}