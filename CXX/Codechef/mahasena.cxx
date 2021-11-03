#include <iostream>
using namespace std;
int main(){
	int i,n;cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int even=0,odd=0;
	for(i=0;i<5;i++){
		if(arr[i]%2==0)
		   even++;
		else
		   odd++;
	}	
	if(even>odd)
	   cout<<"READY FOR BATTLE";
	else
	   cout<<"NOT READY";
}

