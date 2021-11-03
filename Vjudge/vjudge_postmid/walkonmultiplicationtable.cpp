#include <iostream>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long i,m=n-1,tmp=0;
	for(i=1;i*i<=n;i++){
		if(n%i==0){
			tmp=i+n/i-2;
			if(tmp<m) m=tmp;
		}
	}
	cout<<m<<endl;
}