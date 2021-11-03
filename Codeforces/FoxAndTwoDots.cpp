#include <bits/stdc++.h>
using namespace std;

string s[51];
bool visited[100][100],f;
int dx[]={0,0,1,-1},n,m,
	dy[]={1,-1,0,0},
    counter[]={1,0,3,2};


bool valid(int i,int j,char x){
	if(i<0 || j<0 || i>=n || j>=m)
		return 0;
	return s[i][j]==x;
}

void dfs(int ix,int iy,char now,int move=0){
	visited[ix][iy]=1;
	for(int i=0;i<4;++i){
		int x=ix+dx[i],y=iy+dy[i];
		if(!valid(x,y,now)) continue;
		if(visited[x][y] && i!=counter[move]){
			f=1;
			return;
		}
		if(!visited[x][y])
			dfs(x,y,now,i);
	}
}


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n&&!f;i++){
		for(int j=0;j<m&&!f;j++){
			if(!visited[i][j])
				dfs(i,j,s[i][j]);
		}
	}
	cout<<(f?"Yes\n":"No\n");	
}