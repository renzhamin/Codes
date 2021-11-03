#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        int s=2*n+p;
        int i=1,j=2;
        while(i<=n){
            while(j<=n){
                cout<<i<<" "<<j<<"\n";
                j++;
                s--;
                if(s<=0){ i=n;break;}
            }
            i++; j=i+1;
        }
    }
}