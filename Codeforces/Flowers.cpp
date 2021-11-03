#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e5+1,M=1e9+7;
ll arr[N],cs[N];

int main(){
    ll n,k,a,b,ans;
    cin>>n>>k;
    cs[0]=cs[1]=arr[1]=arr[0]=1;
    for(ll i=1;i<N;++i){
        arr[i]=arr[i-1];
        if(i>=k)
            arr[i]+=arr[i-k],arr[i]%=M;
        cs[i]=cs[i-1]+arr[i];
        cs[i]%=M;
    }

    for(int i=0;i<n;++i){
        cin>>a>>b;
        ans=(cs[b]-cs[a-1]+M)%M;
        cout<<ans<<"\n";
    }
}