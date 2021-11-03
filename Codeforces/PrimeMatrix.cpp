#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m;

const int mx=(int)1e5+100;
bool isprime[mx+1]; 
int primes[9600],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

void sieve(){
    memset(isprime,1,sizeof(isprime));
    int n=sqrt(mx)+1;
    isprime[0]=isprime[1]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i])
            for(int j=i*i;j<=mx;j+=i)
                isprime[j]=0;        
    }
    for(int i=2;i<=mx;i++) if(isprime[i]) primes[primeno++]=i; 
}

int main(){
    sieve();
    ll ind,mxr=1e6,mxc;
    cin>>n>>m;
    ll arr[n][m],tmp,r[n]{},c[m]{};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            ind = lower_bound(primes,primes+primeno,arr[i][j])-primes;
            tmp=primes[ind]-arr[i][j];
            r[i]+=tmp;
            c[j]+=tmp;
        }
        mxr=min(mxr,r[i]);
    }
    mxc = *min_element(c,c+m);
    cout<<min(mxr,mxc)<<"\n";
}