// UVA 10226

#include <bits/stdc++.h>
using namespace std;
const int alph=53;
struct trie{
	trie* next[alph];
	bool end;
	int occ;
	trie(){
		for(int i=0;i<alph;i++) next[i]=0;
		end=0;
		occ=0;
	}
} *root;



int getid(char c){
	switch(c){
		case ' ': return 26;
		case 'A' ... 'Z': return (c-'A');
		case 'a' ... 'z': return (c-'a'+27);
	}
    return -1;
}
char revid(int i){
	switch(i){
		case 26 : return ' ';
		case 0 ... 25 : return (i+'A');
		case 27 ... 52 : return (i-27+'a');
	}
    return ' ';
}

void insert(string &s){
	trie *cur=root;
	int id,n=s.length();
	for(int i=0;i<n;i++){
		id=getid(s[i]);
		if(!cur->next[id])
			cur->next[id]=new trie();
		cur=cur->next[id];
	}
	cur->occ++;
	cur->end=1;
}

double total;

void print(trie* ff,string s="",int l=0){
	trie *cur=ff;
	if(cur->end==1){
		cout<<setprecision(4)<<fixed<<s<<" "<<
			(double)((cur->occ)*100.0000)/total<<"\n";
	}
	for(int i=0;i<alph;i++){
		if(cur->next[i]){
// 			s.erase(l);
// 			s+=(revid(i));
			print(cur->next[i],s+revid(i),l+1);
		}
	}

}


void deltrie(trie* cur){
	for(int i=0;i<alph;i++)
		if(cur->next[i])
			deltrie(cur->next[i]);
	delete(cur);
}


int main(){
	int t,T=1;cin>>t;
	string tmp; 
	while(t--){
		total=0;
		if(T)getchar();T=0;
		root = new trie();
		while(getline(cin,tmp)){
			if(tmp=="") break;
			total++;
			insert(tmp);
		}	
		print(root);
		deltrie(root);	
		if(t)cout<<"\n";
	}
}
