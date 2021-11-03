#include "bubbleSort.c"

int main(){
    int n;
    scanf("%d",&n);
    int arr[n],ind[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        ind[i]=i;
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
                swap(&ind[i],&ind[j]);
            }
        }
    }

    for(int i=0;i<n;++i){
        printf("%d ",ind[i]);
    }

}

