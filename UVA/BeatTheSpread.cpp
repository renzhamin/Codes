#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){   
    int t;cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll x=(a-b)/2,y=(a+b)/2;
        if(x+y==a && y-x==b && x>=0 && y>=0)
            cout<<y<<" "<<x<<"\n";
        else
            cout<<"impossible"<<"\n";
    }
}