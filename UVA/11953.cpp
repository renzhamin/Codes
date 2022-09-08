#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
bool visited[105][105];
bool valid(int i,int j,string *s){
	if(i>=n || i<0 || j>=n || j<0)
		return 0;
	if(s[i][j]=='.' || visited[i][j])
		return 0;
	return 1;
}

bool f=0;
int cnt=0;
void go(int i,int j,string *s,int l=0){
	if(!valid(i,j,s) || l>=n/2) return;
	// printf("s[%d][%d]=%c\n",i,j,s[i][j]);
	if(s[i][j]=='x') f=1;
	visited[i][j]=1;
	go(i+1,j,s,l+1);
	go(i,j+1,s,l+1);
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		cnt=f=0;
		cin>>n;
		memset(visited,0,sizeof(visited));
		string s[n];
		for(int i=0;i<n;i++) cin>>s[i];
		for(int i=0;i<n;i++,f=0){
			for(int j=0;j<n;j++,f=0){
				if(s[i][j]!='.'){
					go(i,j,s);
					if(f) cnt++;
				}
			}
		}
		cout<<"Case "<<T++<<": ";
		cout<<cnt<<"\n";
	}
}
/*
2
4
x...
..x.
@.@.
....
2
..
x.
*/