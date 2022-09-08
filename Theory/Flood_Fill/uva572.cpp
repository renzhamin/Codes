#include <iostream>
#include <string.h>
using namespace std;

int r,c,cnt;
bool visited[101][101];

int x[8]={0,0, 1,1,1,-1,-1,-1},
	y[8]={1,-1,0,1,-1,0,1,-1};


bool valid(int i,int j,char s){
	if(i==r || i<0 || j==c || j<0 || s=='*' || visited[i][j])
		return 0;
	return 1;
}

void flood(int i,int j,string s[]){
	
	if(!valid(i,j,s[i][j])) return; 
	
	visited[i][j]=1;

	for(int k=0;k<8;k++)
		flood(i+x[k],j+y[k],s);
}



int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	
	while(cin>>r>>c && r!=0){
		string s[r];
		memset(visited,0,sizeof(visited));
		for(int i=0;i<r;i++)
				cin>>s[i];

		cnt=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				if(valid(i,j,s[i][j])){
					flood(i,j,s);
					cnt++;
				}
		}
		cout<<cnt<<endl;
	}
}