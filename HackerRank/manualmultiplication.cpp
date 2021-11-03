#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string x,y;cin>>y>>x;
	int n=x.length(),k=y.length(),m=0,tmp,carry=0,r;
	string s[n],mul;
	for(int i=n-1;i>=0;i--,m++){
		carry=0;
		for(int j=k-1;j>=0;j--){
			tmp=(x[i]-48)*(y[j]-48);
			r=tmp%10;
			carry+=r+tmp/10;
			mul+=(carry+48);
			//cout<<tmp<<endl;
		}
		s[i]=mul+(carry+48)+(string(m,'0'));
	}
	cout<<s[0]<<endl;
}