#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n1,n2,tmp;
	cin>>n1>>n2>>tmp>>tmp;
	if(n1>n2)
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;
}