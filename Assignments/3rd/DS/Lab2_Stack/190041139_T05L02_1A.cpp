#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int arr[1001];

int main(){
    int n;
    while(cin>>n && n){
        for(int i=0;i<n;i++) cin>>arr[i];
        stack<int>st;
        int cur=1;
        for(int i=0;i<n;i++){
            while(st.size() && st.top()==cur){
                cur++;
                st.pop();
            }
            st.push(arr[i]);
        } 
        while(st.size()){
            if(st.top()!=cur) break;
            st.pop();
            cur++;
        }
        cout<<(st.empty()?"yes\n":"no\n");	    
    }
}


/*

5
5 1 2 4 3
5
5 4 3 2 1
5
1 2 4 3 5
5
1 2 5 3 4

*/

