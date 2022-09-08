#include <bits/stdc++.h>
#define ll long long 
using namespace std;

    
ll n=5,arr[5],s;
bool done;

void sub(int i,ll num=0){
    if(i==n){
        if(num==23) done=1;
        return;
    }
    if(done) return;
    sub(i+1,num+arr[i]);    
    sub(i+1,num-arr[i]);
    sub(i+1,num*arr[i]);
}

int main(){
    while(1){
        for(int i=0;i<n;i++) cin>>arr[i];
        if(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]==0) break;
        done=0;
        sort(arr,arr+n);
        do{
            sub(1,arr[0]);
        }while(!done && next_permutation(arr,arr+5));

        cout<<(done?"Possible\n":"Impossible\n"); 
    }
}