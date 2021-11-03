#include <bits/stdc++.h>
#define ll long long 
using namespace std;

string openParen="([{";
string closeParen=")]}";
unordered_map<char,char>mp;

bool sol(string s){
    stack<int>st; 
    for(int i=0;i<s.size();i++){
        if(openParen.find(s[i])!=-1){
            st.push(s[i]);
            continue;
        }
        if(closeParen.find(s[i])!=-1){
           if(st.empty() || mp[s[i]]!=st.top())
                return 0;
            st.pop();
        }
    }
    return 1;
}

int main(){
    for(int i=0;i<closeParen.size();i++)
        mp[closeParen[i]] = openParen[i];
    
    string s;
    int t;cin>>t;cin.get();
    while(t--){
        getline(cin,s);
        cout<<(sol(s)?"Yes\n":"No\n");	
    }
}
