#include <iostream>
#include <algorithm>
using namespace std;
long long arr[1000000];
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long tmp,n=1;
	while(cin>>tmp) arr[n++]=tmp;arr[0]=0;
	for(int i=1;i<n;i++){
		sort(arr,arr+i);
		if(i&1){
			tmp=arr[i/2+1];
			cout<<tmp<<endl;
		} else {
			tmp=(arr[i/2]+arr[i/2+1])/2;
			cout<<tmp<<endl;
		}
	}
}