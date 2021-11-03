#include <iostream>
using namespace std;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long n,tmp,minp=101,load,waste=0; 
	cin>>n; 
	while(n--){
		cin>>load>>tmp; 
		minp=min(tmp,minp);
		waste+=minp*load;
	}
	cout<<waste<<endl;
}	