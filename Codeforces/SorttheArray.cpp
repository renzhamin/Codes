#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n;
	int arr[n],copy[n];
	for(int i=0;i<n;i++) cin>>arr[i],copy[i]=arr[i];
	sort(arr,arr+n);
	int s=0,e=1;
	bool first=1;
	for(int i=0;i<n;i++){
		if(arr[i]!=copy[i]){
			if(first)
				s=i,
				first=0;
			else
				e=i+1;
		}
	}
	reverse(copy+s,copy+e);
	if(is_sorted(copy,copy+n))
		cout<<"yes"<<endl<<s+1<<" "<<e<<endl;
	else
		cout<<"no"<<endl;
}