#include "Max_Heap.cpp"
#define ll long long 
using namespace std;

int main(){
    int n,k,a,b;
    cin>>n>>k;
    Max_Heap q(n);
    for(int i=0;i<n;i++){
        cin>>a; q.push(-a);
    } 
    while(q.size()){
        a = q.top();
        if(-a >=k ) break;
        q.pop();
        if(q.empty()){
            a=-1; break;
        }
        b = q.top();
        q.pop();
        q.push(a+2*b);
    }
    if(a==-1)
        cout<<a<<"\n";
    else 
        cout<<n-q.size()<<"\n";
}


/*
6 7
1 2 3 9 10 12
*/
