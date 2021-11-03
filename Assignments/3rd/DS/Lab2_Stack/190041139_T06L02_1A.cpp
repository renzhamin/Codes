#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    string s;
    while(cin>>s){
        stack<char>st;
        ll ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                continue;
            }
            if(st.empty()) ans++;
            else
                st.pop();
        }
        ans += st.size();
        cout<<ans<<"\n";
    }
}


/*
()))((
(())(())
((())()
))))))((
(()((
*/
