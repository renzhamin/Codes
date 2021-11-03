#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,k,d,tmp;
	cin>>n>>k;
	int arr[n+1]{};
	while(k--){
       cin>>d;
       for(int i=1;i<=d;++i){
       	   cin>>tmp;
       	   arr[tmp]=1;
       }
	}
	int ans=count(arr+1,arr+n+1,0);
	cout<<ans<<"\n";

}