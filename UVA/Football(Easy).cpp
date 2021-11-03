#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Team{
	string name;
	int point,played,wins,ties,looses,gd,scored,consumed;
	Team(){
		point=played=wins=ties=looses=gd=scored=consumed=0;	
	}
};

void update(Team *team,int s,int c){
	team->scored+=s;
	team->consumed+=c;
	team->played++;
	team->gd+=(s-c);
	if(s==c) team->point++,team->ties++;
	else if(s>c) team->point+=3,team->wins++;
	else team->looses++;

}

void parse(string s,unordered_map<string,Team*> &d){
	int i,j,n=s.length();
	string s1,s2,g1,g2;
	
	for(i=0;s[i]!='#';++i) s1+=s[i]; 
	
	if(s[i+3]=='@') g1+=s[i+1],g1+=s[i+2],i+=3;
	else g1+=s[i+1],i+=2;
	
	if(s[i+3]=='#') g2+=s[i+1],g2+=s[i+2],i+=4;
	else g2+=s[i+1],i+=3;
	
	for(;i<n;i++) s2+=s[i];
	
	int sc1=stoi(g1),sc2=stoi(g2);
	update(d[s1],sc1,sc2);
	update(d[s2],sc2,sc1);
}

void tolower(string &s){
	int n=s.length();
	for(int i=0;i<n;i++) {
		if(s[i]>='A' && s[i]<='Z')
			s[i]=s[i]-'A'+'a';
	}
}

bool order(Team a,Team b){
	if(a.point!=b.point)
		return a.point>b.point;
	
	if(a.wins!=b.wins)
		return a.wins>b.wins;

	if(a.gd!=b.gd)
		return a.gd>b.gd;

	if(a.scored!=b.scored)
		return a.scored>b.scored;

	if(a.played!=b.played)
		return a.played < b.played;

	string tmp1=a.name,tmp2=b.name;
	tolower(tmp1),tolower(tmp2);	

	return tmp1 < tmp2;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string tmp,torname;	
	int ntor,n,m;
	cin>>ntor; getchar();
	while(ntor--){
		getline(cin,torname);
		cin>>n;getchar();
		Team team[n];	
		unordered_map<string,Team*>d;
		for(int i=0;i<n;++i){
			getline(cin,tmp);
			d[tmp]=&team[i];
			team[i].name=tmp;
		}
		cin>>m; getchar();
		while(m--){
			getline(cin,tmp);
			parse(tmp,d);
		}
		sort(team,team+n,order);
		cout<<torname<<"\n";
		for(int i=0;i<n;++i){
			cout<<i+1<<") "<<team[i].name<<" "<<
			team[i].point<<"p, "<<team[i].played<<
			"g ("<<team[i].wins<<"-"<<team[i].ties<<"-"<<
			team[i].looses<<"), "<<team[i].gd<<"gd ("<<
			team[i].scored<<"-"<<team[i].consumed<<")\n";
		}
		if(ntor)cout<<"\n";
	}
}