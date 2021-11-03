#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int pr[4],pc[4];
bool vis[20][20];
int dist[20][20];
int dx[]={-1,1,0,0},
	dy[]={0,0,1,-1};
int r,c;

bool valid(int i,int j,char x){
	if(i<0 || i>=r || j<0 || j>=c) return 0;
	if(x=='#' || x=='m' || vis[i][j]) return 0;
	return 1;
}

void bfs(string *s){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			vis[i][j]=0;		
			dist[i][j]=100;
		}
	}
	int x,y,px,py;
	queue<pair<int,int>>q;
	vis[pr[3]][pc[3]]=1;
	dist[pr[3]][pc[3]]=0;
	q.push({pr[3],pc[3]});
	while(!q.empty()){
		px=q.front().first,py=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			x=px+dy[i],y=py+dx[i];
			if(valid(x,y,s[x][y])){
				vis[x][y]=1;
				q.push({x,y});
				dist[x][y]=dist[px][py]+1;
			}
		}
	}
}

int main(){
	//freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		cin>>r>>c;
		string s[r];
		size_t f;
		for(int i=0;i<r;i++) cin>>s[i];
		for(int i=0;i<r;++i){
			for(int j=0;j<s[i].length();++j){
				if(s[i][j]=='a' || s[i][j]=='b' || s[i][j]=='c')
					pr[s[i][j]-'a']=i,pc[s[i][j]-'a']=j;
				if(s[i][j]=='h')
					pr[3]=i,pc[3]=j;
			}
		}
		bfs(s);
		cout<<"Case "<<T++<<": ";
		cout<<max(dist[pr[0]][pc[0]],
			max(dist[pr[1]][pc[1]],dist[pr[2]][pc[2]]))<<"\n";
	}
}