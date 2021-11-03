#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n;

void p(int cur){
    if(cur>n) return;
    cout<<cur<<" ";
    p(cur+2);
}

int main(){
    cin>>n;
    p(0);
}