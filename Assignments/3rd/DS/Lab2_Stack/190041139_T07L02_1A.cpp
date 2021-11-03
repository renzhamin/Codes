#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define travStack(cond)while(st.size() && cond){ans+=st.top();st.pop();}

void printStack(stack<char>st){
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

string oper="+*/^";
unordered_map<char,int>prio;

string convertInfixToPostfix(string s){
    string ans="";
    stack<char>st;
    for(int i=0;i<s.size();i++){
        cout<<ans<<"  ";printStack(st);
        if(s[i]=='('){
            st.push('('); continue;
        }
        if(s[i]==')'){
            travStack(st.top()!='(');
            st.pop();
            continue;
        }
        if(prio[s[i]]){
            travStack(prio[st.top()]>prio[s[i]]);
            st.push(s[i]);
            continue;
        }
        ans += s[i];
    }
    travStack(1);
    return ans;
}

int main(){
    for(int i=0;i<oper.size();i++){
        prio[oper[i]] = i+1;
    }
    prio['-'] = prio['+'];
    string s;
    int t;cin>>t;
    while(t--){
        cin>>s;
        cout<<convertInfixToPostfix(s)<<"\n";
    }
}
