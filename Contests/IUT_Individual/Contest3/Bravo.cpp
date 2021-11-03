#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=0;cin>>t;
	int n,m,x[11],y[11],type[11];
	memset(type,-1,sizeof(type));
	while(cin>>n){
		cin>>m;
		int arr[n+1];
		for(int i=1;i<=n;i++) arr[i]=i;
		for(int i=1;i<=m;i++) cin>>type[i]>>x[i]>>y[i];
		for(int i=1;i<=m;i++){
			if(type[i]==1){
				if(arr[x]!=arr[y]-1)
			}
		}
	}
}