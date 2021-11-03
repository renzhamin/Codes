#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct Stack {
        int cur;
        int *arr;
        Stack (int n){
            cur=0;
            arr = new int[n];
        }
        bool empty(){
            return !cur;
        }
        int size(){
            return cur;
        }
        void pop_front(){
            cur--;
        }
        void push_front(int x){
            arr[cur++] = x; 
        }
        int& operator[](int index){
            return arr[index];
        }
};



template <typename Type>
void sol(Type st){
    int t,tmp;cin>>t;
    while(t--){
        cin>>tmp;
        if(tmp==1){
            cin>>tmp;
            st.push_front(tmp);
        } else if(st.size())st.pop_front();
        cout<<"size= "<<st.size()<<" ";
        cout<<"items=";
        if(st.empty()) cout<<"NULL";
        else
            for(int i=0;i<st.size();i++)
                cout<<st[i]<<" ";
        cout<<"\n";
    }
}

int main(){
    int n;cin>>n;
    Stack st(n);
    sol(st);

//  Task1b
//  deque<int>st_b;
//  sol(st_b);
}
