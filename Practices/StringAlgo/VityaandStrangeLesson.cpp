#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxBits 19

struct Trie{
	Trie* next[2];
    int len;
	Trie(){
		for(int i=0;i<2;i++) next[i]=0;
		len=0;
	}
} *root;

bool flipped[maxBits];

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

int MEX(int X){
    string x=bitset<maxBits>(X).to_string();

    for(int i=0;i<maxBits;i++){
        flipped[i]^=(x[i]-'0');
    } 

    Trie *cur=root;
    int ans=0,b1,b2,b,level=0;
    
    while(level<maxBits){
        b1=b2=-1;
        if(cur->next[0])
            b1 = flipped[level]; 

        if(cur->next[1])
            b2 = !flipped[level];

        if(b1==0 || b2==0){
            b=(b1==0?0:1);

            if(cur->next[b]->len<(1<<(maxBits-level-1))){
                cur = cur->next[b]; 
            } 
            else {
                ans += (1<<(maxBits-level-1));
                if(cur->next[b^1])
                    cur = cur->next[b^1];
                else break;
            }
        } 
        else break;

        level++;
    }

    return ans;
}

unordered_set<int>st;

int main(){
    root = new Trie();
    int n,m,tmp; cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(st.find(tmp)==st.end()){
            insert(tmp);
            st.emplace(tmp);
        }
    }
    while(m--){
        cin>>tmp;
        cout<<MEX(tmp)<<"\n";
    }
}
