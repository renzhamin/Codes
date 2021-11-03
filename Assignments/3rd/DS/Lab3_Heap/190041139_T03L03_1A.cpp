#include "Max_Heap.cpp"

class Min_Heap : public Max_Heap {
public:
    int Min_Heap_Insert(int x){
        return push(-x);
    }
    int Heap_Min(){
        return -top();
    }
    int Heap_Extract_Min(){
        return pop();
    }
    int Heap_Increase_Key(int index,int value){
        rte(index>=len);
        arr[index] = -value;
        heapify(arr,index,len);
        return value;
    }
    int Heap_Decrease_Key(int i,int value){
        rte(i>=len);
        arr[i] = -value;
        while(i>0 && arr[(i-1)/2] < arr[i]){
            swap(arr[(i-1)/2],arr[i]);
            i = (i-1)/2;
        }
        return value;
    }
    int operator [](int index){
        return -arr[index];
    }
};

int main(){
    Min_Heap x(10);    
    int n = 5;
    for(int i=0;i<n;i++){
        x.Min_Heap_Insert(i);
    } 
//     x.Heap_Decrease_Key(4,-1);
//     x.Heap_Increase_Key(0,10);
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    } 
}
