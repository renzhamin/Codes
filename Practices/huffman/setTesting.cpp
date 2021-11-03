#include <bits/stdc++.h>
#define ll long long 
#define pl pair<ll,ll>
#define ff first
#define ss second
using namespace std;

pl tmp;

bool cmp(pl* a,pl* b){
    return a->second<b->second;
}


int main(){
    set<pl*,decltype(cmp)*>st(cmp);
    auto x=(pl*)malloc(sizeof(pl)); 
    x->first=1,x->second=2;
    st.emplace(x);
    auto y=(pl*)malloc(sizeof(pl)); 
    y->first=10,y->second=1;
    st.emplace(y);
    auto it=st.begin(),it2=it;
    it2++;
    st.erase(it2);
    st.erase(it);
    st.emplace(x);
    for(auto i=st.begin();i!=st.end();i++){
        cout<<(**i).first<<"\n";
    }
}
