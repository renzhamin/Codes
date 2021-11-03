#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,s,arr[(int)1e5+10],st,lo=1,hi,mid,ans;

bool check(){
    ll sums=0;
    for(int i=0;i<n;++i){
        sums+=arr[i]/mid;
    }
    return sums>=s;
}

ll bs(){
    lo=1,ans=1,hi=st/s;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(check())
            lo=mid+1,ans=mid;
        else
            hi=mid-1;
    }
    return ans;
}

int main(){
    int t,T=1;cin>>t;
    while(t--){
        st=0;
        cin>>n>>s;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            st+=arr[i];
        }
        cout<<"Case "<<T++<<": ";
        cout<<bs()<<"\n";
    }
}