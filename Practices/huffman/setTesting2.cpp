#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int a=1,b=2,c=3;
    set<int*>st;
    st.emplace(&a);
    auto it=st.begin();
    cout<<**it<<"\n";
}
