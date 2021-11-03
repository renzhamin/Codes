#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,tmp;cin>>t;
	while(t--){
		int s=0;
		set<string>winners;
		cin>>n;
		pair<long long,string>arr[n+1];
		for(int i=0;i<n;i++) cin>>arr[i].second>>arr[i].first;
		sort(arr,arr+n);
		for(int i=n-1;i>=2;i--){
			for(int j=i-1;j>=1;j--){
				for(int k=j-1;k>=0;k--){
					if(arr[i].first==arr[j].first+arr[k].first){
						winners.insert(arr[i].second);
					}
				}
			}
		}
		for(int i=n-1;i>=3;i--){
			for(int j=i-1;j>=2;j--){
				for(int k=j-1;k>=1;k--){
					for(int l=k-1;l>=0;l--){
						if(arr[i].first==arr[j].first+arr[k].first+arr[l].first){
							winners.insert(arr[i].second);
						}
					}
				}
			}
		}
		cout<<winners.size()<<endl;
		for(auto i:winners)
			cout<<i<<endl;
	}
}