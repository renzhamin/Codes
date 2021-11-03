#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    int n; cin>>n;
    int o1=0,o2=0,e1,e2,xx,yy;
    bool x[n]{},y[n]{};
    for(int i=0;i<n;i++) {
        cin>>xx>>yy;
        if(xx&1) x[i]=1;
        if(yy&1) y[i]=1;
        o1+=x[i]; o2+=y[i];
    }
    e1=n-o1,e2=n-o2;
    if((o1%2==0 && o2%2==0)||!(o1+o2)) done(0)
    
    if((o1+o2)&1) done(-1) 

    for(int i=0;i<n;++i){
        if(x[i] ^ y[i]) done(1)
    }

    done(-1)
}