#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	if(m>n) {cout<<n;return 0;}
	int i,s=n/m;
	for(i=n+1;s>0;i++){
		s--;
		if(i%m==0) s++;
	}
	cout<<i-1;
}