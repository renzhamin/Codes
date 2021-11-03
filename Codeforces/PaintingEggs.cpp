#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n;cin>>n;
    pair<int,int>arr[n];
    int ag=0,bg=0;
    for(int i=0;i<n;i++){ 
        cin>>arr[i].first>>arr[i].second;
    }
    int A=0,G=0,x,y;
    string s;
    bool f=0;
    for(int i=0;i<n;++i){
        x=arr[i].first,y=arr[i].second;
        if(y+G-A<=500)G+=y,s+='G';
        else A+=x,s+='A';
    }

    if(fabs(A-G)>500) f=1;

    cout<<(f?"-1\n":s);    

}