#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


const long long mod = 1000000007;
long long arr[100005],sum,t,n;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n,greater<long long>());
		sum=0;
		for(int i=0;i<n;i++){
			arr[i]-=i;
			if(arr[i]<=0) break;
			sum+=arr[i];
		}
		sum%=mod;
		cout<<sum<<endl;
		memset(arr,0,sizeof(arr));
	}
}