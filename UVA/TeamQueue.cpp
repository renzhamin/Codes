#include <iostream>
#include <queue>
using namespace std;
int inteam[999999+2];
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,tmp,nt,T=1;string com;
	while(cin>>nt && nt){
		cout<<"Scenario #"<<T++<<"\n";
		queue<int>playerline[nt],teamline;
		for(int i=0;i<nt;++i){
			cin>>n;
			while(n--){
				cin>>tmp;
				inteam[tmp]=i;
			}
		}
		while(cin>>com && com[0]!='S'){
			if(com[0]=='E'){
				cin>>tmp;
				nt=inteam[tmp];
				if(playerline[nt].empty())
					teamline.push(nt);
				playerline[nt].push(tmp);
			} 
			else {
				nt=teamline.front();
				cout<<playerline[nt].front()<<"\n";
				playerline[nt].pop();
				if(playerline[nt].empty()) teamline.pop();
			}
		}
		cout<<"\n";
	}
}