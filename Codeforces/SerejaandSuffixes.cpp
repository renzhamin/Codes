#include <iostream>
#define max 100001
using namespace std;

int arr[max],cnt[max],csum[max];

int i,n,m,tmp;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	for(cin>>n>>m,i=1;i<=n;i++) cin>>arr[i];
	for(i=n;i>0;i--) csum[i]=csum[i+1]+!cnt[arr[i]]++;
	for(;cin>>tmp;cout<<csum[tmp]<<"\n") ;
}