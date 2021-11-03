#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll num[10];

void fn(int digit){
    if(digit==4) num[2]+=2,num[3]++;
    else if(digit==6) num[3]++,num[5]++;
    else if(digit==8) num[7]++,num[2]+=3;
    else if(digit==9) num[7]++,num[3]+=2,num[2]++;
    else num[digit]++;
}

int main(){
    string s,ans;ll n; 
    cin>>n>>s; 
    for(int i=0;i<n;i++){
        fn(s[i]-48);
    } 
    for(int i=9;i>1;i--){
        ans+=string(num[i],i+48);
    }
    cout<<ans<<"\n";
}