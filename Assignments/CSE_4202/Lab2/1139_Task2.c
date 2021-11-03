#include "bubbleSort.c"

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int arr[n];
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        bubblesort(arr,arr+n);
        int minsum=0,maxsum=0,k=n-m;
        for(int i=0;i<n;++i){
            if(i<k) minsum+=arr[i];
            if(n-i<=k) maxsum+=arr[i];
        }
        printf("%d\n",maxsum-minsum);
    }
}