#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define N(s) (-1+sqrt(1+8*s))/2.0
#define sum(n) n*(n+1)/2

int main(){
    int t;cin>>t;
    while(t--){
        double x;cin>>x;
        double ans=ceil(N(x));
        ans+=(sum(ans)-x==1);
        cout<<ans<<"\n";
    }
}
