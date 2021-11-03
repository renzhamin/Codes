#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,i,j; cin>>n; string s[n];
		for(int i=0;i<n;i++) cin>>s[i];
		if(n<3) { cout<<"NO"<<endl; continue;}
		for(i=0;i<n;i++){
			for(j=i+2;j<n;j++)
				if(s[i]==s[j]){
					cout<<"YES"<<endl; 
					break;
				}
			if(j<n) break;
		}
		if(i<n) continue;
		cout<<"NO"<<endl;
	}
}