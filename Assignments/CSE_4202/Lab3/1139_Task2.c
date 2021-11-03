#include <stdio.h>

int n,m,k;

int binarysearch(int *arr){
    int lo=0,hi=n-1,mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(arr[mid]>k)
            hi=mid-1;
        else if(arr[mid]<k)
            lo=mid+1;
        else
            return 1;
    }
    return 0;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    
    n=n*m;
    int arr[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }

    if(binarysearch(arr)){
        printf("True\n");
    } else {
        printf("False\n");
    }
}