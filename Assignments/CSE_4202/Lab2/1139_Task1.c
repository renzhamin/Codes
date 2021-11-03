#include "bubbleSort.c"

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int x;
    if(!(x=bubblesort(arr,arr+n))){
        printf("YES\n");
    } else{
        printf("NO\n");
        for(int i=0;i<n;++i){
            printf("%d ",arr[i]);
        }
    }
    printf("%d\n",x );
}