#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
    int t;cin>>t;
    int i=1;
    while(t--){
    double ab,ac,bc,rt;
    cin>>ab>>ac>>bc>>rt;
    cout<<"Case "<<i<<": "<<setprecision(10)<<fixed<<sqrt(rt/(rt+1))*ab<<"\n";
    i++;
    }
}
