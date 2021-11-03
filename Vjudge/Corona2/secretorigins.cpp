#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	long long tmp,n;
	while(t--){
		int n0=0,n1=0;
		cin>>tmp;
		n=tmp;
		while(!(1&tmp) && tmp!=0) n0++,tmp>>=1;		
		while(1&tmp && tmp!=0) n1++,tmp>>=1;
		cout<<"Case "<<T++<<": "<<
			n+(1<<n0)+(1<<(n1-1))-1<<endl;
	}
}