#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define mx 10000


int main(){
    ll cs{0},ans{0},n,num;
    set<ll>st{0};
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>num;
        cs+=num;
        if(st.find(cs)!=st.end()){
            ans++;
            st.clear();
            st.emplace(0);
            cs=num;
        } 
        st.emplace(cs);
    }
    cout<<ans<<"\n";
}