#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,t,subl,dis;
	char s='a';
	cin>>t;
	while(t--){
		cin>>n>>subl>>dis;
		s='a';
		string ans;
		int ds=0;
		for(int i=0;i<n;++i){
			ans+=s;
			ds++;
			if(ds==dis){
				ds=0;
				s='a';
			} else 
				s++;	
		}
		cout<<ans<<"\n";
	}
}