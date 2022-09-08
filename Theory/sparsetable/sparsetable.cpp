#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll MAX=100001;
ll table[MAX][__lg(MAX)+1],n;

void sparsebuild(ll *arr){
    for(int i=0;i<n;++i){
        table[i][0]=i;
    }
    ll col=__lg(n);
    for(int j=1;j<=col;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            ll &ind1 = table[i][j-1];
            ll &ind2 = table[i+(1<<(j-1))][j-1];
            table[i][j]=(arr[ind1]<arr[ind2]?
                ind1:ind2);
        }
    }
}

int main(){
    cin>>n;
    ll arr[n],l,r,q,k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sparsebuild(arr);
    cin>>q;
    while(q--){
        cin>>l>>r;
        k=__lg(r-l+1);
        ll ans=min(arr[table[l][k]],
            arr[table[r+1-(1<<k)][k]]);
        cout<<ans<<"\n";
    }
}