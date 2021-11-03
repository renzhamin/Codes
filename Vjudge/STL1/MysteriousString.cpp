#include <iostream>
using namespace std;
int main(){
	//freopen("Input.txt","r",stdin);
	string x,y;
	cin>>x>>y;
	int i,n=y.length();
	for(i=0;i<n;i++)
		if(x[i]<y[i])
			break;
	if(i==n)
		cout<<y<<endl;
	else
		cout<<-1<<endl;
}