#include <iostream>
#include <iomanip>
using namespace std;
int n,allprob=0,prob=0,yes=0;
void go(int i,int x,string &s){
	if(i==n) {
		if(x==yes)
			prob++;
		allprob++;
		return;
	}
	if(s[i]=='+')
		go(i+1,x+1,s);
	else
	if(s[i]=='-')
		go(i+1,x-1,s);
	else{
		go(i+1,x+1,s);
		go(i+1,x-1,s);
	}
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string r,s;cin>>r>>s;
	for(auto di:r) if(i=='+') yes++; else if(i=='-') yes--;
	n=s.length();
	go(0,0,s);
	cout<<setprecision(10)<<(double)prob/(double)allprob<<endl;
}