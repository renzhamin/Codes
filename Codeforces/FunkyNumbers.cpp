#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll n,tmp;
    set<ll>st{1};
    cin>>n;
    ll cur=1,i=2;
    while(cur<n){
        cur+=i++;
        st.emplace(cur);
    }
    for(auto i=st.begin();i!=st.end();++i){
        if(st.find(n-(*i))!=st.end())
            done("YES")
    }
    done("NO")
}