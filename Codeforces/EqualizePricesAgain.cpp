#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long t,n,tmp,sum,ans;cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>tmp; sum+=tmp;
		}
		ans=ceil((double)sum/n);
		cout<<ans<<endl;
	}
}