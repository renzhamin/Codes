#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll mx = 1e6+1;

ll arr[mx];

void sol(){    
    ll tmp=1;
    int n=0;
    cin>>tmp;
    while(tmp!=-1){
        arr[n++] = tmp;
        cin>>tmp;
    }
    if(n==1){
        cout<<-1<<" ";
        return;
    }
    stack<ll>st;
    st.push(arr[n-1]);
    arr[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(st.size() && arr[i]>st.top())
            st.pop();
        tmp = arr[i];
        arr[i] = (st.empty()?-1:st.top());
        st.push(tmp);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

int main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}

/*
6

4 5 2 25 -1
13 7 6 12 -1
11 13 21 3 20 -1
12 17 1 5 0 2 2 7 18 25 20 12 5 1 2 -1
10 20 30 40 50 -1
50 40 30 20 10 -1

*/
