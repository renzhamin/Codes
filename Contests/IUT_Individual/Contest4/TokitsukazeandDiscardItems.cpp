#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	double good,bad,box,total,Bad;
	double ans=0,prob,allprob;
	cin>>good>>bad>>box;
	Bad=bad;
	bad=bad-(box-1);
	if(bad>0){
		total=bad+good;
		prob=(box-1)+bad/total;
		allprob=prob+good/total;
		ans=prob/allprob;
		cout<<setprecision(10)<<ans<<endl;
		return 0;
	} 

	prob=Bad;
	allprob=Bad+(box-Bad);
	ans=prob/allprob;
	cout<<setprecision(10)<<ans<<endl;

}