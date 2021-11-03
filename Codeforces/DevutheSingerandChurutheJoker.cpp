#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,t,sum=0,tmp; cin>>n>>t;
	for(int i=0;i<n;i++) cin>>tmp,sum+=tmp;

	if((n-1)*10+sum>t){ cout<<-1<<endl; return 0;}

	int r=(t-sum)/5;
	cout<<r<<endl;

}