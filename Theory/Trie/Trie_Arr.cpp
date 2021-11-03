#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e2;
const int alph=26;

struct TrieNode{
    int next[alph]={};
    int len=0;
    bool end=0;
}T[mx];

int getID(char x){
    return x-'a';
}

queue<int>vaccant;

class TriePointer{
    static int nodeNo;
public:
    int id;
    TrieNode *trie;
    TriePointer(TrieNode* NodeArray,int x=0){
        trie = NodeArray;
        id = x;
    }

    int& nextId(int ind){
        return trie[id].next[ind];
    }

    TriePointer next(int ind){
        return TriePointer(trie,nextId(ind));
    }
    
    int create(int ind){
        int &c = nextId(ind);
        if(!c){
            if(vaccant.size()){
                c = vaccant.front();
                vaccant.pop();
            } else c = ++nodeNo;
        }
        return c;
    }

    void move(int ind){
        id = nextId(ind);
    }

    TrieNode& node(){
        return trie[id];
    }

    operator bool(){
        return id!=0;
    }

} root(T,0);

int TriePointer::nodeNo=0;

void insert(string s){
    int n=s.size();
    TriePointer cur=root; cur.node().len++;
    for(int i=0;i<n;i++){
        int id=getID(s[i]);
        if(!cur.next(id)){
            cur.create(id);
        }
        cur.move(id);
        cur.node().len++;
    }
    cur.node().end=1;
}


bool erase(string s,TriePointer cur=root,int i=0){
    
    if(i==s.size()){
        if(cur.node().end){
            cur.node().len--;
            if(cur.node().len==0){
                cur.node().end = 0;
            }
            return 1;
        }
        return 0;
    }

    int id=getID(s[i]);

    if(cur.next(id) && erase(s,cur.next(id),i+1)){
        cur.node().len--;
        if(cur.next(id).node().len==0){
            vaccant.push(cur.node().next[id]);
            cur.node().next[id] = 0;
        }
        return 1;
    }
    
    return 0;
}

void showTrie(TriePointer cur,string w=""){
    if(cur.node().end){
        cout<<w<<"\n";
    }

    for(int i=0;i<alph;i++){
        if(!cur.next(i)) continue;
        showTrie(cur.next(i),w+(char)(i+'a'));
    }
}

int main(){
    insert("abc");
    insert("abd");
    erase("abd");
    insert("abe");
    showTrie(root);
}
