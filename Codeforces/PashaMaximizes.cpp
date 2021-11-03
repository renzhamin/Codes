#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int k;
    string s,ans;
    cin>>s>>k;
    int n=s.length();
    vector<int>arr[10];
    for(int i=1;i<n;++i){
        arr[s[i]-48].emplace_back(i);        
    }  

    for(int i=9;i>=1&&k>0;--i){
        for(int j=0;j<arr[i].size()&&k>0;++j){
            int &y=arr[i][j];
            if(y==-1 || k<y) continue;
            k-=y;
            ans+=i+48;
            y=-1;
        }
    }
}