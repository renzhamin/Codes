#include <iostream>
using namespace std;

struct trie{
	trie* next[10];
	bool end;
	trie(){
		for(int i=0;i<10;i++) next[i]=0;
		end=0;
	}
} *root;

bool isprefix(trie* cur){
	for(int i=0;i<10;i++){
		if(cur->next[i]!=NULL)
			return 1;
	}
	return 0;
}
bool f=1;
void insert(string s,int n){
	trie *cur=root;
	if(f){	
		int id;
		for(int i=0;i<s.length();i++){
			id=s[i]-48;
			if(!cur->next[id])
				cur->next[id]=new trie();
			cur=cur->next[id];
			if(cur->end) f=0;
		}
		cur->end=1;
		if(isprefix(cur)){
			f=0;
		}
	}
}



void search(trie* ff,string s){
	trie *cur=ff;
	
	if(cur->end==1 && f)
		if(isprefix(cur)){
			cout<<"NO"<<endl;
			f=0;
			return;
		}
	for(int i=0;i<10;i++){
		if(cur->next[i]!=NULL){
			s+=(i+48);
			search(cur->next[i],s);
			s.clear();
		}
	}

}

void deltrie(trie* cur){
	for(int i=0;i<10;i++)
		if(cur->next[i])
			deltrie(cur->next[i]);
	delete cur;
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		f=1;
		root = new trie();
		int n;cin>>n;
		while(n--){
			string tmp;cin>>tmp;
			insert(tmp,tmp.length());
		}
		cout<<"Case "<<T++<<": ";
		if(f)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		deltrie(root);	
	}
}