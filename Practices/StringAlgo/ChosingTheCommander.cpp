#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxBits 27

struct Trie{
	Trie* next[2];
	int len;
	Trie(){
		for(int i=0;i<2;i++) next[i]=0;
		len=0;
	}
} *root;

void insert(ll num){
    string s=bitset<maxBits>(num).to_string();
	Trie *cur=root;
	int id;
	for(int i=0;i<maxBits;i++){
		id=s[i]-'0';
		if(!cur->next[id])
			cur->next[id]=new Trie();
		cur=cur->next[id];
        cur->len++;
	}
}

void delTrie(Trie* cur){
	for(int i=0;i<2;i++)
		if(cur->next[i])
			delTrie(cur->next[i]);
	delete cur;
}

void erase(ll num){
    string s=bitset<maxBits>(num).to_string();
    Trie *cur=root,*last=root;
    for(int i=0;i<maxBits;i++){
        cur=last->next[s[i]-'0'];
        if(!cur) return;
        cur->len--;
        if(!cur->len){
            last->next[s[i]-'0']=NULL;
            delTrie(cur);
            break;
        }
        last=cur;
    }
}

ll noOfFollowers(ll personality,ll leadership){
    string ps=bitset<maxBits>(personality).to_string();
    string ls=bitset<maxBits>(leadership).to_string();
    Trie *cur=root;
    ll n=maxBits;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(!cur) break;
        int p = ps[i]-'0';
        int l = ls[i]-'0';
        if(l==0){
            cur = cur->next[p];
        } else {
            if(cur->next[p])
                ans += cur->next[p]->len;
            cur = cur->next[p^1];
        }
    } 
    return ans;
}

int main(){
    root = new Trie();
    int c,t;
    cin>>t;
    while(t--){
        ll personality,leadership;
        cin>>c>>personality;

        if(c==1){
            insert(personality);
        } else if(c==2){
            erase(personality);
        } else {
            cin>>leadership;
            cout<<noOfFollowers(personality,leadership)<<"\n";
        }
    }
}
