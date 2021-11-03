#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    int tmp1,tmp2;
    pair<int,pair<int,int>>arr[n*2];
    string a[2];
    a[0]=string(n,'0'),a[1]=a[0];
    for(int i=0;i<n;++i){
        cin>>tmp1>>tmp2;
        arr[i*2]={tmp1,{0,i}};
        arr[i*2+1]={tmp2,{1,i}};
    }
    sort(arr,arr+n*2);
    for(int i=0;i<n/2;++i){
        a[0][i]=a[1][i]='1';
    }
    for(int i=0;i<n;++i){
        a[arr[i].second.first][arr[i].second.second]='1';
    }
    cout<<a[0]<<"\n";
    cout<<a[1]<<"\n";
}