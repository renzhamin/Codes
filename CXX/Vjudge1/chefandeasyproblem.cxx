#include <iostream>
using namespace std;
int main(){
	unsigned long long int t;cin>>t;
	while(t--){
    unsigned long long int s=0;
    unsigned long long int n,i,j,tmp;cin>>n;
	unsigned long long int arr[n];
	for( i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				tmp=arr[j];
				arr[j]=arr[i];
				arr[i]=tmp;
			}
		}
	}
	for(i=0;i<n;i=i+2){
		s=s+arr[i];
	}
	cout<<s<<endl;
	}
}