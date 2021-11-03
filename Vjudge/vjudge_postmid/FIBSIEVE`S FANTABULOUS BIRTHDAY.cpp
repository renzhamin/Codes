#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{  long long int n,t,j=0;
   cin>>t;
   while(t--)
   {   cin>>n;
       long long sq=ceil(sqrt(n));
       long long r=sq*sq-n;
       long long x,y;
       if(r<sq){
           y=r+1;
           x=sq;
       }
       else{
           x=2*sq-r-1;
           y=sq;
       }
       if( sq & 1)
	       swap(x,y);
       cout<<"Case "<<++j<<": "<<x<<" "<<y<<endl;

   }
}