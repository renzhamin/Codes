#include <iostream>
using namespace std;

int value(char x){
	if(x=='Q' || x=='q') return 9;
	if(x=='R' || x=='r') return 5;
	if(x=='B' || x=='b') return 3;
	if(x=='N' || x=='n') return 3;
	if(x=='P' || x=='p') return 1;
	if(x=='K' || x=='k' || x=='.') return 0;
}

bool White(char x){
	if(x>='A' && x<='Z') return 1;
	return 0;
}

int white=0,black=0;

void solve(int i,int j,string *s){
	if(i<0) return;
	
	if(White(s[i][j])) white+=value(s[i][j]);
	else black+=value(s[i][j]);
	
	if(j>0) 
		solve(i,j-1,s);
	else
		solve(i-1,7,s);
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s[8];
	for(int i=0;i<8;i++) cin>>s[i];
	solve(7,7,s);
	if(white>black)
		cout<<"White";
	else
	if(white<black)
		cout<<"Black";
	else
		cout<<"Draw";
}