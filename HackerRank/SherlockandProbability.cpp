#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        ll n,k;
        string s;
        cin>>n>>k>>s;
        ll cs[n+k]{};
        cs[0]=(s[0]=='1'?1:0);
        for(int i=1;i<n;i++) cs[i]=cs[i-1]+(s[i]=='1'?1:0);
        ll ans=cs[n-1],range;
        for(int i=0;i<n-1;++i){
            if(s[i]=='0') continue;
            range=min(i+k,n-1);
            ans+=(cs[range]-cs[i])*2;
        }      
        ll gcd=__gcd(ans,n*n);  
        cout<<ans/gcd<<"/"<<n*n/gcd<<"\n";  
    }
}
