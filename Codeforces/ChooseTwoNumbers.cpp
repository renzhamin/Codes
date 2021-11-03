#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,tmp,max1=-1,max2=-1;cin>>n;
	for(int i=0;i<n;i++) cin>>tmp,max1=max(max1,tmp);
	cin>>n;
	for(int i=0;i<n;i++) cin>>tmp,max2=max(max2,tmp);
	cout<<max1<<" "<<max2;
}