#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int alph = 26;

struct trie{
	trie* next[26];
	int visited;
	bool end;
	trie(){
		for(int i=0;i<alph;i++) next[i]=0;
		end=0;
		visited=0;
	}
} *root;

void to_lower(string &s){
    int n = s.length();
    for(int i=0;i<n;i++){
        s[i] |= 32;
    } 
}

void insert(string s){
    to_lower(s);
	trie *cur=root;
	int id,n=s.size();
	for(int i=0;i<n;i++){
		id=s[i]-'a';
		if(!cur->next[id])
			cur->next[id]=new trie();
		cur=cur->next[id];
		cur->visited++;
	}
	cur->end=1;
}

int prefixOf(string s){
    to_lower(s);
    if(!root) return 0;
	trie *cur=root;
	int id,n=s.size();
	for(int i=0;i<n;i++){
		id=s[i]-'a';
		if(!cur->next[id])
            return 0;
		cur=cur->next[id];
	}
    return cur->visited;
}


int main(){
    root = new trie();
    int n,q; cin>>n>>q;
    string tmp;
    while(n--){
        cin>>tmp;
        insert(tmp);
    }
    while(q--){
        cin>>tmp;
        cout<<prefixOf(tmp)<<"\n";
    }
}


/*

10 10
Beauty
Beast
Beautiful
Amazing
Amsterdam
Beautify
Banana
Xray
Beauty
Glorifying
A
Am
AM
Beauty
Beaut
Beast
Ing
AMS
Be
B

*/
