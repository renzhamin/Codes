#include <iostream>
using namespace std;
int fib[46];
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		fib[0]=1; fib[1]=1;
		for(int i=2;i<=45;i++)
			fib[i]=fib[i-1]+fib[i-2];

		int n,i,l=1; cin>>n>>i;
		while(n>=0){
			if(n==0) {cout<<"a"<<endl;break;} else if(n==1) {cout<<"b"<<endl;break;}
			if(i>fib[n-2])
				i=i-fib[n-2],n--;
			else
				n-=2;
			//cout<<"at step "<<l++<<" n="<<n<<" i="<<i<<endl;
		}	
	}
}