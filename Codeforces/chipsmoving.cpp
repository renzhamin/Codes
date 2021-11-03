#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	int odd=0,even=0,tmp;
	for(int i=0;i<n,cin>>tmp;i++) if(tmp&1) odd++; else even++;
	cout<<min(odd,even)<<endl;
}