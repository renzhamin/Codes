#include <iostream>
using namespace std;
int main(){
	int n;cin>>n;
	int k;cin>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int s=0;
	for(int i=0;i<n;i++){
		if(arr[i]%k==0)
		   s++;
	}
	cout<<s<<endl;
}