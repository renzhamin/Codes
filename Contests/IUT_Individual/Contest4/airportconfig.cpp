#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long n,tmp,l,s=0,t;
	while(cin>>n && n!=0){
		long arr[n];s=0;
		for(int i=0;i<n;i++) cin>>arr[i];
		s+=(arr[0]*6+5);
		for(int i=1;i<n;i++){
			tmp=arr[i]-arr[i-1];
			if(tmp>0){
				s+=(tmp*6+5);
			} else {
				s+=(abs(tmp)*4+5);
			}

		}
		cout<<s<<endl;
	}
}