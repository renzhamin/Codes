#include <iostream>
#define done(x) {cout<<x<<"\n";continue;} 
#define ll long long 
using namespace std;

string s[3];
int ix,io;


void id2(char x){
	bool yes = (s[1][1]==x && s[0][2]==x && s[2][0]==x);
	if(yes && x=='X') ix++;
	if(yes && x=='O') io++;
}

void id1(char x){
	bool yes = (s[1][1]==x && s[0][0]==x && s[2][2]==x);
	if(yes && x=='X') ix++;
	if(yes && x=='O') io++;
}

void iv(int l){	
	char x=s[0][l];
	bool yes = (s[1][l]==x && s[2][l]==x && s[0][l]);
	if(yes && x=='X') ix++;
	if(yes && x=='O') io++;
}

void ih(int l){
	char x=s[l][0];
	bool yes = (s[l][1]==x && s[l][2]==x && s[l][0]);
	if(yes && x=='X') ix++;
	if(yes && x=='O') io++;
}


int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,r=3,X,O;cin>>t;
	while(t--){
		ix=io=X=O=0;
		for(int i=0;i<r;i++) cin>>s[i];
		for(int i=0;i<r;i++){
			for(int j=0;j<r;j++){
				if(s[i][j]=='X') X++;
				else if(s[i][j]=='O') O++;
			}
		}
		for(int i=0;i<r;i++) ih(i),iv(i);
		id2('X'),id2('O');
		id1('X'),id1('O');

		if((io>0 && ix>0) || O>X || O>=5 || X>5 || io>1 || (X-O)>1)
			done("no")
		if((ix && X-O!=1) || (io && X!=O))
			done("no")
		cout<<"yes"<<"\n";
	}
}