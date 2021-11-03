#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int a,b;cin>>a>>b;
	int sum=a+b,small=min(a,b),big=max(a,b),dif=big-small+1;
	cout<<sum-dif<<endl;

}