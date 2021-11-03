#include <stdio.h>


int n,k,firstoccur=-1,lastoccur;
int lo,hi,mid;

void binarysearch(int *arr,int &occur,int finding_first){
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(arr[mid]>k)
            hi=mid-1;
        else if(arr[mid]<k)
            lo=mid+1;
        else {
            occur=mid;
            if(finding_first)
                hi=mid-1;
            else
                lo=mid+1;        
        }
    }
}

int main(){
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }

    lo=0,hi=n-1;
    binarysearch(arr,firstoccur,1);

    if(firstoccur==-1){
        printf("%d is not present\n",k);
    } else {
        lo=firstoccur,hi=n-1;
        binarysearch(arr,lastoccur,0);
        printf("First occurence of element %d is at index %d\n",k,firstoccur);
        printf("Last occurence of element %d is at index %d\n",k,lastoccur);            
    }
}

