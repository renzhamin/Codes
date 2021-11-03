#include <bits/stdc++.h>
using namespace std;

bool check(long long *arr,int n,long long mid,int cow){
	int cows=1,i=0;
	while(1){
		long long x=arr[i]+mid;
		auto value=lower_bound(arr+i,arr+n,x);
		auto pos=distance(arr,value);
		if(pos==n) break;
		cows++;
		i=pos;
	}
	return cows>=cow;
}

long long bs(long long *arr,int n,int cow){
	long long high=arr[n-1],
		low=0,mid,ans=0;
	while(low<=high){
		mid=(high+low)/2;
		// cout<<"low="<<low<<" high="<<high<<" mid="<<mid<<"\n";
		if(check(arr,n,mid,cow))
			low=mid+1,ans=mid;
		else
			high=mid-1;
	}
	return ans;
}


int main(){
	long long n,cow,ans;
	int t;cin>>t;
	while(t--){
		cin>>n>>cow;
		long long arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		ans=bs(arr,n,cow);
		cout<<ans<<"\n";
	}
}
/*
1
5 3
1
2
8
4
9
*/
