#include <iostream>
using namespace std;
const long long mod=(int)1e9+7;

unsigned long long ml(unsigned long long a,unsigned long long n){
	unsigned long long result=1,i=a,c=n/a;
	a++;
	while(c){
		result=(result*a)%mod;
		a=a+i;
		c--;
	}
	return result;
}

int main(){
	freopen("Input.txt","r",stdin); 
	freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	long long n,k;
	while(t--){
		cin>>k>>n;
		cout<<"Case "<<T++<<": ";
		cout<<ml(k,n)<<endl;		
	}
}