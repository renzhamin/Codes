#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        string s,s1,s2;
        cin>>s;
        n=s.length();
        s1=s.substr(0,n/2);
        if(n%2==0){
            s2=s.substr(n/2,n);
        }
        else{
           s2=s.substr((n/2)+1,n);
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
}