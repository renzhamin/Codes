#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1,j;cin>>t;
	while(t--){
		string s;
		long long div,x=0;
		cin>>s>>div;
		j=0;
		if(s[0]=='-') j=1;
		if(div<0) div*=-1;
		for(int i=j;s[i];i++){
			x=x*10+(s[i]-48);
			x=x%div;
		}
		cout<<"Case "<<T++<<": ";
		if(x==0)
			cout<<"divisible"<<endl;
		else
			cout<<"not divisible"<<endl;
	}
}