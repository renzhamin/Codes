#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mx=101,c=19,M=101;


ll hashit(string s){
	ll n=s.length(),hv=0;
	for(ll i=0;i<n;++i){
		hv+=((i+1)*s[i]);
	}
	return (c*hv)%M;
}

int total=0;
void insert(string s,string *table){
	ll ind=hashit(s),pos=ind;
	for(int i=0;i<mx;++i){
		if(table[i]==s)
			return;
	}
	for(int i=1;i<=20;++i){
		if(table[pos].empty()){
			table[pos]=s;
			total++;
			return;
		}
		pos=(ind+i*i+23*i)%M;
	}
}

void del(string s,string *table){
	for(int i=0;i<mx;++i){
		if(table[i]==s){
			table[i].clear();
			total--;
			return;
		}
	}
}

void print(string *table){
	cout<<total<<"\n";
	for(int i=0;i<mx;++i){
		if(!table[i].empty())
			cout<<i<<":"<<table[i]<<"\n";
	}
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		total=0;
		int n;cin>>n; 
		string table[mx];
		while(n--){
			string tmp,str; cin>>tmp;
			str=tmp.substr(4,tmp.size()-4);
			if(tmp[0]=='A')
				insert(str,table);
			else 
				del(str,table);
		}
		print(table);
	}
}
/*
1
5
ADD: 
ADD:e
DEL:e
ADD:ee
ADD:e
*/
