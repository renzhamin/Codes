#include "Max_Heap.cpp"

void build_max_heap(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
}

void heapSort(int *arr,int n){
    build_max_heap(arr,n);
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}



int main(){
    int arr[]={4,3,5,2,1,6};
    int n=sizeof(arr)/sizeof(int);
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
