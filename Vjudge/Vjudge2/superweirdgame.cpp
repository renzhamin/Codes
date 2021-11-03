#include <iostream>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    int m[n];
    for(int i=0;i<n;i++) cin>>m[i];
    int b[n];
    for(int i=0;i<n;i++) cin>>b[i];
    int ms=0,bs=0,j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(i<j && m[i]+m[j]==k) ms++;
            if(i<j && b[i]+b[j]==k) bs++;
        }
    }
    if(ms==bs) cout<<"Draw";
    else if(ms>bs) cout<<"Mahmoud";
    else cout<<"Bashar";
}
