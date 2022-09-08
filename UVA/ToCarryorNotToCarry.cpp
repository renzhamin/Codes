#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll a,b,b1,b2,ans,i;
    while(cin>>a>>b){
        ans=i=0;
        while(a>0 || b>0){
            b1=a&1,b2=b&1;
            if(b1!=b2)
                ans|=1<<i;
            a>>=1,b>>=1;
            i++;
        }
        cout<<ans<<"\n";
    }
}