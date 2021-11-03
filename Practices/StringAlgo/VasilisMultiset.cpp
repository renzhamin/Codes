#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxBits 30

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

ll calXor(ll num){
    string s=bitset<30>(num).to_string();
    Trie *cur=root;
    ll n=maxBits;
    ll ans=0;
    for(int i=0;i<n;i++){
        int a = s[i]-'0';
        int b = a^1;
        if(cur->next[b]){
            cur=cur->next[b];
            ans += 1LL<<(n-i-1);
        } else {
            cur=cur->next[a];
        } 
    } 
    return ans;
}

int main(){
    root = new Trie();
    insert(0);
    char c;
    int t;
    scanf("%d\n",&t);
    while(t--){
        ll num;
        scanf("%c %lld\n",&c,&num);

        if(c=='+'){
            if(num==0) continue;
            insert(num);
        } else if(c=='-'){
            if(num==0) continue;
            erase(num);
        } else {
            printf("%lld\n",calXor(num));
        }
    }
}
