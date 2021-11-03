#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define MX 1000000

struct Set{
    int size=0;
    int arr[MX];
    void insert(int value){
        for(int i=0;i<size;++i){
            if(arr[i]==value) return;
        }
        arr[size++]=value;
        sort(arr,arr+size);
    }
    bool count(int value){
        return binary_search(arr,arr+size,value);
    }
};


int main(){
    Set st;
    st.insert(2),st.insert(3),st.insert(-3);
    //printing the elements
    for(int i=0;i<st.size;i++)
        cout<<st.arr[i]<<"\n"; // print -3,2,3
    cout<<st.count(5)<<"\n"; // return 0
    cout<<st.count(2)<<"\n"; // return 1
}




void setfunctions(){
    set<int>st;
    //Insert Operations
    st.insert(1); st.insert(2);
    int c1=st.count(1);// will return 1
    int c2=st.count(2);// will return 0
    for(auto i=st.begin();i!=st.end();i++)
        cout<<*i<<"\n";
}
