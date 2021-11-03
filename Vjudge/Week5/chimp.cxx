#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;cin>>n;
	long long arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
//	long longn=sizeof(arr)/sizeof(arr[0]);
	long q;
	cin>>q;

    //for(long long i=0;i<q;i++) cin>>m;
	while(q--){
	long long low=0,high=n-1;
	long long mid;
	long long m;
    cin>>m;
	/*for(;low<=high;){
		mid=(low+high)/2;
		if(arr[mid]> m ){
		     high=mid-1;
		}
		else if(arr[mid]<m){
		     low=mid+1;
		}
		else if(arr[mid]==m){
		     break;
		}
	} */
   string x="X";
   long long s=0,t=0;

   s=lower_bound(0,n-1,m)-0;
   t=upper_bound(0,n-1,m)-0;

   if(!s) cout<<x<<" ";
   else cout<<arr[s-1]<<" ";
   if(!t) cout<<x<<"\n";
   else cout<<arr[t]<<"\n";
// cout<<arr[mid];
	}

}
