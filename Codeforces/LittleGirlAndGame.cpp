#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length(),freq[26]{};
    for(int i=0;i<n;i++) freq[s[i]-'a']++;    
    int even=0,odd=0;
    for(int i=0;i<26;i++) {
        if(freq[i])
            if(freq[i]&1)odd++;
            else even++;
    }
    if(odd<2) done("First")
    if(even&1 && !(odd&1)) done("Second")
    if(odd&1) done("First")
    done("Second")
}