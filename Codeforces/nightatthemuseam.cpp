#include <iostream>
using namespace std;

int id(char x){
	return (x-'a');
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s;cin>>s;
	int cur=0,las=0,m=0;

	for(int i=0;i<s.length();i++){
		cur=id(s[i]);
		m+=min(abs(cur-las),(26-abs(cur-las)));
		las=cur;
	}

	cout<<m<<endl;

}	