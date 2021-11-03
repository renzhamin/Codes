#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll x[n*m],y[n*m],l=0;
    ll i=0,j=0,d=1;
    while(l<n*m){
        if(j==m) i++,d=-d,j--;
        if(j==-1 && d==-1) d=-d,i++,j++;
        x[l]=i+1,y[l++]=j+1;
        j+=d;
    }
    ll p=2*(k-1);
    for(i=0;i<p;i++){
        cout<<"2 "<<x[i]<<" "<<y[i++]<<" ";
        cout<<x[i]<<" "<<y[i]<<"\n";
    }
    cout<<n*m-p<<" ";
    while(i<l){
        cout<<x[i]<<" "<<y[i++]<<" ";
    }
}