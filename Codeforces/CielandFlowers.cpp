#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n=3,arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    int r,g,b;
    r=arr[0],g=arr[1],b=arr[2];

    sort(arr,arr+n);
    int ans=0;

    ans+=ceil((arr[1]-arr[0])/3.0); 
    arr[1]-=ans*3;
    ans+=ceil((arr[2]-arr[0])/3.0);
    arr[2]-=ceil((arr[2]-arr[0])/3.0)*3;
    if(arr[1]<0 || arr[2]<0) ans=-1e5;
    ans+=min({arr[0],arr[1],arr[2]});

    int s=min({r,g,b});
    int ans1=s;
    ans1+=(r-s)/3,ans1+=(g-s)/3,ans1+=(b-s)/3;
    int ans2=0;
    ans2+=r/3,ans2+=b/3,ans2+=g/3;
    ans2+=min({(r-r/3*3),(g-g/3*3),(b-b/3*3)});

    cout<<max({ans,ans1,ans2})<<"\n";

}