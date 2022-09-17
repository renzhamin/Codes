#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=2e6+4;

int M[mx];

void Manachar(string s){
    int n=s.size();
    string t="%#";
    for(int i=0;i<n;i++){
        t+=s[i];
        t+='#';
    }
    t+='!';
    
    n=t.size();
    int c=2,r=c,m;

    for(int i=2;i<n;i++){
        m=2*c-i;
        if(i<r)
            M[i]=min(M[m],r-i);

        while(t[i+M[i]+1]==t[i-M[i]-1])
            M[i]++;

        if(i+M[i]>r){
            c=i;
            r=M[i]+i;
        }
    }
}


int main(){
    string s;
    int n;cin>>n>>s;
    Manachar(s);
    int ans=*(max_element(M,M+n*2+3));
    cout<<ans<<"\n";
}
