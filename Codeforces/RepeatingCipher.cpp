#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int i=1,csum[56];csum[0]=0;
	for(int i=1;i<=55;i++) csum[i]=(csum[i-1]+i);
	int n,ind;cin>>n;
	string s;cin>>s;
	for(int i=0;csum[i]+1<=n;i++)
		cout<<s[csum[i]];
	
}