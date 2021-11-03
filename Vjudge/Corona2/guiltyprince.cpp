#include <iostream>
#include <string.h>
using namespace std;

int start,ind,n,c,cnt,visited[20][20];
string s[20];

bool valid(int i,int j){
	bool f=1;
	if(i<0 || i>=n || j<0 || j>=c || visited[i][j])
		f=0;
	if(f && s[i][j]=='#') return 0;
	return f;
}

void goDaddy(int i,int j){
	if(!valid(i,j)) return;
	visited[i][j]=1; 
	cnt++;	
			goDaddy(i+1,j); 
	goDaddy(i,j+1);
			goDaddy(i-1,j); 
	goDaddy(i,j-1);
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;;cin>>t;
	size_t tmp;
	while(t--){
		cnt=0;
		memset(visited,0,sizeof(visited));
		cin>>c>>n;
		for(int i=0;i<n;i++){ 
			cin>>s[i];
			tmp=s[i].find('@');
			if(tmp!=string::npos)
				start=tmp,ind=i;
		}
		goDaddy(ind,start);
		cout<<"Case "<<T++<<": "<<cnt<<endl;
	}
}