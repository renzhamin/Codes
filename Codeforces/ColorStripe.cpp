#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ll n,k,ans=0;
    string s,s2;
    cin>>n>>k>>s;
    s2=s;
    if(k==2){
        ll ans2=0;
        char a='A',b='B';
        for(int i=0;i<n;++i){
            if(s[i]!=a){
                ans++;
                s[i]=a;
            } else if(s[i]!=b){
                ans2++;
                s2[i]=b;
            }
            if(a=='A') a='B'; else a='A';
            if(b=='A') b='B'; else b='A';            
        }
        if(ans>ans2) ans=ans2,s=s2;
    } else 
    for(int i=1;i<n-1;++i){
        if(s[i]==s[i-1]){
            if(s[i]<='B'){
                if(s[i+1]!='C') s[i]='C';
                else {
                    if(s[i]=='B') s[i]='A';
                    else s[i]='B';
                }
            } else {
                if(s[i+1]=='A') s[i]='B';
                else s[i]='A';
            }
            ans++;
        }
    } 
    
    if(s[n-1]==s[n-2]){
       if(s[n-1]=='A')
           s[n-1]='B';
       else if(s[n-1]=='B')
           s[n-1]='A';
       else
           s[n-1]='A';
        ans++;
    }
    cout<<ans<<"\n";
    cout<<s<<"\n";
}