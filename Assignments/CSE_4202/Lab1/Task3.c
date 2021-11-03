#include <stdio.h>

int freq[(int)1e6+1];

int main(){
    int n,num,mx=-1e6,ans=1e7;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num); 
        freq[num]++;
        if(freq[num]==mx && num>ans) continue;
        if(freq[num]>=mx){
            mx=freq[num];
            ans=num;            
        }
    } 
    printf("%d\n",ans );
}