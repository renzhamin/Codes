#include <iostream>
#include 
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int arr[20],n;
	cin>>arr[0]>>arr[1]>>n;
	for(int i=2;i<20;i++)
		arr[i]=arr[i-1]*arr[i-1]+arr[i-2];
	cout<<arr[n-1]<<endl;
}