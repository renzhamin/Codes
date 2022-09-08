#include <iostream>
#include <map>
using namespace std;


map<int,int>nsize;
map<int,int>nodes;
int cnt=0;

int root(int x){
	if(x==nodes[x])
		return x;
	return nodes[x]=root(nodes[x]);
	//while traveling back set parent to x for each of the nodes in the path
}

void mu(int x,int y){
	if(nsize[x]>nsize[y])
		nodes[y]=x,nsize[x]+=nsize[y];
	else
		nodes[x]=y;nsize[y]+=nsize[x];
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,m,c1,c2,x,y;
	cin>>n>>m;
	cnt=n;	
	for(int i=0;i<m;i++){
		cin>>c1>>c2;
		if(!nodes[c1]) nodes[c1]=c1,nsize[c1]=1;
		if(!nodes[c2]) nodes[c2]=c2,nsize[c2]=1;
		x=root(c1),y=root(c2);
		if(x!=y){   // if x==y than cnt is already decremented for that node
			mu(x,y);
			cnt--;
		}		
	} 
	cout<<cnt<<"\n";
}
/*
9 5
1 3
6 1
7 6
2 7
8 9*/