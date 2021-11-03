#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=2.5e6;

int trie[mx][4],len[mx];

unordered_map<char,int>mp={
    {'A',0},{'C',1},{'G',2},{'T',3}
};

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,T=1;cin>>t;
    while(t--){
        memset(trie,0,sizeof(trie));
        memset(len,0,sizeof(len));
        ll ans=-1;
        int nodeNo=0,curNode=0,n;
        string s; cin>>n;

        while(n--){
            curNode=0;
            cin>>s;
            for(int i=0;i<s.size();i++){
                if(!trie[curNode][mp[s[i]]])
                    trie[curNode][mp[s[i]]]=++nodeNo;
               
                curNode = trie[curNode][mp[s[i]]];
                len[curNode]++;
                ans = max(ans,len[curNode]*(i+1LL));
            }
        }

        cout<<"Case "<<T++<<": ";
        cout<<ans<<"\n";
    }
}
