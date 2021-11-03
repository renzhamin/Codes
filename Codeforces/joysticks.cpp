#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int a,b,s=0;
	int *ch,*batt; cin>>a>>b;
	if(a==1 && b==1) {cout<<0; return 0;}
	while(1){
		s++;
		if(a<b) ch=&a,batt=&b; else ch=&b,batt=&a;
		(*ch)++; (*batt)-=2;
		if(a<=0 || b<=0)
			break;
	}
	cout<<s<<endl;
}