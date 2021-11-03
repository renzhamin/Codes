#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void print(stack<int>st){
    int tmp;
    cout<<"Size:"<<st.size()<<" elements: ";
    if(!st.size()){
        cout<<"NULL"<<"\n";
        return;
    }
    while(st.size()){
        tmp = st.top(); st.pop();
        cout<<tmp<<" ";
    }
    cout<<"\n";
}

stack<int> getRev(stack<int>st){
    stack<int>B;
    int tmp;
    while(st.size()){
        tmp = st.top(); st.pop();
        B.push(tmp);
    }
    return B;
}

int main(){
    stack<int>A,B;
    int n,t,q,tmp;cin>>n>>t;
    while(t--){
        cin>>q;
        if(q==1){
            if(A.size()==n){
                cout<<"Size:"<<A.size()<<" elements: Overflow!";
                continue;
            }
            cin>>tmp; A.push(tmp);
            print(getRev(A));
        } else {
            B=getRev(A);
            B.pop();
            print(B);
            A=getRev(B);
        }
    }
}

/*
5
10
1 42
2
1 14
1 25
1 33
2
1 10
1 22
1 99
1 75

*/
