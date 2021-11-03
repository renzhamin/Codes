#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string.h>
using namespace std;

struct Team{
	char name[35];
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
		return a.played<b.played;

	return strcasecmp(a.name,b.name)<0;	
}

void parse(char *s,unordered_map<string,Team*> &d){
	char t1[35],t2[35];
	int g1,g2;
	sscanf(s,"%[^#]#%d@%d#%[^\n]",t1,&g1,&g2,t2);
	update(d[t1],g1,g2);
	update(d[t2],g2,g1);
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	char torname[200],ctmp[200];	
	int ntor,n,m;
	scanf("%d\n",&ntor);
	while(ntor--){
		scanf("%[^\n]\n",torname);
		scanf("%d\n",&n);
		Team team[n];	
		unordered_map<string,Team*>d;

		printf("%s\n",torname);
		for(int i=0;i<n;++i){
			scanf("%[^\n]\n",team[i].name);
			d[team[i].name]=&team[i];
		
}		scanf("%d\n",&m);
		while(m--){
			scanf("%[^\n]\n",ctmp);
			parse(ctmp,d);
		}
		sort(team,team+n,order);
		for(int i=0;i<n;++i){
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
			i+1,team[i].name,team[i].point,team[i].played,
			team[i].wins,team[i].ties,team[i].looses,
			team[i].gd,team[i].scored,team[i].consumed);
		}
		if(ntor)
			printf("\n");
	}
}