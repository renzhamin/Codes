#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long n,k;
	cin>>n>>k;
	long arr[n+1],tmp;
	arr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		arr[i]=tmp+arr[i-1];
	}
	long planks=arr[k],ind=1;

	for(int i=k+1;i<=n;i++){
		if((arr[i]-arr[i-k])<planks){
			ind=i-k+1;
			planks=arr[i]-arr[i-k];
		}
	}

	cout<<ind<<endl;
}