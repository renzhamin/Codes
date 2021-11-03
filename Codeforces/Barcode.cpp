#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n,col,x,y;
int mem[100000],hashes[100000];
string s[10000];

int paint(int r,char now,int len){
	if(r>=col) return 0;
	if(len>y) return 0;
	if(len<x) {
		if(now=='#')
			goto Hash;
		else if(now=='.')
			goto Dot;
	}
	
	int c=hashes[r];
	int dot=1000000,hash=1000000;
	
	Dot:{
		dot=c+paint(r+1,'.',now=='.'||r==0?len+1:1);
	}
	Hash:{
		hash=n-c+paint(r+1,'#',now=='#'||r==0?len+1:1);
	}
	Zero:{
		if(r) goto done;
		dot=min(dot,c+paint(r+1,'#',1));
		hash=min(hash,n-c+paint(r+1,'.',1));
	}
	done:
	 return min(dot,hash);
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	memset(mem,-1,sizeof(mem));
	cin>>n>>col>>x>>y;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<col;i++){
	 	for(int j=0;j<n;j++){
	 		if(s[j][i]=='#')
	 			hashes[i]++;
	 	}
	 } 
	cout<<paint(0,'F',1)<<"\n";
}