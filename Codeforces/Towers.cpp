#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,k,tmp,l=0;
    cin>>n>>k;
    set<pair<ll,int>>arr;
    pair<int,int>moves[k];
    for(int i=0;i<n;i++) cin>>tmp,arr.emplace(tmp,i+1);
    while(k>0){
        auto lo=arr.begin();
        auto hi=prev(arr.end());
        if(lo->first>=hi->first) break;
        moves[l].first=hi->second;
        moves[l++].second=lo->second;
        auto left=*(lo);
        auto right=*(hi);
        arr.erase(hi);
        arr.erase(lo);
        arr.emplace(left.first+1,left.second);
        arr.emplace(right.first-1,right.second);
        k--;
    }
    auto lo=arr.begin();auto hi=arr.rbegin();
    cout<<(hi->first)-(lo->first)<<" "<<l<<"\n";
    for(int i=0;i<l;++i){
        cout<<moves[i].first<<" "<<moves[i].second<<"\n";
    }
} 