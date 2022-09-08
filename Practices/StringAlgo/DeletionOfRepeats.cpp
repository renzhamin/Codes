#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define P 53
const int mx=1e5+1;

int n;
ll arr[mx],hashes[mx],powP[mx];
unordered_map<int,vector<int>>mp;

void compute(){
    powP[0] = 1;
    for(int i=1;i<=n;i++){
        powP[i] = (powP[i-1]*P);
        hashes[i] = (arr[i] + (hashes[i-1]*P));
    }
}


int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    compute();

    for(int i=1;i<=n;i++){
        mp[arr[i]].push_back(i);
    }

    int ind=1;

    for(int i=1;i<n;i++){
        for(auto k:mp[arr[i]]){
            int j=k,l=j-i;
            if(l<1 || j+l-1>n) continue;
            ll h1=(hashes[j-1]-(hashes[i-1]*powP[l]));
            ll h2=(hashes[j+l-1]-(hashes[j-1]*powP[l]));
            if(h1==h2){
                i=j-1;
                ind = j;
                break;
            }
        }
    }

    cout<<n-ind+1<<"\n";
    for(int i=ind;i<=n;i++)
        cout<<arr[i]<<" ";

}
