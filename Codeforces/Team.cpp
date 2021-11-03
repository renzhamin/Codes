#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll z,o;
    cin>>z>>o;
    if((z+1)*2<o || z-1>o)
        done(-1)

    bool f= z*2>o;
    bool d= abs(z-o)>1;
    string s;

    while(z>0 || o>0){
        if(f){
            if(z>0)
                s+="0";
            z--;
            f=0;
        } else {
            if(o-1<z) d=0;
            if(o>0){
                if(o>1 && d) s+="11",o-=2;
                else s+="1",o--;
            }
            f=1;
        }
    }
    cout<<s<<"\n";
}