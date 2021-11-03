#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    int a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    if(a*d>c*b) swap(c,d),swap(a,b);
    else if(c==d){
        c=d=1;
        if(a>b) swap(a,b);
    }
    x = c*b-a*d,y = c*b;
    if(x<=0)done("0/"<<c)
    int g=__gcd(x,y);
    x/=g,y/=g;
    if(c==d) y=max(a,b);
    cout<<x<<"/"<<y<<"\n";
}