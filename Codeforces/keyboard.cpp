#include <iostream>
using namespace std;
int main(){
	//freopen("Input.txt","r",stdin);
	string s="qwertyuiopasdfghjkl;zxcvbnm,./",inp;
	char tmp;int m; 
	cin>>tmp>>inp;
	if(tmp=='R') m=-1; else m=1;
	for(int i=0;i<inp.size();i++)
		for(int j=0;j<s.size();j++){
			if(inp[i]==s[j]){
				inp[i]=s[j+m];
				break;
			}
		}
	cout<<inp;
}