#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int tx,ty,bx,by;
	int t;cin>>t;
	string s[2]={"Escape is possible.","Box cannot be dropped."};
	while(t--){
		cin>>tx>>ty>>bx>>by;
		bool f=(max(tx,ty)-min(bx,by)>=0);
		if(f)
			cout<<s[0]<<"\n";
		else
			cout<<s[1]<<"\n";
	}
}