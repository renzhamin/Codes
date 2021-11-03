#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define INVALID LLONG_MIN
using namespace std;

string opers="/*+-";

ld result(char oper,ld a,ld b){
    ld r;
    switch(oper){
        case '+':
            r=a+b;break;
        case '-':
            r=a-b;break;
        case '*':
            r=a*b;break;
        case '/':
            r=a/b;break;
        default:
            r=INVALID;
    }
    return r;
}


ld eval(string s){
    stack<ld>st;
    ld a,b;
    for(int i=0;i<s.size();i++){
        if(opers.find(s[i])!=-1){
            if(st.size()<2) return INVALID;
            b = st.top(),st.pop();
            a = st.top(),st.pop();
            st.push(result(s[i],a,b));
        } else {
            st.push(s[i]-'0');
        }
    }
    return st.top();
}

int main(){
    string s;
    int t;cin>>t;
    while(t--){
        cin>>s;
        cout<<eval(s)<<"\n";
    }
}
