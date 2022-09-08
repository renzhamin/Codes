#include <iostream>
#include <map>
using namespace std;
map<string,string>node;
map<string,int>s;

string root(string s){
	if(s==node[s])
		return s;
	return node[s]=root(node[s]);
}


void Union(string a,string b){
	string x=root(a),y=root(b);
	if(x!=y){
		if(s[x]>s[y]){
			node[y]=x,s[x]+=s[y];
		} else {
			node[x]=y,s[y]+=s[x];
		}
	}
	cout<<max(s[x],s[y])<<"\n";
}

int main(){
	//freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string tmp1,tmp2;int t,n;cin>>t;
	while(t--){
		node.clear(),s.clear();
		cin>>n;
		while(n--){
			cin>>tmp1>>tmp2;
			if(!s[tmp1]) node[tmp1]=tmp1,s[tmp1]=1;
			if(!s[tmp2]) node[tmp2]=tmp2,s[tmp2]=1;
			Union(tmp1,tmp2);
		}
	}
}


/*
1
4
Lucy Patty
Patty Alice
Alice Mira
Tiffany Jayden 
*/