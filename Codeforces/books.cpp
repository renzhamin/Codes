#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long n,t,i=0,j=0,ans=0;cin>>n>>t;
	long tmp,csum[n+1]; csum[0]=0;
	for(int i=1;i<=n;i++) cin>>tmp,csum[i]=tmp+csum[i-1];
	for(i=1;i<=n;i++){
		cout<<"csum["<<i<<"]-csum["<<j<<"]= "<<csum[i]<<"-"<<csum[j]<<" = "<<csum[i]-csum[j]<<endl;
		if(csum[i]-csum[j]>t)
			j++;
		ans=max(i-j,ans);
	}
	cout<<ans<<endl;
}