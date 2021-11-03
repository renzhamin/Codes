#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n+1],ans=0;
    bool havex=0;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(arr[i]==x) havex=1;
    }
    if(!havex) arr[n]=x,n++,ans++;
    sort(arr,arr+n);
    int ind=lower_bound(arr,arr+n,x)-arr+1;
    int i=ind-1;
    if(i<n)
    while(arr[i]==arr[ind] && 2*ind<n)ind++;

    ans+=abs(n-2*ind+1);
    if(n>=2*ind-1 && ((ans>0 && havex)||(!havex && ans>1))){
        ans--;
    }
    cout<<ans<<"\n";
}