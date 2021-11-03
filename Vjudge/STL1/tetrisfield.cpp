#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin);
	int t;cin>>t;while(t--){
		int even=0,odd=0;
		int n,tmp;cin>>n;int x=n;
		while(n--){
			cin>>tmp;
			if(tmp%2) odd++;else even++;
		}
		if(even==x || odd==x) cout<<"YES\n";
		else cout<<"NO\n";
	}
}