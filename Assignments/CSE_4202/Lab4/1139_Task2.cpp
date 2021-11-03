#include <bits/stdc++.h>
#define ll long long 
using namespace std;


ll superdigits(string s){
    int n=s.length();
    ll sum=0;
    for(int i=0;i<n;i++)     
        sum+=s[i]-'0';
    return sum;
}

string solve(string cur){
    if(cur.length()==1) return cur;
    return solve(to_string(superdigits(cur)));
}

int main(){
    string n;    
    ll k;
    cin>>n>>k;
    string ans=solve(to_string(superdigits(n)*k));
    cout<<ans<<"\n";
}