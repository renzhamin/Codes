#include <iostream>
#include <algorithm>
using namespace std;
int n,s=0;

void dispatch(int arr[],int i){
	if(i<=0) return;
	s+=(arr[i]-arr[i-1]);
	dispatch(arr,i-2);
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	dispatch(arr,n-1);
	cout<<s<<endl;
}