#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long a,b,c,s1,s2,tmp1,tmp2,dif,ans;
	int t;cin>>t;
	while(t--){
		cin>>a>>b>>c;
		ans=(a+b+c)/2;
		cout<<ans<<endl;
		// tmp1=min(a,b);
		// tmp2=max(a,b);
		// dif=tmp2-tmp1;
		// if(tmp1+c<=tmp2)
		// 	ans=tmp1+c;
		// else
		// 	ans=(c-dif)/2+tmp2;

		// cout<<ans<<endl;
	}	
}