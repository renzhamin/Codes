#include <bits/stdc++.h>
#define MX 1000000
using namespace std;
//
struct Vector{
    int arr[MX],size=0;

    void pushback(int value){
        arr[size++] = value;
    }

    void insert(int index,int value){
        for(int i=size;i>index;i--){
            arr[i] = arr[i-1];
        }
        size++;
        arr[index] = value;
    }
    
    void erase(int index){
        for(int i=index;i<size-1;i++){
            arr[i] = arr[i+1];
        }
        size--;
    }

    void popback(){
        size--;
    }

};

int main(){
    Vector v;
    for(int i=0;i<5;i++) v.pushback(i);
    // 1,2,3,4
    v.popback();

    for(int i=0;i<v.size;i++){
        cout<<v.arr[i]<<" "; // 1,2,3
    }
    cout<<'\n';

    v.insert(0,100);
    for(int i=0;i<v.size;i++){
        cout<<v.arr[i]<<" "; //100,1,2,3
    }
    cout<<'\n';
    v.erase(0);
    for(int i=0;i<v.size;i++){
        cout<<v.arr[i]<<" "; //1,2,3
    }
}


void vectorfunctions(){
    vector <int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    // 1,2,3,4
    arr.pop_back();
    // 1,2,3
    arr.erase(arr.begin()+2);
    // 1,2
    arr.insert(arr.begin()+1, 100);
    // 1,100,2
    for(auto it=arr.begin();it!=arr.end();it++){
        cout<<*it<<"\n";
    }
}
