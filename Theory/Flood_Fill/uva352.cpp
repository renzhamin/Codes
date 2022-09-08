#include <iostream>
#include <string.h>
using namespace std;

int r,c,cnt;
bool visited[101][101];
bool valid(int i,int j,char s){
	if(i==r || i<0 || j==c || j<0 || s=='0' || visited[i][j])
		return 0;
	return 1;
}

void flood(int i,int j,string s[]){
	
	if(!valid(i,j,s[i][j])) return; 
	
	visited[i][j]=1;

		flood(i,j+1,s);	flood(i-1,j-1,s);
		flood(i,j-1,s); flood(i+1,j-1,s);
		flood(i+1,j,s); flood(i+1,j+1,s);
		flood(i-1,j,s); flood(i-1,j+1,s);
}



int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t=1;
	while(cin>>r){
		string s[r];
		memset(visited,0,sizeof(visited));
		for(int i=0;i<r;i++)
				cin>>s[i];

		cnt=0;
		for(int i=0;i<r;i++){
			c=s[i].length();
			for(int j=0;j<c;j++)
				if(valid(i,j,s[i][j])){
					flood(i,j,s);
					cnt++;
				}
		}
		cout<<"Image number "<<t++<<" contains "<<cnt<<" war eagles."<<endl;
	}
}