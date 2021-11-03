#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool sortdesc(pair<int,int>&a,pair<int,int>&b){
	return a.first>b.first ;
}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		pair<int,int>arr[n+1];
		for(int i=1;i<=n;i++) {
			cin>>arr[i].first;
			arr[i].second=i;
		}
		sort(arr+1,arr+n+1,sortdesc);
		int half=n/2;
		bool flag=0;
		int j=0,yes=1,tmp=-1,s=0;
		for(int i=1;i<=half;i++){
			yes=1;
			for(j=1;j<=half;j++){
				tmp=arr[j].second;//cout<<tmp<<endl;
				if(j>1 && arr[j].first<arr[j-1].first) break;
				if(tmp+i>n || tmp+i<=half) {yes=0;break;}
			} 
			if(yes) s++;
		}
		cout<<s<<endl;
		//cout<<"Done"<<endl;
	}
}