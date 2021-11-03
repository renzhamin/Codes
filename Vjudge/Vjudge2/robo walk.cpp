#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x1;
    cin>>n,cin>>x1;
    int x=x1-1;
    string p;cin>>p;
    int com;cin>>com;
    string d;
    cin>>d;
    cout<<p[x];
    for(int i=0;i<com;i++){
        if(d[i]==(char)82){
            x++;cout<<p[x];
        }
        if(d[i]==char(76)){
            x--;cout<<p[x];
        }

    }
}
