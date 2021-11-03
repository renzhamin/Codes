#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b){
    if(abs(a.first)==abs(b.first))
        return abs(a.second)<abs(b.second);
    return abs(a.first)<abs(b.first);
}

int main(){
    ll n,k=0;
    cin>>n;
    pair<int,int>point[n];
    for(int i=0;i<n;++i){
        cin>>point[i].first>>point[i].second;
        if(point[i].first!=0 && point[i].second!=0)
            k+=4;
        else 
            k+=2;
        k+=2;
        
    }
    sort(point,point+n,comp);
    cout<<k<<"\n";
    for(int i=0;i<n;++i){
        if(point[i].first!=0)
            cout<<1<<" "<<abs(point[i].first)<<(point[i].first<0?" L ":" R")<<"\n" ;
        if(point[i].second!=0)
            cout<<1<<" "<<abs(point[i].second)<<(point[i].second<0?" D ":" U")<<"\n" ;
        cout<<2<<"\n";
        if(point[i].first!=0)
            cout<<1<<" "<<abs(point[i].first)<<(point[i].first>0?" L ":" R")<<"\n" ;
        if(point[i].second!=0)
            cout<<1<<" "<<abs(point[i].second)<<(point[i].second>0?" D ":" U")<<"\n" ;
        cout<<3<<"\n";
    }
}