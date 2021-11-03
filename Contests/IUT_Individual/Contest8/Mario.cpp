#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    // freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll n,i=0,turns=0,stars=0,dir=0;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    while(stars<n){
        if(i<0){
            i=0;dir=0;turns++;
        }
        if(i>=n){
            i=n-1;dir=1;turns++;
        }
        if(arr[i]<=stars){
        	stars++;arr[i]=n+10;
        }
        if(dir==0) i++; else i--;
    }
    cout<<turns<<"\n";
}
