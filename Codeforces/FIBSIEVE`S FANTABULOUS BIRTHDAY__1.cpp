#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
  
int main(){
   long long n,s,r,t;
   cin>>t;
   for(int i=1;i<=t;i++){
       int x,y;
       cin>>n;
       s= ceil(sqrt(n));
       r=n-(s-1)*(s-1);
       if(r>s) {x=s;y=(1+s*s-n);}
       else {y=s;x=r;}
       if(s%2) swap(x,y);
       cout<<"Case "<<i<<": "<<x<<" "<<y<<endl;
   }
}