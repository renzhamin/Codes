#include <bits/stdc++.h>
#define ll long long 
#define M 100003
using namespace std;

vector<pair<string,string>>table[M];


int hashit(string s){
	int n=s.length(),ind=0;
	for(int i=0;i<n;++i){
		int id=(s[i]-'0')*(i+1);
		ind+=id;
		ind%=M;
	}	
	return ind;
}

void insert(string s,string roll){
	int n=s.length();
	int ind=hashit(roll);
	table[ind].push_back({s,roll});
}

string search(string roll){
	int ind=hashit(roll);
	string ans;
	for(auto i:table[ind]){
		if(i.second==roll)
			return i.first;
	}

}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	while(n--) {string r,tmp;cin>>r>>tmp;insert(tmp,r);}
	cin>>n;
	while(n--){string r;cin>>r;cout<<search(r)<<"\n";}
}