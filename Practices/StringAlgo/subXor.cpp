#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxBits 20

struct Trie{
	Trie* next[2];
	int len;
	Trie(){
		for(int i=0;i<2;i++) next[i]=0;
		len=0;
	}
}*root;


ll ans=0,n,K,x,preXor;

void insert(ll num){
    string s=bitset<maxBits>(num).to_string();
    string k=bitset<maxBits>(K).to_string();
	Trie *cur=root,*xcur=root;

	for(int i=0;i<maxBits;i++){
        int pre = s[i]-'0';
        int kn = k[i]-'0';

        if(xcur){
            if(kn==0){
                xcur = xcur->next[pre];
            } else {
                if(xcur->next[pre])
                    ans += xcur->next[pre]->len;
                xcur = xcur->next[pre^1];
            }
        }

		if(!cur->next[pre])
			cur->next[pre]=new Trie();
		cur=cur->next[pre];
        cur->len++;
	}
}

void delTrie(Trie *cur){
    for(int i=0;i<2;i++){
        if(cur->next[i])
            delTrie(cur->next[i]);
    }
    delete cur;
}


int main(){
    int t; cin>>t;
    while(t--){
        root = new Trie();
        ans = preXor = 0;
        insert(0); 

        cin>>n>>K;

        for(int i=0;i<n;i++){
            cin>>x;
            preXor^=x;
            insert(preXor);
        } 

        cout<<ans<<"\n";

        delTrie(root);
    }
}
