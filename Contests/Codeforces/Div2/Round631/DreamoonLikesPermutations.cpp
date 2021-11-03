#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
int cnt[102];
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,sum,nth,ind[100],j;cin>>t;
	while(t--){
		bool f=0;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			cnt[arr[i]]++;			
		}
		sum=nth=j=0;
		int l=0;
		for(int i=0;i<n;i++){
			sum+=arr[i]; l++;
			nth=(1+sqrt(1+8*sum))/2-1;
			if(sum==(nth*(nth+1)/2) && l==nth){
				ind[j++]=nth;
				sum=0;
				l=0;
			}
		}
		cout<<ind[0]<<" "<<ind[1]<<endl;
		memset(cnt,0,sizeof(cnt));
	}
}