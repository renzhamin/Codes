#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int mx=1000;
bool grid[1002][1002];



int main(){
    int x,y,n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        grid[x][y]=1;
    }

    ll ans=0,ci=1,all=0;

    while(ci<mx){
        ll i=ci,j=1,s=0;
        while(i<=mx){
            if(grid[i][j])
                s++;
            i++,j++;
        }
        ans+=s*(s-1)/2;
        ci++;
    }
    ci=mx;
    while(ci>1){
        ll i=ci,j=1,s=0;
        while(i>0){
            if(grid[i][j])
                s++;
            i--,++j;            
        }
        ans+=s*(s-1)/2;
        ci--;
    }
    ci=2;
    while(ci<mx){
        ll i=ci,j=mx,s=0;
        while(i<=mx){
            if(grid[i][j])
                s++;
            i++,j--;
        }
        ans+=s*(s-1)/2;
        ci++;
    }
    ci=1;
    int cx=2;
    while(cx<mx){
        ll i=1,j=cx,s=0;
        while(j<=mx){
            if(grid[i][j])
                s++;
            i++,++j;
        }
        ans+=s*(s-1)/2;
        cx++;
    }

    cout<<ans<<"\n";
}