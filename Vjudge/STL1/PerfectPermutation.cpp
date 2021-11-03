#include <iostream>
using namespace std;
int n,i;
int main(){
	cin>>n;
	if(n%2==0)
		for(i=n; i>=1; i--)
		cout<<i<<" ";
	else cout<<-1;
}
