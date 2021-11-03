#include <iostream>
#include <string.h>
using namespace std;

struct Team{
	int id;
	Team *next;
	Team(int n){
		id=n;
		next=0;
	}
};

void enque(Team **team,Team *&root,Team *&end,int *teamno){
	int n;cin>>n;
	Team *tmp=new Team(n),*node;
	int no=teamno[n];
	if(team[no]){
		node=team[no];
		tmp->next=node->next;
		if(!tmp->next) end=tmp;
		node->next=tmp;
	} else {
		if(root){
			end->next=tmp;
			end=tmp;
		} else {
			root=end=tmp; //
		}
	}
	team[no]=tmp;
}

void deque(Team *team[],Team *&root,Team *&end,int *teamno){
	cout<<root->id<<endl;
	int no=teamno[root->id];
	if(team[no]==root) team[no]=0;
	Team *node=root;
	root=root->next;
	delete(node);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long nt,np,temp,T=1; string com;
	int teamno[(int)1e6];
	while(cin>>nt &&nt){
		cout<<"Scenario #"<<T++<<"\n";
		memset(teamno,0,sizeof(teamno));
		Team *team[nt],*root=0,*end=0,*node;
		for(int t=0;t<nt;t++){
			cin>>np;
			while(np--){
				cin>>temp;
				teamno[temp]=t;
			}
			team[t]=0;
		}
		while(cin>>com && com!="STOP"){
			if(com[0]=='E')
				enque(team,root,end,teamno);
			else{
				deque(team,root,end,teamno);
			}
		}
		cout<<"\n";
	}
}