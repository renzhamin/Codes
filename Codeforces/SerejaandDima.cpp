#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	int last=n-1,first=0,sh=0,dm=0;
	int i=0;
	while(1){
		if(i%2==0){
			if(arr[last]>arr[first]){
				sh+=arr[last];last--;
			} else {
				sh+=arr[first]; first++;
			}
		} else {
			if(arr[last]>arr[first]){
				dm+=arr[last];last--;
			} else {
				dm+=arr[first]; first++;
			}			
		}
		i++;
		if(i==n) break;
	}
	cout<<sh<<" "<<dm<<endl;
}