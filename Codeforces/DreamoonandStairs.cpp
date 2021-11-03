#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
	int n,m,x,s;
	cin>>n>>m;
	x=n/2;
	while(x>=0){
		s=x+(n-x*2);	
		if(s%m==0) break;
		else x--;
	}
	cout<<(x>=0?s:x);
}