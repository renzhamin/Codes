#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin);
	string s1,s2;
	int n,s=0;cin>>n>>s1>>s2;
	int x,y;
	for(int i=0;i<n;i++){
		x=s1[i]-48; y=s2[i]-48;
		s+=min(abs(x-y),min(x,y)+10-max(x,y));
	}
	cout<<s<<endl;
}