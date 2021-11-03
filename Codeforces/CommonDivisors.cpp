#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define concate(x,s,b) while(x--)s+=b; 

int main(){
    string s1,s2,tmp1,tmp2,ca,cb;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    int l=min(n,m);
    ll ans=0,x1,x2;
    for(int i=0;i<l;++i){
        ca+=s1[i],cb+=s2[i];
        tmp1="";
        x1=n/(i+1);
        concate(x1,tmp1,ca);
        tmp2="";
        x2=m/(i+1);
        concate(x2,tmp2,cb);
        if(tmp1==s1 && tmp2==s2 && ca==cb)
            ans++;
    }
    cout<<ans<<"\n";
}