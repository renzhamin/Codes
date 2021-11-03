#include <stdio.h>
#include <math.h>
#define ll long long
// #define findn(s) (-1+sqrt(1+24*s))/6
#define cardsneeded(n) n*(n+1) + (n*(n-1))/2


ll findn(ll cards){
    ll lo=0,hi=1e5,mid,ans=0,tmp;
    while(lo<=hi){
        mid=(lo+hi)>>1LL;
        if(cardsneeded(mid)<=cards)
            lo=mid+1,ans=mid;
        else
            hi=mid-1;
    }
    return ans;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll cards; scanf("%lld",&cards);
        ll n=findn(cards),ans=0;
        while(n>0){
            ans++;
            cards-=cardsneeded(n);
            n=findn(cards);
        }
        printf("%lld\n",ans );
    }
}