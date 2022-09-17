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


ll fn(ll a, ll b=UNDEFINED){
    return a+b;
}


void compute_sparse_table(){
    ll level = __lg(n) + 1;

    for(int i=0;i<n;i++) {
        dp[i][0] = arr[i]; 
        // ind[i][0] = i;
    }

    for(ll k=1; k<=level; k++){
        for(ll i=0; i + ( 1LL << (k-1) ) < n; i++){

            ll left = dp[i][k-1];
            ll right = dp[ i + ( 1LL << (k-1) ) ][k-1];


            dp[i][k] = fn(left, right);
//             ind[i][k] = (dp[i][k]==left? ind[i][k-1]:ind[i+1LL<<(k-1)][k-1]);
        }
    }
}

ll query(ll l, ll r){
    if(l>r) swap(l,r);
    ll k = __lg(r-l+1);
    ll left = dp[l][k];
    ll right = dp[r - (1LL<<k) + 1][k];
    return fn(left, right);
}


ll nonOverlapingQuery(ll l, ll r){
    if(l>r) swap(l,r);
    ll ans = UNDEFINED, k;
    while(l<=r){
        k = __lg(r-l+1);
        ans = fn(ans, dp[l][k]);
        l += (1LL<<k);
    }
    return ans;
}


int main(){

    ll q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    compute_sparse_table();

    while(q--){
        ll l,r; cin>>l>>r;
        cout<<nonOverlapingQuery(l-1,r-1)<<"\n";
    }
}
