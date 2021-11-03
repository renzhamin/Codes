#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n; cin>>n;
    for(int i=0,j=n*2;i<=n;i++,j-=2){
        for(int k=j;k>0;k--)cout<<" ";
        int k;
        for(k=0;k<i;k++) cout<<k<<" ";
        cout<<k;
        if(k) cout<<" ";
        while(k-->1)cout<<k<<" ";
        if(k>=0) cout<<k;
        cout<<"\n";
    } 
    for(int i=n,j=2;i>0;i--,j+=2){
        for(int k=j;k>0;k--)cout<<" ";
        int k;
        for(k=0;k<i-1;k++) cout<<k<<" ";
        cout<<k;
        if(k) cout<<" ";
        while(k-->1)cout<<k<<" ";
        if(k>=0) cout<<k;
        cout<<"\n";
    } 
}