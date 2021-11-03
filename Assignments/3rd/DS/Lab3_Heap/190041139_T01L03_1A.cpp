#include <bits/stdc++.h>
#define ll long long
#define errorCode INT_MIN
#define rte(x) if(x){cout<<"error"<<"\n";return errorCode;} 
using namespace std;

class linearQueue{
public:
    int *arr,len,front,back,maxSize;
    linearQueue(int n){
        arr = new int[n];
        maxSize = n;
        front=back=len=0;
    }
    int push(int x){
        rte(len==maxSize);
        arr[back++] = x;
        len++;
        return x;
    }
    int pop(){
        rte(!len);
        len--;
        return arr[back--];
    }
    int top(){
        return arr[front];
    }
    bool empty(){
        return !len;
    }
    int size(){
        return len;
    }
    int & operator [](int index){
        return arr[index];
    }
};

class circularQueue{
private:
    int *arr,len,front,back,maxSize;
public:
    circularQueue(int n){
        arr = new int[n];
        maxSize = n;
        back=-1;
        len=front=0;
    }
    int push(int x){
        rte(len==maxSize);
        back = (back+1)%maxSize;
        arr[back] = x;
        len++;
        return x;
    }
    int pop(){
        rte(!len);
        int tmp=arr[front];
        front = (front+1)%maxSize;
        len--;
        return tmp;
    }
    int top(){
        rte(!len);
        return arr[front];
    }
    int size(){
        return len;
    }
    bool empty(){
        return !len;
    }
    int & operator [](int index){
        return arr[index];
    }
};

int main(){
    int n=10;
    circularQueue q(10);
    for(int i=0;i<10;i++){
        q.push(i);
    }
    q.pop();
    q.push(2);
    cout<<q.top()<<"\n";
}
