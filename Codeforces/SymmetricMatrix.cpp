#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        ll n,m,o,o2,t1,t2; 
        cin>>n>>m;
        bool f=0;
        for(int i=0;i<n;++i){
            cin>>o>>o2>>t1>>t2;
            if(o2==t1) f=1;
        }
        cout<<(f && !(m&1)?"YES\n":"NO\n");    
    }
}