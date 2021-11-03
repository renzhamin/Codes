#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool solve(int r,int k){
    if(r==1) return 0;
    return (solve(r-1,(k+1)/2)? k&1 : !(k&1));
}


int main(){
    ll n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<"\n";
}