#include <iostream>
#include <string>
using namespace std;

string o1,o2;
bool flag=0;
void getv(char x){
	if(x=='2'){
		if(flag){
			o1+='0';o2+='2';
		} else {
			o1+='1'; o2+='1';
		}
		return;
	} 

	if(x=='1'){
		if(flag) {o1+='0'; o2+='1';}
		else {
			o1+='1';o2+='0';
			flag=1;
		}
		return;
	}

	if(x=='0'){
		o1+='0'; o2+='0';
	}
} 


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n;cin>>t;
	while(t--){
		flag=0;
		o1.clear();o2.clear();
		string s;
		cin>>n;
		cin>>s;
		for(int i=0;i<n;i++){
			getv(s[i]);
		}
		cout<<o1<<endl<<o2<<endl;
	}
}