/*
   CSES Static Range Sum Queries
   https://cses.fi/problemset/result/4603207/
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll UNDEFINED = 0;

const ll N = 2e5+5;
const ll L = 20;

ll dp[N][L], arr[N];
ll n;


bool fn(ll a, ll b=UNDEFINED){
    return a <= b;
}


void compute_sparse_table(){
    ll level = __lg(n) + 1;

    for(int i=0;i<n;i++) {
        dp[i][0] = i; 
    }

    for(ll k=1; k<=level; k++){
        for(ll i=0; i + ( 1LL << (k-1) ) < n; i++){

            ll left = dp[i][k-1];
            ll right = dp[ i + ( 1LL << (k-1) ) ][k-1];


            if(fn(arr[left], arr[right]))
                dp[i][k] = left;
            else 
                dp[i][k] = right;
        }
    }
}

ll query(ll l, ll r){
    if(l>r) swap(l,r);
    ll k = __lg(r-l+1);
    ll left = dp[l][k];
    ll right = dp[r - (1LL<<k) + 1][k];
    if(fn(arr[left],arr[right]))
        return arr[left];
    return arr[right];
}


int main(){

    ll q;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    compute_sparse_table();
    cin>>q;
    while(q--){
        ll l,r; cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
}
