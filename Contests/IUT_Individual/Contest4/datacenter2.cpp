#include <iostream>
#include <algorithm>
using namespace std;
long arr[100000];
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,i=1;
	while(cin>>n){
		arr[i-1]=n;
		sort(arr,arr+i);
		if(i&1)
			cout<<arr[i/2]<<endl;
		else
			cout<<(arr[i/2]+arr[i/2-1])/2<<endl;
		i++;
	}
}