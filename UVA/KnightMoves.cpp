#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int c1,c2,r1,r2;
int dx[]={1,1,-1,-1,2,-2,2,-2};
int dy[]={2,-2,2,-2,1,1,-1,-1};
int dist[11][11];
bool visited[11][11];
string s;


void bfs(int j,int i){
	memset(visited,0,sizeof(visited));
	memset(dist,0,sizeof(dist));
	queue<pair<int,int>>q;
	q.push({j,i});
	visited[j][i]=1;
	while(!q.empty()){
		int px=q.front().first,py=q.front().second;
		visited[px][py]=1;
		q.pop();
		if(px==c2 && py==r2){
			cout<<"To get from "<<s[0]<<s[1]<<" to "<<s[3]<<s[4]<<" takes "<<dist[c2][r2]<<" knight moves."<<"\n";
			return;
		}
		for(int i=0;i<8;++i){
			int x=px+dx[i],y=py+dy[i];
			if(x<1 || y<1 || x>8 || y>8 || visited[x][y]) continue;
			dist[x][y]=dist[px][py]+1;
			q.push({x,y});
		}
	}	
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	while(getline(cin,s)){
		r1=s[1]-'0',r2=s[4]-'0';
		c1=s[0]-'a'+1,c2=s[3]-'a'+1;
		bfs(c1,r1);
	}
}	