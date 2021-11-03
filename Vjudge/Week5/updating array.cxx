#include <iostream>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
    vector<int>arr;
    int n,u,q;
    cin>>n>>u;
    int i,tmp;
    int l,r,v;
    arr.assign(n+1,0);
    while(u--) {cin>>l>>r>>v;
    for(i=l;i<=r;i++){
    	arr[i]+=v;
    }
    }
    cin>>q;
    while(q--){
    	cin>>tmp;
    	cout<<arr[tmp]<<endl;
    }
 
    }
}