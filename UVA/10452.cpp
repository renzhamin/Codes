#include <iostream>
#include <cstring>
using namespace std;
int r,c,sr,sc,x,y,t;
int dx[]={0,1,-1},
	dy[]={-1,0,0};

bool visited[10][10];

bool ofb(int i,int j){
	return (i>=r || i<0 || j>=c || j<0 || visited[i][j]);
}

string path="IEHOVA#";
string com[]={"forth","right","left"};

void dfs(int i,int j,string *s,int st=0){
	visited[i][j]=1;
	if(s[i][j]=='#'){
		if(t)cout<<"\n"; 
		return;
	}
	for(int k=0;k<3;++k){
		y=i+dy[k],x=j+dx[k];
		if(ofb(y,x)) continue;
		if(path[st]==s[y][x]){
			cout<<com[k]<<" ";
			dfs(y,x,s,st+1);
		}
	}
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		cin>>r>>c;
		string s[r];
		for(int i=0;i<r;i++) cin>>s[i];
		size_t f;
		for(int i=0;i<r;i++) {
			f=s[i].find("@");
			if(f!=string::npos) sr=i,sc=f; 
		}
		dfs(sr,sc,s,0);
		 // for(auto i:co) cout<<i.first<<" "<<i.second<<"\n";
		// cout<<p<<"\n";
	}
}