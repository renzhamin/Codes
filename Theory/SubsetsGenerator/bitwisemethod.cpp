#include <iostream>
using namespace std;
int main(){
	string s="abc";
	int n=s.length(),setlen=1<<n;
	for(int i=0;i<setlen;i++){
		for(int j=0;j<n;j++){
			if(i & (1<<j))
				cout<<s[j];
		}
		cout<<endl;
	}
}
