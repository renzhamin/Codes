#include <iostream>
using namespace std;
int fib[46];
char f(int n,int i){
	if(n==0) return 'a'; else if(n==1) return 'b';
	else {
		if(i>fib[n-2])
			return f(--n,i-fib[n-2]);
		else
			return f(n-2,i);
	}
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

	fib[0]=1; fib[1]=1;
	for(int i=2;i<=45;i++)
		fib[i]=fib[i-1]+fib[i-2];

	int t,n,i;cin>>t;

	while(t--){
		cin>>n>>i;
		cout<<f(n,i)<<endl;
	}
}