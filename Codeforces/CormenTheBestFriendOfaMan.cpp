#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,k,tmp;cin>>n>>k;int arr[n],change[n],more=0;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n-1;i++){
		tmp=arr[i]+arr[i+1];
		if(tmp<k){
			arr[i+1]=arr[i+1]+(k-tmp);
			more+=(k-tmp);	
		}
		change[i]=arr[i];
	}
	change[n-1]=arr[n-1];
	cout<<more<<endl;
	for(int i=0;i<n;i++) cout<<change[i]<<" ";
}