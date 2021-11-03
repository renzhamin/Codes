#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
pair<int,int>co[1001];

void solve(){
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>co[i].first,cin>>co[i].second;
	sort(co,co+n);
	int x=0,y=0;
	for(int i=0;i<n;i++){
		if(co[i].second<y){
			cout<<"NO\n"; return;		
		}
		y=co[i].second;
	}
	cout<<"YES\n";
	y=0;
	for(int i=0;i<n;i++){
		while(x!=co[i].first) x++,cout<<"R";
		while(y!=co[i].second) y++,cout<<"U";
	}
	cout<<endl;
}

int main(){
	freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--)
		solve();
}