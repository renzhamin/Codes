#include <stdio.h>


int main(){
    int n,k,tmp,ans=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&tmp);
        if(5-tmp>=k) ans++;
    }
    ans/=3;
    printf("%d\n",ans);
}