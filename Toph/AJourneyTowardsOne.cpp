#include <iostream>
using namespace std;
const int MAX=(int)1e6+1;
long mem[MAX];
int solve(int n){
	if(n==1) return 0;
	if(mem[n]!=-1) return mem[n];
	if(n&1)
		return mem[n]=2+min(solve((n+1)/2),solve((n-1)/2));
	else
		return mem[n]=1+solve(n/2);
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n;
	for(int i=0;i<MAX;i++) mem[i]=-1;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<solve(n)<<endl;
	}

}