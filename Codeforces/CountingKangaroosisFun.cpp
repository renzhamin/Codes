#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int j=(n-1)/2+1,i=0,in=0;

    while(j<n){
        if(arr[i]*2<=arr[j]){
            i++, j++, in++;
        } else j++;
    }
    cout<<n-in<<"\n";
}