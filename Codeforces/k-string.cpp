#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    string s;
    int n,k,freq[26]{}; 
    cin>>k>>s;
    n=s.length();
    for(int i=0;i<n;++i){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<26;++i){
        if(freq[i]){
            if(freq[i]%k)
                done(-1)
        }
    }
    string ans;
    for(int i=0;i<26;++i){
        if(freq[i]){
            ans+=string(freq[i]/k,i+'a');
        }
    }
    string a;
    for(int i=0;i<k;i++) a+=ans;
    cout<<a<<"\n"; 

}