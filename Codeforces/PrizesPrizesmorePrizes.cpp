#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll cnt[5];
pair<ll,ll>prizes[5];

int main(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    for(int i=0;i<5;++i){
        cin>>prizes[i].first;
        prizes[i].second=i;
    }
    sort(prizes,prizes+5);
    ll tmp,points=0;
    for(int i=0;i<n;++i){
        points+=arr[i];
        for(int i=4;i>=0;--i){
           tmp =  points/prizes[i].first;
           points-=prizes[i].first*tmp;
           cnt[prizes[i].second]+=tmp;
        }
    }
    for(int i=0;i<5;++i){
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
    cout<<points<<"\n";
}