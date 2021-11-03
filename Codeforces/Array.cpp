#include <bits/stdc++.h>
#define ll long long
#define done(x) {cout<<x<<"\n";return 0;}  
using namespace std;


int freq[(int)1e5+1];

int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==1 && k==1) done("1 1")
    if(n==1) done("-1 -1")
    ll i=0,j=0,cur,m=0,l=-1,r=-1,ci;
    while(j<n){
        cur=arr[j];
        if(!freq[cur]){
            m++;
        }
        freq[cur]++;
        if(m==k){
            ci=i;
            while(freq[arr[ci]]>1){
                freq[arr[ci]]--; 
                ci++;
            }
            i=ci;
            ci--;
            l=i+1,r=j+1;
            break;
        }
        j++;
    }
    cout<<l<<" "<<r<<"\n";
}