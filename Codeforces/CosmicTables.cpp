#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll arr[n][m],r[n],c[m],x,y;
    iota(r,r+n,0); iota(c,c+m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    char s[2];
    while(k--){
        cin>>s>>x>>y;
        x--,y--;
        if(s[0]=='c') swap(c[x],c[y]);
        else if(s[0]=='r') swap(r[y],r[x]);
        else cout<<arr[r[x]][c[y]]<<"\n";
    }
}