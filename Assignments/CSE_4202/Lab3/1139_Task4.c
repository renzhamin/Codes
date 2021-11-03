#include <stdio.h>
#include <math.h>
#define ll long long
#define findn(s) (-1+sqrt(1+24*s))/6
#define cardsneeded(n) n*(n+1) + (n*(n-1))/2

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

/*
5
3 14 15 24
1000000000
*/