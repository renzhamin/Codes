#include <iostream>
#define done(s) {cout<<s<<endl;continue;}
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n[]={6,7,3,6,5,4,5,5,6};
	int t;cin>>t;
	while(t--){
		int seg;cin>>seg;
		
		if(seg>46) done("998244353")
		if(seg==2) done("1")
		if(seg==3) done("7")
		
		if(seg<=18){
			for(int i=1;i<=seg/2;i++) cout<<1;
			cout<<endl;
			continue;
		}
		string s=string(9,'1');
		int j=0;
		seg-=16;
		for(int i=0;i<10;i++){
			if(n[i]<=seg){
				s[j++]=(10-(i+1))+48;
				seg-=n[i];
			}
			if(seg<=0) break;
		}
		cout<<s<<endl;
	}
}