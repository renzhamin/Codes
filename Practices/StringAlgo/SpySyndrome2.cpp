#include <bits/stdc++.h>
using namespace std;
const int alph=52;

struct Trie{
	Trie* next[alph];
	bool end;
	Trie(){
		for(int i=0;i<alph;i++) next[i]=0;
		end = 0;
	}
}*root;

int getid(char c){
    if(isupper(c)) return c-'A'+26;
    return c-'a';
}

void insert(string &s){
	Trie *cur=root;
	int id,n=s.length();
	for(int i=0;i<n;i++){
		id=getid(s[i]);
        if(!cur->next[id]){
            cur->next[id]=new Trie();
        }
		cur=cur->next[id];
	}
	cur->end=1;
}

int n,m;
string s;
vector<string>ans;

bool F(Trie *prev,int i,string w){
    Trie *cur1,*cur2;
    char c1=s[i],c2=s[i]^32;
    cur1 = prev->next[getid(c1)];
    cur2 = prev->next[getid(c2)];

    if(!cur1 && !cur2) return 0;
        
    bool f1=0,f2=0;

    if(i==n-1){
        if(cur1 && cur1->end){
            w += c1;
            reverse(w.begin(),w.end());
            ans.emplace_back(w);
            return 1;
        } else if(cur2 && cur2->end){
            w += c2;
            reverse(w.begin(),w.end());
            ans.emplace_back(w);
            return 1;
        } 
        else {
            return 0;
        }
    }

    if(cur1 && cur1->end && (f1=F(root,i+1,""))){
        w += c1;
        reverse(w.begin(),w.end());
        ans.emplace_back(w);
    } 
    else if(cur2 && cur2->end && (f2=F(root,i+1,""))){
        w += c2;
        reverse(w.begin(),w.end());
        ans.emplace_back(w);
    } 
    else {
        if(cur1) f1=F(cur1,i+1,w+c1);
        if(!f1 && cur2) f2=F(cur2,i+1,w+c2);
    }

    return f1 || f2;
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    root = new Trie();
    string tmp;

    cin>>n>>s;
    cin>>m;

    while(m--){
        cin>>tmp;
        reverse(tmp.begin(),tmp.end());
        insert(tmp);
    }
    
    F(root,0,"");

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }

}
