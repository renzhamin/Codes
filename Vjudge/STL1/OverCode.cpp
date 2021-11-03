#include <iostream>
#include <algorithm>
using namespace std;
int arr[6000];
int main(){
  freopen("overcode.in","r",stdin);
  int t;cin>>t;while(t--){	
	int n;cin>>n;
	int s=0;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if(i+5<n)
			if(arr[i+5]-arr[i]<=1000) {
				s++;i+=5;
			}
	}
	cout<<s<<endl;
   }
}