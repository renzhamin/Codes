#include <iostream>
using namespace std;

struct trie{
	trie* next[4];
	bool end;
	int count;
	trie(){
		for(int i=0;i<4;i++) next[i]=0;
		end=0;
		count=0;
	}
} *root;


int ans=-1;

int getid(char c){
	switch(c){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
}

void insert(string s,int n){
	trie *cur=root;
	int id;
	for(int i=0;i<s.length();i++){
		id=getid(s[i]);
		if(!cur->next[id])
			cur->next[id]=new trie();
		cur=cur->next[id];
		cur->count++;
		ans=max(ans,cur->count*(i+1));
	}
	cur->end=1;
}


void deltrie(trie* cur){
	for(int i=0;i<4;i++)
		if(cur->next[i])
			deltrie(cur->next[i]);
	delete cur;
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		ans=0;
		root = new trie();
		int n;cin>>n;
		while(n--){
			string tmp;cin>>tmp;
			insert(tmp,tmp.length());
		}
		cout<<"Case "<<T++<<": ";
		cout<<ans<<endl;
		deltrie(root);	
	}
}