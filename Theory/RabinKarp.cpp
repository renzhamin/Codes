// Deletion of Repeats
#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int getID(int x){
    static unordered_map<int,int>ids;
    static int elems=-5e4;
    int &v=ids[x];
    if(!v) v=++elems;
    return v;
}

class RabinKarp{
public:
    ll *hashes,*primePower,Prime=53,MOD=1e9+7,N;

    RabinKarp(ll n,ll P=53,ll M=1e9+7){
        Prime = P;
        MOD = M;
        N = n+1;
    }

    template<typename T>
    void preCompute(T s,int n){  // 1 indexed
        hashes = new ll[N];
        primePower = new ll[N];
        primePower[0] = 1;
        hashes[0] = 0;

        for(int i=1;i<=n;i++){
            hashes[i]=( (hashes[i-1]*Prime)%MOD + getID(s[i-1]) )%MOD;
            primePower[i] = ( primePower[i-1]*Prime )%MOD;
        } 
    }

    ll rollingHash(int i,int j){
        return (hashes[j] - (hashes[i]*primePower[j-i])%MOD +MOD )%MOD;
    }

    ll rollingHashOfLengthN(int i,int n){
        return ( hashes[i] - (hashes[i-n]*primePower[n])%MOD +MOD )%MOD;
    }

    template<typename T>
    ll getHash(T s,int n){
        ll H=0;
        for(int i=0;i<n;i++){
            H = ( (H*Prime)%MOD + getID(s[i]) )%MOD;
        } 
        return H;
    }
};

int main(){
    int n;
    unordered_map<ll,vector<int>>mp;

    cin>>n;

    int arr[n];

    RabinKarp H(n);

    for(int i=0;i<n;i++) 
        cin>>arr[i];
    
    H.preCompute(arr,n);

    for(int i=0;i<n;i++){
        mp[arr[i]].push_back(i+1);
    }

    int ind=0;

    for(int i=1;i<n;i++){
        for(auto k:mp[arr[i-1]]){
            int j=k,l=j-i;
            if(l<1 || j+l-1>n) continue;
            ll h1=H.rollingHash(i-1,j-1);
            ll h2=H.rollingHash(j-1,j+l-1);
            if(h1==h2){
                i=j-1;
                ind = j-1;
                break;
            }
        }
    }

    cout<<n-ind<<"\n";
    for(int i=ind;i<n;i++)
        cout<<arr[i]<<" ";

}
