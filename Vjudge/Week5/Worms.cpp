#include <iostream>
#include <vector>
using namespace std;
typedef long long lli;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	vector<lli>arr;
	vector<lli>csum;
	lli tmp=0,inp;
	for(int i=0;i<n;i++){
		cin>>inp;
		arr.push_back(inp);
		tmp+=arr[i];
		csum.push_back(tmp);
	}
	int t;cin>>t;
	while(t--){
    lli m;
    cin>>m;
    lli mid,low=0,high=n-1;
    mid=(high+low)/2;
    while(low<=high){
        mid=(high+low)/2;
        if(csum[mid]==m)
            break;
        if(csum[mid]>m)
            high=mid-1;
        if(csum[mid]<m)
            low=mid+1;

    }
    if(csum[mid]<m && mid+1<(n-1)) mid++;
    cout<<mid+1<<endl;
	}
}
