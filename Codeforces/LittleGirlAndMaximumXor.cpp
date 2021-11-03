#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;


string d2b(ll b){
    string d;
    ll r;
    while(b>0){
        r=(b&1);
        d.push_back(r+'0');
        b/=2;
    }
    reverse(d.begin(),d.end());
    return d;
}

ll b2d(string b){
    ll d=0,tmp;
    ll n=b.length(),m=n-1;
    for(ll i=0;i<n;++i){
        tmp=(b[i]-'0')&1;
        d+=powl(2,m)*tmp;
        m--;
    }
    return d;
}

int main(){
    ll li,ri;
    cin>>li>>ri;
    ll pad=(ll)log2(ri)-(ll)log2(li);
    string l=string(pad,'0');
    string r=d2b(ri);
    l=l+d2b(li);

    string ans;
    int n=r.length();
    int i,tmp;
    for(i=0;i<n;++i){
        tmp = (l[i]-'0')^(r[i]-'0');
        ans.push_back(tmp+'0');
        if(l[i]!=r[i]){
            i++;
            break;
        } 
    }

    for(;i<n;++i){
        ans.push_back('1');
    }

    ll d=b2d(ans);

    cout<<d<<"\n";

}