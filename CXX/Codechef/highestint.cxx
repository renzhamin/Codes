#include <iostream>
using namespace std;
int highestint(int arr[],int n){
	int max=arr[0];
	for(int i=1;i<n;i++){
		if (arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
	
int main(){
	int lis[]={19,2,65,8};
	int n=sizeof(lis)/sizeof(lis[0]);
	int mli=highestint(lis,n);
	cout << mli;
	
}
