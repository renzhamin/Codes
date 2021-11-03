#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll l,s;
    cin>>l>>s;
    if(!s)
        if(l>1) done("-1 -1")
        else done("0 0")

    string mx=string(s/9,'9'),mn=mx;
    if(mx.length()<l) mx+=s%9+48;
    if(mx.length()<l)
        mx+=string(l-mx.length(),'0');


    ll zero=0;
    if(s%9==0) mn[mn.length()-1]='8'; 
    else if(l-mn.length()>1)
        mn+=(s-(s/9)*9-1)+48;
    else if(l-mn.length()==1)
        mn+=s%9+48;

    zero=l-mn.length()-1;
    if(zero>0)mn+=string(zero,'0');
    if(mn.length()<l)mn+='1';
    reverse(mn.begin(),mn.end());

    if(s==l*9) mn="-1";
    if(l==1 && s<10) mx=mn=to_string(s);
    if(s>l*9) mx=mn="-1";
    if(s%9==0 && s/9==l) mn=mx;

    cout<<mn<<" "<<mx<<"\n";
}