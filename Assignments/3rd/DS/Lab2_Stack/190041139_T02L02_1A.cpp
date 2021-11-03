#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    string s;
    stack<char>st;
    int t;cin>>t;
    while(t--){
        cin>>s;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        while(st.size()){
            cout<<st.top();
            st.pop();
        }
        cout<<"\n";
    }
}
