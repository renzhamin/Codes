#include <stdio.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int bubblesort(int *start,int *end){
    int swaped=0; 
    for(int *i=start;i<end;i++){
        for(int *j=i+1;j<end;j++){
            if(*i>*j){
                swap(i,j);
                swaped++;
            }
        }
    }
    return swaped;
}



int n,k;

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
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,arr+n);
    int found=binarysearch(arr);
    printf("%s\n",(found?"Found":"Not Found"));
}