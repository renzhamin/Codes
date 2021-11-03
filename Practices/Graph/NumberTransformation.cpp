#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=(int)1e3+10;
bool isprime[mx+1]; 
int primes[78600],primeno=0; //78600 for 1e6,664700 for 1e7,6303400 for 1e7+1e8

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

int A,B,px;

vector<int> factors(int n){
    if(isprime[n]) return {};
    vector<int>f;
    for(int i=0;primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            f.emplace_back(primes[i]);
            while(n%primes[i]==0){
                n/=primes[i];
            }
        }
    }
    if(n>1) f.emplace_back(n);
    return f;
}

int bfs(){
    if(A==B) return 0;
    queue<int>q;
    bool vis[10001]{};
    int d[10001]{};
    q.push(A); vis[A]=1;
    while(!q.empty()){
        px=q.front();q.pop();
        auto f=factors(px);
        for(auto x:f){
            if(x+px>B || vis[x+px]) continue;
            vis[x+px]=1;
            d[x+px]=d[px]+1;
            if(x+px==B) return d[x+px];
            q.push(x+px);
        } 
    }
    return -1;
}


int main(){
    sieve();
    int t,T=1;cin>>t;
    while(t--){
        cin>>A>>B;
        cout<<"Case "<<T++<<": ";
        cout<<bfs()<<"\n";
    }
}
