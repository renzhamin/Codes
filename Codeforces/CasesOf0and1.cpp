#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin);
	freopen("Output.txt","w",stdout);
	int n;cin>>n;
	string s;cin>>s;
	int a[2]={};			
	for(int i=0;i<n;i++){
		a[s[i]-48]++;
	}
	cout<<abs(a[0]-a[1]);

}