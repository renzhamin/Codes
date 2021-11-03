#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll na,nb,nc,pa,pb,pc,r;
ll B,C,S;

bool check(ll mid){
    ll x=0,y=0,z=0;
    x=max(x,(mid*B-na)*pa);
    y=max(y,(mid*S-nb)*pb);
    z=max(z,(mid*C-nc)*pc);
    return x+y+z<=r;
}


ll bs(ll hi){
    ll lo=0,mid,ans;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(check(mid))
            lo=mid+1,ans=mid;
        else
            hi=mid-1;
    }
    return ans;
}


int main(){
    string s;
    cin>>s>>na>>nb>>nc>>pa>>pb>>pc>>r;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='B')B++; 
        else if(s[i]=='C') C++;
        else S++;
    }

    if(!B)B=-1; if(!C)C=-1; if(!S)S=-1;

    ll mxB=(r/pa+na)/B,mxS=(r/pb+nb)/S,mxC=(r/pc+nc)/C;
    ll mx=-1;
    if(B>0) mx=mxB;
    if(S>0) mx=max(mx,mxS);
    if(C>0) mx=max(mx,mxC);

    cout<<bs(mx)<<"\n";
}