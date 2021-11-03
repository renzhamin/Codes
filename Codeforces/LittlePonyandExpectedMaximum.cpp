#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

int main(){
    ll m,k; 
    cin>>m>>k;
    ld pk=0,nk,ans=0;
    for(ld i=1;i<=m;++i){
        nk=powl(i/m,k);
        ans+=(nk-pk)*i;
        pk=nk;
    }
    cout<<setprecision(10)<<fixed<<ans<<"\n";
}