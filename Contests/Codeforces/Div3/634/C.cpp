#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n,dup,dist,tmp,ndups,disdups,maxdups,ans,A,B;
	int t;cin>>t;
	while(t--){
		cin>>n;
		dup=dist=ndups=disdups=maxdups=ans=A=B=0;
		long long arr[n+1];
		bool isdup[n+1];
		for(int i=1;i<=n;i++) arr[i]=0,isdup[i]=0;
		for(int i=1;i<=n;i++) {
			cin>>tmp;
			arr[tmp]++;
			if(arr[tmp]==1)
				dist++;
			if(arr[tmp]>1)
				dup++,isdup[tmp]=1;
		}
		for(int i=1;i<=n;i++) {
			if(arr[i]==1) ndups++;
			if(isdup[i]) disdups++;
			maxdups=max(maxdups,arr[i]);
		}
		A=ndups+disdups;
		B=max(0LL,maxdups);
		if(A>1 && !B) B=1;
		ans=min(A,B);
		if(n==1) ans=0;
		if(A==B) ans=max(--ans,0LL);
		cout<<ans<<"\n";
	}
}