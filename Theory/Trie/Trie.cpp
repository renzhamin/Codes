#include <bits/stdc++.h>
using namespace std;
const int alph = 26;

struct trie{
	trie* next[alph]{};
	int visited;
	int end;
	trie(){
		end=0;
		visited=0;
	}
} *root;

#define getID(x) x-'a'
#define revID(x) (char)(x+'a')

void insert(string s){
	trie *cur=root;
	int id;
	for(int i=0;i<s.length();i++){
		id=getID(s[i]);
		if(!cur->next[id])
			cur->next[id]=new trie();
		cur=cur->next[id];
		cur->visited++;
	}
	cur->end++;
}

bool search(string s){
    int n=s.length(),id; 
    trie *cur=root;

    for(int i=0;i<n;i++){
        id = getID(s[i]);
        if(!cur->next[id])
            return 0;
        cur = cur->next[id];
    } 
    return cur->end;
}

void deltrie(trie* cur){
	for(int i=0;i<alph;i++)
		if(cur->next[i])
			deltrie(cur->next[i]);
	delete cur;
}

void showTrie(trie *cur=root,string s=""){
    if(!cur) return;
    if(cur->end)
        cout<<s<<"\n";

    for(int i=0;i<alph;i++){
        if(cur->next[i])
            showTrie(cur->next[i],s+revID(i));
    }
}


bool erase(string s){
    if(!search(s)) return 0;
    trie *cur=root,*parent;
    int i,n=s.size(),id;

    for(i=0;i<n;i++){
        id = getID(s[i]);
        parent=cur;
        cur=cur->next[id];
        cur->visited--;
        if(cur->visited==0) {
            parent->next[id] = NULL;
            break;
        };
    }
    
    if(i==n-1) 
        delete cur;
    
    if(i==n)
        cur->end--;

    i++;

    while(i<n){
        parent=cur;
        cur=cur->next[getID(s[i])];
        delete parent;
        i++;
    }

    return 1;
}

string longest_prefix(string s){
    int n = s.size();
    int id;
    trie *cur=root;
    string ans;

    for(int i=0;i<n;i++){
        id = getID(s[i]);
        if(!cur->next[id]) break;
        ans += s[i];
        cur = cur->next[id];
    } 

    return ans;
}

int main(){
    root = new trie();
    insert("abcef");
    insert("abcde");
    insert("abcf");
    cout<<longest_prefix("abcfgdsadasfsaf")<<"\n";
//     showTrie();
}
