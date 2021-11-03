#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long n,neg=0,s=0;cin>>n;
	long long arr[n],n0=0;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){ 
		if(arr[i]<0) neg++;
		if(!arr[i]) n0++;
		else 
		if(arr[i]>0)
			s+=(arr[i]-1);
		else
			s+=(-1-arr[i]);
	}
	if(neg&1 && !n0) s+=2;
	cout<<s+n0<<endl;  
}	