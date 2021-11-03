#include <iostream>
using namespace std;
int main(){
	freopen("Output.txt","w",stdout);
	string s="IJ TPGEPS BMJ";
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]!=' ') s[i]--;
		cout<<s[i];
	}
}



[[(){]}]

