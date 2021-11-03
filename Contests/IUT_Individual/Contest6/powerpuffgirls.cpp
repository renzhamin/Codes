#include <iostream>
#include <string.h>
using namespace std;
string s[20];
int r,c,visited[20][20];

bool valid(int i,int j){
	bool f=1;
	if(i>=r || i<0 || j>=c || j<0 || visited[i][j])
		f=0;
	if(f && (s[i][j]=='#' || s[i][j]=='m'))
		return 0;
	return f;
}

void home(int i,int j){
	if(!valid(i,j)) return;
	visited[i][j]=1;
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,col[3],row[3],h[2];cin>>t;
	size_t tmp;
	char g;
	while(t--){
		cin>>r>>c;
		for(int i=0;i<r;i++) cin>>s[i];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				g=s[i][j];
				if(g=='a' || g=='b' || g=='c')
					row[g-'a']=i,col[g-'a']=j;
				if(g=='h')
					h[0]=i,h[1]=j;
			}
		}
	}
}