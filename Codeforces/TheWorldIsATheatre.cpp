#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll ncr[150][150];
void pascal(int n){
    for(int i=1;i<=n;i++){
        ncr[i][0]=1,ncr[i][1]=i;
        for(int j=2;j<=n;j++)
            ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
    }    
}


int main(){
    pascal(30);
    ll n,m,t,s=0;
    cin>>n>>m>>t;
    int i,j;
    i=min(n,t-1),j=t-i;
    while(j<=m && i>=4){
        s+=ncr[n][i]*ncr[m][j];
        i--;j=t-i;
    }
    cout<<s<<"\n";
}