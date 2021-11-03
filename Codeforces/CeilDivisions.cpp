#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int N,y;
void solve(int n,vector<pair<int,int>>&ans){
    if(n==2) return;
    N=ceil(sqrt((double)n));
    for(int i=N+1;i<n;i++) ans.emplace_back(i,i+1);
    ans.emplace_back(n,N);
    ans.emplace_back(n,N);
    solve(N,ans);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>>ans;
        solve(n,ans);
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
}
